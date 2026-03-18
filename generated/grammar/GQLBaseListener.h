
// Generated from grammar/GQL.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "GQLListener.h"


/**
 * This class provides an empty implementation of GQLListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  GQLBaseListener : public GQLListener {
public:

  virtual void enterGqlProgram(GQLParser::GqlProgramContext * /*ctx*/) override { }
  virtual void exitGqlProgram(GQLParser::GqlProgramContext * /*ctx*/) override { }

  virtual void enterProgramActivity(GQLParser::ProgramActivityContext * /*ctx*/) override { }
  virtual void exitProgramActivity(GQLParser::ProgramActivityContext * /*ctx*/) override { }

  virtual void enterSessionActivity(GQLParser::SessionActivityContext * /*ctx*/) override { }
  virtual void exitSessionActivity(GQLParser::SessionActivityContext * /*ctx*/) override { }

  virtual void enterTransactionActivity(GQLParser::TransactionActivityContext * /*ctx*/) override { }
  virtual void exitTransactionActivity(GQLParser::TransactionActivityContext * /*ctx*/) override { }

  virtual void enterSessionSetCommand(GQLParser::SessionSetCommandContext * /*ctx*/) override { }
  virtual void exitSessionSetCommand(GQLParser::SessionSetCommandContext * /*ctx*/) override { }

  virtual void enterSessionSetSchemaClause(GQLParser::SessionSetSchemaClauseContext * /*ctx*/) override { }
  virtual void exitSessionSetSchemaClause(GQLParser::SessionSetSchemaClauseContext * /*ctx*/) override { }

  virtual void enterSessionSetGraphClause(GQLParser::SessionSetGraphClauseContext * /*ctx*/) override { }
  virtual void exitSessionSetGraphClause(GQLParser::SessionSetGraphClauseContext * /*ctx*/) override { }

  virtual void enterSessionSetTimeZoneClause(GQLParser::SessionSetTimeZoneClauseContext * /*ctx*/) override { }
  virtual void exitSessionSetTimeZoneClause(GQLParser::SessionSetTimeZoneClauseContext * /*ctx*/) override { }

  virtual void enterSessionSetParameterClause(GQLParser::SessionSetParameterClauseContext * /*ctx*/) override { }
  virtual void exitSessionSetParameterClause(GQLParser::SessionSetParameterClauseContext * /*ctx*/) override { }

  virtual void enterSessionResetCommand(GQLParser::SessionResetCommandContext * /*ctx*/) override { }
  virtual void exitSessionResetCommand(GQLParser::SessionResetCommandContext * /*ctx*/) override { }

  virtual void enterStartTransactionCommand(GQLParser::StartTransactionCommandContext * /*ctx*/) override { }
  virtual void exitStartTransactionCommand(GQLParser::StartTransactionCommandContext * /*ctx*/) override { }

  virtual void enterTransactionAccessMode(GQLParser::TransactionAccessModeContext * /*ctx*/) override { }
  virtual void exitTransactionAccessMode(GQLParser::TransactionAccessModeContext * /*ctx*/) override { }

  virtual void enterNestedProcedureSpecification(GQLParser::NestedProcedureSpecificationContext * /*ctx*/) override { }
  virtual void exitNestedProcedureSpecification(GQLParser::NestedProcedureSpecificationContext * /*ctx*/) override { }

  virtual void enterProcedureBody(GQLParser::ProcedureBodyContext * /*ctx*/) override { }
  virtual void exitProcedureBody(GQLParser::ProcedureBodyContext * /*ctx*/) override { }

  virtual void enterStatementBlock(GQLParser::StatementBlockContext * /*ctx*/) override { }
  virtual void exitStatementBlock(GQLParser::StatementBlockContext * /*ctx*/) override { }

  virtual void enterStatement(GQLParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(GQLParser::StatementContext * /*ctx*/) override { }

  virtual void enterNextStatement(GQLParser::NextStatementContext * /*ctx*/) override { }
  virtual void exitNextStatement(GQLParser::NextStatementContext * /*ctx*/) override { }

  virtual void enterBindingVariableDefinition(GQLParser::BindingVariableDefinitionContext * /*ctx*/) override { }
  virtual void exitBindingVariableDefinition(GQLParser::BindingVariableDefinitionContext * /*ctx*/) override { }

  virtual void enterGraphExpression(GQLParser::GraphExpressionContext * /*ctx*/) override { }
  virtual void exitGraphExpression(GQLParser::GraphExpressionContext * /*ctx*/) override { }

  virtual void enterBindingTableExpression(GQLParser::BindingTableExpressionContext * /*ctx*/) override { }
  virtual void exitBindingTableExpression(GQLParser::BindingTableExpressionContext * /*ctx*/) override { }

  virtual void enterLinearCatalogModifyingStatement(GQLParser::LinearCatalogModifyingStatementContext * /*ctx*/) override { }
  virtual void exitLinearCatalogModifyingStatement(GQLParser::LinearCatalogModifyingStatementContext * /*ctx*/) override { }

  virtual void enterPrimitiveCatalogModifyingStatement(GQLParser::PrimitiveCatalogModifyingStatementContext * /*ctx*/) override { }
  virtual void exitPrimitiveCatalogModifyingStatement(GQLParser::PrimitiveCatalogModifyingStatementContext * /*ctx*/) override { }

  virtual void enterOpenGraphType(GQLParser::OpenGraphTypeContext * /*ctx*/) override { }
  virtual void exitOpenGraphType(GQLParser::OpenGraphTypeContext * /*ctx*/) override { }

  virtual void enterOfGraphType(GQLParser::OfGraphTypeContext * /*ctx*/) override { }
  virtual void exitOfGraphType(GQLParser::OfGraphTypeContext * /*ctx*/) override { }

  virtual void enterGraphTypeSource(GQLParser::GraphTypeSourceContext * /*ctx*/) override { }
  virtual void exitGraphTypeSource(GQLParser::GraphTypeSourceContext * /*ctx*/) override { }

  virtual void enterGraphSource(GQLParser::GraphSourceContext * /*ctx*/) override { }
  virtual void exitGraphSource(GQLParser::GraphSourceContext * /*ctx*/) override { }

  virtual void enterLinearDataModifyingStatement(GQLParser::LinearDataModifyingStatementContext * /*ctx*/) override { }
  virtual void exitLinearDataModifyingStatement(GQLParser::LinearDataModifyingStatementContext * /*ctx*/) override { }

  virtual void enterFocusedLinearDataModifyingStatement(GQLParser::FocusedLinearDataModifyingStatementContext * /*ctx*/) override { }
  virtual void exitFocusedLinearDataModifyingStatement(GQLParser::FocusedLinearDataModifyingStatementContext * /*ctx*/) override { }

  virtual void enterAmbientLinearDataModifyingStatement(GQLParser::AmbientLinearDataModifyingStatementContext * /*ctx*/) override { }
  virtual void exitAmbientLinearDataModifyingStatement(GQLParser::AmbientLinearDataModifyingStatementContext * /*ctx*/) override { }

  virtual void enterSimpleDataAccessingStatement(GQLParser::SimpleDataAccessingStatementContext * /*ctx*/) override { }
  virtual void exitSimpleDataAccessingStatement(GQLParser::SimpleDataAccessingStatementContext * /*ctx*/) override { }

  virtual void enterPrimitiveDataModifyingStatement(GQLParser::PrimitiveDataModifyingStatementContext * /*ctx*/) override { }
  virtual void exitPrimitiveDataModifyingStatement(GQLParser::PrimitiveDataModifyingStatementContext * /*ctx*/) override { }

  virtual void enterSetItem(GQLParser::SetItemContext * /*ctx*/) override { }
  virtual void exitSetItem(GQLParser::SetItemContext * /*ctx*/) override { }

  virtual void enterRemoveItem(GQLParser::RemoveItemContext * /*ctx*/) override { }
  virtual void exitRemoveItem(GQLParser::RemoveItemContext * /*ctx*/) override { }

  virtual void enterCompositeQueryStatement(GQLParser::CompositeQueryStatementContext * /*ctx*/) override { }
  virtual void exitCompositeQueryStatement(GQLParser::CompositeQueryStatementContext * /*ctx*/) override { }

  virtual void enterCompositeQueryExpression(GQLParser::CompositeQueryExpressionContext * /*ctx*/) override { }
  virtual void exitCompositeQueryExpression(GQLParser::CompositeQueryExpressionContext * /*ctx*/) override { }

  virtual void enterQueryConjunction(GQLParser::QueryConjunctionContext * /*ctx*/) override { }
  virtual void exitQueryConjunction(GQLParser::QueryConjunctionContext * /*ctx*/) override { }

  virtual void enterLinearQueryStatement(GQLParser::LinearQueryStatementContext * /*ctx*/) override { }
  virtual void exitLinearQueryStatement(GQLParser::LinearQueryStatementContext * /*ctx*/) override { }

  virtual void enterFocusedLinearQueryStatement(GQLParser::FocusedLinearQueryStatementContext * /*ctx*/) override { }
  virtual void exitFocusedLinearQueryStatement(GQLParser::FocusedLinearQueryStatementContext * /*ctx*/) override { }

  virtual void enterAmbientLinearQueryStatement(GQLParser::AmbientLinearQueryStatementContext * /*ctx*/) override { }
  virtual void exitAmbientLinearQueryStatement(GQLParser::AmbientLinearQueryStatementContext * /*ctx*/) override { }

  virtual void enterNestedQuerySpecification(GQLParser::NestedQuerySpecificationContext * /*ctx*/) override { }
  virtual void exitNestedQuerySpecification(GQLParser::NestedQuerySpecificationContext * /*ctx*/) override { }

  virtual void enterSimpleQueryStatement(GQLParser::SimpleQueryStatementContext * /*ctx*/) override { }
  virtual void exitSimpleQueryStatement(GQLParser::SimpleQueryStatementContext * /*ctx*/) override { }

  virtual void enterPrimitiveQueryStatement(GQLParser::PrimitiveQueryStatementContext * /*ctx*/) override { }
  virtual void exitPrimitiveQueryStatement(GQLParser::PrimitiveQueryStatementContext * /*ctx*/) override { }

  virtual void enterMatchStatement(GQLParser::MatchStatementContext * /*ctx*/) override { }
  virtual void exitMatchStatement(GQLParser::MatchStatementContext * /*ctx*/) override { }

  virtual void enterLetVariableDefinition(GQLParser::LetVariableDefinitionContext * /*ctx*/) override { }
  virtual void exitLetVariableDefinition(GQLParser::LetVariableDefinitionContext * /*ctx*/) override { }

  virtual void enterOrderByAndPageStatement(GQLParser::OrderByAndPageStatementContext * /*ctx*/) override { }
  virtual void exitOrderByAndPageStatement(GQLParser::OrderByAndPageStatementContext * /*ctx*/) override { }

  virtual void enterPrimitiveResultStatement(GQLParser::PrimitiveResultStatementContext * /*ctx*/) override { }
  virtual void exitPrimitiveResultStatement(GQLParser::PrimitiveResultStatementContext * /*ctx*/) override { }

  virtual void enterReturnItem(GQLParser::ReturnItemContext * /*ctx*/) override { }
  virtual void exitReturnItem(GQLParser::ReturnItemContext * /*ctx*/) override { }

  virtual void enterSelectStatement(GQLParser::SelectStatementContext * /*ctx*/) override { }
  virtual void exitSelectStatement(GQLParser::SelectStatementContext * /*ctx*/) override { }

  virtual void enterSelectItem(GQLParser::SelectItemContext * /*ctx*/) override { }
  virtual void exitSelectItem(GQLParser::SelectItemContext * /*ctx*/) override { }

  virtual void enterHavingClause(GQLParser::HavingClauseContext * /*ctx*/) override { }
  virtual void exitHavingClause(GQLParser::HavingClauseContext * /*ctx*/) override { }

  virtual void enterSelectStatementBody(GQLParser::SelectStatementBodyContext * /*ctx*/) override { }
  virtual void exitSelectStatementBody(GQLParser::SelectStatementBodyContext * /*ctx*/) override { }

  virtual void enterSelectGraphMatch(GQLParser::SelectGraphMatchContext * /*ctx*/) override { }
  virtual void exitSelectGraphMatch(GQLParser::SelectGraphMatchContext * /*ctx*/) override { }

  virtual void enterSelectQuerySpecification(GQLParser::SelectQuerySpecificationContext * /*ctx*/) override { }
  virtual void exitSelectQuerySpecification(GQLParser::SelectQuerySpecificationContext * /*ctx*/) override { }

  virtual void enterCallProcedureStatement(GQLParser::CallProcedureStatementContext * /*ctx*/) override { }
  virtual void exitCallProcedureStatement(GQLParser::CallProcedureStatementContext * /*ctx*/) override { }

  virtual void enterProcedureCall(GQLParser::ProcedureCallContext * /*ctx*/) override { }
  virtual void exitProcedureCall(GQLParser::ProcedureCallContext * /*ctx*/) override { }

  virtual void enterAtSchemaClause(GQLParser::AtSchemaClauseContext * /*ctx*/) override { }
  virtual void exitAtSchemaClause(GQLParser::AtSchemaClauseContext * /*ctx*/) override { }

  virtual void enterUseGraphClause(GQLParser::UseGraphClauseContext * /*ctx*/) override { }
  virtual void exitUseGraphClause(GQLParser::UseGraphClauseContext * /*ctx*/) override { }

  virtual void enterGraphPatternBindingTable(GQLParser::GraphPatternBindingTableContext * /*ctx*/) override { }
  virtual void exitGraphPatternBindingTable(GQLParser::GraphPatternBindingTableContext * /*ctx*/) override { }

  virtual void enterGraphPattern(GQLParser::GraphPatternContext * /*ctx*/) override { }
  virtual void exitGraphPattern(GQLParser::GraphPatternContext * /*ctx*/) override { }

  virtual void enterMatchMode(GQLParser::MatchModeContext * /*ctx*/) override { }
  virtual void exitMatchMode(GQLParser::MatchModeContext * /*ctx*/) override { }

  virtual void enterPathPattern(GQLParser::PathPatternContext * /*ctx*/) override { }
  virtual void exitPathPattern(GQLParser::PathPatternContext * /*ctx*/) override { }

  virtual void enterKeepClause(GQLParser::KeepClauseContext * /*ctx*/) override { }
  virtual void exitKeepClause(GQLParser::KeepClauseContext * /*ctx*/) override { }

  virtual void enterInsertGraphPattern(GQLParser::InsertGraphPatternContext * /*ctx*/) override { }
  virtual void exitInsertGraphPattern(GQLParser::InsertGraphPatternContext * /*ctx*/) override { }

  virtual void enterInsertPathPattern(GQLParser::InsertPathPatternContext * /*ctx*/) override { }
  virtual void exitInsertPathPattern(GQLParser::InsertPathPatternContext * /*ctx*/) override { }

  virtual void enterInsertNodePattern(GQLParser::InsertNodePatternContext * /*ctx*/) override { }
  virtual void exitInsertNodePattern(GQLParser::InsertNodePatternContext * /*ctx*/) override { }

  virtual void enterInsertEdgePattern(GQLParser::InsertEdgePatternContext * /*ctx*/) override { }
  virtual void exitInsertEdgePattern(GQLParser::InsertEdgePatternContext * /*ctx*/) override { }

  virtual void enterInsertElementPatternFiller(GQLParser::InsertElementPatternFillerContext * /*ctx*/) override { }
  virtual void exitInsertElementPatternFiller(GQLParser::InsertElementPatternFillerContext * /*ctx*/) override { }

  virtual void enterLabelAndPropertySetSpecification(GQLParser::LabelAndPropertySetSpecificationContext * /*ctx*/) override { }
  virtual void exitLabelAndPropertySetSpecification(GQLParser::LabelAndPropertySetSpecificationContext * /*ctx*/) override { }

  virtual void enterPathPatternPrefix(GQLParser::PathPatternPrefixContext * /*ctx*/) override { }
  virtual void exitPathPatternPrefix(GQLParser::PathPatternPrefixContext * /*ctx*/) override { }

  virtual void enterPathModePrefix(GQLParser::PathModePrefixContext * /*ctx*/) override { }
  virtual void exitPathModePrefix(GQLParser::PathModePrefixContext * /*ctx*/) override { }

  virtual void enterPathSearchPrefix(GQLParser::PathSearchPrefixContext * /*ctx*/) override { }
  virtual void exitPathSearchPrefix(GQLParser::PathSearchPrefixContext * /*ctx*/) override { }

  virtual void enterShortestPathSearch(GQLParser::ShortestPathSearchContext * /*ctx*/) override { }
  virtual void exitShortestPathSearch(GQLParser::ShortestPathSearchContext * /*ctx*/) override { }

  virtual void enterPpePathTerm(GQLParser::PpePathTermContext * /*ctx*/) override { }
  virtual void exitPpePathTerm(GQLParser::PpePathTermContext * /*ctx*/) override { }

  virtual void enterPpeMultisetAlternation(GQLParser::PpeMultisetAlternationContext * /*ctx*/) override { }
  virtual void exitPpeMultisetAlternation(GQLParser::PpeMultisetAlternationContext * /*ctx*/) override { }

  virtual void enterPpePatternUnion(GQLParser::PpePatternUnionContext * /*ctx*/) override { }
  virtual void exitPpePatternUnion(GQLParser::PpePatternUnionContext * /*ctx*/) override { }

  virtual void enterPathTerm(GQLParser::PathTermContext * /*ctx*/) override { }
  virtual void exitPathTerm(GQLParser::PathTermContext * /*ctx*/) override { }

  virtual void enterPfPathPrimary(GQLParser::PfPathPrimaryContext * /*ctx*/) override { }
  virtual void exitPfPathPrimary(GQLParser::PfPathPrimaryContext * /*ctx*/) override { }

  virtual void enterPfQuantifiedPathPrimary(GQLParser::PfQuantifiedPathPrimaryContext * /*ctx*/) override { }
  virtual void exitPfQuantifiedPathPrimary(GQLParser::PfQuantifiedPathPrimaryContext * /*ctx*/) override { }

  virtual void enterPfQuestionedPathPrimary(GQLParser::PfQuestionedPathPrimaryContext * /*ctx*/) override { }
  virtual void exitPfQuestionedPathPrimary(GQLParser::PfQuestionedPathPrimaryContext * /*ctx*/) override { }

  virtual void enterPpElementPattern(GQLParser::PpElementPatternContext * /*ctx*/) override { }
  virtual void exitPpElementPattern(GQLParser::PpElementPatternContext * /*ctx*/) override { }

  virtual void enterPpParenthesizedPathPatternExpression(GQLParser::PpParenthesizedPathPatternExpressionContext * /*ctx*/) override { }
  virtual void exitPpParenthesizedPathPatternExpression(GQLParser::PpParenthesizedPathPatternExpressionContext * /*ctx*/) override { }

  virtual void enterPpSimplifiedPathPatternExpression(GQLParser::PpSimplifiedPathPatternExpressionContext * /*ctx*/) override { }
  virtual void exitPpSimplifiedPathPatternExpression(GQLParser::PpSimplifiedPathPatternExpressionContext * /*ctx*/) override { }

  virtual void enterElementPattern(GQLParser::ElementPatternContext * /*ctx*/) override { }
  virtual void exitElementPattern(GQLParser::ElementPatternContext * /*ctx*/) override { }

  virtual void enterElementPatternFiller(GQLParser::ElementPatternFillerContext * /*ctx*/) override { }
  virtual void exitElementPatternFiller(GQLParser::ElementPatternFillerContext * /*ctx*/) override { }

  virtual void enterElementVariableDeclaration(GQLParser::ElementVariableDeclarationContext * /*ctx*/) override { }
  virtual void exitElementVariableDeclaration(GQLParser::ElementVariableDeclarationContext * /*ctx*/) override { }

  virtual void enterIsLabelExpression(GQLParser::IsLabelExpressionContext * /*ctx*/) override { }
  virtual void exitIsLabelExpression(GQLParser::IsLabelExpressionContext * /*ctx*/) override { }

  virtual void enterIsOrColon(GQLParser::IsOrColonContext * /*ctx*/) override { }
  virtual void exitIsOrColon(GQLParser::IsOrColonContext * /*ctx*/) override { }

  virtual void enterElementPatternPredicate(GQLParser::ElementPatternPredicateContext * /*ctx*/) override { }
  virtual void exitElementPatternPredicate(GQLParser::ElementPatternPredicateContext * /*ctx*/) override { }

  virtual void enterElementPropertySpecification(GQLParser::ElementPropertySpecificationContext * /*ctx*/) override { }
  virtual void exitElementPropertySpecification(GQLParser::ElementPropertySpecificationContext * /*ctx*/) override { }

  virtual void enterPropertyKeyValuePairList(GQLParser::PropertyKeyValuePairListContext * /*ctx*/) override { }
  virtual void exitPropertyKeyValuePairList(GQLParser::PropertyKeyValuePairListContext * /*ctx*/) override { }

  virtual void enterPropertyKeyValuePair(GQLParser::PropertyKeyValuePairContext * /*ctx*/) override { }
  virtual void exitPropertyKeyValuePair(GQLParser::PropertyKeyValuePairContext * /*ctx*/) override { }

  virtual void enterFullEdgePattern(GQLParser::FullEdgePatternContext * /*ctx*/) override { }
  virtual void exitFullEdgePattern(GQLParser::FullEdgePatternContext * /*ctx*/) override { }

  virtual void enterAbbreviatedEdgePattern(GQLParser::AbbreviatedEdgePatternContext * /*ctx*/) override { }
  virtual void exitAbbreviatedEdgePattern(GQLParser::AbbreviatedEdgePatternContext * /*ctx*/) override { }

  virtual void enterParenthesizedPathPatternExpression(GQLParser::ParenthesizedPathPatternExpressionContext * /*ctx*/) override { }
  virtual void exitParenthesizedPathPatternExpression(GQLParser::ParenthesizedPathPatternExpressionContext * /*ctx*/) override { }

  virtual void enterLabelExpressionNegation(GQLParser::LabelExpressionNegationContext * /*ctx*/) override { }
  virtual void exitLabelExpressionNegation(GQLParser::LabelExpressionNegationContext * /*ctx*/) override { }

  virtual void enterLabelExpressionDisjunction(GQLParser::LabelExpressionDisjunctionContext * /*ctx*/) override { }
  virtual void exitLabelExpressionDisjunction(GQLParser::LabelExpressionDisjunctionContext * /*ctx*/) override { }

  virtual void enterLabelExpressionParenthesized(GQLParser::LabelExpressionParenthesizedContext * /*ctx*/) override { }
  virtual void exitLabelExpressionParenthesized(GQLParser::LabelExpressionParenthesizedContext * /*ctx*/) override { }

  virtual void enterLabelExpressionWildcard(GQLParser::LabelExpressionWildcardContext * /*ctx*/) override { }
  virtual void exitLabelExpressionWildcard(GQLParser::LabelExpressionWildcardContext * /*ctx*/) override { }

  virtual void enterLabelExpressionConjunction(GQLParser::LabelExpressionConjunctionContext * /*ctx*/) override { }
  virtual void exitLabelExpressionConjunction(GQLParser::LabelExpressionConjunctionContext * /*ctx*/) override { }

  virtual void enterLabelExpressionName(GQLParser::LabelExpressionNameContext * /*ctx*/) override { }
  virtual void exitLabelExpressionName(GQLParser::LabelExpressionNameContext * /*ctx*/) override { }

  virtual void enterGraphPatternQuantifier(GQLParser::GraphPatternQuantifierContext * /*ctx*/) override { }
  virtual void exitGraphPatternQuantifier(GQLParser::GraphPatternQuantifierContext * /*ctx*/) override { }

  virtual void enterSimplifiedPathPatternExpression(GQLParser::SimplifiedPathPatternExpressionContext * /*ctx*/) override { }
  virtual void exitSimplifiedPathPatternExpression(GQLParser::SimplifiedPathPatternExpressionContext * /*ctx*/) override { }

  virtual void enterSimplifiedContents(GQLParser::SimplifiedContentsContext * /*ctx*/) override { }
  virtual void exitSimplifiedContents(GQLParser::SimplifiedContentsContext * /*ctx*/) override { }

  virtual void enterSimplifiedFactorLowLabel(GQLParser::SimplifiedFactorLowLabelContext * /*ctx*/) override { }
  virtual void exitSimplifiedFactorLowLabel(GQLParser::SimplifiedFactorLowLabelContext * /*ctx*/) override { }

  virtual void enterSimplifiedConcatenationLabel(GQLParser::SimplifiedConcatenationLabelContext * /*ctx*/) override { }
  virtual void exitSimplifiedConcatenationLabel(GQLParser::SimplifiedConcatenationLabelContext * /*ctx*/) override { }

  virtual void enterSimplifiedConjunctionLabel(GQLParser::SimplifiedConjunctionLabelContext * /*ctx*/) override { }
  virtual void exitSimplifiedConjunctionLabel(GQLParser::SimplifiedConjunctionLabelContext * /*ctx*/) override { }

  virtual void enterSimplifiedFactorHighLabel(GQLParser::SimplifiedFactorHighLabelContext * /*ctx*/) override { }
  virtual void exitSimplifiedFactorHighLabel(GQLParser::SimplifiedFactorHighLabelContext * /*ctx*/) override { }

  virtual void enterSimplifiedFactorHigh(GQLParser::SimplifiedFactorHighContext * /*ctx*/) override { }
  virtual void exitSimplifiedFactorHigh(GQLParser::SimplifiedFactorHighContext * /*ctx*/) override { }

  virtual void enterSimplifiedTertiary(GQLParser::SimplifiedTertiaryContext * /*ctx*/) override { }
  virtual void exitSimplifiedTertiary(GQLParser::SimplifiedTertiaryContext * /*ctx*/) override { }

  virtual void enterSimplifiedSecondary(GQLParser::SimplifiedSecondaryContext * /*ctx*/) override { }
  virtual void exitSimplifiedSecondary(GQLParser::SimplifiedSecondaryContext * /*ctx*/) override { }

  virtual void enterSimplifiedPrimary(GQLParser::SimplifiedPrimaryContext * /*ctx*/) override { }
  virtual void exitSimplifiedPrimary(GQLParser::SimplifiedPrimaryContext * /*ctx*/) override { }

  virtual void enterWhereClause(GQLParser::WhereClauseContext * /*ctx*/) override { }
  virtual void exitWhereClause(GQLParser::WhereClauseContext * /*ctx*/) override { }

  virtual void enterYieldClause(GQLParser::YieldClauseContext * /*ctx*/) override { }
  virtual void exitYieldClause(GQLParser::YieldClauseContext * /*ctx*/) override { }

  virtual void enterYieldItem(GQLParser::YieldItemContext * /*ctx*/) override { }
  virtual void exitYieldItem(GQLParser::YieldItemContext * /*ctx*/) override { }

  virtual void enterGroupByClause(GQLParser::GroupByClauseContext * /*ctx*/) override { }
  virtual void exitGroupByClause(GQLParser::GroupByClauseContext * /*ctx*/) override { }

  virtual void enterOrderByClause(GQLParser::OrderByClauseContext * /*ctx*/) override { }
  virtual void exitOrderByClause(GQLParser::OrderByClauseContext * /*ctx*/) override { }

  virtual void enterSortSpecification(GQLParser::SortSpecificationContext * /*ctx*/) override { }
  virtual void exitSortSpecification(GQLParser::SortSpecificationContext * /*ctx*/) override { }

  virtual void enterLimitClause(GQLParser::LimitClauseContext * /*ctx*/) override { }
  virtual void exitLimitClause(GQLParser::LimitClauseContext * /*ctx*/) override { }

  virtual void enterOffsetClause(GQLParser::OffsetClauseContext * /*ctx*/) override { }
  virtual void exitOffsetClause(GQLParser::OffsetClauseContext * /*ctx*/) override { }

  virtual void enterSchemaReference(GQLParser::SchemaReferenceContext * /*ctx*/) override { }
  virtual void exitSchemaReference(GQLParser::SchemaReferenceContext * /*ctx*/) override { }

  virtual void enterAbsoluteCatalogSchemaReference(GQLParser::AbsoluteCatalogSchemaReferenceContext * /*ctx*/) override { }
  virtual void exitAbsoluteCatalogSchemaReference(GQLParser::AbsoluteCatalogSchemaReferenceContext * /*ctx*/) override { }

  virtual void enterCatalogSchemaParentAndName(GQLParser::CatalogSchemaParentAndNameContext * /*ctx*/) override { }
  virtual void exitCatalogSchemaParentAndName(GQLParser::CatalogSchemaParentAndNameContext * /*ctx*/) override { }

  virtual void enterRelativeCatalogSchemaReference(GQLParser::RelativeCatalogSchemaReferenceContext * /*ctx*/) override { }
  virtual void exitRelativeCatalogSchemaReference(GQLParser::RelativeCatalogSchemaReferenceContext * /*ctx*/) override { }

  virtual void enterAbsoluteDirectoryPath(GQLParser::AbsoluteDirectoryPathContext * /*ctx*/) override { }
  virtual void exitAbsoluteDirectoryPath(GQLParser::AbsoluteDirectoryPathContext * /*ctx*/) override { }

  virtual void enterRelativeDirectoryPath(GQLParser::RelativeDirectoryPathContext * /*ctx*/) override { }
  virtual void exitRelativeDirectoryPath(GQLParser::RelativeDirectoryPathContext * /*ctx*/) override { }

  virtual void enterSimpleDirectoryPath(GQLParser::SimpleDirectoryPathContext * /*ctx*/) override { }
  virtual void exitSimpleDirectoryPath(GQLParser::SimpleDirectoryPathContext * /*ctx*/) override { }

  virtual void enterGraphReference(GQLParser::GraphReferenceContext * /*ctx*/) override { }
  virtual void exitGraphReference(GQLParser::GraphReferenceContext * /*ctx*/) override { }

  virtual void enterCatalogGraphParentAndName(GQLParser::CatalogGraphParentAndNameContext * /*ctx*/) override { }
  virtual void exitCatalogGraphParentAndName(GQLParser::CatalogGraphParentAndNameContext * /*ctx*/) override { }

  virtual void enterGraphTypeReference(GQLParser::GraphTypeReferenceContext * /*ctx*/) override { }
  virtual void exitGraphTypeReference(GQLParser::GraphTypeReferenceContext * /*ctx*/) override { }

  virtual void enterCatalogGraphTypeParentAndName(GQLParser::CatalogGraphTypeParentAndNameContext * /*ctx*/) override { }
  virtual void exitCatalogGraphTypeParentAndName(GQLParser::CatalogGraphTypeParentAndNameContext * /*ctx*/) override { }

  virtual void enterBindingTableReference(GQLParser::BindingTableReferenceContext * /*ctx*/) override { }
  virtual void exitBindingTableReference(GQLParser::BindingTableReferenceContext * /*ctx*/) override { }

  virtual void enterProcedureReference(GQLParser::ProcedureReferenceContext * /*ctx*/) override { }
  virtual void exitProcedureReference(GQLParser::ProcedureReferenceContext * /*ctx*/) override { }

  virtual void enterCatalogObjectParentReference(GQLParser::CatalogObjectParentReferenceContext * /*ctx*/) override { }
  virtual void exitCatalogObjectParentReference(GQLParser::CatalogObjectParentReferenceContext * /*ctx*/) override { }

  virtual void enterNestedGraphTypeSpecification(GQLParser::NestedGraphTypeSpecificationContext * /*ctx*/) override { }
  virtual void exitNestedGraphTypeSpecification(GQLParser::NestedGraphTypeSpecificationContext * /*ctx*/) override { }

  virtual void enterElementTypeSpecification(GQLParser::ElementTypeSpecificationContext * /*ctx*/) override { }
  virtual void exitElementTypeSpecification(GQLParser::ElementTypeSpecificationContext * /*ctx*/) override { }

  virtual void enterNodeTypeSpecification(GQLParser::NodeTypeSpecificationContext * /*ctx*/) override { }
  virtual void exitNodeTypeSpecification(GQLParser::NodeTypeSpecificationContext * /*ctx*/) override { }

  virtual void enterNodeTypePhraseFiller(GQLParser::NodeTypePhraseFillerContext * /*ctx*/) override { }
  virtual void exitNodeTypePhraseFiller(GQLParser::NodeTypePhraseFillerContext * /*ctx*/) override { }

  virtual void enterNodeTypeFiller(GQLParser::NodeTypeFillerContext * /*ctx*/) override { }
  virtual void exitNodeTypeFiller(GQLParser::NodeTypeFillerContext * /*ctx*/) override { }

  virtual void enterNodeTypeImpliedContent(GQLParser::NodeTypeImpliedContentContext * /*ctx*/) override { }
  virtual void exitNodeTypeImpliedContent(GQLParser::NodeTypeImpliedContentContext * /*ctx*/) override { }

  virtual void enterEdgeTypeSpecification(GQLParser::EdgeTypeSpecificationContext * /*ctx*/) override { }
  virtual void exitEdgeTypeSpecification(GQLParser::EdgeTypeSpecificationContext * /*ctx*/) override { }

  virtual void enterEdgeTypePhraseFiller(GQLParser::EdgeTypePhraseFillerContext * /*ctx*/) override { }
  virtual void exitEdgeTypePhraseFiller(GQLParser::EdgeTypePhraseFillerContext * /*ctx*/) override { }

  virtual void enterEdgeTypeFiller(GQLParser::EdgeTypeFillerContext * /*ctx*/) override { }
  virtual void exitEdgeTypeFiller(GQLParser::EdgeTypeFillerContext * /*ctx*/) override { }

  virtual void enterEdgeTypeImpliedContent(GQLParser::EdgeTypeImpliedContentContext * /*ctx*/) override { }
  virtual void exitEdgeTypeImpliedContent(GQLParser::EdgeTypeImpliedContentContext * /*ctx*/) override { }

  virtual void enterEdgeTypePatternDirected(GQLParser::EdgeTypePatternDirectedContext * /*ctx*/) override { }
  virtual void exitEdgeTypePatternDirected(GQLParser::EdgeTypePatternDirectedContext * /*ctx*/) override { }

  virtual void enterEdgeTypePatternUndirected(GQLParser::EdgeTypePatternUndirectedContext * /*ctx*/) override { }
  virtual void exitEdgeTypePatternUndirected(GQLParser::EdgeTypePatternUndirectedContext * /*ctx*/) override { }

  virtual void enterArcTypePointingRight(GQLParser::ArcTypePointingRightContext * /*ctx*/) override { }
  virtual void exitArcTypePointingRight(GQLParser::ArcTypePointingRightContext * /*ctx*/) override { }

  virtual void enterArcTypePointingLeft(GQLParser::ArcTypePointingLeftContext * /*ctx*/) override { }
  virtual void exitArcTypePointingLeft(GQLParser::ArcTypePointingLeftContext * /*ctx*/) override { }

  virtual void enterArcTypeUndirected(GQLParser::ArcTypeUndirectedContext * /*ctx*/) override { }
  virtual void exitArcTypeUndirected(GQLParser::ArcTypeUndirectedContext * /*ctx*/) override { }

  virtual void enterSourceNodeTypeReference(GQLParser::SourceNodeTypeReferenceContext * /*ctx*/) override { }
  virtual void exitSourceNodeTypeReference(GQLParser::SourceNodeTypeReferenceContext * /*ctx*/) override { }

  virtual void enterDestinationNodeTypeReference(GQLParser::DestinationNodeTypeReferenceContext * /*ctx*/) override { }
  virtual void exitDestinationNodeTypeReference(GQLParser::DestinationNodeTypeReferenceContext * /*ctx*/) override { }

  virtual void enterEdgeKind(GQLParser::EdgeKindContext * /*ctx*/) override { }
  virtual void exitEdgeKind(GQLParser::EdgeKindContext * /*ctx*/) override { }

  virtual void enterEndpointPairPhrase(GQLParser::EndpointPairPhraseContext * /*ctx*/) override { }
  virtual void exitEndpointPairPhrase(GQLParser::EndpointPairPhraseContext * /*ctx*/) override { }

  virtual void enterEndpointPair(GQLParser::EndpointPairContext * /*ctx*/) override { }
  virtual void exitEndpointPair(GQLParser::EndpointPairContext * /*ctx*/) override { }

  virtual void enterLabelSetPhrase(GQLParser::LabelSetPhraseContext * /*ctx*/) override { }
  virtual void exitLabelSetPhrase(GQLParser::LabelSetPhraseContext * /*ctx*/) override { }

  virtual void enterLabelSetSpecification(GQLParser::LabelSetSpecificationContext * /*ctx*/) override { }
  virtual void exitLabelSetSpecification(GQLParser::LabelSetSpecificationContext * /*ctx*/) override { }

  virtual void enterPropertyTypesSpecification(GQLParser::PropertyTypesSpecificationContext * /*ctx*/) override { }
  virtual void exitPropertyTypesSpecification(GQLParser::PropertyTypesSpecificationContext * /*ctx*/) override { }

  virtual void enterPropertyValueType(GQLParser::PropertyValueTypeContext * /*ctx*/) override { }
  virtual void exitPropertyValueType(GQLParser::PropertyValueTypeContext * /*ctx*/) override { }

  virtual void enterBindingTableType(GQLParser::BindingTableTypeContext * /*ctx*/) override { }
  virtual void exitBindingTableType(GQLParser::BindingTableTypeContext * /*ctx*/) override { }

  virtual void enterDynamicPropertyValueTypeLabel(GQLParser::DynamicPropertyValueTypeLabelContext * /*ctx*/) override { }
  virtual void exitDynamicPropertyValueTypeLabel(GQLParser::DynamicPropertyValueTypeLabelContext * /*ctx*/) override { }

  virtual void enterClosedDynamicUnionTypeAtl1(GQLParser::ClosedDynamicUnionTypeAtl1Context * /*ctx*/) override { }
  virtual void exitClosedDynamicUnionTypeAtl1(GQLParser::ClosedDynamicUnionTypeAtl1Context * /*ctx*/) override { }

  virtual void enterClosedDynamicUnionTypeAtl2(GQLParser::ClosedDynamicUnionTypeAtl2Context * /*ctx*/) override { }
  virtual void exitClosedDynamicUnionTypeAtl2(GQLParser::ClosedDynamicUnionTypeAtl2Context * /*ctx*/) override { }

  virtual void enterPathValueTypeLabel(GQLParser::PathValueTypeLabelContext * /*ctx*/) override { }
  virtual void exitPathValueTypeLabel(GQLParser::PathValueTypeLabelContext * /*ctx*/) override { }

  virtual void enterListValueTypeAlt3(GQLParser::ListValueTypeAlt3Context * /*ctx*/) override { }
  virtual void exitListValueTypeAlt3(GQLParser::ListValueTypeAlt3Context * /*ctx*/) override { }

  virtual void enterListValueTypeAlt2(GQLParser::ListValueTypeAlt2Context * /*ctx*/) override { }
  virtual void exitListValueTypeAlt2(GQLParser::ListValueTypeAlt2Context * /*ctx*/) override { }

  virtual void enterListValueTypeAlt1(GQLParser::ListValueTypeAlt1Context * /*ctx*/) override { }
  virtual void exitListValueTypeAlt1(GQLParser::ListValueTypeAlt1Context * /*ctx*/) override { }

  virtual void enterPredefinedTypeLabel(GQLParser::PredefinedTypeLabelContext * /*ctx*/) override { }
  virtual void exitPredefinedTypeLabel(GQLParser::PredefinedTypeLabelContext * /*ctx*/) override { }

  virtual void enterRecordTypeLabel(GQLParser::RecordTypeLabelContext * /*ctx*/) override { }
  virtual void exitRecordTypeLabel(GQLParser::RecordTypeLabelContext * /*ctx*/) override { }

  virtual void enterOpenDynamicUnionTypeLabel(GQLParser::OpenDynamicUnionTypeLabelContext * /*ctx*/) override { }
  virtual void exitOpenDynamicUnionTypeLabel(GQLParser::OpenDynamicUnionTypeLabelContext * /*ctx*/) override { }

  virtual void enterTyped(GQLParser::TypedContext * /*ctx*/) override { }
  virtual void exitTyped(GQLParser::TypedContext * /*ctx*/) override { }

  virtual void enterPredefinedType(GQLParser::PredefinedTypeContext * /*ctx*/) override { }
  virtual void exitPredefinedType(GQLParser::PredefinedTypeContext * /*ctx*/) override { }

  virtual void enterBooleanType(GQLParser::BooleanTypeContext * /*ctx*/) override { }
  virtual void exitBooleanType(GQLParser::BooleanTypeContext * /*ctx*/) override { }

  virtual void enterCharacterStringType(GQLParser::CharacterStringTypeContext * /*ctx*/) override { }
  virtual void exitCharacterStringType(GQLParser::CharacterStringTypeContext * /*ctx*/) override { }

  virtual void enterByteStringType(GQLParser::ByteStringTypeContext * /*ctx*/) override { }
  virtual void exitByteStringType(GQLParser::ByteStringTypeContext * /*ctx*/) override { }

  virtual void enterMinLength(GQLParser::MinLengthContext * /*ctx*/) override { }
  virtual void exitMinLength(GQLParser::MinLengthContext * /*ctx*/) override { }

  virtual void enterMaxLength(GQLParser::MaxLengthContext * /*ctx*/) override { }
  virtual void exitMaxLength(GQLParser::MaxLengthContext * /*ctx*/) override { }

  virtual void enterFixedLength(GQLParser::FixedLengthContext * /*ctx*/) override { }
  virtual void exitFixedLength(GQLParser::FixedLengthContext * /*ctx*/) override { }

  virtual void enterNumericType(GQLParser::NumericTypeContext * /*ctx*/) override { }
  virtual void exitNumericType(GQLParser::NumericTypeContext * /*ctx*/) override { }

  virtual void enterExactNumericType(GQLParser::ExactNumericTypeContext * /*ctx*/) override { }
  virtual void exitExactNumericType(GQLParser::ExactNumericTypeContext * /*ctx*/) override { }

  virtual void enterBinaryExactNumericType(GQLParser::BinaryExactNumericTypeContext * /*ctx*/) override { }
  virtual void exitBinaryExactNumericType(GQLParser::BinaryExactNumericTypeContext * /*ctx*/) override { }

  virtual void enterSignedBinaryExactNumericType(GQLParser::SignedBinaryExactNumericTypeContext * /*ctx*/) override { }
  virtual void exitSignedBinaryExactNumericType(GQLParser::SignedBinaryExactNumericTypeContext * /*ctx*/) override { }

  virtual void enterUnsignedBinaryExactNumericType(GQLParser::UnsignedBinaryExactNumericTypeContext * /*ctx*/) override { }
  virtual void exitUnsignedBinaryExactNumericType(GQLParser::UnsignedBinaryExactNumericTypeContext * /*ctx*/) override { }

  virtual void enterVerboseBinaryExactNumericType(GQLParser::VerboseBinaryExactNumericTypeContext * /*ctx*/) override { }
  virtual void exitVerboseBinaryExactNumericType(GQLParser::VerboseBinaryExactNumericTypeContext * /*ctx*/) override { }

  virtual void enterDecimalExactNumericType(GQLParser::DecimalExactNumericTypeContext * /*ctx*/) override { }
  virtual void exitDecimalExactNumericType(GQLParser::DecimalExactNumericTypeContext * /*ctx*/) override { }

  virtual void enterPrecision(GQLParser::PrecisionContext * /*ctx*/) override { }
  virtual void exitPrecision(GQLParser::PrecisionContext * /*ctx*/) override { }

  virtual void enterScale(GQLParser::ScaleContext * /*ctx*/) override { }
  virtual void exitScale(GQLParser::ScaleContext * /*ctx*/) override { }

  virtual void enterApproximateNumericType(GQLParser::ApproximateNumericTypeContext * /*ctx*/) override { }
  virtual void exitApproximateNumericType(GQLParser::ApproximateNumericTypeContext * /*ctx*/) override { }

  virtual void enterTemporalType(GQLParser::TemporalTypeContext * /*ctx*/) override { }
  virtual void exitTemporalType(GQLParser::TemporalTypeContext * /*ctx*/) override { }

  virtual void enterTemporalInstantType(GQLParser::TemporalInstantTypeContext * /*ctx*/) override { }
  virtual void exitTemporalInstantType(GQLParser::TemporalInstantTypeContext * /*ctx*/) override { }

  virtual void enterDatetimeType(GQLParser::DatetimeTypeContext * /*ctx*/) override { }
  virtual void exitDatetimeType(GQLParser::DatetimeTypeContext * /*ctx*/) override { }

  virtual void enterLocaldatetimeType(GQLParser::LocaldatetimeTypeContext * /*ctx*/) override { }
  virtual void exitLocaldatetimeType(GQLParser::LocaldatetimeTypeContext * /*ctx*/) override { }

  virtual void enterDateType(GQLParser::DateTypeContext * /*ctx*/) override { }
  virtual void exitDateType(GQLParser::DateTypeContext * /*ctx*/) override { }

  virtual void enterTimeType(GQLParser::TimeTypeContext * /*ctx*/) override { }
  virtual void exitTimeType(GQLParser::TimeTypeContext * /*ctx*/) override { }

  virtual void enterLocaltimeType(GQLParser::LocaltimeTypeContext * /*ctx*/) override { }
  virtual void exitLocaltimeType(GQLParser::LocaltimeTypeContext * /*ctx*/) override { }

  virtual void enterTemporalDurationType(GQLParser::TemporalDurationTypeContext * /*ctx*/) override { }
  virtual void exitTemporalDurationType(GQLParser::TemporalDurationTypeContext * /*ctx*/) override { }

  virtual void enterReferenceValueType(GQLParser::ReferenceValueTypeContext * /*ctx*/) override { }
  virtual void exitReferenceValueType(GQLParser::ReferenceValueTypeContext * /*ctx*/) override { }

  virtual void enterImmaterialValueType(GQLParser::ImmaterialValueTypeContext * /*ctx*/) override { }
  virtual void exitImmaterialValueType(GQLParser::ImmaterialValueTypeContext * /*ctx*/) override { }

  virtual void enterGraphReferenceValueType(GQLParser::GraphReferenceValueTypeContext * /*ctx*/) override { }
  virtual void exitGraphReferenceValueType(GQLParser::GraphReferenceValueTypeContext * /*ctx*/) override { }

  virtual void enterBindingTableReferenceValueType(GQLParser::BindingTableReferenceValueTypeContext * /*ctx*/) override { }
  virtual void exitBindingTableReferenceValueType(GQLParser::BindingTableReferenceValueTypeContext * /*ctx*/) override { }

  virtual void enterNodeReferenceValueType(GQLParser::NodeReferenceValueTypeContext * /*ctx*/) override { }
  virtual void exitNodeReferenceValueType(GQLParser::NodeReferenceValueTypeContext * /*ctx*/) override { }

  virtual void enterEdgeReferenceValueType(GQLParser::EdgeReferenceValueTypeContext * /*ctx*/) override { }
  virtual void exitEdgeReferenceValueType(GQLParser::EdgeReferenceValueTypeContext * /*ctx*/) override { }

  virtual void enterPathValueType(GQLParser::PathValueTypeContext * /*ctx*/) override { }
  virtual void exitPathValueType(GQLParser::PathValueTypeContext * /*ctx*/) override { }

  virtual void enterListValueTypeName(GQLParser::ListValueTypeNameContext * /*ctx*/) override { }
  virtual void exitListValueTypeName(GQLParser::ListValueTypeNameContext * /*ctx*/) override { }

  virtual void enterRecordType(GQLParser::RecordTypeContext * /*ctx*/) override { }
  virtual void exitRecordType(GQLParser::RecordTypeContext * /*ctx*/) override { }

  virtual void enterFieldTypesSpecification(GQLParser::FieldTypesSpecificationContext * /*ctx*/) override { }
  virtual void exitFieldTypesSpecification(GQLParser::FieldTypesSpecificationContext * /*ctx*/) override { }

  virtual void enterNotNull(GQLParser::NotNullContext * /*ctx*/) override { }
  virtual void exitNotNull(GQLParser::NotNullContext * /*ctx*/) override { }

  virtual void enterSearchCondition(GQLParser::SearchConditionContext * /*ctx*/) override { }
  virtual void exitSearchCondition(GQLParser::SearchConditionContext * /*ctx*/) override { }

  virtual void enterPredicate(GQLParser::PredicateContext * /*ctx*/) override { }
  virtual void exitPredicate(GQLParser::PredicateContext * /*ctx*/) override { }

  virtual void enterCompOp(GQLParser::CompOpContext * /*ctx*/) override { }
  virtual void exitCompOp(GQLParser::CompOpContext * /*ctx*/) override { }

  virtual void enterConjunctiveExprAlt(GQLParser::ConjunctiveExprAltContext * /*ctx*/) override { }
  virtual void exitConjunctiveExprAlt(GQLParser::ConjunctiveExprAltContext * /*ctx*/) override { }

  virtual void enterPropertyGraphExprAlt(GQLParser::PropertyGraphExprAltContext * /*ctx*/) override { }
  virtual void exitPropertyGraphExprAlt(GQLParser::PropertyGraphExprAltContext * /*ctx*/) override { }

  virtual void enterMultDivExprAlt(GQLParser::MultDivExprAltContext * /*ctx*/) override { }
  virtual void exitMultDivExprAlt(GQLParser::MultDivExprAltContext * /*ctx*/) override { }

  virtual void enterBindingTableExprAlt(GQLParser::BindingTableExprAltContext * /*ctx*/) override { }
  virtual void exitBindingTableExprAlt(GQLParser::BindingTableExprAltContext * /*ctx*/) override { }

  virtual void enterInExprAlt(GQLParser::InExprAltContext * /*ctx*/) override { }
  virtual void exitInExprAlt(GQLParser::InExprAltContext * /*ctx*/) override { }

  virtual void enterSignedExprAlt(GQLParser::SignedExprAltContext * /*ctx*/) override { }
  virtual void exitSignedExprAlt(GQLParser::SignedExprAltContext * /*ctx*/) override { }

  virtual void enterIsNotExprAlt(GQLParser::IsNotExprAltContext * /*ctx*/) override { }
  virtual void exitIsNotExprAlt(GQLParser::IsNotExprAltContext * /*ctx*/) override { }

  virtual void enterNormalizedPredicateExprAlt(GQLParser::NormalizedPredicateExprAltContext * /*ctx*/) override { }
  virtual void exitNormalizedPredicateExprAlt(GQLParser::NormalizedPredicateExprAltContext * /*ctx*/) override { }

  virtual void enterNotExprAlt(GQLParser::NotExprAltContext * /*ctx*/) override { }
  virtual void exitNotExprAlt(GQLParser::NotExprAltContext * /*ctx*/) override { }

  virtual void enterValueFunctionExprAlt(GQLParser::ValueFunctionExprAltContext * /*ctx*/) override { }
  virtual void exitValueFunctionExprAlt(GQLParser::ValueFunctionExprAltContext * /*ctx*/) override { }

  virtual void enterConcatenationExprAlt(GQLParser::ConcatenationExprAltContext * /*ctx*/) override { }
  virtual void exitConcatenationExprAlt(GQLParser::ConcatenationExprAltContext * /*ctx*/) override { }

  virtual void enterDisjunctiveExprAlt(GQLParser::DisjunctiveExprAltContext * /*ctx*/) override { }
  virtual void exitDisjunctiveExprAlt(GQLParser::DisjunctiveExprAltContext * /*ctx*/) override { }

  virtual void enterComparisonExprAlt(GQLParser::ComparisonExprAltContext * /*ctx*/) override { }
  virtual void exitComparisonExprAlt(GQLParser::ComparisonExprAltContext * /*ctx*/) override { }

  virtual void enterPrimaryExprAlt(GQLParser::PrimaryExprAltContext * /*ctx*/) override { }
  virtual void exitPrimaryExprAlt(GQLParser::PrimaryExprAltContext * /*ctx*/) override { }

  virtual void enterAddSubtractExprAlt(GQLParser::AddSubtractExprAltContext * /*ctx*/) override { }
  virtual void exitAddSubtractExprAlt(GQLParser::AddSubtractExprAltContext * /*ctx*/) override { }

  virtual void enterPredicateExprAlt(GQLParser::PredicateExprAltContext * /*ctx*/) override { }
  virtual void exitPredicateExprAlt(GQLParser::PredicateExprAltContext * /*ctx*/) override { }

  virtual void enterValueFunction(GQLParser::ValueFunctionContext * /*ctx*/) override { }
  virtual void exitValueFunction(GQLParser::ValueFunctionContext * /*ctx*/) override { }

  virtual void enterBooleanValueExpression(GQLParser::BooleanValueExpressionContext * /*ctx*/) override { }
  virtual void exitBooleanValueExpression(GQLParser::BooleanValueExpressionContext * /*ctx*/) override { }

  virtual void enterCharacterOrByteStringFunction(GQLParser::CharacterOrByteStringFunctionContext * /*ctx*/) override { }
  virtual void exitCharacterOrByteStringFunction(GQLParser::CharacterOrByteStringFunctionContext * /*ctx*/) override { }

  virtual void enterAggregatingValueExpression(GQLParser::AggregatingValueExpressionContext * /*ctx*/) override { }
  virtual void exitAggregatingValueExpression(GQLParser::AggregatingValueExpressionContext * /*ctx*/) override { }

  virtual void enterValueExpressionPrimary(GQLParser::ValueExpressionPrimaryContext * /*ctx*/) override { }
  virtual void exitValueExpressionPrimary(GQLParser::ValueExpressionPrimaryContext * /*ctx*/) override { }

  virtual void enterParenthesizedValueExpression(GQLParser::ParenthesizedValueExpressionContext * /*ctx*/) override { }
  virtual void exitParenthesizedValueExpression(GQLParser::ParenthesizedValueExpressionContext * /*ctx*/) override { }

  virtual void enterNonParenthesizedValueExpressionPrimarySpecialCase(GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext * /*ctx*/) override { }
  virtual void exitNonParenthesizedValueExpressionPrimarySpecialCase(GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext * /*ctx*/) override { }

  virtual void enterUnsignedValueSpecification(GQLParser::UnsignedValueSpecificationContext * /*ctx*/) override { }
  virtual void exitUnsignedValueSpecification(GQLParser::UnsignedValueSpecificationContext * /*ctx*/) override { }

  virtual void enterNonNegativeIntegerSpecification(GQLParser::NonNegativeIntegerSpecificationContext * /*ctx*/) override { }
  virtual void exitNonNegativeIntegerSpecification(GQLParser::NonNegativeIntegerSpecificationContext * /*ctx*/) override { }

  virtual void enterCaseExpression(GQLParser::CaseExpressionContext * /*ctx*/) override { }
  virtual void exitCaseExpression(GQLParser::CaseExpressionContext * /*ctx*/) override { }

  virtual void enterSimpleWhenClause(GQLParser::SimpleWhenClauseContext * /*ctx*/) override { }
  virtual void exitSimpleWhenClause(GQLParser::SimpleWhenClauseContext * /*ctx*/) override { }

  virtual void enterSearchedWhenClause(GQLParser::SearchedWhenClauseContext * /*ctx*/) override { }
  virtual void exitSearchedWhenClause(GQLParser::SearchedWhenClauseContext * /*ctx*/) override { }

  virtual void enterElseClause(GQLParser::ElseClauseContext * /*ctx*/) override { }
  virtual void exitElseClause(GQLParser::ElseClauseContext * /*ctx*/) override { }

  virtual void enterCaseOperand(GQLParser::CaseOperandContext * /*ctx*/) override { }
  virtual void exitCaseOperand(GQLParser::CaseOperandContext * /*ctx*/) override { }

  virtual void enterWhenOperand(GQLParser::WhenOperandContext * /*ctx*/) override { }
  virtual void exitWhenOperand(GQLParser::WhenOperandContext * /*ctx*/) override { }

  virtual void enterResult(GQLParser::ResultContext * /*ctx*/) override { }
  virtual void exitResult(GQLParser::ResultContext * /*ctx*/) override { }

  virtual void enterAggregateFunction(GQLParser::AggregateFunctionContext * /*ctx*/) override { }
  virtual void exitAggregateFunction(GQLParser::AggregateFunctionContext * /*ctx*/) override { }

  virtual void enterSetQuantifier(GQLParser::SetQuantifierContext * /*ctx*/) override { }
  virtual void exitSetQuantifier(GQLParser::SetQuantifierContext * /*ctx*/) override { }

  virtual void enterBindingVariableReference(GQLParser::BindingVariableReferenceContext * /*ctx*/) override { }
  virtual void exitBindingVariableReference(GQLParser::BindingVariableReferenceContext * /*ctx*/) override { }

  virtual void enterElementVariableReference(GQLParser::ElementVariableReferenceContext * /*ctx*/) override { }
  virtual void exitElementVariableReference(GQLParser::ElementVariableReferenceContext * /*ctx*/) override { }

  virtual void enterPathValueExpression(GQLParser::PathValueExpressionContext * /*ctx*/) override { }
  virtual void exitPathValueExpression(GQLParser::PathValueExpressionContext * /*ctx*/) override { }

  virtual void enterPathValueConstructor(GQLParser::PathValueConstructorContext * /*ctx*/) override { }
  virtual void exitPathValueConstructor(GQLParser::PathValueConstructorContext * /*ctx*/) override { }

  virtual void enterListValueExpression(GQLParser::ListValueExpressionContext * /*ctx*/) override { }
  virtual void exitListValueExpression(GQLParser::ListValueExpressionContext * /*ctx*/) override { }

  virtual void enterListValueFunction(GQLParser::ListValueFunctionContext * /*ctx*/) override { }
  virtual void exitListValueFunction(GQLParser::ListValueFunctionContext * /*ctx*/) override { }

  virtual void enterListValueConstructor(GQLParser::ListValueConstructorContext * /*ctx*/) override { }
  virtual void exitListValueConstructor(GQLParser::ListValueConstructorContext * /*ctx*/) override { }

  virtual void enterRecordConstructor(GQLParser::RecordConstructorContext * /*ctx*/) override { }
  virtual void exitRecordConstructor(GQLParser::RecordConstructorContext * /*ctx*/) override { }

  virtual void enterTruthValue(GQLParser::TruthValueContext * /*ctx*/) override { }
  virtual void exitTruthValue(GQLParser::TruthValueContext * /*ctx*/) override { }

  virtual void enterNumericValueExpression(GQLParser::NumericValueExpressionContext * /*ctx*/) override { }
  virtual void exitNumericValueExpression(GQLParser::NumericValueExpressionContext * /*ctx*/) override { }

  virtual void enterNumericValueFunction(GQLParser::NumericValueFunctionContext * /*ctx*/) override { }
  virtual void exitNumericValueFunction(GQLParser::NumericValueFunctionContext * /*ctx*/) override { }

  virtual void enterCharacterStringValueExpression(GQLParser::CharacterStringValueExpressionContext * /*ctx*/) override { }
  virtual void exitCharacterStringValueExpression(GQLParser::CharacterStringValueExpressionContext * /*ctx*/) override { }

  virtual void enterByteStringValueExpression(GQLParser::ByteStringValueExpressionContext * /*ctx*/) override { }
  virtual void exitByteStringValueExpression(GQLParser::ByteStringValueExpressionContext * /*ctx*/) override { }

  virtual void enterTrimOperands(GQLParser::TrimOperandsContext * /*ctx*/) override { }
  virtual void exitTrimOperands(GQLParser::TrimOperandsContext * /*ctx*/) override { }

  virtual void enterStringLength(GQLParser::StringLengthContext * /*ctx*/) override { }
  virtual void exitStringLength(GQLParser::StringLengthContext * /*ctx*/) override { }

  virtual void enterDatetimeValueExpression(GQLParser::DatetimeValueExpressionContext * /*ctx*/) override { }
  virtual void exitDatetimeValueExpression(GQLParser::DatetimeValueExpressionContext * /*ctx*/) override { }

  virtual void enterDatetimeValueFunction(GQLParser::DatetimeValueFunctionContext * /*ctx*/) override { }
  virtual void exitDatetimeValueFunction(GQLParser::DatetimeValueFunctionContext * /*ctx*/) override { }

  virtual void enterDurationValueExpression(GQLParser::DurationValueExpressionContext * /*ctx*/) override { }
  virtual void exitDurationValueExpression(GQLParser::DurationValueExpressionContext * /*ctx*/) override { }

  virtual void enterDatetimeSubtraction(GQLParser::DatetimeSubtractionContext * /*ctx*/) override { }
  virtual void exitDatetimeSubtraction(GQLParser::DatetimeSubtractionContext * /*ctx*/) override { }

  virtual void enterDurationValueFunction(GQLParser::DurationValueFunctionContext * /*ctx*/) override { }
  virtual void exitDurationValueFunction(GQLParser::DurationValueFunctionContext * /*ctx*/) override { }

  virtual void enterObjectName(GQLParser::ObjectNameContext * /*ctx*/) override { }
  virtual void exitObjectName(GQLParser::ObjectNameContext * /*ctx*/) override { }

  virtual void enterObjectNameOrBindingVariable(GQLParser::ObjectNameOrBindingVariableContext * /*ctx*/) override { }
  virtual void exitObjectNameOrBindingVariable(GQLParser::ObjectNameOrBindingVariableContext * /*ctx*/) override { }

  virtual void enterDirectoryName(GQLParser::DirectoryNameContext * /*ctx*/) override { }
  virtual void exitDirectoryName(GQLParser::DirectoryNameContext * /*ctx*/) override { }

  virtual void enterSchemaName(GQLParser::SchemaNameContext * /*ctx*/) override { }
  virtual void exitSchemaName(GQLParser::SchemaNameContext * /*ctx*/) override { }

  virtual void enterGraphName(GQLParser::GraphNameContext * /*ctx*/) override { }
  virtual void exitGraphName(GQLParser::GraphNameContext * /*ctx*/) override { }

  virtual void enterDelimitedGraphName(GQLParser::DelimitedGraphNameContext * /*ctx*/) override { }
  virtual void exitDelimitedGraphName(GQLParser::DelimitedGraphNameContext * /*ctx*/) override { }

  virtual void enterGraphTypeName(GQLParser::GraphTypeNameContext * /*ctx*/) override { }
  virtual void exitGraphTypeName(GQLParser::GraphTypeNameContext * /*ctx*/) override { }

  virtual void enterNodeTypeName(GQLParser::NodeTypeNameContext * /*ctx*/) override { }
  virtual void exitNodeTypeName(GQLParser::NodeTypeNameContext * /*ctx*/) override { }

  virtual void enterEdgeTypeName(GQLParser::EdgeTypeNameContext * /*ctx*/) override { }
  virtual void exitEdgeTypeName(GQLParser::EdgeTypeNameContext * /*ctx*/) override { }

  virtual void enterBindingTableName(GQLParser::BindingTableNameContext * /*ctx*/) override { }
  virtual void exitBindingTableName(GQLParser::BindingTableNameContext * /*ctx*/) override { }

  virtual void enterDelimitedBindingTableName(GQLParser::DelimitedBindingTableNameContext * /*ctx*/) override { }
  virtual void exitDelimitedBindingTableName(GQLParser::DelimitedBindingTableNameContext * /*ctx*/) override { }

  virtual void enterProcedureName(GQLParser::ProcedureNameContext * /*ctx*/) override { }
  virtual void exitProcedureName(GQLParser::ProcedureNameContext * /*ctx*/) override { }

  virtual void enterLabelName(GQLParser::LabelNameContext * /*ctx*/) override { }
  virtual void exitLabelName(GQLParser::LabelNameContext * /*ctx*/) override { }

  virtual void enterPropertyName(GQLParser::PropertyNameContext * /*ctx*/) override { }
  virtual void exitPropertyName(GQLParser::PropertyNameContext * /*ctx*/) override { }

  virtual void enterFieldName(GQLParser::FieldNameContext * /*ctx*/) override { }
  virtual void exitFieldName(GQLParser::FieldNameContext * /*ctx*/) override { }

  virtual void enterElementVariable(GQLParser::ElementVariableContext * /*ctx*/) override { }
  virtual void exitElementVariable(GQLParser::ElementVariableContext * /*ctx*/) override { }

  virtual void enterPathVariable(GQLParser::PathVariableContext * /*ctx*/) override { }
  virtual void exitPathVariable(GQLParser::PathVariableContext * /*ctx*/) override { }

  virtual void enterSubpathVariable(GQLParser::SubpathVariableContext * /*ctx*/) override { }
  virtual void exitSubpathVariable(GQLParser::SubpathVariableContext * /*ctx*/) override { }

  virtual void enterBindingVariable(GQLParser::BindingVariableContext * /*ctx*/) override { }
  virtual void exitBindingVariable(GQLParser::BindingVariableContext * /*ctx*/) override { }

  virtual void enterUnsignedLiteral(GQLParser::UnsignedLiteralContext * /*ctx*/) override { }
  virtual void exitUnsignedLiteral(GQLParser::UnsignedLiteralContext * /*ctx*/) override { }

  virtual void enterGeneralLiteral(GQLParser::GeneralLiteralContext * /*ctx*/) override { }
  virtual void exitGeneralLiteral(GQLParser::GeneralLiteralContext * /*ctx*/) override { }

  virtual void enterTemporalLiteral(GQLParser::TemporalLiteralContext * /*ctx*/) override { }
  virtual void exitTemporalLiteral(GQLParser::TemporalLiteralContext * /*ctx*/) override { }

  virtual void enterListLiteral(GQLParser::ListLiteralContext * /*ctx*/) override { }
  virtual void exitListLiteral(GQLParser::ListLiteralContext * /*ctx*/) override { }

  virtual void enterRecordLiteral(GQLParser::RecordLiteralContext * /*ctx*/) override { }
  virtual void exitRecordLiteral(GQLParser::RecordLiteralContext * /*ctx*/) override { }

  virtual void enterIdentifier(GQLParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(GQLParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterRegularIdentifier(GQLParser::RegularIdentifierContext * /*ctx*/) override { }
  virtual void exitRegularIdentifier(GQLParser::RegularIdentifierContext * /*ctx*/) override { }

  virtual void enterTimeZoneString(GQLParser::TimeZoneStringContext * /*ctx*/) override { }
  virtual void exitTimeZoneString(GQLParser::TimeZoneStringContext * /*ctx*/) override { }

  virtual void enterCharacterStringLiteral(GQLParser::CharacterStringLiteralContext * /*ctx*/) override { }
  virtual void exitCharacterStringLiteral(GQLParser::CharacterStringLiteralContext * /*ctx*/) override { }

  virtual void enterUnsignedNumericLiteral(GQLParser::UnsignedNumericLiteralContext * /*ctx*/) override { }
  virtual void exitUnsignedNumericLiteral(GQLParser::UnsignedNumericLiteralContext * /*ctx*/) override { }

  virtual void enterExactNumericLiteral(GQLParser::ExactNumericLiteralContext * /*ctx*/) override { }
  virtual void exitExactNumericLiteral(GQLParser::ExactNumericLiteralContext * /*ctx*/) override { }

  virtual void enterApproximateNumericLiteral(GQLParser::ApproximateNumericLiteralContext * /*ctx*/) override { }
  virtual void exitApproximateNumericLiteral(GQLParser::ApproximateNumericLiteralContext * /*ctx*/) override { }

  virtual void enterUnsignedInteger(GQLParser::UnsignedIntegerContext * /*ctx*/) override { }
  virtual void exitUnsignedInteger(GQLParser::UnsignedIntegerContext * /*ctx*/) override { }

  virtual void enterUnsignedDecimalInteger(GQLParser::UnsignedDecimalIntegerContext * /*ctx*/) override { }
  virtual void exitUnsignedDecimalInteger(GQLParser::UnsignedDecimalIntegerContext * /*ctx*/) override { }

  virtual void enterNullLiteral(GQLParser::NullLiteralContext * /*ctx*/) override { }
  virtual void exitNullLiteral(GQLParser::NullLiteralContext * /*ctx*/) override { }

  virtual void enterDateString(GQLParser::DateStringContext * /*ctx*/) override { }
  virtual void exitDateString(GQLParser::DateStringContext * /*ctx*/) override { }

  virtual void enterTimeString(GQLParser::TimeStringContext * /*ctx*/) override { }
  virtual void exitTimeString(GQLParser::TimeStringContext * /*ctx*/) override { }

  virtual void enterDatetimeString(GQLParser::DatetimeStringContext * /*ctx*/) override { }
  virtual void exitDatetimeString(GQLParser::DatetimeStringContext * /*ctx*/) override { }

  virtual void enterDurationLiteral(GQLParser::DurationLiteralContext * /*ctx*/) override { }
  virtual void exitDurationLiteral(GQLParser::DurationLiteralContext * /*ctx*/) override { }

  virtual void enterDurationString(GQLParser::DurationStringContext * /*ctx*/) override { }
  virtual void exitDurationString(GQLParser::DurationStringContext * /*ctx*/) override { }

  virtual void enterNodeSynonym(GQLParser::NodeSynonymContext * /*ctx*/) override { }
  virtual void exitNodeSynonym(GQLParser::NodeSynonymContext * /*ctx*/) override { }

  virtual void enterEdgesSynonym(GQLParser::EdgesSynonymContext * /*ctx*/) override { }
  virtual void exitEdgesSynonym(GQLParser::EdgesSynonymContext * /*ctx*/) override { }

  virtual void enterEdgeSynonym(GQLParser::EdgeSynonymContext * /*ctx*/) override { }
  virtual void exitEdgeSynonym(GQLParser::EdgeSynonymContext * /*ctx*/) override { }

  virtual void enterNonReservedWords(GQLParser::NonReservedWordsContext * /*ctx*/) override { }
  virtual void exitNonReservedWords(GQLParser::NonReservedWordsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

