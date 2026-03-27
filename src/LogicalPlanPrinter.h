#pragma once
#include "LogicalPlanNodes.h"
#include <iostream>

#include "LogicalPlanVisitor.h"

/**
 * LogicalPlanPrinter: Pretty-prints logical plan tree
 */
class LogicalPlanPrinter : public LogicalPlanVisitor {
private:
    int indent = 0;
    void printIndent();
    
public:
    void visitNodeScan(NodeScanNode* n) override;
    void visitEdgeScan(EdgeScanNode* n) override;
    void visitFilter(FilterNode* n) override;
    void visitProject(ProjectNode* n) override;
    void visitJoin(JoinNode* n) override;
    void visitAggregate(AggregateNode* n) override;
    void visitSort(SortNode* n) override;
    void visitLimit(LimitNode* n) override;
    void visitOffset(OffsetNode* n) override;
    void visitDistinct(DistinctNode* n) override;
    void visitUnion(UnionNode* n) override;
    void visitDeleteOp(DeleteOpNode* n) override;
    void visitInsertOp(InsertOpNode* n) override;
    void visitUpdateOp(UpdateOpNode* n) override;
    void visitBinaryExpression(BinaryExpressionNode* n) override;
    void visitPropertyAccess(PropertyAccessNode* n) override;
    void visitVariableReference(VariableReferenceNode* n) override;
    void visitLiteral(LiteralNode* n) override;
    
    // Entry point
    void print(LogicalPlanNode* plan);
};

