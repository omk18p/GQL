#pragma once
#include "GQLBaseVisitor.h"
#include "ASTNodes.h"

class ASTBuilder : public GQLBaseVisitor {
    std::unique_ptr<QueryNode> root;
    MatchStatementNode* currentMatchNode = nullptr;  // Track current MATCH statement being built
    ReturnStatementNode* currentReturnNode = nullptr;  // Track current RETURN statement being built
public:
    std::unique_ptr<QueryNode> build(GQLParser::GqlProgramContext* ctx);

    antlrcpp::Any visitGqlProgram(GQLParser::GqlProgramContext* ctx) override;
    antlrcpp::Any visitProgramActivity(GQLParser::ProgramActivityContext* ctx) override;
    antlrcpp::Any visitSessionActivity(GQLParser::SessionActivityContext* ctx) override;
    antlrcpp::Any visitSessionSetCommand(GQLParser::SessionSetCommandContext* ctx) override;
    antlrcpp::Any visitSessionResetCommand(GQLParser::SessionResetCommandContext* ctx) override;
    antlrcpp::Any visitTransactionActivity(GQLParser::TransactionActivityContext* ctx) override;
    antlrcpp::Any visitStartTransactionCommand(GQLParser::StartTransactionCommandContext* ctx) override;
    
    // MATCH statement visitors
    antlrcpp::Any visitMatchStatement(GQLParser::MatchStatementContext* ctx) override;
    antlrcpp::Any visitGraphPatternBindingTable(GQLParser::GraphPatternBindingTableContext* ctx) override;
    antlrcpp::Any visitGraphPattern(GQLParser::GraphPatternContext* ctx) override;
    antlrcpp::Any visitPathPattern(GQLParser::PathPatternContext* ctx) override;
    antlrcpp::Any visitPpePathTerm(GQLParser::PpePathTermContext* ctx) override;
    antlrcpp::Any visitPpePatternUnion(GQLParser::PpePatternUnionContext* ctx) override;
    antlrcpp::Any visitPpeMultisetAlternation(GQLParser::PpeMultisetAlternationContext* ctx) override;
    antlrcpp::Any visitPathTerm(GQLParser::PathTermContext* ctx) override;
    antlrcpp::Any visitPfPathPrimary(GQLParser::PfPathPrimaryContext* ctx) override;
    antlrcpp::Any visitPfQuantifiedPathPrimary(GQLParser::PfQuantifiedPathPrimaryContext* ctx) override;
    antlrcpp::Any visitPfQuestionedPathPrimary(GQLParser::PfQuestionedPathPrimaryContext* ctx) override;
    antlrcpp::Any visitPpElementPattern(GQLParser::PpElementPatternContext* ctx) override;
    antlrcpp::Any visitPpParenthesizedPathPatternExpression(GQLParser::PpParenthesizedPathPatternExpressionContext* ctx) override;
    antlrcpp::Any visitPpSimplifiedPathPatternExpression(GQLParser::PpSimplifiedPathPatternExpressionContext* ctx) override;
    antlrcpp::Any visitElementPattern(GQLParser::ElementPatternContext* ctx) override;
    antlrcpp::Any visitFullEdgePattern(GQLParser::FullEdgePatternContext* ctx) override;
    antlrcpp::Any visitAbbreviatedEdgePattern(GQLParser::AbbreviatedEdgePatternContext* ctx) override;
    antlrcpp::Any visitLabelExpressionName(GQLParser::LabelExpressionNameContext* ctx) override;
    antlrcpp::Any visitPrimitiveResultStatement(GQLParser::PrimitiveResultStatementContext* ctx) override;
    antlrcpp::Any visitReturnItem(GQLParser::ReturnItemContext* ctx) override;
    antlrcpp::Any visitWhereClause(GQLParser::WhereClauseContext* ctx) override;
    
    // Phase 2: Primitive query statement visitors
    antlrcpp::Any visitLetVariableDefinition(GQLParser::LetVariableDefinitionContext* ctx) override;
    antlrcpp::Any visitOrderByAndPageStatement(GQLParser::OrderByAndPageStatementContext* ctx) override;
    antlrcpp::Any visitOrderByClause(GQLParser::OrderByClauseContext* ctx) override;
    antlrcpp::Any visitSortSpecification(GQLParser::SortSpecificationContext* ctx) override;
    antlrcpp::Any visitOffsetClause(GQLParser::OffsetClauseContext* ctx) override;
    antlrcpp::Any visitLimitClause(GQLParser::LimitClauseContext* ctx) override;
    
    // Phase 3: Data modifying statement visitors
    antlrcpp::Any visitLinearDataModifyingStatement(GQLParser::LinearDataModifyingStatementContext* ctx) override;
    antlrcpp::Any visitAmbientLinearDataModifyingStatement(GQLParser::AmbientLinearDataModifyingStatementContext* ctx) override;
    antlrcpp::Any visitSimpleDataAccessingStatement(GQLParser::SimpleDataAccessingStatementContext* ctx) override;
    antlrcpp::Any visitSimpleQueryStatement(GQLParser::SimpleQueryStatementContext* ctx) override;
    antlrcpp::Any visitPrimitiveDataModifyingStatement(GQLParser::PrimitiveDataModifyingStatementContext* ctx) override;
    antlrcpp::Any visitInsertGraphPattern(GQLParser::InsertGraphPatternContext* ctx) override;
    antlrcpp::Any visitInsertPathPattern(GQLParser::InsertPathPatternContext* ctx) override;
    antlrcpp::Any visitInsertNodePattern(GQLParser::InsertNodePatternContext* ctx) override;
    antlrcpp::Any visitInsertEdgePattern(GQLParser::InsertEdgePatternContext* ctx) override;
    antlrcpp::Any visitSetItem(GQLParser::SetItemContext* ctx) override;
    antlrcpp::Any visitRemoveItem(GQLParser::RemoveItemContext* ctx) override;
    
    // Phase 4: Composite query statement visitors
    antlrcpp::Any visitCompositeQueryStatement(GQLParser::CompositeQueryStatementContext* ctx) override;
    antlrcpp::Any visitCompositeQueryExpression(GQLParser::CompositeQueryExpressionContext* ctx) override;
    antlrcpp::Any visitQueryConjunction(GQLParser::QueryConjunctionContext* ctx) override;
    antlrcpp::Any visitLinearQueryStatement(GQLParser::LinearQueryStatementContext* ctx) override;
    antlrcpp::Any visitFocusedLinearQueryStatement(GQLParser::FocusedLinearQueryStatementContext* ctx) override;
    antlrcpp::Any visitAmbientLinearQueryStatement(GQLParser::AmbientLinearQueryStatementContext* ctx) override;
    
    // Additional visitors for procedure body and statements
    antlrcpp::Any visitProcedureBody(GQLParser::ProcedureBodyContext* ctx) override;
    antlrcpp::Any visitStatementBlock(GQLParser::StatementBlockContext* ctx) override;
    antlrcpp::Any visitStatement(GQLParser::StatementContext* ctx) override;
    antlrcpp::Any visitPrimitiveQueryStatement(GQLParser::PrimitiveQueryStatementContext* ctx) override;
  
    
};
