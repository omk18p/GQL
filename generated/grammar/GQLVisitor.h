
// Generated from grammar/GQL.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "GQLParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by GQLParser.
 */
class  GQLVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by GQLParser.
   */
    virtual std::any visitGqlProgram(GQLParser::GqlProgramContext *context) = 0;

    virtual std::any visitProgramActivity(GQLParser::ProgramActivityContext *context) = 0;

    virtual std::any visitSessionActivity(GQLParser::SessionActivityContext *context) = 0;

    virtual std::any visitTransactionActivity(GQLParser::TransactionActivityContext *context) = 0;

    virtual std::any visitSessionSetCommand(GQLParser::SessionSetCommandContext *context) = 0;

    virtual std::any visitSessionSetSchemaClause(GQLParser::SessionSetSchemaClauseContext *context) = 0;

    virtual std::any visitSessionSetGraphClause(GQLParser::SessionSetGraphClauseContext *context) = 0;

    virtual std::any visitSessionSetTimeZoneClause(GQLParser::SessionSetTimeZoneClauseContext *context) = 0;

    virtual std::any visitSessionSetParameterClause(GQLParser::SessionSetParameterClauseContext *context) = 0;

    virtual std::any visitSessionResetCommand(GQLParser::SessionResetCommandContext *context) = 0;

    virtual std::any visitStartTransactionCommand(GQLParser::StartTransactionCommandContext *context) = 0;

    virtual std::any visitTransactionAccessMode(GQLParser::TransactionAccessModeContext *context) = 0;

    virtual std::any visitNestedProcedureSpecification(GQLParser::NestedProcedureSpecificationContext *context) = 0;

    virtual std::any visitProcedureBody(GQLParser::ProcedureBodyContext *context) = 0;

    virtual std::any visitStatementBlock(GQLParser::StatementBlockContext *context) = 0;

    virtual std::any visitStatement(GQLParser::StatementContext *context) = 0;

    virtual std::any visitNextStatement(GQLParser::NextStatementContext *context) = 0;

    virtual std::any visitBindingVariableDefinition(GQLParser::BindingVariableDefinitionContext *context) = 0;

    virtual std::any visitGraphExpression(GQLParser::GraphExpressionContext *context) = 0;

    virtual std::any visitBindingTableExpression(GQLParser::BindingTableExpressionContext *context) = 0;

    virtual std::any visitLinearCatalogModifyingStatement(GQLParser::LinearCatalogModifyingStatementContext *context) = 0;

    virtual std::any visitPrimitiveCatalogModifyingStatement(GQLParser::PrimitiveCatalogModifyingStatementContext *context) = 0;

    virtual std::any visitOpenGraphType(GQLParser::OpenGraphTypeContext *context) = 0;

    virtual std::any visitOfGraphType(GQLParser::OfGraphTypeContext *context) = 0;

    virtual std::any visitGraphTypeSource(GQLParser::GraphTypeSourceContext *context) = 0;

    virtual std::any visitGraphSource(GQLParser::GraphSourceContext *context) = 0;

    virtual std::any visitLinearDataModifyingStatement(GQLParser::LinearDataModifyingStatementContext *context) = 0;

    virtual std::any visitFocusedLinearDataModifyingStatement(GQLParser::FocusedLinearDataModifyingStatementContext *context) = 0;

    virtual std::any visitAmbientLinearDataModifyingStatement(GQLParser::AmbientLinearDataModifyingStatementContext *context) = 0;

    virtual std::any visitSimpleDataAccessingStatement(GQLParser::SimpleDataAccessingStatementContext *context) = 0;

    virtual std::any visitPrimitiveDataModifyingStatement(GQLParser::PrimitiveDataModifyingStatementContext *context) = 0;

    virtual std::any visitSetItem(GQLParser::SetItemContext *context) = 0;

    virtual std::any visitRemoveItem(GQLParser::RemoveItemContext *context) = 0;

    virtual std::any visitCompositeQueryStatement(GQLParser::CompositeQueryStatementContext *context) = 0;

    virtual std::any visitCompositeQueryExpression(GQLParser::CompositeQueryExpressionContext *context) = 0;

    virtual std::any visitQueryConjunction(GQLParser::QueryConjunctionContext *context) = 0;

    virtual std::any visitLinearQueryStatement(GQLParser::LinearQueryStatementContext *context) = 0;

    virtual std::any visitFocusedLinearQueryStatement(GQLParser::FocusedLinearQueryStatementContext *context) = 0;

    virtual std::any visitAmbientLinearQueryStatement(GQLParser::AmbientLinearQueryStatementContext *context) = 0;

    virtual std::any visitNestedQuerySpecification(GQLParser::NestedQuerySpecificationContext *context) = 0;

    virtual std::any visitSimpleQueryStatement(GQLParser::SimpleQueryStatementContext *context) = 0;

    virtual std::any visitPrimitiveQueryStatement(GQLParser::PrimitiveQueryStatementContext *context) = 0;

    virtual std::any visitMatchStatement(GQLParser::MatchStatementContext *context) = 0;

    virtual std::any visitLetVariableDefinition(GQLParser::LetVariableDefinitionContext *context) = 0;

    virtual std::any visitOrderByAndPageStatement(GQLParser::OrderByAndPageStatementContext *context) = 0;

    virtual std::any visitPrimitiveResultStatement(GQLParser::PrimitiveResultStatementContext *context) = 0;

    virtual std::any visitReturnItem(GQLParser::ReturnItemContext *context) = 0;

    virtual std::any visitSelectStatement(GQLParser::SelectStatementContext *context) = 0;

    virtual std::any visitSelectItem(GQLParser::SelectItemContext *context) = 0;

    virtual std::any visitHavingClause(GQLParser::HavingClauseContext *context) = 0;

    virtual std::any visitSelectStatementBody(GQLParser::SelectStatementBodyContext *context) = 0;

    virtual std::any visitSelectGraphMatch(GQLParser::SelectGraphMatchContext *context) = 0;

    virtual std::any visitSelectQuerySpecification(GQLParser::SelectQuerySpecificationContext *context) = 0;

    virtual std::any visitCallProcedureStatement(GQLParser::CallProcedureStatementContext *context) = 0;

    virtual std::any visitProcedureCall(GQLParser::ProcedureCallContext *context) = 0;

    virtual std::any visitAtSchemaClause(GQLParser::AtSchemaClauseContext *context) = 0;

    virtual std::any visitUseGraphClause(GQLParser::UseGraphClauseContext *context) = 0;

    virtual std::any visitGraphPatternBindingTable(GQLParser::GraphPatternBindingTableContext *context) = 0;

    virtual std::any visitGraphPattern(GQLParser::GraphPatternContext *context) = 0;

    virtual std::any visitMatchMode(GQLParser::MatchModeContext *context) = 0;

    virtual std::any visitPathPattern(GQLParser::PathPatternContext *context) = 0;

    virtual std::any visitKeepClause(GQLParser::KeepClauseContext *context) = 0;

    virtual std::any visitInsertGraphPattern(GQLParser::InsertGraphPatternContext *context) = 0;

    virtual std::any visitInsertPathPattern(GQLParser::InsertPathPatternContext *context) = 0;

    virtual std::any visitInsertNodePattern(GQLParser::InsertNodePatternContext *context) = 0;

    virtual std::any visitInsertEdgePattern(GQLParser::InsertEdgePatternContext *context) = 0;

    virtual std::any visitInsertElementPatternFiller(GQLParser::InsertElementPatternFillerContext *context) = 0;

    virtual std::any visitLabelAndPropertySetSpecification(GQLParser::LabelAndPropertySetSpecificationContext *context) = 0;

    virtual std::any visitPathPatternPrefix(GQLParser::PathPatternPrefixContext *context) = 0;

    virtual std::any visitPathModePrefix(GQLParser::PathModePrefixContext *context) = 0;

    virtual std::any visitPathSearchPrefix(GQLParser::PathSearchPrefixContext *context) = 0;

    virtual std::any visitShortestPathSearch(GQLParser::ShortestPathSearchContext *context) = 0;

    virtual std::any visitPpePathTerm(GQLParser::PpePathTermContext *context) = 0;

    virtual std::any visitPpeMultisetAlternation(GQLParser::PpeMultisetAlternationContext *context) = 0;

    virtual std::any visitPpePatternUnion(GQLParser::PpePatternUnionContext *context) = 0;

    virtual std::any visitPathTerm(GQLParser::PathTermContext *context) = 0;

    virtual std::any visitPfPathPrimary(GQLParser::PfPathPrimaryContext *context) = 0;

    virtual std::any visitPfQuantifiedPathPrimary(GQLParser::PfQuantifiedPathPrimaryContext *context) = 0;

    virtual std::any visitPfQuestionedPathPrimary(GQLParser::PfQuestionedPathPrimaryContext *context) = 0;

    virtual std::any visitPpElementPattern(GQLParser::PpElementPatternContext *context) = 0;

    virtual std::any visitPpParenthesizedPathPatternExpression(GQLParser::PpParenthesizedPathPatternExpressionContext *context) = 0;

    virtual std::any visitPpSimplifiedPathPatternExpression(GQLParser::PpSimplifiedPathPatternExpressionContext *context) = 0;

    virtual std::any visitElementPattern(GQLParser::ElementPatternContext *context) = 0;

    virtual std::any visitElementPatternFiller(GQLParser::ElementPatternFillerContext *context) = 0;

    virtual std::any visitElementVariableDeclaration(GQLParser::ElementVariableDeclarationContext *context) = 0;

    virtual std::any visitIsLabelExpression(GQLParser::IsLabelExpressionContext *context) = 0;

    virtual std::any visitIsOrColon(GQLParser::IsOrColonContext *context) = 0;

    virtual std::any visitElementPatternPredicate(GQLParser::ElementPatternPredicateContext *context) = 0;

    virtual std::any visitElementPropertySpecification(GQLParser::ElementPropertySpecificationContext *context) = 0;

    virtual std::any visitPropertyKeyValuePairList(GQLParser::PropertyKeyValuePairListContext *context) = 0;

    virtual std::any visitPropertyKeyValuePair(GQLParser::PropertyKeyValuePairContext *context) = 0;

    virtual std::any visitFullEdgePattern(GQLParser::FullEdgePatternContext *context) = 0;

    virtual std::any visitAbbreviatedEdgePattern(GQLParser::AbbreviatedEdgePatternContext *context) = 0;

    virtual std::any visitParenthesizedPathPatternExpression(GQLParser::ParenthesizedPathPatternExpressionContext *context) = 0;

    virtual std::any visitLabelExpressionNegation(GQLParser::LabelExpressionNegationContext *context) = 0;

    virtual std::any visitLabelExpressionDisjunction(GQLParser::LabelExpressionDisjunctionContext *context) = 0;

    virtual std::any visitLabelExpressionParenthesized(GQLParser::LabelExpressionParenthesizedContext *context) = 0;

    virtual std::any visitLabelExpressionWildcard(GQLParser::LabelExpressionWildcardContext *context) = 0;

    virtual std::any visitLabelExpressionConjunction(GQLParser::LabelExpressionConjunctionContext *context) = 0;

    virtual std::any visitLabelExpressionName(GQLParser::LabelExpressionNameContext *context) = 0;

    virtual std::any visitGraphPatternQuantifier(GQLParser::GraphPatternQuantifierContext *context) = 0;

    virtual std::any visitSimplifiedPathPatternExpression(GQLParser::SimplifiedPathPatternExpressionContext *context) = 0;

    virtual std::any visitSimplifiedContents(GQLParser::SimplifiedContentsContext *context) = 0;

    virtual std::any visitSimplifiedFactorLowLabel(GQLParser::SimplifiedFactorLowLabelContext *context) = 0;

    virtual std::any visitSimplifiedConcatenationLabel(GQLParser::SimplifiedConcatenationLabelContext *context) = 0;

    virtual std::any visitSimplifiedConjunctionLabel(GQLParser::SimplifiedConjunctionLabelContext *context) = 0;

    virtual std::any visitSimplifiedFactorHighLabel(GQLParser::SimplifiedFactorHighLabelContext *context) = 0;

    virtual std::any visitSimplifiedFactorHigh(GQLParser::SimplifiedFactorHighContext *context) = 0;

    virtual std::any visitSimplifiedTertiary(GQLParser::SimplifiedTertiaryContext *context) = 0;

    virtual std::any visitSimplifiedSecondary(GQLParser::SimplifiedSecondaryContext *context) = 0;

    virtual std::any visitSimplifiedPrimary(GQLParser::SimplifiedPrimaryContext *context) = 0;

    virtual std::any visitWhereClause(GQLParser::WhereClauseContext *context) = 0;

    virtual std::any visitYieldClause(GQLParser::YieldClauseContext *context) = 0;

    virtual std::any visitYieldItem(GQLParser::YieldItemContext *context) = 0;

    virtual std::any visitGroupByClause(GQLParser::GroupByClauseContext *context) = 0;

    virtual std::any visitOrderByClause(GQLParser::OrderByClauseContext *context) = 0;

    virtual std::any visitSortSpecification(GQLParser::SortSpecificationContext *context) = 0;

    virtual std::any visitLimitClause(GQLParser::LimitClauseContext *context) = 0;

    virtual std::any visitOffsetClause(GQLParser::OffsetClauseContext *context) = 0;

    virtual std::any visitSchemaReference(GQLParser::SchemaReferenceContext *context) = 0;

    virtual std::any visitAbsoluteCatalogSchemaReference(GQLParser::AbsoluteCatalogSchemaReferenceContext *context) = 0;

    virtual std::any visitCatalogSchemaParentAndName(GQLParser::CatalogSchemaParentAndNameContext *context) = 0;

    virtual std::any visitRelativeCatalogSchemaReference(GQLParser::RelativeCatalogSchemaReferenceContext *context) = 0;

    virtual std::any visitAbsoluteDirectoryPath(GQLParser::AbsoluteDirectoryPathContext *context) = 0;

    virtual std::any visitRelativeDirectoryPath(GQLParser::RelativeDirectoryPathContext *context) = 0;

    virtual std::any visitSimpleDirectoryPath(GQLParser::SimpleDirectoryPathContext *context) = 0;

    virtual std::any visitGraphReference(GQLParser::GraphReferenceContext *context) = 0;

    virtual std::any visitCatalogGraphParentAndName(GQLParser::CatalogGraphParentAndNameContext *context) = 0;

    virtual std::any visitGraphTypeReference(GQLParser::GraphTypeReferenceContext *context) = 0;

    virtual std::any visitCatalogGraphTypeParentAndName(GQLParser::CatalogGraphTypeParentAndNameContext *context) = 0;

    virtual std::any visitBindingTableReference(GQLParser::BindingTableReferenceContext *context) = 0;

    virtual std::any visitProcedureReference(GQLParser::ProcedureReferenceContext *context) = 0;

    virtual std::any visitCatalogObjectParentReference(GQLParser::CatalogObjectParentReferenceContext *context) = 0;

    virtual std::any visitNestedGraphTypeSpecification(GQLParser::NestedGraphTypeSpecificationContext *context) = 0;

    virtual std::any visitElementTypeSpecification(GQLParser::ElementTypeSpecificationContext *context) = 0;

    virtual std::any visitNodeTypeSpecification(GQLParser::NodeTypeSpecificationContext *context) = 0;

    virtual std::any visitNodeTypePhraseFiller(GQLParser::NodeTypePhraseFillerContext *context) = 0;

    virtual std::any visitNodeTypeFiller(GQLParser::NodeTypeFillerContext *context) = 0;

    virtual std::any visitNodeTypeImpliedContent(GQLParser::NodeTypeImpliedContentContext *context) = 0;

    virtual std::any visitEdgeTypeSpecification(GQLParser::EdgeTypeSpecificationContext *context) = 0;

    virtual std::any visitEdgeTypePhraseFiller(GQLParser::EdgeTypePhraseFillerContext *context) = 0;

    virtual std::any visitEdgeTypeFiller(GQLParser::EdgeTypeFillerContext *context) = 0;

    virtual std::any visitEdgeTypeImpliedContent(GQLParser::EdgeTypeImpliedContentContext *context) = 0;

    virtual std::any visitEdgeTypePatternDirected(GQLParser::EdgeTypePatternDirectedContext *context) = 0;

    virtual std::any visitEdgeTypePatternUndirected(GQLParser::EdgeTypePatternUndirectedContext *context) = 0;

    virtual std::any visitArcTypePointingRight(GQLParser::ArcTypePointingRightContext *context) = 0;

    virtual std::any visitArcTypePointingLeft(GQLParser::ArcTypePointingLeftContext *context) = 0;

    virtual std::any visitArcTypeUndirected(GQLParser::ArcTypeUndirectedContext *context) = 0;

    virtual std::any visitSourceNodeTypeReference(GQLParser::SourceNodeTypeReferenceContext *context) = 0;

    virtual std::any visitDestinationNodeTypeReference(GQLParser::DestinationNodeTypeReferenceContext *context) = 0;

    virtual std::any visitEdgeKind(GQLParser::EdgeKindContext *context) = 0;

    virtual std::any visitEndpointPairPhrase(GQLParser::EndpointPairPhraseContext *context) = 0;

    virtual std::any visitEndpointPair(GQLParser::EndpointPairContext *context) = 0;

    virtual std::any visitLabelSetPhrase(GQLParser::LabelSetPhraseContext *context) = 0;

    virtual std::any visitLabelSetSpecification(GQLParser::LabelSetSpecificationContext *context) = 0;

    virtual std::any visitPropertyTypesSpecification(GQLParser::PropertyTypesSpecificationContext *context) = 0;

    virtual std::any visitPropertyValueType(GQLParser::PropertyValueTypeContext *context) = 0;

    virtual std::any visitBindingTableType(GQLParser::BindingTableTypeContext *context) = 0;

    virtual std::any visitDynamicPropertyValueTypeLabel(GQLParser::DynamicPropertyValueTypeLabelContext *context) = 0;

    virtual std::any visitClosedDynamicUnionTypeAtl1(GQLParser::ClosedDynamicUnionTypeAtl1Context *context) = 0;

    virtual std::any visitClosedDynamicUnionTypeAtl2(GQLParser::ClosedDynamicUnionTypeAtl2Context *context) = 0;

    virtual std::any visitPathValueTypeLabel(GQLParser::PathValueTypeLabelContext *context) = 0;

    virtual std::any visitListValueTypeAlt3(GQLParser::ListValueTypeAlt3Context *context) = 0;

    virtual std::any visitListValueTypeAlt2(GQLParser::ListValueTypeAlt2Context *context) = 0;

    virtual std::any visitListValueTypeAlt1(GQLParser::ListValueTypeAlt1Context *context) = 0;

    virtual std::any visitPredefinedTypeLabel(GQLParser::PredefinedTypeLabelContext *context) = 0;

    virtual std::any visitRecordTypeLabel(GQLParser::RecordTypeLabelContext *context) = 0;

    virtual std::any visitOpenDynamicUnionTypeLabel(GQLParser::OpenDynamicUnionTypeLabelContext *context) = 0;

    virtual std::any visitTyped(GQLParser::TypedContext *context) = 0;

    virtual std::any visitPredefinedType(GQLParser::PredefinedTypeContext *context) = 0;

    virtual std::any visitBooleanType(GQLParser::BooleanTypeContext *context) = 0;

    virtual std::any visitCharacterStringType(GQLParser::CharacterStringTypeContext *context) = 0;

    virtual std::any visitByteStringType(GQLParser::ByteStringTypeContext *context) = 0;

    virtual std::any visitMinLength(GQLParser::MinLengthContext *context) = 0;

    virtual std::any visitMaxLength(GQLParser::MaxLengthContext *context) = 0;

    virtual std::any visitFixedLength(GQLParser::FixedLengthContext *context) = 0;

    virtual std::any visitNumericType(GQLParser::NumericTypeContext *context) = 0;

    virtual std::any visitExactNumericType(GQLParser::ExactNumericTypeContext *context) = 0;

    virtual std::any visitBinaryExactNumericType(GQLParser::BinaryExactNumericTypeContext *context) = 0;

    virtual std::any visitSignedBinaryExactNumericType(GQLParser::SignedBinaryExactNumericTypeContext *context) = 0;

    virtual std::any visitUnsignedBinaryExactNumericType(GQLParser::UnsignedBinaryExactNumericTypeContext *context) = 0;

    virtual std::any visitVerboseBinaryExactNumericType(GQLParser::VerboseBinaryExactNumericTypeContext *context) = 0;

    virtual std::any visitDecimalExactNumericType(GQLParser::DecimalExactNumericTypeContext *context) = 0;

    virtual std::any visitPrecision(GQLParser::PrecisionContext *context) = 0;

    virtual std::any visitScale(GQLParser::ScaleContext *context) = 0;

    virtual std::any visitApproximateNumericType(GQLParser::ApproximateNumericTypeContext *context) = 0;

    virtual std::any visitTemporalType(GQLParser::TemporalTypeContext *context) = 0;

    virtual std::any visitTemporalInstantType(GQLParser::TemporalInstantTypeContext *context) = 0;

    virtual std::any visitDatetimeType(GQLParser::DatetimeTypeContext *context) = 0;

    virtual std::any visitLocaldatetimeType(GQLParser::LocaldatetimeTypeContext *context) = 0;

    virtual std::any visitDateType(GQLParser::DateTypeContext *context) = 0;

    virtual std::any visitTimeType(GQLParser::TimeTypeContext *context) = 0;

    virtual std::any visitLocaltimeType(GQLParser::LocaltimeTypeContext *context) = 0;

    virtual std::any visitTemporalDurationType(GQLParser::TemporalDurationTypeContext *context) = 0;

    virtual std::any visitReferenceValueType(GQLParser::ReferenceValueTypeContext *context) = 0;

    virtual std::any visitImmaterialValueType(GQLParser::ImmaterialValueTypeContext *context) = 0;

    virtual std::any visitGraphReferenceValueType(GQLParser::GraphReferenceValueTypeContext *context) = 0;

    virtual std::any visitBindingTableReferenceValueType(GQLParser::BindingTableReferenceValueTypeContext *context) = 0;

    virtual std::any visitNodeReferenceValueType(GQLParser::NodeReferenceValueTypeContext *context) = 0;

    virtual std::any visitEdgeReferenceValueType(GQLParser::EdgeReferenceValueTypeContext *context) = 0;

    virtual std::any visitPathValueType(GQLParser::PathValueTypeContext *context) = 0;

    virtual std::any visitListValueTypeName(GQLParser::ListValueTypeNameContext *context) = 0;

    virtual std::any visitRecordType(GQLParser::RecordTypeContext *context) = 0;

    virtual std::any visitFieldTypesSpecification(GQLParser::FieldTypesSpecificationContext *context) = 0;

    virtual std::any visitNotNull(GQLParser::NotNullContext *context) = 0;

    virtual std::any visitSearchCondition(GQLParser::SearchConditionContext *context) = 0;

    virtual std::any visitPredicate(GQLParser::PredicateContext *context) = 0;

    virtual std::any visitCompOp(GQLParser::CompOpContext *context) = 0;

    virtual std::any visitConjunctiveExprAlt(GQLParser::ConjunctiveExprAltContext *context) = 0;

    virtual std::any visitPropertyGraphExprAlt(GQLParser::PropertyGraphExprAltContext *context) = 0;

    virtual std::any visitMultDivExprAlt(GQLParser::MultDivExprAltContext *context) = 0;

    virtual std::any visitBindingTableExprAlt(GQLParser::BindingTableExprAltContext *context) = 0;

    virtual std::any visitInExprAlt(GQLParser::InExprAltContext *context) = 0;

    virtual std::any visitSignedExprAlt(GQLParser::SignedExprAltContext *context) = 0;

    virtual std::any visitIsNotExprAlt(GQLParser::IsNotExprAltContext *context) = 0;

    virtual std::any visitNormalizedPredicateExprAlt(GQLParser::NormalizedPredicateExprAltContext *context) = 0;

    virtual std::any visitNotExprAlt(GQLParser::NotExprAltContext *context) = 0;

    virtual std::any visitValueFunctionExprAlt(GQLParser::ValueFunctionExprAltContext *context) = 0;

    virtual std::any visitConcatenationExprAlt(GQLParser::ConcatenationExprAltContext *context) = 0;

    virtual std::any visitDisjunctiveExprAlt(GQLParser::DisjunctiveExprAltContext *context) = 0;

    virtual std::any visitComparisonExprAlt(GQLParser::ComparisonExprAltContext *context) = 0;

    virtual std::any visitPrimaryExprAlt(GQLParser::PrimaryExprAltContext *context) = 0;

    virtual std::any visitAddSubtractExprAlt(GQLParser::AddSubtractExprAltContext *context) = 0;

    virtual std::any visitPredicateExprAlt(GQLParser::PredicateExprAltContext *context) = 0;

    virtual std::any visitValueFunction(GQLParser::ValueFunctionContext *context) = 0;

    virtual std::any visitBooleanValueExpression(GQLParser::BooleanValueExpressionContext *context) = 0;

    virtual std::any visitCharacterOrByteStringFunction(GQLParser::CharacterOrByteStringFunctionContext *context) = 0;

    virtual std::any visitAggregatingValueExpression(GQLParser::AggregatingValueExpressionContext *context) = 0;

    virtual std::any visitValueExpressionPrimary(GQLParser::ValueExpressionPrimaryContext *context) = 0;

    virtual std::any visitParenthesizedValueExpression(GQLParser::ParenthesizedValueExpressionContext *context) = 0;

    virtual std::any visitNonParenthesizedValueExpressionPrimarySpecialCase(GQLParser::NonParenthesizedValueExpressionPrimarySpecialCaseContext *context) = 0;

    virtual std::any visitUnsignedValueSpecification(GQLParser::UnsignedValueSpecificationContext *context) = 0;

    virtual std::any visitNonNegativeIntegerSpecification(GQLParser::NonNegativeIntegerSpecificationContext *context) = 0;

    virtual std::any visitCaseExpression(GQLParser::CaseExpressionContext *context) = 0;

    virtual std::any visitSimpleWhenClause(GQLParser::SimpleWhenClauseContext *context) = 0;

    virtual std::any visitSearchedWhenClause(GQLParser::SearchedWhenClauseContext *context) = 0;

    virtual std::any visitElseClause(GQLParser::ElseClauseContext *context) = 0;

    virtual std::any visitCaseOperand(GQLParser::CaseOperandContext *context) = 0;

    virtual std::any visitWhenOperand(GQLParser::WhenOperandContext *context) = 0;

    virtual std::any visitResult(GQLParser::ResultContext *context) = 0;

    virtual std::any visitAggregateFunction(GQLParser::AggregateFunctionContext *context) = 0;

    virtual std::any visitSetQuantifier(GQLParser::SetQuantifierContext *context) = 0;

    virtual std::any visitBindingVariableReference(GQLParser::BindingVariableReferenceContext *context) = 0;

    virtual std::any visitElementVariableReference(GQLParser::ElementVariableReferenceContext *context) = 0;

    virtual std::any visitPathValueExpression(GQLParser::PathValueExpressionContext *context) = 0;

    virtual std::any visitPathValueConstructor(GQLParser::PathValueConstructorContext *context) = 0;

    virtual std::any visitListValueExpression(GQLParser::ListValueExpressionContext *context) = 0;

    virtual std::any visitListValueFunction(GQLParser::ListValueFunctionContext *context) = 0;

    virtual std::any visitListValueConstructor(GQLParser::ListValueConstructorContext *context) = 0;

    virtual std::any visitRecordConstructor(GQLParser::RecordConstructorContext *context) = 0;

    virtual std::any visitTruthValue(GQLParser::TruthValueContext *context) = 0;

    virtual std::any visitNumericValueExpression(GQLParser::NumericValueExpressionContext *context) = 0;

    virtual std::any visitNumericValueFunction(GQLParser::NumericValueFunctionContext *context) = 0;

    virtual std::any visitCharacterStringValueExpression(GQLParser::CharacterStringValueExpressionContext *context) = 0;

    virtual std::any visitByteStringValueExpression(GQLParser::ByteStringValueExpressionContext *context) = 0;

    virtual std::any visitTrimOperands(GQLParser::TrimOperandsContext *context) = 0;

    virtual std::any visitStringLength(GQLParser::StringLengthContext *context) = 0;

    virtual std::any visitDatetimeValueExpression(GQLParser::DatetimeValueExpressionContext *context) = 0;

    virtual std::any visitDatetimeValueFunction(GQLParser::DatetimeValueFunctionContext *context) = 0;

    virtual std::any visitDurationValueExpression(GQLParser::DurationValueExpressionContext *context) = 0;

    virtual std::any visitDatetimeSubtraction(GQLParser::DatetimeSubtractionContext *context) = 0;

    virtual std::any visitDurationValueFunction(GQLParser::DurationValueFunctionContext *context) = 0;

    virtual std::any visitObjectName(GQLParser::ObjectNameContext *context) = 0;

    virtual std::any visitObjectNameOrBindingVariable(GQLParser::ObjectNameOrBindingVariableContext *context) = 0;

    virtual std::any visitDirectoryName(GQLParser::DirectoryNameContext *context) = 0;

    virtual std::any visitSchemaName(GQLParser::SchemaNameContext *context) = 0;

    virtual std::any visitGraphName(GQLParser::GraphNameContext *context) = 0;

    virtual std::any visitDelimitedGraphName(GQLParser::DelimitedGraphNameContext *context) = 0;

    virtual std::any visitGraphTypeName(GQLParser::GraphTypeNameContext *context) = 0;

    virtual std::any visitNodeTypeName(GQLParser::NodeTypeNameContext *context) = 0;

    virtual std::any visitEdgeTypeName(GQLParser::EdgeTypeNameContext *context) = 0;

    virtual std::any visitBindingTableName(GQLParser::BindingTableNameContext *context) = 0;

    virtual std::any visitDelimitedBindingTableName(GQLParser::DelimitedBindingTableNameContext *context) = 0;

    virtual std::any visitProcedureName(GQLParser::ProcedureNameContext *context) = 0;

    virtual std::any visitLabelName(GQLParser::LabelNameContext *context) = 0;

    virtual std::any visitPropertyName(GQLParser::PropertyNameContext *context) = 0;

    virtual std::any visitFieldName(GQLParser::FieldNameContext *context) = 0;

    virtual std::any visitElementVariable(GQLParser::ElementVariableContext *context) = 0;

    virtual std::any visitPathVariable(GQLParser::PathVariableContext *context) = 0;

    virtual std::any visitSubpathVariable(GQLParser::SubpathVariableContext *context) = 0;

    virtual std::any visitBindingVariable(GQLParser::BindingVariableContext *context) = 0;

    virtual std::any visitUnsignedLiteral(GQLParser::UnsignedLiteralContext *context) = 0;

    virtual std::any visitGeneralLiteral(GQLParser::GeneralLiteralContext *context) = 0;

    virtual std::any visitTemporalLiteral(GQLParser::TemporalLiteralContext *context) = 0;

    virtual std::any visitListLiteral(GQLParser::ListLiteralContext *context) = 0;

    virtual std::any visitRecordLiteral(GQLParser::RecordLiteralContext *context) = 0;

    virtual std::any visitIdentifier(GQLParser::IdentifierContext *context) = 0;

    virtual std::any visitRegularIdentifier(GQLParser::RegularIdentifierContext *context) = 0;

    virtual std::any visitTimeZoneString(GQLParser::TimeZoneStringContext *context) = 0;

    virtual std::any visitCharacterStringLiteral(GQLParser::CharacterStringLiteralContext *context) = 0;

    virtual std::any visitUnsignedNumericLiteral(GQLParser::UnsignedNumericLiteralContext *context) = 0;

    virtual std::any visitExactNumericLiteral(GQLParser::ExactNumericLiteralContext *context) = 0;

    virtual std::any visitApproximateNumericLiteral(GQLParser::ApproximateNumericLiteralContext *context) = 0;

    virtual std::any visitUnsignedInteger(GQLParser::UnsignedIntegerContext *context) = 0;

    virtual std::any visitUnsignedDecimalInteger(GQLParser::UnsignedDecimalIntegerContext *context) = 0;

    virtual std::any visitNullLiteral(GQLParser::NullLiteralContext *context) = 0;

    virtual std::any visitDateString(GQLParser::DateStringContext *context) = 0;

    virtual std::any visitTimeString(GQLParser::TimeStringContext *context) = 0;

    virtual std::any visitDatetimeString(GQLParser::DatetimeStringContext *context) = 0;

    virtual std::any visitDurationLiteral(GQLParser::DurationLiteralContext *context) = 0;

    virtual std::any visitDurationString(GQLParser::DurationStringContext *context) = 0;

    virtual std::any visitNodeSynonym(GQLParser::NodeSynonymContext *context) = 0;

    virtual std::any visitEdgesSynonym(GQLParser::EdgesSynonymContext *context) = 0;

    virtual std::any visitEdgeSynonym(GQLParser::EdgeSynonymContext *context) = 0;

    virtual std::any visitNonReservedWords(GQLParser::NonReservedWordsContext *context) = 0;


};

