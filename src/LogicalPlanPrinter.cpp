#include "LogicalPlanPrinter.h"
#include <iostream>

void LogicalPlanPrinter::printIndent() {
    for (int i = 0; i < indent; i++) {
        std::cout << "  ";
    }
}

void LogicalPlanPrinter::print(LogicalPlanNode* plan) {
    if (!plan) {
        std::cout << "(No logical plan)\n";
        return;
    }
    plan->accept(this);
}

void LogicalPlanPrinter::visitNodeScan(NodeScanNode* n) {
    printIndent();
    std::cout << "NodeScan(" << n->label;
    if (!n->variable.empty()) {
        std::cout << ", var=" << n->variable;
    }
    std::cout << ")\n";
    
    // Visit children
    indent++;
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitEdgeScan(EdgeScanNode* n) {
    printIndent();
    std::cout << "EdgeScan(" << n->label;
    if (!n->variable.empty()) {
        std::cout << ", var=" << n->variable;
    }
    std::cout << ", dir=" << n->direction << ")\n";
    
    indent++;
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitFilter(FilterNode* n) {
    printIndent();
    std::cout << "Filter\n";
    
    indent++;
    
    // Print the condition expression tree if it exists
    if (n->condition) {
        n->condition->accept(this);
    }
    
    // Print child nodes
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitProject(ProjectNode* n) {
    printIndent();
    std::cout << "Project([";
    for (size_t i = 0; i < n->fields.size(); i++) {
        std::cout << n->fields[i];
        if (i < n->fields.size() - 1) std::cout << ", ";
    }
    std::cout << "])\n";
    
    indent++;
    // Print expressions if they exist
    if (!n->expressions.empty()) {
        printIndent();
        std::cout << "EXPRESSIONS:\n";
        indent++;
        for (auto& expr : n->expressions) {
            if (expr) expr->accept(this);
        }
        indent--;
    }
    
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitJoin(JoinNode* n) {
    printIndent();
    std::cout << "Join(" << n->joinType << ")\n";
    
    indent++;
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitAggregate(AggregateNode* n) {
    printIndent();
    std::cout << "Aggregate\n";
    
    indent++;
    
    // Print grouping expressions
    if (!n->groupingExpressions.empty()) {
        printIndent();
        std::cout << "GROUP BY:\n";
        indent++;
        for (size_t i = 0; i < n->groupingExpressions.size(); i++) {
            n->groupingExpressions[i]->accept(this);
            if (!n->groupingAliases[i].empty()) {
                printIndent();
                std::cout << "  AS " << n->groupingAliases[i] << "\n";
            }
        }
        indent--;
    }
    
    // Print aggregate items
    if (!n->aggregateItems.empty()) {
        printIndent();
        std::cout << "AGGREGATES:\n";
        indent++;
        for (auto& item : n->aggregateItems) {
            printIndent();
            std::cout << item.functionName << "(" << (item.distinct ? "DISTINCT " : "") << "\n";
            indent++;
            if (item.expression) {
                item.expression->accept(this);
            }
            indent--;
            printIndent();
            std::cout << ")\n";
            if (!item.alias.empty()) {
                printIndent();
                std::cout << "  AS " << item.alias << "\n";
            }
        }
        indent--;
    }
    
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitSort(SortNode* n) {
    printIndent();
    std::cout << "Sort([";
    for (size_t i = 0; i < n->sortFields.size(); i++) {
        std::cout << n->sortFields[i].field << " " << n->sortFields[i].direction;
        if (i < n->sortFields.size() - 1) std::cout << ", ";
    }
    std::cout << "])\n";
    
    indent++;
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitLimit(LimitNode* n) {
    printIndent();
    std::cout << "Limit(" << n->limit << ")\n";
    
    indent++;
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitOffset(OffsetNode* n) {
    printIndent();
    std::cout << "Offset(" << n->offset << ")\n";
    
    indent++;
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitDistinct(DistinctNode* n) {
    printIndent();
    std::cout << "Distinct\n";
    
    indent++;
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitUnion(UnionNode* n) {
    printIndent();
    std::cout << "Union(" << (n->distinct ? "DISTINCT" : "ALL") << ")\n";
    
    indent++;
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitDeleteOp(DeleteOpNode* n) {
    printIndent();
    std::cout << "DeleteOp([";
    for (size_t i = 0; i < n->variables.size(); i++) {
        std::cout << n->variables[i];
        if (i < n->variables.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
    if (n->detach) std::cout << ", DETACH";
    std::cout << ")\n";
    
    indent++;
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitInsertOp(InsertOpNode* n) {
    printIndent();
    std::cout << "InsertOp(" << n->patterns.size() << " patterns)\n";
    
    indent++;
    for (auto& pattern : n->patterns) {
        pattern->accept(this);
    }
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

void LogicalPlanPrinter::visitUpdateOp(UpdateOpNode* n) {
    printIndent();
    std::cout << "UpdateOp(" << n->items.size() << " items)\n";
    
    indent++;
    for (auto& item : n->items) {
        printIndent();
        std::cout << "- ";
        switch (item.type) {
            case UpdateOpNode::SET_PROPERTY: std::cout << "SET_PROPERTY"; break;
            case UpdateOpNode::SET_LABEL:    std::cout << "SET_LABEL";    break;
            case UpdateOpNode::REMOVE_PROPERTY: std::cout << "REMOVE_PROPERTY"; break;
            case UpdateOpNode::REMOVE_LABEL:    std::cout << "REMOVE_LABEL";    break;
            case UpdateOpNode::SET_MAP:      std::cout << "SET_MAP";      break;
        }
        std::cout << " [" << item.variable << " / " << item.key << "]\n";
        if (item.value) {
            indent++;
            item.value->accept(this);
            indent--;
        }
    }
    for (auto& child : n->children) {
        child->accept(this);
    }
    indent--;
}

// ========== EXPRESSION PRINTING ==========

void LogicalPlanPrinter::visitBinaryExpression(BinaryExpressionNode* n) {
    printIndent();
    std::cout << "BinaryExpression(" << n->op << ")\n";
    indent++;
    if (n->left) n->left->accept(this);
    if (n->right) n->right->accept(this);
    indent--;
}

void LogicalPlanPrinter::visitPropertyAccess(PropertyAccessNode* n) {
    printIndent();
    std::cout << "PropertyAccess(" << n->variable << "." << n->property << ")\n";
}

void LogicalPlanPrinter::visitVariableReference(VariableReferenceNode* n) {
    printIndent();
    std::cout << "VariableReference(" << n->variable << ")\n";
}

void LogicalPlanPrinter::visitLiteral(LiteralNode* n) {
    printIndent();
    std::cout << "Literal(" << n->value << " : " << n->literalType << ")\n";
}

