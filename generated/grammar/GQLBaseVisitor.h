
// Generated from grammar/GQL.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "GQLVisitor.h"


/**
 * This class provides an empty implementation of GQLVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  GQLBaseVisitor : public GQLVisitor {
public:

  virtual std::any visitGqlProgram(GQLParser::GqlProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProgramActivity(GQLParser::ProgramActivityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSessionActivity(GQLParser::SessionActivityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTransactionActivity(GQLParser::TransactionActivityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSessionSetCommand(GQLParser::SessionSetCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSessionSetSchemaClause(GQLParser::SessionSetSchemaClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSessionSetGraphClause(GQLParser::SessionSetGraphClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSessionSetTimeZoneClause(GQLParser::SessionSetTimeZoneClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSessionSetParameterClause(GQLParser::SessionSetParameterClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSessionResetCommand(GQLParser::SessionResetCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStartTransactionCommand(GQLParser::StartTransactionCommandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTransactionAccessMode(GQLParser::TransactionAccessModeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNestedProcedureSpecification(GQLParser::NestedProcedureSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureBody(GQLParser::ProcedureBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementBlock(GQLParser::StatementBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(GQLParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNextStatement(GQLParser::NextStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBindingVariableDefinition(GQLParser::BindingVariableDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphExpression(GQLParser::GraphExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBindingTableExpression(GQLParser::BindingTableExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLinearCatalogModifyingStatement(GQLParser::LinearCatalogModifyingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitiveCatalogModifyingStatement(GQLParser::PrimitiveCatalogModifyingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOpenGraphType(GQLParser::OpenGraphTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOfGraphType(GQLParser::OfGraphTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphTypeSource(GQLParser::GraphTypeSourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphSource(GQLParser::GraphSourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLinearDataModifyingStatement(GQLParser::LinearDataModifyingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFocusedLinearDataModifyingStatement(GQLParser::FocusedLinearDataModifyingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAmbientLinearDataModifyingStatement(GQLParser::AmbientLinearDataModifyingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleDataAccessingStatement(GQLParser::SimpleDataAccessingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitiveDataModifyingStatement(GQLParser::PrimitiveDataModifyingStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetItem(GQLParser::SetItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRemoveItem(GQLParser::RemoveItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompositeQueryStatement(GQLParser::CompositeQueryStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompositeQueryExpression(GQLParser::CompositeQueryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQueryConjunction(GQLParser::QueryConjunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLinearQueryStatement(GQLParser::LinearQueryStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFocusedLinearQueryStatement(GQLParser::FocusedLinearQueryStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAmbientLinearQueryStatement(GQLParser::AmbientLinearQueryStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNestedQuerySpecification(GQLParser::NestedQuerySpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleQueryStatement(GQLParser::SimpleQueryStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitiveQueryStatement(GQLParser::PrimitiveQueryStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatchStatement(GQLParser::MatchStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLetVariableDefinition(GQLParser::LetVariableDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrderByAndPageStatement(GQLParser::OrderByAndPageStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitiveResultStatement(GQLParser::PrimitiveResultStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnItem(GQLParser::ReturnItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectStatement(GQLParser::SelectStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectItem(GQLParser::SelectItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHavingClause(GQLParser::HavingClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectStatementBody(GQLParser::SelectStatementBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectGraphMatch(GQLParser::SelectGraphMatchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelectQuerySpecification(GQLParser::SelectQuerySpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallProcedureStatement(GQLParser::CallProcedureStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureCall(GQLParser::ProcedureCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtSchemaClause(GQLParser::AtSchemaClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUseGraphClause(GQLParser::UseGraphClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphPatternBindingTable(GQLParser::GraphPatternBindingTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphPattern(GQLParser::GraphPatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatchMode(GQLParser::MatchModeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathPattern(GQLParser::PathPatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeepClause(GQLParser::KeepClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInsertGraphPattern(GQLParser::InsertGraphPatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInsertPathPattern(GQLParser::InsertPathPatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInsertNodePattern(GQLParser::InsertNodePatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInsertEdgePattern(GQLParser::InsertEdgePatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInsertElementPatternFiller(GQLParser::InsertElementPatternFillerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelAndPropertySetSpecification(GQLParser::LabelAndPropertySetSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathPatternPrefix(GQLParser::PathPatternPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathModePrefix(GQLParser::PathModePrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathSearchPrefix(GQLParser::PathSearchPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShortestPathSearch(GQLParser::ShortestPathSearchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPpePathTerm(GQLParser::PpePathTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPpeMultisetAlternation(GQLParser::PpeMultisetAlternationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPpePatternUnion(GQLParser::PpePatternUnionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathTerm(GQLParser::PathTermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPfPathPrimary(GQLParser::PfPathPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPfQuantifiedPathPrimary(GQLParser::PfQuantifiedPathPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPfQuestionedPathPrimary(GQLParser::PfQuestionedPathPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPpElementPattern(GQLParser::PpElementPatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPpParenthesizedPathPatternExpression(GQLParser::PpParenthesizedPathPatternExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPpSimplifiedPathPatternExpression(GQLParser::PpSimplifiedPathPatternExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementPattern(GQLParser::ElementPatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementPatternFiller(GQLParser::ElementPatternFillerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementVariableDeclaration(GQLParser::ElementVariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIsLabelExpression(GQLParser::IsLabelExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIsOrColon(GQLParser::IsOrColonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementPatternPredicate(GQLParser::ElementPatternPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementPropertySpecification(GQLParser::ElementPropertySpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyKeyValuePairList(GQLParser::PropertyKeyValuePairListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyKeyValuePair(GQLParser::PropertyKeyValuePairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFullEdgePattern(GQLParser::FullEdgePatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAbbreviatedEdgePattern(GQLParser::AbbreviatedEdgePatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesizedPathPatternExpression(GQLParser::ParenthesizedPathPatternExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelExpressionNegation(GQLParser::LabelExpressionNegationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelExpressionDisjunction(GQLParser::LabelExpressionDisjunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelExpressionParenthesized(GQLParser::LabelExpressionParenthesizedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelExpressionWildcard(GQLParser::LabelExpressionWildcardContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelExpressionConjunction(GQLParser::LabelExpressionConjunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelExpressionName(GQLParser::LabelExpressionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphPatternQuantifier(GQLParser::GraphPatternQuantifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimplifiedPathPatternExpression(GQLParser::SimplifiedPathPatternExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimplifiedContents(GQLParser::SimplifiedContentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimplifiedFactorLowLabel(GQLParser::SimplifiedFactorLowLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimplifiedConcatenationLabel(GQLParser::SimplifiedConcatenationLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimplifiedConjunctionLabel(GQLParser::SimplifiedConjunctionLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimplifiedFactorHighLabel(GQLParser::SimplifiedFactorHighLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimplifiedFactorHigh(GQLParser::SimplifiedFactorHighContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimplifiedTertiary(GQLParser::SimplifiedTertiaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimplifiedSecondary(GQLParser::SimplifiedSecondaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimplifiedPrimary(GQLParser::SimplifiedPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhereClause(GQLParser::WhereClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitYieldClause(GQLParser::YieldClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitYieldItem(GQLParser::YieldItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGroupByClause(GQLParser::GroupByClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrderByClause(GQLParser::OrderByClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSortSpecification(GQLParser::SortSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLimitClause(GQLParser::LimitClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOffsetClause(GQLParser::OffsetClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSchemaReference(GQLParser::SchemaReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAbsoluteCatalogSchemaReference(GQLParser::AbsoluteCatalogSchemaReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCatalogSchemaParentAndName(GQLParser::CatalogSchemaParentAndNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelativeCatalogSchemaReference(GQLParser::RelativeCatalogSchemaReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAbsoluteDirectoryPath(GQLParser::AbsoluteDirectoryPathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelativeDirectoryPath(GQLParser::RelativeDirectoryPathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleDirectoryPath(GQLParser::SimpleDirectoryPathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphReference(GQLParser::GraphReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCatalogGraphParentAndName(GQLParser::CatalogGraphParentAndNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphTypeReference(GQLParser::GraphTypeReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCatalogGraphTypeParentAndName(GQLParser::CatalogGraphTypeParentAndNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBindingTableReference(GQLParser::BindingTableReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureReference(GQLParser::ProcedureReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCatalogObjectParentReference(GQLParser::CatalogObjectParentReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNestedGraphTypeSpecification(GQLParser::NestedGraphTypeSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementTypeSpecification(GQLParser::ElementTypeSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNodeTypeSpecification(GQLParser::NodeTypeSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNodeTypePhraseFiller(GQLParser::NodeTypePhraseFillerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNodeTypeFiller(GQLParser::NodeTypeFillerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNodeTypeImpliedContent(GQLParser::NodeTypeImpliedContentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgeTypeSpecification(GQLParser::EdgeTypeSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgeTypePhraseFiller(GQLParser::EdgeTypePhraseFillerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgeTypeFiller(GQLParser::EdgeTypeFillerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgeTypeImpliedContent(GQLParser::EdgeTypeImpliedContentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgeTypePatternDirected(GQLParser::EdgeTypePatternDirectedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgeTypePatternUndirected(GQLParser::EdgeTypePatternUndirectedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArcTypePointingRight(GQLParser::ArcTypePointingRightContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArcTypePointingLeft(GQLParser::ArcTypePointingLeftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArcTypeUndirected(GQLParser::ArcTypeUndirectedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSourceNodeTypeReference(GQLParser::SourceNodeTypeReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDestinationNodeTypeReference(GQLParser::DestinationNodeTypeReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgeKind(GQLParser::EdgeKindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEndpointPairPhrase(GQLParser::EndpointPairPhraseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEndpointPair(GQLParser::EndpointPairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelSetPhrase(GQLParser::LabelSetPhraseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelSetSpecification(GQLParser::LabelSetSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyTypesSpecification(GQLParser::PropertyTypesSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyValueType(GQLParser::PropertyValueTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBindingTableType(GQLParser::BindingTableTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDynamicPropertyValueTypeLabel(GQLParser::DynamicPropertyValueTypeLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClosedDynamicUnionTypeAtl1(GQLParser::ClosedDynamicUnionTypeAtl1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClosedDynamicUnionTypeAtl2(GQLParser::ClosedDynamicUnionTypeAtl2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathValueTypeLabel(GQLParser::PathValueTypeLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListValueTypeAlt3(GQLParser::ListValueTypeAlt3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListValueTypeAlt2(GQLParser::ListValueTypeAlt2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListValueTypeAlt1(GQLParser::ListValueTypeAlt1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPredefinedTypeLabel(GQLParser::PredefinedTypeLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordTypeLabel(GQLParser::RecordTypeLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOpenDynamicUnionTypeLabel(GQLParser::OpenDynamicUnionTypeLabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTyped(GQLParser::TypedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPredefinedType(GQLParser::PredefinedTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanType(GQLParser::BooleanTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharacterStringType(GQLParser::CharacterStringTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitByteStringType(GQLParser::ByteStringTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMinLength(GQLParser::MinLengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMaxLength(GQLParser::MaxLengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFixedLength(GQLParser::FixedLengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumericType(GQLParser::NumericTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExactNumericType(GQLParser::ExactNumericTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryExactNumericType(GQLParser::BinaryExactNumericTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSignedBinaryExactNumericType(GQLParser::SignedBinaryExactNumericTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnsignedBinaryExactNumericType(GQLParser::UnsignedBinaryExactNumericTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVerboseBinaryExactNumericType(GQLParser::VerboseBinaryExactNumericTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecimalExactNumericType(GQLParser::DecimalExactNumericTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrecision(GQLParser::PrecisionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitScale(GQLParser::ScaleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApproximateNumericType(GQLParser::ApproximateNumericTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTemporalType(GQLParser::TemporalTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTemporalInstantType(GQLParser::TemporalInstantTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDatetimeType(GQLParser::DatetimeTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLocaldatetimeType(GQLParser::LocaldatetimeTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDateType(GQLParser::DateTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimeType(GQLParser::TimeTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLocaltimeType(GQLParser::LocaltimeTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTemporalDurationType(GQLParser::TemporalDurationTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReferenceValueType(GQLParser::ReferenceValueTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImmaterialValueType(GQLParser::ImmaterialValueTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphReferenceValueType(GQLParser::GraphReferenceValueTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBindingTableReferenceValueType(GQLParser::BindingTableReferenceValueTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNodeReferenceValueType(GQLParser::NodeReferenceValueTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgeReferenceValueType(GQLParser::EdgeReferenceValueTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathValueType(GQLParser::PathValueTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListValueTypeName(GQLParser::ListValueTypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordType(GQLParser::RecordTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldTypesSpecification(GQLParser::FieldTypesSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotNull(GQLParser::NotNullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSearchCondition(GQLParser::SearchConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPredicate(GQLParser::PredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompOp(GQLParser::CompOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConjunctiveExprAlt(GQLParser::ConjunctiveExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyGraphExprAlt(GQLParser::PropertyGraphExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultDivExprAlt(GQLParser::MultDivExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBindingTableExprAlt(GQLParser::BindingTableExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInExprAlt(GQLParser::InExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSignedExprAlt(GQLParser::SignedExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIsNotExprAlt(GQLParser::IsNotExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNormalizedPredicateExprAlt(GQLParser::NormalizedPredicateExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExprAlt(GQLParser::NotExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValueFunctionExprAlt(GQLParser::ValueFunctionExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConcatenationExprAlt(GQLParser::ConcatenationExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDisjunctiveExprAlt(GQLParser::DisjunctiveExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparisonExprAlt(GQLParser::ComparisonExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExprAlt(GQLParser::PrimaryExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddSubtractExprAlt(GQLParser::AddSubtractExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPredicateExprAlt(GQLParser::PredicateExprAltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValueFunction(GQLParser::ValueFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanValueExpression(GQLParser::BooleanValueExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharacterOrByteStringFunction(GQLParser::CharacterOrByteStringFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAggregatingValueExpression(GQLParser::AggregatingValueExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValueExpressionPrimary(GQLParser::ValueExpressionPrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesizedValueExpression(GQLParser::ParenthesizedValueExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonParenthesizedValueExpressionPrimarySpecialCase(GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnsignedValueSpecification(GQLParser::UnsignedValueSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonNegativeIntegerSpecification(GQLParser::NonNegativeIntegerSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseExpression(GQLParser::CaseExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleWhenClause(GQLParser::SimpleWhenClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSearchedWhenClause(GQLParser::SearchedWhenClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElseClause(GQLParser::ElseClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseOperand(GQLParser::CaseOperandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhenOperand(GQLParser::WhenOperandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResult(GQLParser::ResultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAggregateFunction(GQLParser::AggregateFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetQuantifier(GQLParser::SetQuantifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBindingVariableReference(GQLParser::BindingVariableReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementVariableReference(GQLParser::ElementVariableReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathValueExpression(GQLParser::PathValueExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathValueConstructor(GQLParser::PathValueConstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListValueExpression(GQLParser::ListValueExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListValueFunction(GQLParser::ListValueFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListValueConstructor(GQLParser::ListValueConstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordConstructor(GQLParser::RecordConstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTruthValue(GQLParser::TruthValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumericValueExpression(GQLParser::NumericValueExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumericValueFunction(GQLParser::NumericValueFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharacterStringValueExpression(GQLParser::CharacterStringValueExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitByteStringValueExpression(GQLParser::ByteStringValueExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrimOperands(GQLParser::TrimOperandsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLength(GQLParser::StringLengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDatetimeValueExpression(GQLParser::DatetimeValueExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDatetimeValueFunction(GQLParser::DatetimeValueFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDurationValueExpression(GQLParser::DurationValueExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDatetimeSubtraction(GQLParser::DatetimeSubtractionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDurationValueFunction(GQLParser::DurationValueFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObjectName(GQLParser::ObjectNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObjectNameOrBindingVariable(GQLParser::ObjectNameOrBindingVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDirectoryName(GQLParser::DirectoryNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSchemaName(GQLParser::SchemaNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphName(GQLParser::GraphNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDelimitedGraphName(GQLParser::DelimitedGraphNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGraphTypeName(GQLParser::GraphTypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNodeTypeName(GQLParser::NodeTypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgeTypeName(GQLParser::EdgeTypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBindingTableName(GQLParser::BindingTableNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDelimitedBindingTableName(GQLParser::DelimitedBindingTableNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcedureName(GQLParser::ProcedureNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelName(GQLParser::LabelNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyName(GQLParser::PropertyNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldName(GQLParser::FieldNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementVariable(GQLParser::ElementVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathVariable(GQLParser::PathVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubpathVariable(GQLParser::SubpathVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBindingVariable(GQLParser::BindingVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnsignedLiteral(GQLParser::UnsignedLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGeneralLiteral(GQLParser::GeneralLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTemporalLiteral(GQLParser::TemporalLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListLiteral(GQLParser::ListLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordLiteral(GQLParser::RecordLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(GQLParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRegularIdentifier(GQLParser::RegularIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimeZoneString(GQLParser::TimeZoneStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharacterStringLiteral(GQLParser::CharacterStringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnsignedNumericLiteral(GQLParser::UnsignedNumericLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExactNumericLiteral(GQLParser::ExactNumericLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApproximateNumericLiteral(GQLParser::ApproximateNumericLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnsignedInteger(GQLParser::UnsignedIntegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnsignedDecimalInteger(GQLParser::UnsignedDecimalIntegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullLiteral(GQLParser::NullLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDateString(GQLParser::DateStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTimeString(GQLParser::TimeStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDatetimeString(GQLParser::DatetimeStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDurationLiteral(GQLParser::DurationLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDurationString(GQLParser::DurationStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNodeSynonym(GQLParser::NodeSynonymContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgesSynonym(GQLParser::EdgesSynonymContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgeSynonym(GQLParser::EdgeSynonymContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonReservedWords(GQLParser::NonReservedWordsContext *ctx) override {
    return visitChildren(ctx);
  }


};

