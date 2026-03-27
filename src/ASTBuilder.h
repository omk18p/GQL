#pragma once
#include "GQLBaseVisitor.h"
#include "ASTNodes.h"

class ASTBuilder : public GQLBaseVisitor {
    std::unique_ptr<QueryNode> root;
    MatchStatementNode* currentMatchNode = nullptr;  // Track current MATCH statement being built
    NodePatternNode* currentNodePattern = nullptr;  // Track current node pattern being built (for properties)
    ReturnStatementNode* currentReturnNode = nullptr;  // Track current RETURN statement being built
    std::string currentQuantifier;  // Track quantifier for current edge pattern
    std::string lastInsertedNodeVar; // Track the last node variable during INSERT path building
    
    // Helper methods for expression tree building
    std::unique_ptr<ExpressionNode> buildExpressionFromContext(GQLParser::BooleanValueExpressionContext* ctx);
    std::unique_ptr<ExpressionNode> buildExpressionFromValueExpression(antlr4::ParserRuleContext* ctx);
    std::unique_ptr<ExpressionNode> buildExpressionFromPrimary(antlr4::ParserRuleContext* ctx);
    
public:
    std::unique_ptr<QueryNode> build(GQLParser::GqlProgramContext* ctx);

    std::any visitGqlProgram(GQLParser::GqlProgramContext* ctx) override;
    std::any visitProgramActivity(GQLParser::ProgramActivityContext* ctx) override;
    std::any visitSessionActivity(GQLParser::SessionActivityContext* ctx) override;
    std::any visitSessionSetCommand(GQLParser::SessionSetCommandContext* ctx) override;
    std::any visitSessionResetCommand(GQLParser::SessionResetCommandContext* ctx) override;
    std::any visitTransactionActivity(GQLParser::TransactionActivityContext* ctx) override;
    std::any visitStartTransactionCommand(GQLParser::StartTransactionCommandContext* ctx) override;
    
    // MATCH statement visitors
    std::any visitMatchStatement(GQLParser::MatchStatementContext* ctx) override;
    std::any visitGraphPatternBindingTable(GQLParser::GraphPatternBindingTableContext* ctx) override;
    std::any visitGraphPattern(GQLParser::GraphPatternContext* ctx) override;
    std::any visitPathPattern(GQLParser::PathPatternContext* ctx) override;
    std::any visitPpePathTerm(GQLParser::PpePathTermContext* ctx) override;
    std::any visitPpePatternUnion(GQLParser::PpePatternUnionContext* ctx) override;
    std::any visitPpeMultisetAlternation(GQLParser::PpeMultisetAlternationContext* ctx) override;
    std::any visitPathTerm(GQLParser::PathTermContext* ctx) override;
    std::any visitPfPathPrimary(GQLParser::PfPathPrimaryContext* ctx) override;
    std::any visitPfQuantifiedPathPrimary(GQLParser::PfQuantifiedPathPrimaryContext* ctx) override;
    std::any visitPfQuestionedPathPrimary(GQLParser::PfQuestionedPathPrimaryContext* ctx) override;
    std::any visitPpElementPattern(GQLParser::PpElementPatternContext* ctx) override;
    std::any visitPpParenthesizedPathPatternExpression(GQLParser::PpParenthesizedPathPatternExpressionContext* ctx) override;
    std::any visitPpSimplifiedPathPatternExpression(GQLParser::PpSimplifiedPathPatternExpressionContext* ctx) override;
    std::any visitElementPattern(GQLParser::ElementPatternContext* ctx) override;
    std::any visitFullEdgePattern(GQLParser::FullEdgePatternContext* ctx) override;
    std::any visitAbbreviatedEdgePattern(GQLParser::AbbreviatedEdgePatternContext* ctx) override;
    std::any visitLabelExpressionName(GQLParser::LabelExpressionNameContext* ctx) override;
    std::any visitLabelExpressionNegation(GQLParser::LabelExpressionNegationContext* ctx) override;
    std::any visitLabelExpressionConjunction(GQLParser::LabelExpressionConjunctionContext* ctx) override;
    std::any visitLabelExpressionDisjunction(GQLParser::LabelExpressionDisjunctionContext* ctx) override;
    std::any visitLabelExpressionParenthesized(GQLParser::LabelExpressionParenthesizedContext* ctx) override;
    std::any visitLabelExpressionWildcard(GQLParser::LabelExpressionWildcardContext* ctx) override;
    std::any visitGraphPatternQuantifier(GQLParser::GraphPatternQuantifierContext* ctx) override;
    std::any visitPrimitiveResultStatement(GQLParser::PrimitiveResultStatementContext* ctx) override;
    std::any visitReturnItem(GQLParser::ReturnItemContext* ctx) override;
    std::any visitWhereClause(GQLParser::WhereClauseContext* ctx) override;
    
    // Phase 2: Primitive query statement visitors
    std::any visitLetVariableDefinition(GQLParser::LetVariableDefinitionContext* ctx) override;
    std::any visitOrderByAndPageStatement(GQLParser::OrderByAndPageStatementContext* ctx) override;
    std::any visitOrderByClause(GQLParser::OrderByClauseContext* ctx) override;
    std::any visitSortSpecification(GQLParser::SortSpecificationContext* ctx) override;
    std::any visitOffsetClause(GQLParser::OffsetClauseContext* ctx) override;
    std::any visitLimitClause(GQLParser::LimitClauseContext* ctx) override;
    
    // Phase 3: Data modifying statement visitors
    std::any visitLinearDataModifyingStatement(GQLParser::LinearDataModifyingStatementContext* ctx) override;
    std::any visitAmbientLinearDataModifyingStatement(GQLParser::AmbientLinearDataModifyingStatementContext* ctx) override;
    std::any visitSimpleDataAccessingStatement(GQLParser::SimpleDataAccessingStatementContext* ctx) override;
    std::any visitSimpleQueryStatement(GQLParser::SimpleQueryStatementContext* ctx) override;
    std::any visitPrimitiveDataModifyingStatement(GQLParser::PrimitiveDataModifyingStatementContext* ctx) override;
    std::any visitInsertGraphPattern(GQLParser::InsertGraphPatternContext* ctx) override;
    std::any visitInsertPathPattern(GQLParser::InsertPathPatternContext* ctx) override;
    std::any visitInsertNodePattern(GQLParser::InsertNodePatternContext* ctx) override;
    std::any visitInsertEdgePattern(GQLParser::InsertEdgePatternContext* ctx) override;
    std::any visitSetItem(GQLParser::SetItemContext* ctx) override;
    std::any visitRemoveItem(GQLParser::RemoveItemContext* ctx) override;
    
    // Phase 4: Composite query statement visitors
    std::any visitCompositeQueryStatement(GQLParser::CompositeQueryStatementContext* ctx) override;
    std::any visitCompositeQueryExpression(GQLParser::CompositeQueryExpressionContext* ctx) override;
    std::any visitQueryConjunction(GQLParser::QueryConjunctionContext* ctx) override;
    std::any visitLinearQueryStatement(GQLParser::LinearQueryStatementContext* ctx) override;
    std::any visitFocusedLinearQueryStatement(GQLParser::FocusedLinearQueryStatementContext* ctx) override;
    std::any visitAmbientLinearQueryStatement(GQLParser::AmbientLinearQueryStatementContext* ctx) override;
    
    // Phase 5: SELECT statement visitors
    std::any visitSelectStatement(GQLParser::SelectStatementContext* ctx) override;
    std::any visitSelectItem(GQLParser::SelectItemContext* ctx) override;
    std::any visitSelectStatementBody(GQLParser::SelectStatementBodyContext* ctx) override;
    std::any visitSelectGraphMatch(GQLParser::SelectGraphMatchContext* ctx) override;
    std::any visitGroupByClause(GQLParser::GroupByClauseContext* ctx) override;
    std::any visitHavingClause(GQLParser::HavingClauseContext* ctx) override;
    
    // Phase 6: Procedure call visitors
    std::any visitCallProcedureStatement(GQLParser::CallProcedureStatementContext* ctx) override;
    std::any visitProcedureCall(GQLParser::ProcedureCallContext* ctx) override;
    std::any visitNestedProcedureSpecification(GQLParser::NestedProcedureSpecificationContext* ctx) override;
    
    // Phase 7: USE Graph clause visitors
    std::any visitUseGraphClause(GQLParser::UseGraphClauseContext* ctx) override;
    
    // Phase 8: Expression parsing visitors
    std::any visitBooleanValueExpression(GQLParser::BooleanValueExpressionContext* ctx) override;
    std::any visitSearchCondition(GQLParser::SearchConditionContext* ctx) override;
    std::any visitComparisonExprAlt(GQLParser::ComparisonExprAltContext* ctx) override;
    std::any visitConjunctiveExprAlt(GQLParser::ConjunctiveExprAltContext* ctx) override;
    std::any visitDisjunctiveExprAlt(GQLParser::DisjunctiveExprAltContext* ctx) override;
    std::any visitAddSubtractExprAlt(GQLParser::AddSubtractExprAltContext* ctx) override;
    std::any visitMultDivExprAlt(GQLParser::MultDivExprAltContext* ctx) override;
    std::any visitSignedExprAlt(GQLParser::SignedExprAltContext* ctx) override;
    std::any visitNotExprAlt(GQLParser::NotExprAltContext* ctx) override;
    std::any visitPrimaryExprAlt(GQLParser::PrimaryExprAltContext* ctx) override;
    std::any visitValueFunctionExprAlt(GQLParser::ValueFunctionExprAltContext* ctx) override;
    std::any visitValueExpressionPrimary(GQLParser::ValueExpressionPrimaryContext* ctx) override;
    std::any visitBindingVariableReference(GQLParser::BindingVariableReferenceContext* ctx) override;
    std::any visitPropertyName(GQLParser::PropertyNameContext* ctx) override;
    std::any visitValueFunction(GQLParser::ValueFunctionContext* ctx) override;
    std::any visitNumericValueFunction(GQLParser::NumericValueFunctionContext* ctx) override;
    std::any visitAggregateFunction(GQLParser::AggregateFunctionContext* ctx) override;
    std::any visitDatetimeValueFunction(GQLParser::DatetimeValueFunctionContext* ctx) override;
    std::any visitCharacterOrByteStringFunction(GQLParser::CharacterOrByteStringFunctionContext* ctx) override;
    std::any visitListValueFunction(GQLParser::ListValueFunctionContext* ctx) override;
    std::any visitDurationValueFunction(GQLParser::DurationValueFunctionContext* ctx) override;
    std::any visitDatetimeSubtraction(GQLParser::DatetimeSubtractionContext* ctx) override;
    std::any visitElementPropertySpecification(GQLParser::ElementPropertySpecificationContext* ctx) override;
    std::any visitPropertyKeyValuePairList(GQLParser::PropertyKeyValuePairListContext* ctx) override;
    std::any visitPropertyKeyValuePair(GQLParser::PropertyKeyValuePairContext* ctx) override;
    
    // Additional visitors for procedure body and statements
    std::any visitProcedureBody(GQLParser::ProcedureBodyContext* ctx) override;
    std::any visitStatementBlock(GQLParser::StatementBlockContext* ctx) override;
    std::any visitStatement(GQLParser::StatementContext* ctx) override;
    std::any visitPrimitiveQueryStatement(GQLParser::PrimitiveQueryStatementContext* ctx) override;
    std::any visitLinearCatalogModifyingStatement(GQLParser::LinearCatalogModifyingStatementContext* ctx) override;
    std::any visitPrimitiveCatalogModifyingStatement(GQLParser::PrimitiveCatalogModifyingStatementContext* ctx) override;
  
    
};
