
// Generated from grammar/GQL.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "GQLParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by GQLParser.
 */
class  GQLListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterGqlProgram(GQLParser::GqlProgramContext *ctx) = 0;
  virtual void exitGqlProgram(GQLParser::GqlProgramContext *ctx) = 0;

  virtual void enterProgramActivity(GQLParser::ProgramActivityContext *ctx) = 0;
  virtual void exitProgramActivity(GQLParser::ProgramActivityContext *ctx) = 0;

  virtual void enterSessionActivity(GQLParser::SessionActivityContext *ctx) = 0;
  virtual void exitSessionActivity(GQLParser::SessionActivityContext *ctx) = 0;

  virtual void enterTransactionActivity(GQLParser::TransactionActivityContext *ctx) = 0;
  virtual void exitTransactionActivity(GQLParser::TransactionActivityContext *ctx) = 0;

  virtual void enterSessionSetCommand(GQLParser::SessionSetCommandContext *ctx) = 0;
  virtual void exitSessionSetCommand(GQLParser::SessionSetCommandContext *ctx) = 0;

  virtual void enterSessionSetSchemaClause(GQLParser::SessionSetSchemaClauseContext *ctx) = 0;
  virtual void exitSessionSetSchemaClause(GQLParser::SessionSetSchemaClauseContext *ctx) = 0;

  virtual void enterSessionSetGraphClause(GQLParser::SessionSetGraphClauseContext *ctx) = 0;
  virtual void exitSessionSetGraphClause(GQLParser::SessionSetGraphClauseContext *ctx) = 0;

  virtual void enterSessionSetTimeZoneClause(GQLParser::SessionSetTimeZoneClauseContext *ctx) = 0;
  virtual void exitSessionSetTimeZoneClause(GQLParser::SessionSetTimeZoneClauseContext *ctx) = 0;

  virtual void enterSessionSetParameterClause(GQLParser::SessionSetParameterClauseContext *ctx) = 0;
  virtual void exitSessionSetParameterClause(GQLParser::SessionSetParameterClauseContext *ctx) = 0;

  virtual void enterSessionResetCommand(GQLParser::SessionResetCommandContext *ctx) = 0;
  virtual void exitSessionResetCommand(GQLParser::SessionResetCommandContext *ctx) = 0;

  virtual void enterStartTransactionCommand(GQLParser::StartTransactionCommandContext *ctx) = 0;
  virtual void exitStartTransactionCommand(GQLParser::StartTransactionCommandContext *ctx) = 0;

  virtual void enterTransactionAccessMode(GQLParser::TransactionAccessModeContext *ctx) = 0;
  virtual void exitTransactionAccessMode(GQLParser::TransactionAccessModeContext *ctx) = 0;

  virtual void enterNestedProcedureSpecification(GQLParser::NestedProcedureSpecificationContext *ctx) = 0;
  virtual void exitNestedProcedureSpecification(GQLParser::NestedProcedureSpecificationContext *ctx) = 0;

  virtual void enterProcedureBody(GQLParser::ProcedureBodyContext *ctx) = 0;
  virtual void exitProcedureBody(GQLParser::ProcedureBodyContext *ctx) = 0;

  virtual void enterStatementBlock(GQLParser::StatementBlockContext *ctx) = 0;
  virtual void exitStatementBlock(GQLParser::StatementBlockContext *ctx) = 0;

  virtual void enterStatement(GQLParser::StatementContext *ctx) = 0;
  virtual void exitStatement(GQLParser::StatementContext *ctx) = 0;

  virtual void enterNextStatement(GQLParser::NextStatementContext *ctx) = 0;
  virtual void exitNextStatement(GQLParser::NextStatementContext *ctx) = 0;

  virtual void enterBindingVariableDefinition(GQLParser::BindingVariableDefinitionContext *ctx) = 0;
  virtual void exitBindingVariableDefinition(GQLParser::BindingVariableDefinitionContext *ctx) = 0;

  virtual void enterGraphExpression(GQLParser::GraphExpressionContext *ctx) = 0;
  virtual void exitGraphExpression(GQLParser::GraphExpressionContext *ctx) = 0;

  virtual void enterBindingTableExpression(GQLParser::BindingTableExpressionContext *ctx) = 0;
  virtual void exitBindingTableExpression(GQLParser::BindingTableExpressionContext *ctx) = 0;

  virtual void enterLinearCatalogModifyingStatement(GQLParser::LinearCatalogModifyingStatementContext *ctx) = 0;
  virtual void exitLinearCatalogModifyingStatement(GQLParser::LinearCatalogModifyingStatementContext *ctx) = 0;

  virtual void enterPrimitiveCatalogModifyingStatement(GQLParser::PrimitiveCatalogModifyingStatementContext *ctx) = 0;
  virtual void exitPrimitiveCatalogModifyingStatement(GQLParser::PrimitiveCatalogModifyingStatementContext *ctx) = 0;

  virtual void enterOpenGraphType(GQLParser::OpenGraphTypeContext *ctx) = 0;
  virtual void exitOpenGraphType(GQLParser::OpenGraphTypeContext *ctx) = 0;

  virtual void enterOfGraphType(GQLParser::OfGraphTypeContext *ctx) = 0;
  virtual void exitOfGraphType(GQLParser::OfGraphTypeContext *ctx) = 0;

  virtual void enterGraphTypeSource(GQLParser::GraphTypeSourceContext *ctx) = 0;
  virtual void exitGraphTypeSource(GQLParser::GraphTypeSourceContext *ctx) = 0;

  virtual void enterGraphSource(GQLParser::GraphSourceContext *ctx) = 0;
  virtual void exitGraphSource(GQLParser::GraphSourceContext *ctx) = 0;

  virtual void enterLinearDataModifyingStatement(GQLParser::LinearDataModifyingStatementContext *ctx) = 0;
  virtual void exitLinearDataModifyingStatement(GQLParser::LinearDataModifyingStatementContext *ctx) = 0;

  virtual void enterFocusedLinearDataModifyingStatement(GQLParser::FocusedLinearDataModifyingStatementContext *ctx) = 0;
  virtual void exitFocusedLinearDataModifyingStatement(GQLParser::FocusedLinearDataModifyingStatementContext *ctx) = 0;

  virtual void enterAmbientLinearDataModifyingStatement(GQLParser::AmbientLinearDataModifyingStatementContext *ctx) = 0;
  virtual void exitAmbientLinearDataModifyingStatement(GQLParser::AmbientLinearDataModifyingStatementContext *ctx) = 0;

  virtual void enterSimpleDataAccessingStatement(GQLParser::SimpleDataAccessingStatementContext *ctx) = 0;
  virtual void exitSimpleDataAccessingStatement(GQLParser::SimpleDataAccessingStatementContext *ctx) = 0;

  virtual void enterPrimitiveDataModifyingStatement(GQLParser::PrimitiveDataModifyingStatementContext *ctx) = 0;
  virtual void exitPrimitiveDataModifyingStatement(GQLParser::PrimitiveDataModifyingStatementContext *ctx) = 0;

  virtual void enterSetItem(GQLParser::SetItemContext *ctx) = 0;
  virtual void exitSetItem(GQLParser::SetItemContext *ctx) = 0;

  virtual void enterRemoveItem(GQLParser::RemoveItemContext *ctx) = 0;
  virtual void exitRemoveItem(GQLParser::RemoveItemContext *ctx) = 0;

  virtual void enterCompositeQueryStatement(GQLParser::CompositeQueryStatementContext *ctx) = 0;
  virtual void exitCompositeQueryStatement(GQLParser::CompositeQueryStatementContext *ctx) = 0;

  virtual void enterCompositeQueryExpression(GQLParser::CompositeQueryExpressionContext *ctx) = 0;
  virtual void exitCompositeQueryExpression(GQLParser::CompositeQueryExpressionContext *ctx) = 0;

  virtual void enterQueryConjunction(GQLParser::QueryConjunctionContext *ctx) = 0;
  virtual void exitQueryConjunction(GQLParser::QueryConjunctionContext *ctx) = 0;

  virtual void enterLinearQueryStatement(GQLParser::LinearQueryStatementContext *ctx) = 0;
  virtual void exitLinearQueryStatement(GQLParser::LinearQueryStatementContext *ctx) = 0;

  virtual void enterFocusedLinearQueryStatement(GQLParser::FocusedLinearQueryStatementContext *ctx) = 0;
  virtual void exitFocusedLinearQueryStatement(GQLParser::FocusedLinearQueryStatementContext *ctx) = 0;

  virtual void enterAmbientLinearQueryStatement(GQLParser::AmbientLinearQueryStatementContext *ctx) = 0;
  virtual void exitAmbientLinearQueryStatement(GQLParser::AmbientLinearQueryStatementContext *ctx) = 0;

  virtual void enterNestedQuerySpecification(GQLParser::NestedQuerySpecificationContext *ctx) = 0;
  virtual void exitNestedQuerySpecification(GQLParser::NestedQuerySpecificationContext *ctx) = 0;

  virtual void enterSimpleQueryStatement(GQLParser::SimpleQueryStatementContext *ctx) = 0;
  virtual void exitSimpleQueryStatement(GQLParser::SimpleQueryStatementContext *ctx) = 0;

  virtual void enterPrimitiveQueryStatement(GQLParser::PrimitiveQueryStatementContext *ctx) = 0;
  virtual void exitPrimitiveQueryStatement(GQLParser::PrimitiveQueryStatementContext *ctx) = 0;

  virtual void enterMatchStatement(GQLParser::MatchStatementContext *ctx) = 0;
  virtual void exitMatchStatement(GQLParser::MatchStatementContext *ctx) = 0;

  virtual void enterLetVariableDefinition(GQLParser::LetVariableDefinitionContext *ctx) = 0;
  virtual void exitLetVariableDefinition(GQLParser::LetVariableDefinitionContext *ctx) = 0;

  virtual void enterOrderByAndPageStatement(GQLParser::OrderByAndPageStatementContext *ctx) = 0;
  virtual void exitOrderByAndPageStatement(GQLParser::OrderByAndPageStatementContext *ctx) = 0;

  virtual void enterPrimitiveResultStatement(GQLParser::PrimitiveResultStatementContext *ctx) = 0;
  virtual void exitPrimitiveResultStatement(GQLParser::PrimitiveResultStatementContext *ctx) = 0;

  virtual void enterReturnItem(GQLParser::ReturnItemContext *ctx) = 0;
  virtual void exitReturnItem(GQLParser::ReturnItemContext *ctx) = 0;

  virtual void enterSelectStatement(GQLParser::SelectStatementContext *ctx) = 0;
  virtual void exitSelectStatement(GQLParser::SelectStatementContext *ctx) = 0;

  virtual void enterSelectItem(GQLParser::SelectItemContext *ctx) = 0;
  virtual void exitSelectItem(GQLParser::SelectItemContext *ctx) = 0;

  virtual void enterHavingClause(GQLParser::HavingClauseContext *ctx) = 0;
  virtual void exitHavingClause(GQLParser::HavingClauseContext *ctx) = 0;

  virtual void enterSelectStatementBody(GQLParser::SelectStatementBodyContext *ctx) = 0;
  virtual void exitSelectStatementBody(GQLParser::SelectStatementBodyContext *ctx) = 0;

  virtual void enterSelectGraphMatch(GQLParser::SelectGraphMatchContext *ctx) = 0;
  virtual void exitSelectGraphMatch(GQLParser::SelectGraphMatchContext *ctx) = 0;

  virtual void enterSelectQuerySpecification(GQLParser::SelectQuerySpecificationContext *ctx) = 0;
  virtual void exitSelectQuerySpecification(GQLParser::SelectQuerySpecificationContext *ctx) = 0;

  virtual void enterCallProcedureStatement(GQLParser::CallProcedureStatementContext *ctx) = 0;
  virtual void exitCallProcedureStatement(GQLParser::CallProcedureStatementContext *ctx) = 0;

  virtual void enterProcedureCall(GQLParser::ProcedureCallContext *ctx) = 0;
  virtual void exitProcedureCall(GQLParser::ProcedureCallContext *ctx) = 0;

  virtual void enterAtSchemaClause(GQLParser::AtSchemaClauseContext *ctx) = 0;
  virtual void exitAtSchemaClause(GQLParser::AtSchemaClauseContext *ctx) = 0;

  virtual void enterUseGraphClause(GQLParser::UseGraphClauseContext *ctx) = 0;
  virtual void exitUseGraphClause(GQLParser::UseGraphClauseContext *ctx) = 0;

  virtual void enterGraphPatternBindingTable(GQLParser::GraphPatternBindingTableContext *ctx) = 0;
  virtual void exitGraphPatternBindingTable(GQLParser::GraphPatternBindingTableContext *ctx) = 0;

  virtual void enterGraphPattern(GQLParser::GraphPatternContext *ctx) = 0;
  virtual void exitGraphPattern(GQLParser::GraphPatternContext *ctx) = 0;

  virtual void enterMatchMode(GQLParser::MatchModeContext *ctx) = 0;
  virtual void exitMatchMode(GQLParser::MatchModeContext *ctx) = 0;

  virtual void enterPathPattern(GQLParser::PathPatternContext *ctx) = 0;
  virtual void exitPathPattern(GQLParser::PathPatternContext *ctx) = 0;

  virtual void enterKeepClause(GQLParser::KeepClauseContext *ctx) = 0;
  virtual void exitKeepClause(GQLParser::KeepClauseContext *ctx) = 0;

  virtual void enterInsertGraphPattern(GQLParser::InsertGraphPatternContext *ctx) = 0;
  virtual void exitInsertGraphPattern(GQLParser::InsertGraphPatternContext *ctx) = 0;

  virtual void enterInsertPathPattern(GQLParser::InsertPathPatternContext *ctx) = 0;
  virtual void exitInsertPathPattern(GQLParser::InsertPathPatternContext *ctx) = 0;

  virtual void enterInsertNodePattern(GQLParser::InsertNodePatternContext *ctx) = 0;
  virtual void exitInsertNodePattern(GQLParser::InsertNodePatternContext *ctx) = 0;

  virtual void enterInsertEdgePattern(GQLParser::InsertEdgePatternContext *ctx) = 0;
  virtual void exitInsertEdgePattern(GQLParser::InsertEdgePatternContext *ctx) = 0;

  virtual void enterInsertElementPatternFiller(GQLParser::InsertElementPatternFillerContext *ctx) = 0;
  virtual void exitInsertElementPatternFiller(GQLParser::InsertElementPatternFillerContext *ctx) = 0;

  virtual void enterLabelAndPropertySetSpecification(GQLParser::LabelAndPropertySetSpecificationContext *ctx) = 0;
  virtual void exitLabelAndPropertySetSpecification(GQLParser::LabelAndPropertySetSpecificationContext *ctx) = 0;

  virtual void enterPathPatternPrefix(GQLParser::PathPatternPrefixContext *ctx) = 0;
  virtual void exitPathPatternPrefix(GQLParser::PathPatternPrefixContext *ctx) = 0;

  virtual void enterPathModePrefix(GQLParser::PathModePrefixContext *ctx) = 0;
  virtual void exitPathModePrefix(GQLParser::PathModePrefixContext *ctx) = 0;

  virtual void enterPathSearchPrefix(GQLParser::PathSearchPrefixContext *ctx) = 0;
  virtual void exitPathSearchPrefix(GQLParser::PathSearchPrefixContext *ctx) = 0;

  virtual void enterShortestPathSearch(GQLParser::ShortestPathSearchContext *ctx) = 0;
  virtual void exitShortestPathSearch(GQLParser::ShortestPathSearchContext *ctx) = 0;

  virtual void enterPpePathTerm(GQLParser::PpePathTermContext *ctx) = 0;
  virtual void exitPpePathTerm(GQLParser::PpePathTermContext *ctx) = 0;

  virtual void enterPpeMultisetAlternation(GQLParser::PpeMultisetAlternationContext *ctx) = 0;
  virtual void exitPpeMultisetAlternation(GQLParser::PpeMultisetAlternationContext *ctx) = 0;

  virtual void enterPpePatternUnion(GQLParser::PpePatternUnionContext *ctx) = 0;
  virtual void exitPpePatternUnion(GQLParser::PpePatternUnionContext *ctx) = 0;

  virtual void enterPathTerm(GQLParser::PathTermContext *ctx) = 0;
  virtual void exitPathTerm(GQLParser::PathTermContext *ctx) = 0;

  virtual void enterPfPathPrimary(GQLParser::PfPathPrimaryContext *ctx) = 0;
  virtual void exitPfPathPrimary(GQLParser::PfPathPrimaryContext *ctx) = 0;

  virtual void enterPfQuantifiedPathPrimary(GQLParser::PfQuantifiedPathPrimaryContext *ctx) = 0;
  virtual void exitPfQuantifiedPathPrimary(GQLParser::PfQuantifiedPathPrimaryContext *ctx) = 0;

  virtual void enterPfQuestionedPathPrimary(GQLParser::PfQuestionedPathPrimaryContext *ctx) = 0;
  virtual void exitPfQuestionedPathPrimary(GQLParser::PfQuestionedPathPrimaryContext *ctx) = 0;

  virtual void enterPpElementPattern(GQLParser::PpElementPatternContext *ctx) = 0;
  virtual void exitPpElementPattern(GQLParser::PpElementPatternContext *ctx) = 0;

  virtual void enterPpParenthesizedPathPatternExpression(GQLParser::PpParenthesizedPathPatternExpressionContext *ctx) = 0;
  virtual void exitPpParenthesizedPathPatternExpression(GQLParser::PpParenthesizedPathPatternExpressionContext *ctx) = 0;

  virtual void enterPpSimplifiedPathPatternExpression(GQLParser::PpSimplifiedPathPatternExpressionContext *ctx) = 0;
  virtual void exitPpSimplifiedPathPatternExpression(GQLParser::PpSimplifiedPathPatternExpressionContext *ctx) = 0;

  virtual void enterElementPattern(GQLParser::ElementPatternContext *ctx) = 0;
  virtual void exitElementPattern(GQLParser::ElementPatternContext *ctx) = 0;

  virtual void enterElementPatternFiller(GQLParser::ElementPatternFillerContext *ctx) = 0;
  virtual void exitElementPatternFiller(GQLParser::ElementPatternFillerContext *ctx) = 0;

  virtual void enterElementVariableDeclaration(GQLParser::ElementVariableDeclarationContext *ctx) = 0;
  virtual void exitElementVariableDeclaration(GQLParser::ElementVariableDeclarationContext *ctx) = 0;

  virtual void enterIsLabelExpression(GQLParser::IsLabelExpressionContext *ctx) = 0;
  virtual void exitIsLabelExpression(GQLParser::IsLabelExpressionContext *ctx) = 0;

  virtual void enterIsOrColon(GQLParser::IsOrColonContext *ctx) = 0;
  virtual void exitIsOrColon(GQLParser::IsOrColonContext *ctx) = 0;

  virtual void enterElementPatternPredicate(GQLParser::ElementPatternPredicateContext *ctx) = 0;
  virtual void exitElementPatternPredicate(GQLParser::ElementPatternPredicateContext *ctx) = 0;

  virtual void enterElementPropertySpecification(GQLParser::ElementPropertySpecificationContext *ctx) = 0;
  virtual void exitElementPropertySpecification(GQLParser::ElementPropertySpecificationContext *ctx) = 0;

  virtual void enterPropertyKeyValuePairList(GQLParser::PropertyKeyValuePairListContext *ctx) = 0;
  virtual void exitPropertyKeyValuePairList(GQLParser::PropertyKeyValuePairListContext *ctx) = 0;

  virtual void enterPropertyKeyValuePair(GQLParser::PropertyKeyValuePairContext *ctx) = 0;
  virtual void exitPropertyKeyValuePair(GQLParser::PropertyKeyValuePairContext *ctx) = 0;

  virtual void enterFullEdgePattern(GQLParser::FullEdgePatternContext *ctx) = 0;
  virtual void exitFullEdgePattern(GQLParser::FullEdgePatternContext *ctx) = 0;

  virtual void enterAbbreviatedEdgePattern(GQLParser::AbbreviatedEdgePatternContext *ctx) = 0;
  virtual void exitAbbreviatedEdgePattern(GQLParser::AbbreviatedEdgePatternContext *ctx) = 0;

  virtual void enterParenthesizedPathPatternExpression(GQLParser::ParenthesizedPathPatternExpressionContext *ctx) = 0;
  virtual void exitParenthesizedPathPatternExpression(GQLParser::ParenthesizedPathPatternExpressionContext *ctx) = 0;

  virtual void enterLabelExpressionNegation(GQLParser::LabelExpressionNegationContext *ctx) = 0;
  virtual void exitLabelExpressionNegation(GQLParser::LabelExpressionNegationContext *ctx) = 0;

  virtual void enterLabelExpressionDisjunction(GQLParser::LabelExpressionDisjunctionContext *ctx) = 0;
  virtual void exitLabelExpressionDisjunction(GQLParser::LabelExpressionDisjunctionContext *ctx) = 0;

  virtual void enterLabelExpressionParenthesized(GQLParser::LabelExpressionParenthesizedContext *ctx) = 0;
  virtual void exitLabelExpressionParenthesized(GQLParser::LabelExpressionParenthesizedContext *ctx) = 0;

  virtual void enterLabelExpressionWildcard(GQLParser::LabelExpressionWildcardContext *ctx) = 0;
  virtual void exitLabelExpressionWildcard(GQLParser::LabelExpressionWildcardContext *ctx) = 0;

  virtual void enterLabelExpressionConjunction(GQLParser::LabelExpressionConjunctionContext *ctx) = 0;
  virtual void exitLabelExpressionConjunction(GQLParser::LabelExpressionConjunctionContext *ctx) = 0;

  virtual void enterLabelExpressionName(GQLParser::LabelExpressionNameContext *ctx) = 0;
  virtual void exitLabelExpressionName(GQLParser::LabelExpressionNameContext *ctx) = 0;

  virtual void enterGraphPatternQuantifier(GQLParser::GraphPatternQuantifierContext *ctx) = 0;
  virtual void exitGraphPatternQuantifier(GQLParser::GraphPatternQuantifierContext *ctx) = 0;

  virtual void enterSimplifiedPathPatternExpression(GQLParser::SimplifiedPathPatternExpressionContext *ctx) = 0;
  virtual void exitSimplifiedPathPatternExpression(GQLParser::SimplifiedPathPatternExpressionContext *ctx) = 0;

  virtual void enterSimplifiedContents(GQLParser::SimplifiedContentsContext *ctx) = 0;
  virtual void exitSimplifiedContents(GQLParser::SimplifiedContentsContext *ctx) = 0;

  virtual void enterSimplifiedFactorLowLabel(GQLParser::SimplifiedFactorLowLabelContext *ctx) = 0;
  virtual void exitSimplifiedFactorLowLabel(GQLParser::SimplifiedFactorLowLabelContext *ctx) = 0;

  virtual void enterSimplifiedConcatenationLabel(GQLParser::SimplifiedConcatenationLabelContext *ctx) = 0;
  virtual void exitSimplifiedConcatenationLabel(GQLParser::SimplifiedConcatenationLabelContext *ctx) = 0;

  virtual void enterSimplifiedConjunctionLabel(GQLParser::SimplifiedConjunctionLabelContext *ctx) = 0;
  virtual void exitSimplifiedConjunctionLabel(GQLParser::SimplifiedConjunctionLabelContext *ctx) = 0;

  virtual void enterSimplifiedFactorHighLabel(GQLParser::SimplifiedFactorHighLabelContext *ctx) = 0;
  virtual void exitSimplifiedFactorHighLabel(GQLParser::SimplifiedFactorHighLabelContext *ctx) = 0;

  virtual void enterSimplifiedFactorHigh(GQLParser::SimplifiedFactorHighContext *ctx) = 0;
  virtual void exitSimplifiedFactorHigh(GQLParser::SimplifiedFactorHighContext *ctx) = 0;

  virtual void enterSimplifiedTertiary(GQLParser::SimplifiedTertiaryContext *ctx) = 0;
  virtual void exitSimplifiedTertiary(GQLParser::SimplifiedTertiaryContext *ctx) = 0;

  virtual void enterSimplifiedSecondary(GQLParser::SimplifiedSecondaryContext *ctx) = 0;
  virtual void exitSimplifiedSecondary(GQLParser::SimplifiedSecondaryContext *ctx) = 0;

  virtual void enterSimplifiedPrimary(GQLParser::SimplifiedPrimaryContext *ctx) = 0;
  virtual void exitSimplifiedPrimary(GQLParser::SimplifiedPrimaryContext *ctx) = 0;

  virtual void enterWhereClause(GQLParser::WhereClauseContext *ctx) = 0;
  virtual void exitWhereClause(GQLParser::WhereClauseContext *ctx) = 0;

  virtual void enterYieldClause(GQLParser::YieldClauseContext *ctx) = 0;
  virtual void exitYieldClause(GQLParser::YieldClauseContext *ctx) = 0;

  virtual void enterYieldItem(GQLParser::YieldItemContext *ctx) = 0;
  virtual void exitYieldItem(GQLParser::YieldItemContext *ctx) = 0;

  virtual void enterGroupByClause(GQLParser::GroupByClauseContext *ctx) = 0;
  virtual void exitGroupByClause(GQLParser::GroupByClauseContext *ctx) = 0;

  virtual void enterOrderByClause(GQLParser::OrderByClauseContext *ctx) = 0;
  virtual void exitOrderByClause(GQLParser::OrderByClauseContext *ctx) = 0;

  virtual void enterSortSpecification(GQLParser::SortSpecificationContext *ctx) = 0;
  virtual void exitSortSpecification(GQLParser::SortSpecificationContext *ctx) = 0;

  virtual void enterLimitClause(GQLParser::LimitClauseContext *ctx) = 0;
  virtual void exitLimitClause(GQLParser::LimitClauseContext *ctx) = 0;

  virtual void enterOffsetClause(GQLParser::OffsetClauseContext *ctx) = 0;
  virtual void exitOffsetClause(GQLParser::OffsetClauseContext *ctx) = 0;

  virtual void enterSchemaReference(GQLParser::SchemaReferenceContext *ctx) = 0;
  virtual void exitSchemaReference(GQLParser::SchemaReferenceContext *ctx) = 0;

  virtual void enterAbsoluteCatalogSchemaReference(GQLParser::AbsoluteCatalogSchemaReferenceContext *ctx) = 0;
  virtual void exitAbsoluteCatalogSchemaReference(GQLParser::AbsoluteCatalogSchemaReferenceContext *ctx) = 0;

  virtual void enterCatalogSchemaParentAndName(GQLParser::CatalogSchemaParentAndNameContext *ctx) = 0;
  virtual void exitCatalogSchemaParentAndName(GQLParser::CatalogSchemaParentAndNameContext *ctx) = 0;

  virtual void enterRelativeCatalogSchemaReference(GQLParser::RelativeCatalogSchemaReferenceContext *ctx) = 0;
  virtual void exitRelativeCatalogSchemaReference(GQLParser::RelativeCatalogSchemaReferenceContext *ctx) = 0;

  virtual void enterAbsoluteDirectoryPath(GQLParser::AbsoluteDirectoryPathContext *ctx) = 0;
  virtual void exitAbsoluteDirectoryPath(GQLParser::AbsoluteDirectoryPathContext *ctx) = 0;

  virtual void enterRelativeDirectoryPath(GQLParser::RelativeDirectoryPathContext *ctx) = 0;
  virtual void exitRelativeDirectoryPath(GQLParser::RelativeDirectoryPathContext *ctx) = 0;

  virtual void enterSimpleDirectoryPath(GQLParser::SimpleDirectoryPathContext *ctx) = 0;
  virtual void exitSimpleDirectoryPath(GQLParser::SimpleDirectoryPathContext *ctx) = 0;

  virtual void enterGraphReference(GQLParser::GraphReferenceContext *ctx) = 0;
  virtual void exitGraphReference(GQLParser::GraphReferenceContext *ctx) = 0;

  virtual void enterCatalogGraphParentAndName(GQLParser::CatalogGraphParentAndNameContext *ctx) = 0;
  virtual void exitCatalogGraphParentAndName(GQLParser::CatalogGraphParentAndNameContext *ctx) = 0;

  virtual void enterGraphTypeReference(GQLParser::GraphTypeReferenceContext *ctx) = 0;
  virtual void exitGraphTypeReference(GQLParser::GraphTypeReferenceContext *ctx) = 0;

  virtual void enterCatalogGraphTypeParentAndName(GQLParser::CatalogGraphTypeParentAndNameContext *ctx) = 0;
  virtual void exitCatalogGraphTypeParentAndName(GQLParser::CatalogGraphTypeParentAndNameContext *ctx) = 0;

  virtual void enterBindingTableReference(GQLParser::BindingTableReferenceContext *ctx) = 0;
  virtual void exitBindingTableReference(GQLParser::BindingTableReferenceContext *ctx) = 0;

  virtual void enterProcedureReference(GQLParser::ProcedureReferenceContext *ctx) = 0;
  virtual void exitProcedureReference(GQLParser::ProcedureReferenceContext *ctx) = 0;

  virtual void enterCatalogObjectParentReference(GQLParser::CatalogObjectParentReferenceContext *ctx) = 0;
  virtual void exitCatalogObjectParentReference(GQLParser::CatalogObjectParentReferenceContext *ctx) = 0;

  virtual void enterNestedGraphTypeSpecification(GQLParser::NestedGraphTypeSpecificationContext *ctx) = 0;
  virtual void exitNestedGraphTypeSpecification(GQLParser::NestedGraphTypeSpecificationContext *ctx) = 0;

  virtual void enterElementTypeSpecification(GQLParser::ElementTypeSpecificationContext *ctx) = 0;
  virtual void exitElementTypeSpecification(GQLParser::ElementTypeSpecificationContext *ctx) = 0;

  virtual void enterNodeTypeSpecification(GQLParser::NodeTypeSpecificationContext *ctx) = 0;
  virtual void exitNodeTypeSpecification(GQLParser::NodeTypeSpecificationContext *ctx) = 0;

  virtual void enterNodeTypePhraseFiller(GQLParser::NodeTypePhraseFillerContext *ctx) = 0;
  virtual void exitNodeTypePhraseFiller(GQLParser::NodeTypePhraseFillerContext *ctx) = 0;

  virtual void enterNodeTypeFiller(GQLParser::NodeTypeFillerContext *ctx) = 0;
  virtual void exitNodeTypeFiller(GQLParser::NodeTypeFillerContext *ctx) = 0;

  virtual void enterNodeTypeImpliedContent(GQLParser::NodeTypeImpliedContentContext *ctx) = 0;
  virtual void exitNodeTypeImpliedContent(GQLParser::NodeTypeImpliedContentContext *ctx) = 0;

  virtual void enterEdgeTypeSpecification(GQLParser::EdgeTypeSpecificationContext *ctx) = 0;
  virtual void exitEdgeTypeSpecification(GQLParser::EdgeTypeSpecificationContext *ctx) = 0;

  virtual void enterEdgeTypePhraseFiller(GQLParser::EdgeTypePhraseFillerContext *ctx) = 0;
  virtual void exitEdgeTypePhraseFiller(GQLParser::EdgeTypePhraseFillerContext *ctx) = 0;

  virtual void enterEdgeTypeFiller(GQLParser::EdgeTypeFillerContext *ctx) = 0;
  virtual void exitEdgeTypeFiller(GQLParser::EdgeTypeFillerContext *ctx) = 0;

  virtual void enterEdgeTypeImpliedContent(GQLParser::EdgeTypeImpliedContentContext *ctx) = 0;
  virtual void exitEdgeTypeImpliedContent(GQLParser::EdgeTypeImpliedContentContext *ctx) = 0;

  virtual void enterEdgeTypePatternDirected(GQLParser::EdgeTypePatternDirectedContext *ctx) = 0;
  virtual void exitEdgeTypePatternDirected(GQLParser::EdgeTypePatternDirectedContext *ctx) = 0;

  virtual void enterEdgeTypePatternUndirected(GQLParser::EdgeTypePatternUndirectedContext *ctx) = 0;
  virtual void exitEdgeTypePatternUndirected(GQLParser::EdgeTypePatternUndirectedContext *ctx) = 0;

  virtual void enterArcTypePointingRight(GQLParser::ArcTypePointingRightContext *ctx) = 0;
  virtual void exitArcTypePointingRight(GQLParser::ArcTypePointingRightContext *ctx) = 0;

  virtual void enterArcTypePointingLeft(GQLParser::ArcTypePointingLeftContext *ctx) = 0;
  virtual void exitArcTypePointingLeft(GQLParser::ArcTypePointingLeftContext *ctx) = 0;

  virtual void enterArcTypeUndirected(GQLParser::ArcTypeUndirectedContext *ctx) = 0;
  virtual void exitArcTypeUndirected(GQLParser::ArcTypeUndirectedContext *ctx) = 0;

  virtual void enterSourceNodeTypeReference(GQLParser::SourceNodeTypeReferenceContext *ctx) = 0;
  virtual void exitSourceNodeTypeReference(GQLParser::SourceNodeTypeReferenceContext *ctx) = 0;

  virtual void enterDestinationNodeTypeReference(GQLParser::DestinationNodeTypeReferenceContext *ctx) = 0;
  virtual void exitDestinationNodeTypeReference(GQLParser::DestinationNodeTypeReferenceContext *ctx) = 0;

  virtual void enterEdgeKind(GQLParser::EdgeKindContext *ctx) = 0;
  virtual void exitEdgeKind(GQLParser::EdgeKindContext *ctx) = 0;

  virtual void enterEndpointPairPhrase(GQLParser::EndpointPairPhraseContext *ctx) = 0;
  virtual void exitEndpointPairPhrase(GQLParser::EndpointPairPhraseContext *ctx) = 0;

  virtual void enterEndpointPair(GQLParser::EndpointPairContext *ctx) = 0;
  virtual void exitEndpointPair(GQLParser::EndpointPairContext *ctx) = 0;

  virtual void enterLabelSetPhrase(GQLParser::LabelSetPhraseContext *ctx) = 0;
  virtual void exitLabelSetPhrase(GQLParser::LabelSetPhraseContext *ctx) = 0;

  virtual void enterLabelSetSpecification(GQLParser::LabelSetSpecificationContext *ctx) = 0;
  virtual void exitLabelSetSpecification(GQLParser::LabelSetSpecificationContext *ctx) = 0;

  virtual void enterPropertyTypesSpecification(GQLParser::PropertyTypesSpecificationContext *ctx) = 0;
  virtual void exitPropertyTypesSpecification(GQLParser::PropertyTypesSpecificationContext *ctx) = 0;

  virtual void enterPropertyValueType(GQLParser::PropertyValueTypeContext *ctx) = 0;
  virtual void exitPropertyValueType(GQLParser::PropertyValueTypeContext *ctx) = 0;

  virtual void enterBindingTableType(GQLParser::BindingTableTypeContext *ctx) = 0;
  virtual void exitBindingTableType(GQLParser::BindingTableTypeContext *ctx) = 0;

  virtual void enterDynamicPropertyValueTypeLabel(GQLParser::DynamicPropertyValueTypeLabelContext *ctx) = 0;
  virtual void exitDynamicPropertyValueTypeLabel(GQLParser::DynamicPropertyValueTypeLabelContext *ctx) = 0;

  virtual void enterClosedDynamicUnionTypeAtl1(GQLParser::ClosedDynamicUnionTypeAtl1Context *ctx) = 0;
  virtual void exitClosedDynamicUnionTypeAtl1(GQLParser::ClosedDynamicUnionTypeAtl1Context *ctx) = 0;

  virtual void enterClosedDynamicUnionTypeAtl2(GQLParser::ClosedDynamicUnionTypeAtl2Context *ctx) = 0;
  virtual void exitClosedDynamicUnionTypeAtl2(GQLParser::ClosedDynamicUnionTypeAtl2Context *ctx) = 0;

  virtual void enterPathValueTypeLabel(GQLParser::PathValueTypeLabelContext *ctx) = 0;
  virtual void exitPathValueTypeLabel(GQLParser::PathValueTypeLabelContext *ctx) = 0;

  virtual void enterListValueTypeAlt3(GQLParser::ListValueTypeAlt3Context *ctx) = 0;
  virtual void exitListValueTypeAlt3(GQLParser::ListValueTypeAlt3Context *ctx) = 0;

  virtual void enterListValueTypeAlt2(GQLParser::ListValueTypeAlt2Context *ctx) = 0;
  virtual void exitListValueTypeAlt2(GQLParser::ListValueTypeAlt2Context *ctx) = 0;

  virtual void enterListValueTypeAlt1(GQLParser::ListValueTypeAlt1Context *ctx) = 0;
  virtual void exitListValueTypeAlt1(GQLParser::ListValueTypeAlt1Context *ctx) = 0;

  virtual void enterPredefinedTypeLabel(GQLParser::PredefinedTypeLabelContext *ctx) = 0;
  virtual void exitPredefinedTypeLabel(GQLParser::PredefinedTypeLabelContext *ctx) = 0;

  virtual void enterRecordTypeLabel(GQLParser::RecordTypeLabelContext *ctx) = 0;
  virtual void exitRecordTypeLabel(GQLParser::RecordTypeLabelContext *ctx) = 0;

  virtual void enterOpenDynamicUnionTypeLabel(GQLParser::OpenDynamicUnionTypeLabelContext *ctx) = 0;
  virtual void exitOpenDynamicUnionTypeLabel(GQLParser::OpenDynamicUnionTypeLabelContext *ctx) = 0;

  virtual void enterTyped(GQLParser::TypedContext *ctx) = 0;
  virtual void exitTyped(GQLParser::TypedContext *ctx) = 0;

  virtual void enterPredefinedType(GQLParser::PredefinedTypeContext *ctx) = 0;
  virtual void exitPredefinedType(GQLParser::PredefinedTypeContext *ctx) = 0;

  virtual void enterBooleanType(GQLParser::BooleanTypeContext *ctx) = 0;
  virtual void exitBooleanType(GQLParser::BooleanTypeContext *ctx) = 0;

  virtual void enterCharacterStringType(GQLParser::CharacterStringTypeContext *ctx) = 0;
  virtual void exitCharacterStringType(GQLParser::CharacterStringTypeContext *ctx) = 0;

  virtual void enterByteStringType(GQLParser::ByteStringTypeContext *ctx) = 0;
  virtual void exitByteStringType(GQLParser::ByteStringTypeContext *ctx) = 0;

  virtual void enterMinLength(GQLParser::MinLengthContext *ctx) = 0;
  virtual void exitMinLength(GQLParser::MinLengthContext *ctx) = 0;

  virtual void enterMaxLength(GQLParser::MaxLengthContext *ctx) = 0;
  virtual void exitMaxLength(GQLParser::MaxLengthContext *ctx) = 0;

  virtual void enterFixedLength(GQLParser::FixedLengthContext *ctx) = 0;
  virtual void exitFixedLength(GQLParser::FixedLengthContext *ctx) = 0;

  virtual void enterNumericType(GQLParser::NumericTypeContext *ctx) = 0;
  virtual void exitNumericType(GQLParser::NumericTypeContext *ctx) = 0;

  virtual void enterExactNumericType(GQLParser::ExactNumericTypeContext *ctx) = 0;
  virtual void exitExactNumericType(GQLParser::ExactNumericTypeContext *ctx) = 0;

  virtual void enterBinaryExactNumericType(GQLParser::BinaryExactNumericTypeContext *ctx) = 0;
  virtual void exitBinaryExactNumericType(GQLParser::BinaryExactNumericTypeContext *ctx) = 0;

  virtual void enterSignedBinaryExactNumericType(GQLParser::SignedBinaryExactNumericTypeContext *ctx) = 0;
  virtual void exitSignedBinaryExactNumericType(GQLParser::SignedBinaryExactNumericTypeContext *ctx) = 0;

  virtual void enterUnsignedBinaryExactNumericType(GQLParser::UnsignedBinaryExactNumericTypeContext *ctx) = 0;
  virtual void exitUnsignedBinaryExactNumericType(GQLParser::UnsignedBinaryExactNumericTypeContext *ctx) = 0;

  virtual void enterVerboseBinaryExactNumericType(GQLParser::VerboseBinaryExactNumericTypeContext *ctx) = 0;
  virtual void exitVerboseBinaryExactNumericType(GQLParser::VerboseBinaryExactNumericTypeContext *ctx) = 0;

  virtual void enterDecimalExactNumericType(GQLParser::DecimalExactNumericTypeContext *ctx) = 0;
  virtual void exitDecimalExactNumericType(GQLParser::DecimalExactNumericTypeContext *ctx) = 0;

  virtual void enterPrecision(GQLParser::PrecisionContext *ctx) = 0;
  virtual void exitPrecision(GQLParser::PrecisionContext *ctx) = 0;

  virtual void enterScale(GQLParser::ScaleContext *ctx) = 0;
  virtual void exitScale(GQLParser::ScaleContext *ctx) = 0;

  virtual void enterApproximateNumericType(GQLParser::ApproximateNumericTypeContext *ctx) = 0;
  virtual void exitApproximateNumericType(GQLParser::ApproximateNumericTypeContext *ctx) = 0;

  virtual void enterTemporalType(GQLParser::TemporalTypeContext *ctx) = 0;
  virtual void exitTemporalType(GQLParser::TemporalTypeContext *ctx) = 0;

  virtual void enterTemporalInstantType(GQLParser::TemporalInstantTypeContext *ctx) = 0;
  virtual void exitTemporalInstantType(GQLParser::TemporalInstantTypeContext *ctx) = 0;

  virtual void enterDatetimeType(GQLParser::DatetimeTypeContext *ctx) = 0;
  virtual void exitDatetimeType(GQLParser::DatetimeTypeContext *ctx) = 0;

  virtual void enterLocaldatetimeType(GQLParser::LocaldatetimeTypeContext *ctx) = 0;
  virtual void exitLocaldatetimeType(GQLParser::LocaldatetimeTypeContext *ctx) = 0;

  virtual void enterDateType(GQLParser::DateTypeContext *ctx) = 0;
  virtual void exitDateType(GQLParser::DateTypeContext *ctx) = 0;

  virtual void enterTimeType(GQLParser::TimeTypeContext *ctx) = 0;
  virtual void exitTimeType(GQLParser::TimeTypeContext *ctx) = 0;

  virtual void enterLocaltimeType(GQLParser::LocaltimeTypeContext *ctx) = 0;
  virtual void exitLocaltimeType(GQLParser::LocaltimeTypeContext *ctx) = 0;

  virtual void enterTemporalDurationType(GQLParser::TemporalDurationTypeContext *ctx) = 0;
  virtual void exitTemporalDurationType(GQLParser::TemporalDurationTypeContext *ctx) = 0;

  virtual void enterReferenceValueType(GQLParser::ReferenceValueTypeContext *ctx) = 0;
  virtual void exitReferenceValueType(GQLParser::ReferenceValueTypeContext *ctx) = 0;

  virtual void enterImmaterialValueType(GQLParser::ImmaterialValueTypeContext *ctx) = 0;
  virtual void exitImmaterialValueType(GQLParser::ImmaterialValueTypeContext *ctx) = 0;

  virtual void enterGraphReferenceValueType(GQLParser::GraphReferenceValueTypeContext *ctx) = 0;
  virtual void exitGraphReferenceValueType(GQLParser::GraphReferenceValueTypeContext *ctx) = 0;

  virtual void enterBindingTableReferenceValueType(GQLParser::BindingTableReferenceValueTypeContext *ctx) = 0;
  virtual void exitBindingTableReferenceValueType(GQLParser::BindingTableReferenceValueTypeContext *ctx) = 0;

  virtual void enterNodeReferenceValueType(GQLParser::NodeReferenceValueTypeContext *ctx) = 0;
  virtual void exitNodeReferenceValueType(GQLParser::NodeReferenceValueTypeContext *ctx) = 0;

  virtual void enterEdgeReferenceValueType(GQLParser::EdgeReferenceValueTypeContext *ctx) = 0;
  virtual void exitEdgeReferenceValueType(GQLParser::EdgeReferenceValueTypeContext *ctx) = 0;

  virtual void enterPathValueType(GQLParser::PathValueTypeContext *ctx) = 0;
  virtual void exitPathValueType(GQLParser::PathValueTypeContext *ctx) = 0;

  virtual void enterListValueTypeName(GQLParser::ListValueTypeNameContext *ctx) = 0;
  virtual void exitListValueTypeName(GQLParser::ListValueTypeNameContext *ctx) = 0;

  virtual void enterRecordType(GQLParser::RecordTypeContext *ctx) = 0;
  virtual void exitRecordType(GQLParser::RecordTypeContext *ctx) = 0;

  virtual void enterFieldTypesSpecification(GQLParser::FieldTypesSpecificationContext *ctx) = 0;
  virtual void exitFieldTypesSpecification(GQLParser::FieldTypesSpecificationContext *ctx) = 0;

  virtual void enterNotNull(GQLParser::NotNullContext *ctx) = 0;
  virtual void exitNotNull(GQLParser::NotNullContext *ctx) = 0;

  virtual void enterSearchCondition(GQLParser::SearchConditionContext *ctx) = 0;
  virtual void exitSearchCondition(GQLParser::SearchConditionContext *ctx) = 0;

  virtual void enterPredicate(GQLParser::PredicateContext *ctx) = 0;
  virtual void exitPredicate(GQLParser::PredicateContext *ctx) = 0;

  virtual void enterCompOp(GQLParser::CompOpContext *ctx) = 0;
  virtual void exitCompOp(GQLParser::CompOpContext *ctx) = 0;

  virtual void enterConjunctiveExprAlt(GQLParser::ConjunctiveExprAltContext *ctx) = 0;
  virtual void exitConjunctiveExprAlt(GQLParser::ConjunctiveExprAltContext *ctx) = 0;

  virtual void enterPropertyGraphExprAlt(GQLParser::PropertyGraphExprAltContext *ctx) = 0;
  virtual void exitPropertyGraphExprAlt(GQLParser::PropertyGraphExprAltContext *ctx) = 0;

  virtual void enterMultDivExprAlt(GQLParser::MultDivExprAltContext *ctx) = 0;
  virtual void exitMultDivExprAlt(GQLParser::MultDivExprAltContext *ctx) = 0;

  virtual void enterBindingTableExprAlt(GQLParser::BindingTableExprAltContext *ctx) = 0;
  virtual void exitBindingTableExprAlt(GQLParser::BindingTableExprAltContext *ctx) = 0;

  virtual void enterInExprAlt(GQLParser::InExprAltContext *ctx) = 0;
  virtual void exitInExprAlt(GQLParser::InExprAltContext *ctx) = 0;

  virtual void enterSignedExprAlt(GQLParser::SignedExprAltContext *ctx) = 0;
  virtual void exitSignedExprAlt(GQLParser::SignedExprAltContext *ctx) = 0;

  virtual void enterIsNotExprAlt(GQLParser::IsNotExprAltContext *ctx) = 0;
  virtual void exitIsNotExprAlt(GQLParser::IsNotExprAltContext *ctx) = 0;

  virtual void enterNormalizedPredicateExprAlt(GQLParser::NormalizedPredicateExprAltContext *ctx) = 0;
  virtual void exitNormalizedPredicateExprAlt(GQLParser::NormalizedPredicateExprAltContext *ctx) = 0;

  virtual void enterNotExprAlt(GQLParser::NotExprAltContext *ctx) = 0;
  virtual void exitNotExprAlt(GQLParser::NotExprAltContext *ctx) = 0;

  virtual void enterValueFunctionExprAlt(GQLParser::ValueFunctionExprAltContext *ctx) = 0;
  virtual void exitValueFunctionExprAlt(GQLParser::ValueFunctionExprAltContext *ctx) = 0;

  virtual void enterConcatenationExprAlt(GQLParser::ConcatenationExprAltContext *ctx) = 0;
  virtual void exitConcatenationExprAlt(GQLParser::ConcatenationExprAltContext *ctx) = 0;

  virtual void enterDisjunctiveExprAlt(GQLParser::DisjunctiveExprAltContext *ctx) = 0;
  virtual void exitDisjunctiveExprAlt(GQLParser::DisjunctiveExprAltContext *ctx) = 0;

  virtual void enterComparisonExprAlt(GQLParser::ComparisonExprAltContext *ctx) = 0;
  virtual void exitComparisonExprAlt(GQLParser::ComparisonExprAltContext *ctx) = 0;

  virtual void enterPrimaryExprAlt(GQLParser::PrimaryExprAltContext *ctx) = 0;
  virtual void exitPrimaryExprAlt(GQLParser::PrimaryExprAltContext *ctx) = 0;

  virtual void enterAddSubtractExprAlt(GQLParser::AddSubtractExprAltContext *ctx) = 0;
  virtual void exitAddSubtractExprAlt(GQLParser::AddSubtractExprAltContext *ctx) = 0;

  virtual void enterPredicateExprAlt(GQLParser::PredicateExprAltContext *ctx) = 0;
  virtual void exitPredicateExprAlt(GQLParser::PredicateExprAltContext *ctx) = 0;

  virtual void enterValueFunction(GQLParser::ValueFunctionContext *ctx) = 0;
  virtual void exitValueFunction(GQLParser::ValueFunctionContext *ctx) = 0;

  virtual void enterBooleanValueExpression(GQLParser::BooleanValueExpressionContext *ctx) = 0;
  virtual void exitBooleanValueExpression(GQLParser::BooleanValueExpressionContext *ctx) = 0;

  virtual void enterCharacterOrByteStringFunction(GQLParser::CharacterOrByteStringFunctionContext *ctx) = 0;
  virtual void exitCharacterOrByteStringFunction(GQLParser::CharacterOrByteStringFunctionContext *ctx) = 0;

  virtual void enterAggregatingValueExpression(GQLParser::AggregatingValueExpressionContext *ctx) = 0;
  virtual void exitAggregatingValueExpression(GQLParser::AggregatingValueExpressionContext *ctx) = 0;

  virtual void enterValueExpressionPrimary(GQLParser::ValueExpressionPrimaryContext *ctx) = 0;
  virtual void exitValueExpressionPrimary(GQLParser::ValueExpressionPrimaryContext *ctx) = 0;

  virtual void enterParenthesizedValueExpression(GQLParser::ParenthesizedValueExpressionContext *ctx) = 0;
  virtual void exitParenthesizedValueExpression(GQLParser::ParenthesizedValueExpressionContext *ctx) = 0;

  virtual void enterNonParenthesizedValueExpressionPrimarySpecialCase(GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext *ctx) = 0;
  virtual void exitNonParenthesizedValueExpressionPrimarySpecialCase(GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext *ctx) = 0;

  virtual void enterUnsignedValueSpecification(GQLParser::UnsignedValueSpecificationContext *ctx) = 0;
  virtual void exitUnsignedValueSpecification(GQLParser::UnsignedValueSpecificationContext *ctx) = 0;

  virtual void enterNonNegativeIntegerSpecification(GQLParser::NonNegativeIntegerSpecificationContext *ctx) = 0;
  virtual void exitNonNegativeIntegerSpecification(GQLParser::NonNegativeIntegerSpecificationContext *ctx) = 0;

  virtual void enterCaseExpression(GQLParser::CaseExpressionContext *ctx) = 0;
  virtual void exitCaseExpression(GQLParser::CaseExpressionContext *ctx) = 0;

  virtual void enterSimpleWhenClause(GQLParser::SimpleWhenClauseContext *ctx) = 0;
  virtual void exitSimpleWhenClause(GQLParser::SimpleWhenClauseContext *ctx) = 0;

  virtual void enterSearchedWhenClause(GQLParser::SearchedWhenClauseContext *ctx) = 0;
  virtual void exitSearchedWhenClause(GQLParser::SearchedWhenClauseContext *ctx) = 0;

  virtual void enterElseClause(GQLParser::ElseClauseContext *ctx) = 0;
  virtual void exitElseClause(GQLParser::ElseClauseContext *ctx) = 0;

  virtual void enterCaseOperand(GQLParser::CaseOperandContext *ctx) = 0;
  virtual void exitCaseOperand(GQLParser::CaseOperandContext *ctx) = 0;

  virtual void enterWhenOperand(GQLParser::WhenOperandContext *ctx) = 0;
  virtual void exitWhenOperand(GQLParser::WhenOperandContext *ctx) = 0;

  virtual void enterResult(GQLParser::ResultContext *ctx) = 0;
  virtual void exitResult(GQLParser::ResultContext *ctx) = 0;

  virtual void enterAggregateFunction(GQLParser::AggregateFunctionContext *ctx) = 0;
  virtual void exitAggregateFunction(GQLParser::AggregateFunctionContext *ctx) = 0;

  virtual void enterSetQuantifier(GQLParser::SetQuantifierContext *ctx) = 0;
  virtual void exitSetQuantifier(GQLParser::SetQuantifierContext *ctx) = 0;

  virtual void enterBindingVariableReference(GQLParser::BindingVariableReferenceContext *ctx) = 0;
  virtual void exitBindingVariableReference(GQLParser::BindingVariableReferenceContext *ctx) = 0;

  virtual void enterElementVariableReference(GQLParser::ElementVariableReferenceContext *ctx) = 0;
  virtual void exitElementVariableReference(GQLParser::ElementVariableReferenceContext *ctx) = 0;

  virtual void enterPathValueExpression(GQLParser::PathValueExpressionContext *ctx) = 0;
  virtual void exitPathValueExpression(GQLParser::PathValueExpressionContext *ctx) = 0;

  virtual void enterPathValueConstructor(GQLParser::PathValueConstructorContext *ctx) = 0;
  virtual void exitPathValueConstructor(GQLParser::PathValueConstructorContext *ctx) = 0;

  virtual void enterListValueExpression(GQLParser::ListValueExpressionContext *ctx) = 0;
  virtual void exitListValueExpression(GQLParser::ListValueExpressionContext *ctx) = 0;

  virtual void enterListValueFunction(GQLParser::ListValueFunctionContext *ctx) = 0;
  virtual void exitListValueFunction(GQLParser::ListValueFunctionContext *ctx) = 0;

  virtual void enterListValueConstructor(GQLParser::ListValueConstructorContext *ctx) = 0;
  virtual void exitListValueConstructor(GQLParser::ListValueConstructorContext *ctx) = 0;

  virtual void enterRecordConstructor(GQLParser::RecordConstructorContext *ctx) = 0;
  virtual void exitRecordConstructor(GQLParser::RecordConstructorContext *ctx) = 0;

  virtual void enterTruthValue(GQLParser::TruthValueContext *ctx) = 0;
  virtual void exitTruthValue(GQLParser::TruthValueContext *ctx) = 0;

  virtual void enterNumericValueExpression(GQLParser::NumericValueExpressionContext *ctx) = 0;
  virtual void exitNumericValueExpression(GQLParser::NumericValueExpressionContext *ctx) = 0;

  virtual void enterNumericValueFunction(GQLParser::NumericValueFunctionContext *ctx) = 0;
  virtual void exitNumericValueFunction(GQLParser::NumericValueFunctionContext *ctx) = 0;

  virtual void enterCharacterStringValueExpression(GQLParser::CharacterStringValueExpressionContext *ctx) = 0;
  virtual void exitCharacterStringValueExpression(GQLParser::CharacterStringValueExpressionContext *ctx) = 0;

  virtual void enterByteStringValueExpression(GQLParser::ByteStringValueExpressionContext *ctx) = 0;
  virtual void exitByteStringValueExpression(GQLParser::ByteStringValueExpressionContext *ctx) = 0;

  virtual void enterTrimOperands(GQLParser::TrimOperandsContext *ctx) = 0;
  virtual void exitTrimOperands(GQLParser::TrimOperandsContext *ctx) = 0;

  virtual void enterStringLength(GQLParser::StringLengthContext *ctx) = 0;
  virtual void exitStringLength(GQLParser::StringLengthContext *ctx) = 0;

  virtual void enterDatetimeValueExpression(GQLParser::DatetimeValueExpressionContext *ctx) = 0;
  virtual void exitDatetimeValueExpression(GQLParser::DatetimeValueExpressionContext *ctx) = 0;

  virtual void enterDatetimeValueFunction(GQLParser::DatetimeValueFunctionContext *ctx) = 0;
  virtual void exitDatetimeValueFunction(GQLParser::DatetimeValueFunctionContext *ctx) = 0;

  virtual void enterDurationValueExpression(GQLParser::DurationValueExpressionContext *ctx) = 0;
  virtual void exitDurationValueExpression(GQLParser::DurationValueExpressionContext *ctx) = 0;

  virtual void enterDatetimeSubtraction(GQLParser::DatetimeSubtractionContext *ctx) = 0;
  virtual void exitDatetimeSubtraction(GQLParser::DatetimeSubtractionContext *ctx) = 0;

  virtual void enterDurationValueFunction(GQLParser::DurationValueFunctionContext *ctx) = 0;
  virtual void exitDurationValueFunction(GQLParser::DurationValueFunctionContext *ctx) = 0;

  virtual void enterObjectName(GQLParser::ObjectNameContext *ctx) = 0;
  virtual void exitObjectName(GQLParser::ObjectNameContext *ctx) = 0;

  virtual void enterObjectNameOrBindingVariable(GQLParser::ObjectNameOrBindingVariableContext *ctx) = 0;
  virtual void exitObjectNameOrBindingVariable(GQLParser::ObjectNameOrBindingVariableContext *ctx) = 0;

  virtual void enterDirectoryName(GQLParser::DirectoryNameContext *ctx) = 0;
  virtual void exitDirectoryName(GQLParser::DirectoryNameContext *ctx) = 0;

  virtual void enterSchemaName(GQLParser::SchemaNameContext *ctx) = 0;
  virtual void exitSchemaName(GQLParser::SchemaNameContext *ctx) = 0;

  virtual void enterGraphName(GQLParser::GraphNameContext *ctx) = 0;
  virtual void exitGraphName(GQLParser::GraphNameContext *ctx) = 0;

  virtual void enterDelimitedGraphName(GQLParser::DelimitedGraphNameContext *ctx) = 0;
  virtual void exitDelimitedGraphName(GQLParser::DelimitedGraphNameContext *ctx) = 0;

  virtual void enterGraphTypeName(GQLParser::GraphTypeNameContext *ctx) = 0;
  virtual void exitGraphTypeName(GQLParser::GraphTypeNameContext *ctx) = 0;

  virtual void enterNodeTypeName(GQLParser::NodeTypeNameContext *ctx) = 0;
  virtual void exitNodeTypeName(GQLParser::NodeTypeNameContext *ctx) = 0;

  virtual void enterEdgeTypeName(GQLParser::EdgeTypeNameContext *ctx) = 0;
  virtual void exitEdgeTypeName(GQLParser::EdgeTypeNameContext *ctx) = 0;

  virtual void enterBindingTableName(GQLParser::BindingTableNameContext *ctx) = 0;
  virtual void exitBindingTableName(GQLParser::BindingTableNameContext *ctx) = 0;

  virtual void enterDelimitedBindingTableName(GQLParser::DelimitedBindingTableNameContext *ctx) = 0;
  virtual void exitDelimitedBindingTableName(GQLParser::DelimitedBindingTableNameContext *ctx) = 0;

  virtual void enterProcedureName(GQLParser::ProcedureNameContext *ctx) = 0;
  virtual void exitProcedureName(GQLParser::ProcedureNameContext *ctx) = 0;

  virtual void enterLabelName(GQLParser::LabelNameContext *ctx) = 0;
  virtual void exitLabelName(GQLParser::LabelNameContext *ctx) = 0;

  virtual void enterPropertyName(GQLParser::PropertyNameContext *ctx) = 0;
  virtual void exitPropertyName(GQLParser::PropertyNameContext *ctx) = 0;

  virtual void enterFieldName(GQLParser::FieldNameContext *ctx) = 0;
  virtual void exitFieldName(GQLParser::FieldNameContext *ctx) = 0;

  virtual void enterElementVariable(GQLParser::ElementVariableContext *ctx) = 0;
  virtual void exitElementVariable(GQLParser::ElementVariableContext *ctx) = 0;

  virtual void enterPathVariable(GQLParser::PathVariableContext *ctx) = 0;
  virtual void exitPathVariable(GQLParser::PathVariableContext *ctx) = 0;

  virtual void enterSubpathVariable(GQLParser::SubpathVariableContext *ctx) = 0;
  virtual void exitSubpathVariable(GQLParser::SubpathVariableContext *ctx) = 0;

  virtual void enterBindingVariable(GQLParser::BindingVariableContext *ctx) = 0;
  virtual void exitBindingVariable(GQLParser::BindingVariableContext *ctx) = 0;

  virtual void enterUnsignedLiteral(GQLParser::UnsignedLiteralContext *ctx) = 0;
  virtual void exitUnsignedLiteral(GQLParser::UnsignedLiteralContext *ctx) = 0;

  virtual void enterGeneralLiteral(GQLParser::GeneralLiteralContext *ctx) = 0;
  virtual void exitGeneralLiteral(GQLParser::GeneralLiteralContext *ctx) = 0;

  virtual void enterTemporalLiteral(GQLParser::TemporalLiteralContext *ctx) = 0;
  virtual void exitTemporalLiteral(GQLParser::TemporalLiteralContext *ctx) = 0;

  virtual void enterListLiteral(GQLParser::ListLiteralContext *ctx) = 0;
  virtual void exitListLiteral(GQLParser::ListLiteralContext *ctx) = 0;

  virtual void enterRecordLiteral(GQLParser::RecordLiteralContext *ctx) = 0;
  virtual void exitRecordLiteral(GQLParser::RecordLiteralContext *ctx) = 0;

  virtual void enterIdentifier(GQLParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(GQLParser::IdentifierContext *ctx) = 0;

  virtual void enterRegularIdentifier(GQLParser::RegularIdentifierContext *ctx) = 0;
  virtual void exitRegularIdentifier(GQLParser::RegularIdentifierContext *ctx) = 0;

  virtual void enterTimeZoneString(GQLParser::TimeZoneStringContext *ctx) = 0;
  virtual void exitTimeZoneString(GQLParser::TimeZoneStringContext *ctx) = 0;

  virtual void enterCharacterStringLiteral(GQLParser::CharacterStringLiteralContext *ctx) = 0;
  virtual void exitCharacterStringLiteral(GQLParser::CharacterStringLiteralContext *ctx) = 0;

  virtual void enterUnsignedNumericLiteral(GQLParser::UnsignedNumericLiteralContext *ctx) = 0;
  virtual void exitUnsignedNumericLiteral(GQLParser::UnsignedNumericLiteralContext *ctx) = 0;

  virtual void enterExactNumericLiteral(GQLParser::ExactNumericLiteralContext *ctx) = 0;
  virtual void exitExactNumericLiteral(GQLParser::ExactNumericLiteralContext *ctx) = 0;

  virtual void enterApproximateNumericLiteral(GQLParser::ApproximateNumericLiteralContext *ctx) = 0;
  virtual void exitApproximateNumericLiteral(GQLParser::ApproximateNumericLiteralContext *ctx) = 0;

  virtual void enterUnsignedInteger(GQLParser::UnsignedIntegerContext *ctx) = 0;
  virtual void exitUnsignedInteger(GQLParser::UnsignedIntegerContext *ctx) = 0;

  virtual void enterUnsignedDecimalInteger(GQLParser::UnsignedDecimalIntegerContext *ctx) = 0;
  virtual void exitUnsignedDecimalInteger(GQLParser::UnsignedDecimalIntegerContext *ctx) = 0;

  virtual void enterNullLiteral(GQLParser::NullLiteralContext *ctx) = 0;
  virtual void exitNullLiteral(GQLParser::NullLiteralContext *ctx) = 0;

  virtual void enterDateString(GQLParser::DateStringContext *ctx) = 0;
  virtual void exitDateString(GQLParser::DateStringContext *ctx) = 0;

  virtual void enterTimeString(GQLParser::TimeStringContext *ctx) = 0;
  virtual void exitTimeString(GQLParser::TimeStringContext *ctx) = 0;

  virtual void enterDatetimeString(GQLParser::DatetimeStringContext *ctx) = 0;
  virtual void exitDatetimeString(GQLParser::DatetimeStringContext *ctx) = 0;

  virtual void enterDurationLiteral(GQLParser::DurationLiteralContext *ctx) = 0;
  virtual void exitDurationLiteral(GQLParser::DurationLiteralContext *ctx) = 0;

  virtual void enterDurationString(GQLParser::DurationStringContext *ctx) = 0;
  virtual void exitDurationString(GQLParser::DurationStringContext *ctx) = 0;

  virtual void enterNodeSynonym(GQLParser::NodeSynonymContext *ctx) = 0;
  virtual void exitNodeSynonym(GQLParser::NodeSynonymContext *ctx) = 0;

  virtual void enterEdgesSynonym(GQLParser::EdgesSynonymContext *ctx) = 0;
  virtual void exitEdgesSynonym(GQLParser::EdgesSynonymContext *ctx) = 0;

  virtual void enterEdgeSynonym(GQLParser::EdgeSynonymContext *ctx) = 0;
  virtual void exitEdgeSynonym(GQLParser::EdgeSynonymContext *ctx) = 0;

  virtual void enterNonReservedWords(GQLParser::NonReservedWordsContext *ctx) = 0;
  virtual void exitNonReservedWords(GQLParser::NonReservedWordsContext *ctx) = 0;


};

