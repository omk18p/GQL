#pragma once

// Forward decls
class QueryNode;
class SessionSetNode;
class SessionResetNode;
class SessionCloseNode;
class TransactionNode;
class ProcedureCallNode;
class CatalogStatementNode;
class MatchStatementNode;
class NodePatternNode;
class EdgePatternNode;
class ReturnStatementNode;
class WhereClauseNode;
class ExpressionNode;
class LetStatementNode;
class ForStatementNode;
class FilterStatementNode;
class OrderByStatementNode;
class InsertStatementNode;
class SetStatementNode;
class RemoveStatementNode;
class DeleteStatementNode;
class CompositeQueryNode;


class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;
    virtual void visitQuery(QueryNode* n) = 0;
    virtual void visitSessionSet(SessionSetNode* n) = 0;
    virtual void visitSessionReset(SessionResetNode* n) = 0;
    virtual void visitSessionClose(SessionCloseNode* n) = 0;
    virtual void visitTransaction(TransactionNode* n) = 0;
    virtual void visitProcedureCall(ProcedureCallNode* n) = 0;
    virtual void visitCatalogStatement(CatalogStatementNode* n) = 0;
    virtual void visitMatchStatement(MatchStatementNode* n) = 0;
    virtual void visitNodePattern(NodePatternNode* n) = 0;
    virtual void visitEdgePattern(EdgePatternNode* n) = 0;
    virtual void visitReturnStatement(ReturnStatementNode* n) = 0;
    virtual void visitWhereClause(WhereClauseNode* n) = 0;
    virtual void visitExpression(ExpressionNode* n) = 0;
    virtual void visitLetStatement(LetStatementNode* n) = 0;
    virtual void visitForStatement(ForStatementNode* n) = 0;
    virtual void visitFilterStatement(FilterStatementNode* n) = 0;
    virtual void visitOrderByStatement(OrderByStatementNode* n) = 0;
    virtual void visitInsertStatement(InsertStatementNode* n) = 0;
    virtual void visitSetStatement(SetStatementNode* n) = 0;
    virtual void visitRemoveStatement(RemoveStatementNode* n) = 0;
    virtual void visitDeleteStatement(DeleteStatementNode* n) = 0;
    virtual void visitCompositeQuery(CompositeQueryNode* n) = 0;
};


