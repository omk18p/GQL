#include "PhysicalPlanner.h"
#include <iostream>

using namespace std;

unique_ptr<PhysicalPlanNode> PhysicalPlanner::build(LogicalPlanNode* logicalPlan) {
    if (!logicalPlan) return nullptr;
    logicalPlan->accept(this);
    return move(currentPhysicalNode);
}

void PhysicalPlanner::visitNodeScan(NodeScanNode* node) {
    unique_ptr<PhysicalPlanNode> scanNode;
    if (node->label.empty()) {
        scanNode = make_unique<PhysicalFullScan>(node->variable);
    } else {
        scanNode = make_unique<PhysicalIndexScan>(node->label, node->variable);
    }
    
    if (!node->children.empty()) {
        node->children[0]->accept(this);
        if (currentPhysicalNode) {
            scanNode->children.push_back(move(currentPhysicalNode));
        }
    }
    
    currentPhysicalNode = move(scanNode);
}

void PhysicalPlanner::visitEdgeScan(EdgeScanNode* node) {
    auto scanNode = make_unique<PhysicalEdgeScan>(node->label, node->variable, node->direction);
    
    if (!node->children.empty()) {
        node->children[0]->accept(this);
        if (currentPhysicalNode) {
            scanNode->children.push_back(move(currentPhysicalNode));
        }
    }
    
    currentPhysicalNode = move(scanNode);
}

void PhysicalPlanner::visitFilter(FilterNode* node) {
    // 1. Visit child (source of data)
    unique_ptr<PhysicalPlanNode> childPlan = nullptr;
    if (!node->children.empty()) {
        node->children[0]->accept(this);
        childPlan = move(currentPhysicalNode);
    }

    // 2. Process condition
    currentExpressionString = "";
    if (node->condition) {
        node->condition->accept(this);
    }
    string condition = currentExpressionString;

    // 3. Create Physical Filter
    auto filter = make_unique<PhysicalFilter>(condition);
    if (childPlan) {
        filter->children.push_back(move(childPlan)); // Single child
    }
    currentPhysicalNode = move(filter);
}

void PhysicalPlanner::visitProject(ProjectNode* node) {
    // 1. Visit child
    unique_ptr<PhysicalPlanNode> childPlan = nullptr;
    if (!node->children.empty()) {
        node->children[0]->accept(this);
        childPlan = move(currentPhysicalNode);
    }

    // 2. Create Project
    vector<string> projectFields;
    // Iterate over expressions to potentially get field names
    for (size_t i = 0; i < node->expressions.size(); ++i) {
        currentExpressionString = "";
        node->expressions[i]->accept(this);
        
        string fieldName = "";
        if (i < node->fields.size()) {
            fieldName = node->fields[i]; // Use alias if available
        }
        
        if (fieldName.empty()) {
            fieldName = currentExpressionString; // Fallback
        }
        projectFields.push_back(fieldName);
    }
    
    // Fallback if no expressions found but fields exist
    if (projectFields.empty() && !node->fields.empty()) {
        projectFields = node->fields;
    }

    auto project = make_unique<PhysicalProject>(projectFields);
    if (childPlan) {
        project->children.push_back(move(childPlan)); // Single child
    }
    currentPhysicalNode = move(project);
}

void PhysicalPlanner::visitJoin(JoinNode* node) {
    // Join has 2 children: Left and Right sources
    
    unique_ptr<PhysicalPlanNode> leftPlan = nullptr;
    unique_ptr<PhysicalPlanNode> rightPlan = nullptr;

    if (node->children.size() > 0) {
        node->children[0]->accept(this);
        leftPlan = move(currentPhysicalNode);
    }
    if (node->children.size() > 1) {
        node->children[1]->accept(this);
        rightPlan = move(currentPhysicalNode);
    }

    // Process condition
    currentExpressionString = "";
    if (node->condition) {
        node->condition->accept(this);
    }
    string condition = currentExpressionString;

    // Default to NestedLoopJoin for now
    auto join = make_unique<PhysicalNestedLoopJoin>(node->joinType, condition);
    if (leftPlan) join->children.push_back(move(leftPlan));
    if (rightPlan) join->children.push_back(move(rightPlan));

    currentPhysicalNode = move(join);
}

void PhysicalPlanner::visitAggregate(AggregateNode* node) {
    unique_ptr<PhysicalPlanNode> childPlan = nullptr;
    if (!node->children.empty()) {
        node->children[0]->accept(this);
        childPlan = move(currentPhysicalNode);
    }

    // Build groupings string
    vector<string> groups;
    for (size_t i=0; i < node->groupingExpressions.size(); ++i) {
        currentExpressionString = "";
        node->groupingExpressions[i]->accept(this);
        groups.push_back(currentExpressionString); 
    }

    // Build measures
    vector<string> measures;
    for (const auto& item : node->aggregateItems) {
        currentExpressionString = "";
        if (item.expression) item.expression->accept(this);
        string measure = item.functionName + "(" + (item.distinct ? "DISTINCT " : "") + currentExpressionString + ")";
        if (!item.alias.empty()) measure += " AS " + item.alias;
        measures.push_back(measure);
    }

    auto agg = make_unique<PhysicalAggregate>(groups, measures);
    if (childPlan) agg->children.push_back(move(childPlan));
    currentPhysicalNode = move(agg);
}

void PhysicalPlanner::visitSort(SortNode* node) {
    unique_ptr<PhysicalPlanNode> childPlan = nullptr;
    if (!node->children.empty()) {
        node->children[0]->accept(this);
        childPlan = move(currentPhysicalNode);
    }

    vector<PhysicalSort::SortItem> items;
    for (const auto& f : node->sortFields) {
        items.push_back({f.field, (f.direction == "ASC")});
    }

    auto sort = make_unique<PhysicalSort>(items);
    if (childPlan) sort->children.push_back(move(childPlan));
    currentPhysicalNode = move(sort);
}

void PhysicalPlanner::visitLimit(LimitNode* node) {
    unique_ptr<PhysicalPlanNode> childPlan = nullptr;
    if (!node->children.empty()) {
        node->children[0]->accept(this);
        childPlan = move(currentPhysicalNode);
    }

    auto limit = make_unique<PhysicalLimit>(node->limit);
    if (childPlan) limit->children.push_back(move(childPlan));
    currentPhysicalNode = move(limit);
}

void PhysicalPlanner::visitOffset(OffsetNode* node) {
    unique_ptr<PhysicalPlanNode> childPlan = nullptr;
    if (!node->children.empty()) {
        node->children[0]->accept(this);
        childPlan = move(currentPhysicalNode);
    }
    
    auto offset = make_unique<PhysicalOffset>(node->offset);
    if (childPlan) offset->children.push_back(move(childPlan));
    currentPhysicalNode = move(offset);
}

void PhysicalPlanner::visitUnion(UnionNode* node) {
    unique_ptr<PhysicalPlanNode> leftPlan = nullptr;
    unique_ptr<PhysicalPlanNode> rightPlan = nullptr;

    if (node->children.size() > 0) {
        node->children[0]->accept(this);
        leftPlan = move(currentPhysicalNode);
    }
    if (node->children.size() > 1) {
        node->children[1]->accept(this);
        rightPlan = move(currentPhysicalNode);
    }

    auto unionOp = make_unique<PhysicalUnion>(node->distinct);
    if (leftPlan) unionOp->children.push_back(move(leftPlan));
    if (rightPlan) unionOp->children.push_back(move(rightPlan));
    currentPhysicalNode = move(unionOp);
}

void PhysicalPlanner::visitDeleteOp(DeleteOpNode* node) {
     unique_ptr<PhysicalPlanNode> childPlan = nullptr;
    if (!node->children.empty()) {
        node->children[0]->accept(this);
        childPlan = move(currentPhysicalNode);
    }

    auto deleteOp = make_unique<PhysicalDelete>(node->variables, node->detach);
    if (childPlan) deleteOp->children.push_back(move(childPlan));
    currentPhysicalNode = move(deleteOp);
}

void PhysicalPlanner::visitInsertOp(InsertOpNode* node) {
    auto insertOp = make_unique<PhysicalInsert>();
    
    for (auto& pattern : node->patterns) {
        if (pattern->type == LogicalPlanNode::NODE_SCAN) {
            NodeScanNode* nodeScan = static_cast<NodeScanNode*>(pattern.get());
            PhysicalInsertNode pNode;
            pNode.variable = nodeScan->variable;
            if (!nodeScan->label.empty()) {
                pNode.labels.push_back(nodeScan->label);
            }
            for (auto& prop : nodeScan->properties) {
                pNode.properties.push_back({prop.first, prop.second});
            }
            insertOp->insertNodes.push_back(pNode);
        } else if (pattern->type == LogicalPlanNode::EDGE_SCAN) {
            EdgeScanNode* edgeScan = static_cast<EdgeScanNode*>(pattern.get());
            PhysicalInsertEdge pEdge;
            pEdge.variable = edgeScan->variable;
            pEdge.sourceVar = edgeScan->sourceVar;
            pEdge.targetVar = edgeScan->targetVar;
            pEdge.direction = edgeScan->direction;
            if (!edgeScan->label.empty()) {
                pEdge.labels.push_back(edgeScan->label);
            }
            for (auto& prop : edgeScan->properties) {
                pEdge.properties.push_back({prop.first, prop.second});
            }
            insertOp->insertEdges.push_back(pEdge);
        }
    }
    
    unique_ptr<PhysicalPlanNode> childPlan = nullptr;
    if (!node->children.empty()) {
        node->children[0]->accept(this);
        childPlan = move(currentPhysicalNode);
    }
    if (childPlan) insertOp->children.push_back(move(childPlan));
    
    currentPhysicalNode = move(insertOp);
}

void PhysicalPlanner::visitUpdateOp(UpdateOpNode* node) {
     unique_ptr<PhysicalPlanNode> childPlan = nullptr;
    if (!node->children.empty()) {
        node->children[0]->accept(this);
        childPlan = move(currentPhysicalNode);
    }
    
    auto update = make_unique<PhysicalUpdate>();
    
    for (const auto& item : node->items) {
        PhysicalUpdateItem pItem;
        pItem.variable = item.variable;
        pItem.key = item.key;
        
        switch (item.type) {
            case UpdateOpNode::SET_PROPERTY: pItem.type = PhysicalUpdateItem::SET_PROPERTY; break;
            case UpdateOpNode::SET_LABEL: pItem.type = PhysicalUpdateItem::SET_LABEL; break;
            case UpdateOpNode::REMOVE_PROPERTY: pItem.type = PhysicalUpdateItem::REMOVE_PROPERTY; break;
            case UpdateOpNode::REMOVE_LABEL: pItem.type = PhysicalUpdateItem::REMOVE_LABEL; break;
            default: break;
        }
        
        if (item.value) {
            currentExpressionString = "";
            item.value->accept(this);
            pItem.expressionString = currentExpressionString;
        }
        
        update->items.push_back(pItem);
    }
    
    if (childPlan) update->children.push_back(move(childPlan));
    currentPhysicalNode = move(update);
}

// --- Expressions ---
void PhysicalPlanner::visitBinaryExpression(BinaryExpressionNode* node) {
    if (node->left) node->left->accept(this);
    string left = currentExpressionString;
    
    if (node->right) node->right->accept(this);
    string right = currentExpressionString;
    
    currentExpressionString = "(" + left + " " + node->op + " " + right + ")"; 
}

void PhysicalPlanner::visitPropertyAccess(PropertyAccessNode* node) {
    currentExpressionString = node->variable + "." + node->property;
}

void PhysicalPlanner::visitVariableReference(VariableReferenceNode* node) {
    currentExpressionString = node->variable;
}

void PhysicalPlanner::visitLiteral(LiteralNode* node) {
    if (node->literalType == "STRING") currentExpressionString = "\"" + node->value + "\"";
    else currentExpressionString = node->value;
}
