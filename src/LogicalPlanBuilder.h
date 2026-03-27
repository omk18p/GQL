#pragma once
#include "ASTVisitor.h"
#include "ASTNodes.h"
#include "LogicalPlanNodes.h"
#include <set>

class LogicalPlanBuilder : public ASTVisitor {
private:
    std::unique_ptr<LogicalPlanNode> currentPlan; // Current plan being built
    std::set<std::string> visibleVariables;       // Variables already bound in the stream
    
    // Helper: Build expression tree from AST ExpressionNode
    std::unique_ptr<LogicalPlanNode> buildExpression(ASTNode* expr);
    
    // Help: Check if an expression contains an aggregate function
    bool isAggregateExpression(ASTNode* node);
    
    // Help: Check if a list of expressions contains any aggregations
    bool containsAggregations(const std::vector<std::unique_ptr<ASTNode>>& expressions);
    
    // Helper: Extract field names from RETURN
    std::vector<std::string> extractReturnFields(ReturnStatementNode* ret);
    
public:
    // Build logical plan from AST root
    std::unique_ptr<LogicalPlanNode> build(QueryNode* astRoot);
    
    // ========== AST Visitor Methods ==========
    
    // Query root
    void visitQuery(QueryNode* n) override;
    
    // MATCH statement → NodeScan/EdgeScan + Filter + Project
    void visitMatchStatement(MatchStatementNode* n) override;
    
    // Node pattern → NodeScan
    void visitNodePattern(NodePatternNode* n) override;
    
    // Edge pattern → EdgeScan
    void visitEdgePattern(EdgePatternNode* n) override;
    
    // WHERE clause → Filter
    void visitWhereClause(WhereClauseNode* n) override;
    
    // RETURN statement → Project
    void visitReturnStatement(ReturnStatementNode* n) override;
    
    // Expression → Expression tree (for conditions)
    void visitExpression(ExpressionNode* n) override;
    
    // Other nodes (not yet implemented)
    void visitSessionSet(SessionSetNode* n) override {}
    void visitSessionReset(SessionResetNode* n) override {}
    void visitSessionClose(SessionCloseNode* n) override {}
    void visitTransaction(TransactionNode* n) override {}
    void visitProcedureCall(ProcedureCallNode* n) override {}
    void visitCatalogStatement(CatalogStatementNode* n) override {}
    void visitLetStatement(LetStatementNode* n) override {}
    void visitForStatement(ForStatementNode* n) override {}
    void visitFilterStatement(FilterStatementNode* n) override {}
    void visitOrderByStatement(OrderByStatementNode* n) override;
    void visitInsertStatement(InsertStatementNode* n) override;
    void visitSetStatement(SetStatementNode* n) override;
    void visitRemoveStatement(RemoveStatementNode* n) override;
    void visitDeleteStatement(DeleteStatementNode* n) override;
    void visitCompositeQuery(CompositeQueryNode* n) override {}
    void visitSelectStatement(SelectStatementNode* n) override {}
    void visitGroupByClause(GroupByClauseNode* n) override {}
    void visitHavingClause(HavingClauseNode* n) override {}
    void visitUseGraph(UseGraphNode* n) override {}
};

