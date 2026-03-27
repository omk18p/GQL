#include "LogicalPlanBuilder.h"
#include "ASTNodes.h"
#include "LogicalPlanNodes.h"
#include "LogicalPlanPrinter.h"
#include <iostream>

using namespace std;

// ========== LogicalPlanBuilder Implementation ==========

unique_ptr<LogicalPlanNode> LogicalPlanBuilder::build(QueryNode* astRoot) {
    currentPlan = nullptr;
    
    // Visit AST root - this will build the logical plan
    astRoot->accept(this);
    
    return move(currentPlan);
}

void LogicalPlanBuilder::visitQuery(QueryNode* n) {
    // Process all children (statements) sequentially
    // This allows MATCH followed by SET/DELETE/etc.
    OrderByStatementNode combinedOrderBy;
    bool hasOrderBy = false;
    
    for (auto& child : n->children) {
        if (child->type == ASTNode::ORDER_BY_STATEMENT) {
            hasOrderBy = true;
            OrderByStatementNode* obs = static_cast<OrderByStatementNode*>(child.get());
            if (!obs->sortSpecs.empty()) combinedOrderBy.sortSpecs = move(obs->sortSpecs);
            if (obs->offset) combinedOrderBy.offset = move(obs->offset);
            if (obs->limit) combinedOrderBy.limit = move(obs->limit);
        } else {
            child->accept(this);
        }
    }
    
    if (hasOrderBy) {
        // Apply ORDER BY, OFFSET, and LIMIT in the correct pipeline order:
        // Limit -> Offset -> Sort -> Plan
        visitOrderByStatement(&combinedOrderBy);
    }
}

void LogicalPlanBuilder::visitOrderByStatement(OrderByStatementNode* n) {
    // 1. Sort
    if (!n->sortSpecs.empty()) {
        auto sortOp = make_unique<SortNode>();
        for (const auto& spec : n->sortSpecs) {
            SortNode::SortField sf;
            ExpressionNode* expr = static_cast<ExpressionNode*>(spec.sortKey.get());
            sf.field = expr->value; // e.g., "n.age"
            sf.direction = spec.direction.empty() ? "ASC" : spec.direction;
            sortOp->sortFields.push_back(sf);
        }
        if (currentPlan) {
            if (currentPlan->type == LogicalPlanNode::PROJECT) {
                sortOp->children.push_back(move(currentPlan->children[0]));
                currentPlan->children[0] = move(sortOp);
            } else {
                sortOp->children.push_back(move(currentPlan));
                currentPlan = move(sortOp);
            }
        } else {
            currentPlan = move(sortOp);
        }
    }
    
    // 2. Offset
    if (n->offset) {
        ExpressionNode* expr = static_cast<ExpressionNode*>(n->offset.get());
        int skipVal = stoi(expr->value);
        auto offsetOp = make_unique<OffsetNode>(skipVal);
        if (currentPlan) {
            offsetOp->children.push_back(move(currentPlan));
        }
        currentPlan = move(offsetOp);
    }
    
    // 3. Limit
    if (n->limit) {
        ExpressionNode* expr = static_cast<ExpressionNode*>(n->limit.get());
        int limitVal = stoi(expr->value);
        auto limitOp = make_unique<LimitNode>(limitVal);
        if (currentPlan) {
            limitOp->children.push_back(move(currentPlan));
        }
        currentPlan = move(limitOp);
    }
}

void LogicalPlanBuilder::visitInsertStatement(InsertStatementNode* n) {
    auto insertOp = make_unique<InsertOpNode>();
    
    unique_ptr<LogicalPlanNode> previousPlan = move(currentPlan);
    
    // Save current plan (e.g. from MATCH) as it is the data stream for INSERT
    if (previousPlan) {
        insertOp->children.push_back(move(previousPlan));
    }
    
    // Build patterns to insert
    for (auto& pattern : n->insertPatterns) {
        currentPlan = nullptr;
        pattern->accept(this); // This creates a Scan node in currentPlan
        if (currentPlan) {
            insertOp->patterns.push_back(move(currentPlan));
        }
    }
    
    currentPlan = move(insertOp);
}

void LogicalPlanBuilder::visitSetStatement(SetStatementNode* n) {
    auto updateOp = make_unique<UpdateOpNode>();
    
    unique_ptr<LogicalPlanNode> previousPlan = move(currentPlan);
    
    for (auto& item : n->items) {
        UpdateOpNode::UpdateItem updateItem;
        updateItem.variable = item.variable;
        updateItem.key = (item.type == "LABEL") ? item.labelName : item.propertyName;
        
        if (item.type == "PROPERTY") updateItem.type = UpdateOpNode::SET_PROPERTY;
        else if (item.type == "LABEL") updateItem.type = UpdateOpNode::SET_LABEL;
        else if (item.type == "MAP")   updateItem.type = UpdateOpNode::SET_MAP;
        
        if (item.valueExpression) {
            updateItem.value = buildExpression(item.valueExpression.get());
        }
        
        updateOp->items.push_back(move(updateItem));
    }
    
    if (previousPlan) {
        LogicalPlanNode* current = previousPlan.get();
        auto isProjectLike = [](LogicalPlanNode::Type t) {
            return t == LogicalPlanNode::PROJECT || t == LogicalPlanNode::AGGREGATE ||
                   t == LogicalPlanNode::SORT || t == LogicalPlanNode::LIMIT ||
                   t == LogicalPlanNode::OFFSET || t == LogicalPlanNode::DISTINCT;
        };

        if (isProjectLike(current->type)) {
            while (!current->children.empty() && isProjectLike(current->children[0]->type)) {
                current = current->children[0].get();
            }
            if (!current->children.empty()) {
                updateOp->children.push_back(move(current->children[0]));
                current->children[0] = move(updateOp);
                currentPlan = move(previousPlan);
            } else {
                updateOp->children.push_back(move(previousPlan));
                currentPlan = move(updateOp);
            }
        } else {
            updateOp->children.push_back(move(previousPlan));
            currentPlan = move(updateOp);
        }
    } else {
        currentPlan = move(updateOp);
    }
}

void LogicalPlanBuilder::visitRemoveStatement(RemoveStatementNode* n) {
    auto updateOp = make_unique<UpdateOpNode>();
    
    unique_ptr<LogicalPlanNode> previousPlan = move(currentPlan);
    
    for (auto& item : n->items) {
        UpdateOpNode::UpdateItem updateItem;
        updateItem.variable = item.variable;
        updateItem.key = (item.type == "LABEL") ? item.labelName : item.propertyName;
        
        if (item.type == "PROPERTY") updateItem.type = UpdateOpNode::REMOVE_PROPERTY;
        else if (item.type == "LABEL") updateItem.type = UpdateOpNode::REMOVE_LABEL;
        
        updateOp->items.push_back(move(updateItem));
    }
    
    if (previousPlan) {
        LogicalPlanNode* current = previousPlan.get();
        auto isProjectLike = [](LogicalPlanNode::Type t) {
            return t == LogicalPlanNode::PROJECT || t == LogicalPlanNode::AGGREGATE ||
                   t == LogicalPlanNode::SORT || t == LogicalPlanNode::LIMIT ||
                   t == LogicalPlanNode::OFFSET || t == LogicalPlanNode::DISTINCT;
        };

        if (isProjectLike(current->type)) {
            while (!current->children.empty() && isProjectLike(current->children[0]->type)) {
                current = current->children[0].get();
            }
            if (!current->children.empty()) {
                updateOp->children.push_back(move(current->children[0]));
                current->children[0] = move(updateOp);
                currentPlan = move(previousPlan);
            } else {
                updateOp->children.push_back(move(previousPlan));
                currentPlan = move(updateOp);
            }
        } else {
            updateOp->children.push_back(move(previousPlan));
            currentPlan = move(updateOp);
        }
    } else {
        currentPlan = move(updateOp);
    }
}

void LogicalPlanBuilder::visitDeleteStatement(DeleteStatementNode* n) {
    auto deleteOp = make_unique<DeleteOpNode>();
    deleteOp->detach = n->detach;
    
    unique_ptr<LogicalPlanNode> previousPlan = move(currentPlan);
    
    for (auto& expr : n->expressions) {
        if (expr->type == ASTNode::EXPRESSION) {
            ExpressionNode* exprNode = static_cast<ExpressionNode*>(expr.get());
            deleteOp->variables.push_back(exprNode->value);
        }
    }
    
    if (previousPlan) {
        LogicalPlanNode* current = previousPlan.get();
        auto isProjectLike = [](LogicalPlanNode::Type t) {
            return t == LogicalPlanNode::PROJECT || t == LogicalPlanNode::AGGREGATE ||
                   t == LogicalPlanNode::SORT || t == LogicalPlanNode::LIMIT ||
                   t == LogicalPlanNode::OFFSET || t == LogicalPlanNode::DISTINCT;
        };

        if (isProjectLike(current->type)) {
            while (!current->children.empty() && isProjectLike(current->children[0]->type)) {
                current = current->children[0].get();
            }
            if (!current->children.empty()) {
                deleteOp->children.push_back(move(current->children[0]));
                current->children[0] = move(deleteOp);
                currentPlan = move(previousPlan);
            } else {
                deleteOp->children.push_back(move(previousPlan));
                currentPlan = move(deleteOp);
            }
        } else {
            deleteOp->children.push_back(move(previousPlan));
            currentPlan = move(deleteOp);
        }
    } else {
        currentPlan = move(deleteOp);
    }
}

void LogicalPlanBuilder::visitMatchStatement(MatchStatementNode* n) {
    
    unique_ptr<LogicalPlanNode> previousPlan = move(currentPlan);
    unique_ptr<LogicalPlanNode> plan;
    LogicalPlanNode* previousNode = nullptr;

    for (size_t i = 0; i < n->patterns.size(); ++i) {
        auto& pattern = n->patterns[i];
        
        currentPlan = nullptr; // Reset to avoid appending inside pattern->accept
        pattern->accept(this);
        auto newScan = move(currentPlan);
        
        if (!plan) {
            plan = move(newScan);
            if (previousPlan) {
                // Link the previous plan (e.g. SET/DELETE) to the FIRST node of this MATCH
                plan->children.push_back(move(previousPlan));
            }
            previousNode = plan.get();
        } else {
            auto join = make_unique<JoinNode>();
            join->joinType = "INNER";
            
            // Try to find matching variables between left and right
            // For now, if current is Edge, link it to previous Node
            string leftVar, rightVar;
            if (previousNode->type == LogicalPlanNode::NODE_SCAN) {
                leftVar = static_cast<NodeScanNode*>(previousNode)->variable;
            } else if (previousNode->type == LogicalPlanNode::EDGE_SCAN) {
                leftVar = static_cast<EdgeScanNode*>(previousNode)->variable;
            }

            if (newScan->type == LogicalPlanNode::NODE_SCAN) {
                rightVar = static_cast<NodeScanNode*>(newScan.get())->variable;
            } else if (newScan->type == LogicalPlanNode::EDGE_SCAN) {
                rightVar = static_cast<EdgeScanNode*>(newScan.get())->variable;
            }

            auto binOp = make_unique<BinaryExpressionNode>();
            binOp->op = "=";
            
            // Logic: if left is Node and right is Edge -> node.id = edge._source
            // if left is Edge and right is Node -> edge._target = node.id
            if (previousNode->type == LogicalPlanNode::NODE_SCAN && newScan->type == LogicalPlanNode::EDGE_SCAN) {
                auto rightEdgeScan = static_cast<EdgeScanNode*>(newScan.get());
                binOp->left = make_unique<PropertyAccessNode>(leftVar, "id");
                if (rightEdgeScan->direction == "<--") {
                    rightEdgeScan->targetVar = leftVar;
                    binOp->right = make_unique<PropertyAccessNode>(rightVar, "_target");
                } else {
                    rightEdgeScan->sourceVar = leftVar;
                    binOp->right = make_unique<PropertyAccessNode>(rightVar, "_source");
                }
            } else if (previousNode->type == LogicalPlanNode::EDGE_SCAN && newScan->type == LogicalPlanNode::NODE_SCAN) {
                auto leftEdgeScan = static_cast<EdgeScanNode*>(previousNode);
                binOp->right = make_unique<PropertyAccessNode>(rightVar, "id");
                if (leftEdgeScan->direction == "<--") {
                    leftEdgeScan->sourceVar = rightVar;
                    binOp->left = make_unique<PropertyAccessNode>(leftVar, "_source");
                } else {
                    leftEdgeScan->targetVar = rightVar;
                    binOp->left = make_unique<PropertyAccessNode>(leftVar, "_target");
                }
            } else {
                // Fallback to Cartesian product (always true) for property joins
                auto leftLit = make_unique<LiteralNode>("1", "NUMBER");
                auto rightLit = make_unique<LiteralNode>("1", "NUMBER");
                binOp->left = move(leftLit);
                binOp->right = move(rightLit);
            }
            
            join->condition = move(binOp);
            
            join->children.push_back(move(plan));
            join->children.push_back(move(newScan));
            
            plan = move(join);
            previousNode = plan->children[1].get(); // The new scan is the right child
        }
    }
    
    // Step 1.5: Attach previous plan to the leaf of the Match plan tree
    if (previousPlan && plan) {
        LogicalPlanNode* current = plan.get();
        // Traverse to the left-most leaf (the first scan)
        while (!current->children.empty()) {
            current = current->children[0].get();
        }
        current->children.push_back(move(previousPlan));
    }

    // Step 2: Add Filter if WHERE clause exists
    if (n->whereClause) {
        WhereClauseNode* whereNode = static_cast<WhereClauseNode*>(n->whereClause.get());
        if (whereNode->condition) {
            auto filter = make_unique<FilterNode>();
            filter->condition = buildExpression(whereNode->condition.get());
            
            // Attach filter on top of scan/join tree
            if (plan) {
                filter->children.push_back(move(plan));
            }
            plan = move(filter);
        }
    }
    
    // Step 3: Add Aggregate/Project if RETURN exists
    if (n->returnStatement) {
        ReturnStatementNode* ret = static_cast<ReturnStatementNode*>(n->returnStatement.get());
        
        if (containsAggregations(ret->expressions)) {
            // Aggregation case: divide into grouping and aggregates
            auto aggregate = make_unique<AggregateNode>();
            
            for (auto& expr : ret->expressions) {
                if (expr->type == ASTNode::EXPRESSION) {
                    ExpressionNode* exprNode = static_cast<ExpressionNode*>(expr.get());
                    if (isAggregateExpression(exprNode)) {
                        AggregateNode::AggregateItem aggItem;
                        aggItem.functionName = exprNode->value;
                        aggItem.distinct = (exprNode->operator_ == "DISTINCT");
                        aggItem.alias = exprNode->alias;
                        if (!exprNode->arguments.empty()) {
                            aggItem.expression = buildExpression(exprNode->arguments[0].get());
                        }
                        aggregate->aggregateItems.push_back(move(aggItem));
                    } else {
                        // Grouping item
                        aggregate->groupingExpressions.push_back(buildExpression(exprNode));
                        if (!exprNode->alias.empty()) {
                            aggregate->groupingAliases.push_back(exprNode->alias);
                        } else {
                            aggregate->groupingAliases.push_back(exprNode->value);
                        }
                    }
                }
            }
            
            if (plan) {
                aggregate->children.push_back(move(plan));
            }
            plan = move(aggregate);
        } else {
            // No aggregations, traditional Project logic
            auto project = make_unique<ProjectNode>();
            
            for (auto& expr : ret->expressions) {
                if (expr->type == ASTNode::EXPRESSION) {
                    ExpressionNode* exprNode = static_cast<ExpressionNode*>(expr.get());
                    
                    string field = exprNode->value;
                    size_t dotPos = field.find('.');
                    if (dotPos != string::npos) {
                        field = field.substr(dotPos + 1);
                    }
                    project->fields.push_back(field);
                    
                    // Also build the expression node
                    project->expressions.push_back(buildExpression(exprNode));
                }
            }
            
            if (plan) {
                project->children.push_back(move(plan));
            }
            plan = move(project);
        }
    }
    
    // Set as current plan
    currentPlan = move(plan);
}

void LogicalPlanBuilder::visitNodePattern(NodePatternNode* n) {
    auto nodeScan = make_unique<NodeScanNode>();
    
    nodeScan->variable = n->variable;
    
    // Extract label (first label for now)
    if (!n->labels.empty()) {
        nodeScan->label = n->labels[0];
    }
    
    // Copy properties (for filtering)
    nodeScan->properties = n->properties;
    
    currentPlan = move(nodeScan);
}

void LogicalPlanBuilder::visitEdgePattern(EdgePatternNode* n) {
    auto edgeScan = make_unique<EdgeScanNode>();
    
    edgeScan->variable = n->variable;
    edgeScan->sourceVar = n->sourceVar;
    edgeScan->targetVar = n->targetVar;
    edgeScan->direction = n->direction;
    
    // Extract label (first label for now)
    if (!n->labels.empty()) {
        edgeScan->label = n->labels[0];
    }
    
    // Copy properties
    edgeScan->properties = n->properties;
    
    currentPlan = move(edgeScan);
}

// visitWhereClause is now handled directly in visitMatchStatement via buildExpression
void LogicalPlanBuilder::visitWhereClause(WhereClauseNode* n) {
    // No-op
}

void LogicalPlanBuilder::visitReturnStatement(ReturnStatementNode* n) {
    unique_ptr<LogicalPlanNode> previousPlan = move(currentPlan);
    unique_ptr<LogicalPlanNode> plan;
    
    if (containsAggregations(n->expressions)) {
        auto aggregate = make_unique<AggregateNode>();
        for (auto& expr : n->expressions) {
            if (expr->type == ASTNode::EXPRESSION) {
                ExpressionNode* exprNode = static_cast<ExpressionNode*>(expr.get());
                if (isAggregateExpression(exprNode)) {
                    AggregateNode::AggregateItem aggItem;
                    aggItem.functionName = exprNode->value;
                    aggItem.distinct = (exprNode->operator_ == "DISTINCT");
                    aggItem.alias = exprNode->alias;
                    if (!exprNode->arguments.empty()) {
                        aggItem.expression = buildExpression(exprNode->arguments[0].get());
                    }
                    aggregate->aggregateItems.push_back(move(aggItem));
                } else {
                    aggregate->groupingExpressions.push_back(buildExpression(exprNode));
                    aggregate->groupingAliases.push_back(exprNode->alias.empty() ? exprNode->value : exprNode->alias);
                }
            }
        }
        if (previousPlan) aggregate->children.push_back(move(previousPlan));
        plan = move(aggregate);
    } else {
        auto project = make_unique<ProjectNode>();
        for (auto& expr : n->expressions) {
            if (expr->type == ASTNode::EXPRESSION) {
                ExpressionNode* exprNode = static_cast<ExpressionNode*>(expr.get());
                string field = exprNode->value;
                size_t dotPos = field.find('.');
                if (dotPos != string::npos) field = field.substr(dotPos + 1);
                project->fields.push_back(field);
                project->expressions.push_back(buildExpression(exprNode));
            }
        }
        if (previousPlan) project->children.push_back(move(previousPlan));
        plan = move(project);
    }
    
    currentPlan = move(plan);
}

void LogicalPlanBuilder::visitExpression(ExpressionNode* n) {
    // No-op: handled via buildExpression helper
}

// Helper to convert AST Expression to Logical Expression
unique_ptr<LogicalPlanNode> LogicalPlanBuilder::buildExpression(ASTNode* node) {
    if (!node) return nullptr;
    
    if (node->type != ASTNode::EXPRESSION) {
        return nullptr;
    }
    
    ExpressionNode* expr = static_cast<ExpressionNode*>(node);
    
    if (expr->type == "BINARY_OP") {
        auto binOp = make_unique<BinaryExpressionNode>();
        binOp->op = expr->operator_;
        binOp->left = buildExpression(expr->left.get());
        binOp->right = buildExpression(expr->right.get());
        return binOp;
    } 
    else if (expr->type == "PROPERTY_ACCESS") {
        // object.propertyName
        // object should be a VARIABLE expression
        string varName;
        if (expr->object && expr->object->type == ASTNode::EXPRESSION) {
            ExpressionNode* obj = static_cast<ExpressionNode*>(expr->object.get());
            varName = obj->value;
        }
        return make_unique<PropertyAccessNode>(varName, expr->propertyName);
    }
    else if (expr->type == "VARIABLE") {
        return make_unique<VariableReferenceNode>(expr->value);
    }
    else if (expr->type == "LITERAL" || expr->type == "VALUE") {
        return make_unique<LiteralNode>(expr->value, expr->literalType);
    }
    else if (expr->type == "FUNCTION_CALL") {
        return make_unique<VariableReferenceNode>(expr->value + "(...)");
    }
    else if (expr->type == "CONDITION") {
        return make_unique<VariableReferenceNode>(expr->value);
    }
    
    return nullptr;
}

bool LogicalPlanBuilder::isAggregateExpression(ASTNode* node) {
    if (!node || node->type != ASTNode::EXPRESSION) return false;
    ExpressionNode* expr = static_cast<ExpressionNode*>(node);
    if (expr->type == "FUNCTION_CALL") {
        string funcName = expr->value;
        for (auto & c: funcName) c = toupper(c);
        return (funcName == "COUNT" || funcName == "SUM" || funcName == "AVG" || 
                funcName == "MIN" || funcName == "MAX" || funcName == "COLLECT_LIST");
    }
    return false;
}

bool LogicalPlanBuilder::containsAggregations(const vector<unique_ptr<ASTNode>>& expressions) {
    for (auto& expr : expressions) {
        if (isAggregateExpression(expr.get())) return true;
    }
    return false;
}

vector<string> LogicalPlanBuilder::extractReturnFields(ReturnStatementNode* ret) {
    vector<string> fields;
    
    for (auto& expr : ret->expressions) {
        if (expr->type == ASTNode::EXPRESSION) {
            ExpressionNode* exprNode = static_cast<ExpressionNode*>(expr.get());
            fields.push_back(exprNode->value);
        }
    }
    
    return fields;
}
