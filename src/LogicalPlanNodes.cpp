#include "LogicalPlanNodes.h"
#include "LogicalPlanPrinter.h"

// ========== LogicalPlanNode accept() implementations ==========

void NodeScanNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitNodeScan(this);
}

void EdgeScanNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitEdgeScan(this);
}

void FilterNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitFilter(this);
}

void ProjectNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitProject(this);
}

void JoinNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitJoin(this);
}

void AggregateNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitAggregate(this);
}

void SortNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitSort(this);
}

void LimitNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitLimit(this);
}

void OffsetNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitOffset(this);
}

void DistinctNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitDistinct(this);
}

void UnionNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitUnion(this);
}

void DeleteOpNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitDeleteOp(this);
}

void InsertOpNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitInsertOp(this);
}

void UpdateOpNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitUpdateOp(this);
}

void BinaryExpressionNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitBinaryExpression(this);
}

void PropertyAccessNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitPropertyAccess(this);
}

void VariableReferenceNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitVariableReference(this);
}

void LiteralNode::accept(LogicalPlanVisitor* visitor) {
    visitor->visitLiteral(this);
}
