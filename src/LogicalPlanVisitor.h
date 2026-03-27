#pragma once
#include "LogicalPlanNodes.h"

/**
 * LogicalPlanVisitor: Visitor interface for logical plan nodes
 */
class LogicalPlanVisitor {
public:
    virtual ~LogicalPlanVisitor() = default;
    virtual void visitNodeScan(NodeScanNode* n) = 0;
    virtual void visitEdgeScan(EdgeScanNode* n) = 0;
    virtual void visitFilter(FilterNode* n) = 0;
    virtual void visitProject(ProjectNode* n) = 0;
    virtual void visitJoin(JoinNode* n) = 0;
    virtual void visitAggregate(AggregateNode* n) = 0;
    virtual void visitSort(SortNode* n) = 0;
    virtual void visitLimit(LimitNode* n) = 0;
    virtual void visitOffset(OffsetNode* n) = 0;
    virtual void visitDistinct(DistinctNode* n) = 0;
    virtual void visitUnion(UnionNode* n) = 0;
    virtual void visitDeleteOp(DeleteOpNode* n) = 0;
    virtual void visitInsertOp(InsertOpNode* n) = 0;
    virtual void visitUpdateOp(UpdateOpNode* n) = 0;
    virtual void visitBinaryExpression(BinaryExpressionNode* n) = 0;
    virtual void visitPropertyAccess(PropertyAccessNode* n) = 0;
    virtual void visitVariableReference(VariableReferenceNode* n) = 0;
    virtual void visitLiteral(LiteralNode* n) = 0;
};
