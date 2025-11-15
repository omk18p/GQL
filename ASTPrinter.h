#pragma once
#include "ASTVisitor.h"
#include <iostream>

class ASTPrinter : public ASTVisitor {
    int indent = 0;
    void printIndent();
public:
    void visitQuery(QueryNode* n) override;
    void visitSessionSet(SessionSetNode* n) override;
    void visitSessionReset(SessionResetNode* n) override;
    void visitSessionClose(SessionCloseNode* n) override;
    void visitTransaction(TransactionNode* n) override;
    void visitProcedureCall(ProcedureCallNode* n) override;
    void visitCatalogStatement(CatalogStatementNode* n) override;
    void visitMatchStatement(MatchStatementNode* n) override;
    void visitNodePattern(NodePatternNode* n) override;
    void visitEdgePattern(EdgePatternNode* n) override;
    void visitReturnStatement(ReturnStatementNode* n) override;
    void visitWhereClause(WhereClauseNode* n) override;
    void visitExpression(ExpressionNode* n) override;
    void visitLetStatement(LetStatementNode* n) override;
    void visitForStatement(ForStatementNode* n) override;
    void visitFilterStatement(FilterStatementNode* n) override;
    void visitOrderByStatement(OrderByStatementNode* n) override;
    void visitInsertStatement(InsertStatementNode* n) override;
    void visitSetStatement(SetStatementNode* n) override;
    void visitRemoveStatement(RemoveStatementNode* n) override;
    void visitDeleteStatement(DeleteStatementNode* n) override;
    void visitCompositeQuery(CompositeQueryNode* n) override;
};
