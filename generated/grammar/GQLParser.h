
// Generated from grammar/GQL.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  GQLParser : public antlr4::Parser {
public:
  enum {
    IMPLIES = 1, BOOLEAN_LITERAL = 2, SINGLE_QUOTED_CHARACTER_SEQUENCE = 3, 
    DOUBLE_QUOTED_CHARACTER_SEQUENCE = 4, ACCENT_QUOTED_CHARACTER_SEQUENCE = 5, 
    NO_ESCAPE = 6, BYTE_STRING_LITERAL = 7, UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_EXACT_NUMBER_SUFFIX = 8, 
    UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITHOUT_SUFFIX = 9, UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX = 10, 
    UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_EXACT_NUMBER_SUFFIX = 11, UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITHOUT_SUFFIX = 12, 
    UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX = 13, 
    UNSIGNED_DECIMAL_INTEGER_WITH_EXACT_NUMBER_SUFFIX = 14, UNSIGNED_DECIMAL_INTEGER_WITH_APPROXIMATE_NUMBER_SUFFIX = 15, 
    UNSIGNED_DECIMAL_INTEGER = 16, UNSIGNED_HEXADECIMAL_INTEGER = 17, UNSIGNED_OCTAL_INTEGER = 18, 
    UNSIGNED_BINARY_INTEGER = 19, ABS = 20, ACOS = 21, ALL = 22, ALL_DIFFERENT = 23, 
    AND = 24, ANY = 25, ARRAY = 26, AS = 27, ASC = 28, ASCENDING = 29, ASIN = 30, 
    AT = 31, ATAN = 32, AVG = 33, BIG = 34, BIGINT = 35, BINARY = 36, BOOL = 37, 
    BOOLEAN = 38, BOTH = 39, BTRIM = 40, BY = 41, BYTE_LENGTH = 42, BYTES = 43, 
    CALL = 44, CARDINALITY = 45, CASE = 46, CAST = 47, CEIL = 48, CEILING = 49, 
    CHAR = 50, CHAR_LENGTH = 51, CHARACTER_LENGTH = 52, CHARACTERISTICS = 53, 
    CLOSE = 54, COALESCE = 55, COLLECT_LIST = 56, COMMIT = 57, COPY = 58, 
    COS = 59, COSH = 60, COT = 61, COUNT = 62, CREATE = 63, CURRENT_DATE = 64, 
    CURRENT_GRAPH = 65, CURRENT_PROPERTY_GRAPH = 66, CURRENT_SCHEMA = 67, 
    CURRENT_TIME = 68, CURRENT_TIMESTAMP = 69, DATE = 70, DATETIME = 71, 
    DAY = 72, DEC = 73, DECIMAL = 74, DEGREES = 75, DELETE = 76, DESC = 77, 
    DESCENDING = 78, DETACH = 79, DISTINCT = 80, DOUBLE = 81, DROP = 82, 
    DURATION = 83, DURATION_BETWEEN = 84, ELEMENT_ID = 85, ELSE = 86, END = 87, 
    EXCEPT = 88, EXISTS = 89, EXP = 90, FILTER = 91, FINISH = 92, FLOAT = 93, 
    FLOAT16 = 94, FLOAT32 = 95, FLOAT64 = 96, FLOAT128 = 97, FLOAT256 = 98, 
    FLOOR = 99, FOR = 100, FROM = 101, GROUP = 102, HAVING = 103, HOME_GRAPH = 104, 
    HOME_PROPERTY_GRAPH = 105, HOME_SCHEMA = 106, HOUR = 107, IF = 108, 
    IN = 109, INSERT = 110, INT = 111, INTEGER = 112, INT8 = 113, INTEGER8 = 114, 
    INT16 = 115, INTEGER16 = 116, INT32 = 117, INTEGER32 = 118, INT64 = 119, 
    INTEGER64 = 120, INT128 = 121, INTEGER128 = 122, INT256 = 123, INTEGER256 = 124, 
    INTERSECT = 125, INTERVAL = 126, IS = 127, LEADING = 128, LEFT = 129, 
    LET = 130, LIKE = 131, LIMIT = 132, LIST = 133, LN = 134, LOCAL = 135, 
    LOCAL_DATETIME = 136, LOCAL_TIME = 137, LOCAL_TIMESTAMP = 138, LOG_KW = 139, 
    LOG10 = 140, LOWER = 141, LTRIM = 142, MATCH = 143, MAX = 144, MIN = 145, 
    MINUTE = 146, MOD = 147, MONTH = 148, NEXT = 149, NODETACH = 150, NORMALIZE = 151, 
    NOT = 152, NOTHING = 153, NULL_KW = 154, NULLS = 155, NULLIF = 156, 
    OCTET_LENGTH = 157, OF = 158, OFFSET = 159, OPTIONAL = 160, OR = 161, 
    ORDER = 162, OTHERWISE = 163, PARAMETER = 164, PARAMETERS = 165, PATH = 166, 
    PATH_LENGTH = 167, PATHS = 168, PERCENTILE_CONT = 169, PERCENTILE_DISC = 170, 
    POWER = 171, PRECISION = 172, PROPERTY_EXISTS = 173, RADIANS = 174, 
    REAL = 175, RECORD = 176, REMOVE = 177, REPLACE = 178, RESET = 179, 
    RETURN = 180, RIGHT = 181, ROLLBACK = 182, RTRIM = 183, SAME = 184, 
    SCHEMA = 185, SECOND = 186, SELECT = 187, SESSION = 188, SESSION_USER = 189, 
    SET = 190, SIGNED = 191, SIN = 192, SINH = 193, SIZE = 194, SKIP_RESERVED_WORD = 195, 
    SMALL = 196, SMALLINT = 197, SQRT = 198, START = 199, STDDEV_POP = 200, 
    STDDEV_SAMP = 201, STRING = 202, SUM = 203, TAN = 204, TANH = 205, THEN = 206, 
    TIME = 207, TIMESTAMP = 208, TRAILING = 209, TRIM = 210, TYPED = 211, 
    UBIGINT = 212, UINT = 213, UINT8 = 214, UINT16 = 215, UINT32 = 216, 
    UINT64 = 217, UINT128 = 218, UINT256 = 219, UNION = 220, UNSIGNED = 221, 
    UPPER = 222, USE = 223, USMALLINT = 224, VALUE = 225, VARBINARY = 226, 
    VARCHAR = 227, VARIABLE = 228, WHEN = 229, WHERE = 230, WITH = 231, 
    XOR = 232, YEAR = 233, YIELD = 234, ZONED = 235, ZONED_DATETIME = 236, 
    ZONED_TIME = 237, ABSTRACT = 238, AGGREGATE = 239, AGGREGATES = 240, 
    ALTER = 241, CATALOG = 242, CLEAR = 243, CLONE = 244, CONSTRAINT = 245, 
    CURRENT_ROLE = 246, CURRENT_USER = 247, DATA = 248, DIRECTORY = 249, 
    DRYRUN = 250, EXACT = 251, EXISTING = 252, FUNCTION = 253, GQLSTATUS = 254, 
    GRANT = 255, INSTANT = 256, INFINITY_KW = 257, NUMBER = 258, NUMERIC = 259, 
    ON = 260, OPEN = 261, PARTITION = 262, PROCEDURE = 263, PRODUCT = 264, 
    PROJECT = 265, QUERY = 266, RECORDS = 267, REFERENCE = 268, RENAME = 269, 
    REVOKE = 270, SUBSTRING = 271, SYSTEM_USER = 272, TEMPORAL = 273, UNIQUE = 274, 
    UNIT = 275, VALUES = 276, ACYCLIC = 277, BINDING = 278, BINDINGS = 279, 
    CONNECTING = 280, DESTINATION = 281, DIFFERENT = 282, DIRECTED = 283, 
    EDGE = 284, EDGES = 285, ELEMENT = 286, ELEMENTS = 287, FIRST = 288, 
    GRAPH = 289, GROUPS = 290, KEEP = 291, LABEL = 292, LABELED = 293, LABELS = 294, 
    LAST = 295, NFC = 296, NFD = 297, NFKC = 298, NFKD = 299, NO = 300, 
    NODE = 301, NORMALIZED = 302, ONLY = 303, ORDINALITY = 304, PROPERTY = 305, 
    READ = 306, RELATIONSHIP = 307, RELATIONSHIPS = 308, REPEATABLE = 309, 
    SHORTEST = 310, SIMPLE = 311, SOURCE = 312, TABLE = 313, TO = 314, TRAIL = 315, 
    TRANSACTION = 316, TYPE = 317, UNDIRECTED = 318, VERTEX = 319, WALK = 320, 
    WITHOUT = 321, WRITE = 322, ZONE = 323, REGULAR_IDENTIFIER = 324, SUBSTITUTED_PARAMETER_REFERENCE = 325, 
    GENERAL_PARAMETER_REFERENCE = 326, MULTISET_ALTERNATION_OPERATOR = 327, 
    BRACKET_RIGHT_ARROW = 328, BRACKET_TILDE_RIGHT_ARROW = 329, CONCATENATION_OPERATOR = 330, 
    DOUBLE_COLON = 331, DOUBLE_DOLLAR_SIGN = 332, DOUBLE_PERIOD = 333, GREATER_THAN_OR_EQUALS_OPERATOR = 334, 
    LEFT_ARROW = 335, LEFT_ARROW_TILDE = 336, LEFT_ARROW_BRACKET = 337, 
    LEFT_ARROW_TILDE_BRACKET = 338, LEFT_MINUS_RIGHT = 339, LEFT_MINUS_SLASH = 340, 
    LEFT_TILDE_SLASH = 341, LESS_THAN_OR_EQUALS_OPERATOR = 342, MINUS_LEFT_BRACKET = 343, 
    MINUS_SLASH = 344, NOT_EQUALS_OPERATOR = 345, RIGHT_ARROW = 346, RIGHT_BRACKET_MINUS = 347, 
    RIGHT_BRACKET_TILDE = 348, RIGHT_DOUBLE_ARROW = 349, SLASH_MINUS = 350, 
    SLASH_MINUS_RIGHT = 351, SLASH_TILDE = 352, SLASH_TILDE_RIGHT = 353, 
    TILDE_LEFT_BRACKET = 354, TILDE_RIGHT_ARROW = 355, TILDE_SLASH = 356, 
    AMPERSAND = 357, ASTERISK = 358, COLON = 359, COMMA = 360, COMMERCIAL_AT = 361, 
    DOLLAR_SIGN = 362, DOUBLE_QUOTE = 363, EQUALS_OPERATOR = 364, EXCLAMATION_MARK = 365, 
    RIGHT_ANGLE_BRACKET = 366, GRAVE_ACCENT = 367, LEFT_BRACE = 368, LEFT_BRACKET = 369, 
    LEFT_PAREN = 370, LEFT_ANGLE_BRACKET = 371, MINUS_SIGN = 372, PERCENT = 373, 
    PERIOD = 374, PLUS_SIGN = 375, QUESTION_MARK = 376, QUOTE = 377, REVERSE_SOLIDUS = 378, 
    RIGHT_BRACE = 379, RIGHT_BRACKET = 380, RIGHT_PAREN = 381, SOLIDUS = 382, 
    TILDE = 383, UNDERSCORE = 384, VERTICAL_BAR = 385, SEMICOLON = 386, 
    SP = 387, WHITESPACE = 388, BRACKETED_COMMENT = 389, SIMPLE_COMMENT_SOLIDUS = 390, 
    SIMPLE_COMMENT_MINUS = 391
  };

  enum {
    RuleGqlProgram = 0, RuleProgramActivity = 1, RuleSessionActivity = 2, 
    RuleTransactionActivity = 3, RuleSessionSetCommand = 4, RuleSessionSetSchemaClause = 5, 
    RuleSessionSetGraphClause = 6, RuleSessionSetTimeZoneClause = 7, RuleSessionSetParameterClause = 8, 
    RuleSessionResetCommand = 9, RuleStartTransactionCommand = 10, RuleTransactionAccessMode = 11, 
    RuleNestedProcedureSpecification = 12, RuleProcedureBody = 13, RuleStatementBlock = 14, 
    RuleStatement = 15, RuleNextStatement = 16, RuleBindingVariableDefinition = 17, 
    RuleGraphExpression = 18, RuleBindingTableExpression = 19, RuleLinearCatalogModifyingStatement = 20, 
    RulePrimitiveCatalogModifyingStatement = 21, RuleOpenGraphType = 22, 
    RuleOfGraphType = 23, RuleGraphTypeSource = 24, RuleGraphSource = 25, 
    RuleLinearDataModifyingStatement = 26, RuleFocusedLinearDataModifyingStatement = 27, 
    RuleAmbientLinearDataModifyingStatement = 28, RuleSimpleDataAccessingStatement = 29, 
    RulePrimitiveDataModifyingStatement = 30, RuleSetItem = 31, RuleRemoveItem = 32, 
    RuleCompositeQueryStatement = 33, RuleCompositeQueryExpression = 34, 
    RuleQueryConjunction = 35, RuleLinearQueryStatement = 36, RuleFocusedLinearQueryStatement = 37, 
    RuleAmbientLinearQueryStatement = 38, RuleNestedQuerySpecification = 39, 
    RuleSimpleQueryStatement = 40, RulePrimitiveQueryStatement = 41, RuleMatchStatement = 42, 
    RuleLetVariableDefinition = 43, RuleOrderByAndPageStatement = 44, RulePrimitiveResultStatement = 45, 
    RuleReturnItem = 46, RuleSelectStatement = 47, RuleSelectItem = 48, 
    RuleHavingClause = 49, RuleSelectStatementBody = 50, RuleSelectGraphMatch = 51, 
    RuleSelectQuerySpecification = 52, RuleCallProcedureStatement = 53, 
    RuleProcedureCall = 54, RuleAtSchemaClause = 55, RuleUseGraphClause = 56, 
    RuleGraphPatternBindingTable = 57, RuleGraphPattern = 58, RuleMatchMode = 59, 
    RulePathPattern = 60, RuleKeepClause = 61, RuleInsertGraphPattern = 62, 
    RuleInsertPathPattern = 63, RuleInsertNodePattern = 64, RuleInsertEdgePattern = 65, 
    RuleInsertElementPatternFiller = 66, RuleLabelAndPropertySetSpecification = 67, 
    RulePathPatternPrefix = 68, RulePathModePrefix = 69, RulePathSearchPrefix = 70, 
    RuleShortestPathSearch = 71, RulePathPatternExpression = 72, RulePathTerm = 73, 
    RulePathFactor = 74, RulePathPrimary = 75, RuleElementPattern = 76, 
    RuleElementPatternFiller = 77, RuleElementVariableDeclaration = 78, 
    RuleIsLabelExpression = 79, RuleIsOrColon = 80, RuleElementPatternPredicate = 81, 
    RuleElementPropertySpecification = 82, RulePropertyKeyValuePairList = 83, 
    RulePropertyKeyValuePair = 84, RuleFullEdgePattern = 85, RuleAbbreviatedEdgePattern = 86, 
    RuleParenthesizedPathPatternExpression = 87, RuleLabelExpression = 88, 
    RuleGraphPatternQuantifier = 89, RuleSimplifiedPathPatternExpression = 90, 
    RuleSimplifiedContents = 91, RuleSimplifiedTerm = 92, RuleSimplifiedFactorLow = 93, 
    RuleSimplifiedFactorHigh = 94, RuleSimplifiedTertiary = 95, RuleSimplifiedSecondary = 96, 
    RuleSimplifiedPrimary = 97, RuleWhereClause = 98, RuleYieldClause = 99, 
    RuleYieldItem = 100, RuleGroupByClause = 101, RuleOrderByClause = 102, 
    RuleSortSpecification = 103, RuleLimitClause = 104, RuleOffsetClause = 105, 
    RuleSchemaReference = 106, RuleAbsoluteCatalogSchemaReference = 107, 
    RuleCatalogSchemaParentAndName = 108, RuleRelativeCatalogSchemaReference = 109, 
    RuleAbsoluteDirectoryPath = 110, RuleRelativeDirectoryPath = 111, RuleSimpleDirectoryPath = 112, 
    RuleGraphReference = 113, RuleCatalogGraphParentAndName = 114, RuleGraphTypeReference = 115, 
    RuleCatalogGraphTypeParentAndName = 116, RuleBindingTableReference = 117, 
    RuleProcedureReference = 118, RuleCatalogObjectParentReference = 119, 
    RuleNestedGraphTypeSpecification = 120, RuleElementTypeSpecification = 121, 
    RuleNodeTypeSpecification = 122, RuleNodeTypePhraseFiller = 123, RuleNodeTypeFiller = 124, 
    RuleNodeTypeImpliedContent = 125, RuleEdgeTypeSpecification = 126, RuleEdgeTypePhraseFiller = 127, 
    RuleEdgeTypeFiller = 128, RuleEdgeTypeImpliedContent = 129, RuleEdgeTypePatternDirected = 130, 
    RuleEdgeTypePatternUndirected = 131, RuleArcTypePointingRight = 132, 
    RuleArcTypePointingLeft = 133, RuleArcTypeUndirected = 134, RuleSourceNodeTypeReference = 135, 
    RuleDestinationNodeTypeReference = 136, RuleEdgeKind = 137, RuleEndpointPairPhrase = 138, 
    RuleEndpointPair = 139, RuleLabelSetPhrase = 140, RuleLabelSetSpecification = 141, 
    RulePropertyTypesSpecification = 142, RulePropertyValueType = 143, RuleBindingTableType = 144, 
    RuleValueType = 145, RuleTyped = 146, RulePredefinedType = 147, RuleBooleanType = 148, 
    RuleCharacterStringType = 149, RuleByteStringType = 150, RuleMinLength = 151, 
    RuleMaxLength = 152, RuleFixedLength = 153, RuleNumericType = 154, RuleExactNumericType = 155, 
    RuleBinaryExactNumericType = 156, RuleSignedBinaryExactNumericType = 157, 
    RuleUnsignedBinaryExactNumericType = 158, RuleVerboseBinaryExactNumericType = 159, 
    RuleDecimalExactNumericType = 160, RulePrecision = 161, RuleScale = 162, 
    RuleApproximateNumericType = 163, RuleTemporalType = 164, RuleTemporalInstantType = 165, 
    RuleDatetimeType = 166, RuleLocaldatetimeType = 167, RuleDateType = 168, 
    RuleTimeType = 169, RuleLocaltimeType = 170, RuleTemporalDurationType = 171, 
    RuleReferenceValueType = 172, RuleImmaterialValueType = 173, RuleGraphReferenceValueType = 174, 
    RuleBindingTableReferenceValueType = 175, RuleNodeReferenceValueType = 176, 
    RuleEdgeReferenceValueType = 177, RulePathValueType = 178, RuleListValueTypeName = 179, 
    RuleRecordType = 180, RuleFieldTypesSpecification = 181, RuleNotNull = 182, 
    RuleSearchCondition = 183, RulePredicate = 184, RuleCompOp = 185, RuleValueExpression = 186, 
    RuleValueFunction = 187, RuleBooleanValueExpression = 188, RuleCharacterOrByteStringFunction = 189, 
    RuleAggregatingValueExpression = 190, RuleValueExpressionPrimary = 191, 
    RuleParenthesizedValueExpression = 192, RuleNonParenthesizedValueExpressionPrimarySpecialCase = 193, 
    RuleUnsignedValueSpecification = 194, RuleNonNegativeIntegerSpecification = 195, 
    RuleCaseExpression = 196, RuleSimpleWhenClause = 197, RuleSearchedWhenClause = 198, 
    RuleElseClause = 199, RuleCaseOperand = 200, RuleWhenOperand = 201, 
    RuleResult = 202, RuleAggregateFunction = 203, RuleSetQuantifier = 204, 
    RuleBindingVariableReference = 205, RuleElementVariableReference = 206, 
    RulePathValueExpression = 207, RulePathValueConstructor = 208, RuleListValueExpression = 209, 
    RuleListValueFunction = 210, RuleListValueConstructor = 211, RuleRecordConstructor = 212, 
    RuleTruthValue = 213, RuleNumericValueExpression = 214, RuleNumericValueFunction = 215, 
    RuleCharacterStringValueExpression = 216, RuleByteStringValueExpression = 217, 
    RuleTrimOperands = 218, RuleStringLength = 219, RuleDatetimeValueExpression = 220, 
    RuleDatetimeValueFunction = 221, RuleDurationValueExpression = 222, 
    RuleDatetimeSubtraction = 223, RuleDurationValueFunction = 224, RuleObjectName = 225, 
    RuleObjectNameOrBindingVariable = 226, RuleDirectoryName = 227, RuleSchemaName = 228, 
    RuleGraphName = 229, RuleDelimitedGraphName = 230, RuleGraphTypeName = 231, 
    RuleNodeTypeName = 232, RuleEdgeTypeName = 233, RuleBindingTableName = 234, 
    RuleDelimitedBindingTableName = 235, RuleProcedureName = 236, RuleLabelName = 237, 
    RulePropertyName = 238, RuleFieldName = 239, RuleElementVariable = 240, 
    RulePathVariable = 241, RuleSubpathVariable = 242, RuleBindingVariable = 243, 
    RuleUnsignedLiteral = 244, RuleGeneralLiteral = 245, RuleTemporalLiteral = 246, 
    RuleListLiteral = 247, RuleRecordLiteral = 248, RuleIdentifier = 249, 
    RuleRegularIdentifier = 250, RuleTimeZoneString = 251, RuleCharacterStringLiteral = 252, 
    RuleUnsignedNumericLiteral = 253, RuleExactNumericLiteral = 254, RuleApproximateNumericLiteral = 255, 
    RuleUnsignedInteger = 256, RuleUnsignedDecimalInteger = 257, RuleNullLiteral = 258, 
    RuleDateString = 259, RuleTimeString = 260, RuleDatetimeString = 261, 
    RuleDurationLiteral = 262, RuleDurationString = 263, RuleNodeSynonym = 264, 
    RuleEdgesSynonym = 265, RuleEdgeSynonym = 266, RuleNonReservedWords = 267
  };

  explicit GQLParser(antlr4::TokenStream *input);

  GQLParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~GQLParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class GqlProgramContext;
  class ProgramActivityContext;
  class SessionActivityContext;
  class TransactionActivityContext;
  class SessionSetCommandContext;
  class SessionSetSchemaClauseContext;
  class SessionSetGraphClauseContext;
  class SessionSetTimeZoneClauseContext;
  class SessionSetParameterClauseContext;
  class SessionResetCommandContext;
  class StartTransactionCommandContext;
  class TransactionAccessModeContext;
  class NestedProcedureSpecificationContext;
  class ProcedureBodyContext;
  class StatementBlockContext;
  class StatementContext;
  class NextStatementContext;
  class BindingVariableDefinitionContext;
  class GraphExpressionContext;
  class BindingTableExpressionContext;
  class LinearCatalogModifyingStatementContext;
  class PrimitiveCatalogModifyingStatementContext;
  class OpenGraphTypeContext;
  class OfGraphTypeContext;
  class GraphTypeSourceContext;
  class GraphSourceContext;
  class LinearDataModifyingStatementContext;
  class FocusedLinearDataModifyingStatementContext;
  class AmbientLinearDataModifyingStatementContext;
  class SimpleDataAccessingStatementContext;
  class PrimitiveDataModifyingStatementContext;
  class SetItemContext;
  class RemoveItemContext;
  class CompositeQueryStatementContext;
  class CompositeQueryExpressionContext;
  class QueryConjunctionContext;
  class LinearQueryStatementContext;
  class FocusedLinearQueryStatementContext;
  class AmbientLinearQueryStatementContext;
  class NestedQuerySpecificationContext;
  class SimpleQueryStatementContext;
  class PrimitiveQueryStatementContext;
  class MatchStatementContext;
  class LetVariableDefinitionContext;
  class OrderByAndPageStatementContext;
  class PrimitiveResultStatementContext;
  class ReturnItemContext;
  class SelectStatementContext;
  class SelectItemContext;
  class HavingClauseContext;
  class SelectStatementBodyContext;
  class SelectGraphMatchContext;
  class SelectQuerySpecificationContext;
  class CallProcedureStatementContext;
  class ProcedureCallContext;
  class AtSchemaClauseContext;
  class UseGraphClauseContext;
  class GraphPatternBindingTableContext;
  class GraphPatternContext;
  class MatchModeContext;
  class PathPatternContext;
  class KeepClauseContext;
  class InsertGraphPatternContext;
  class InsertPathPatternContext;
  class InsertNodePatternContext;
  class InsertEdgePatternContext;
  class InsertElementPatternFillerContext;
  class LabelAndPropertySetSpecificationContext;
  class PathPatternPrefixContext;
  class PathModePrefixContext;
  class PathSearchPrefixContext;
  class ShortestPathSearchContext;
  class PathPatternExpressionContext;
  class PathTermContext;
  class PathFactorContext;
  class PathPrimaryContext;
  class ElementPatternContext;
  class ElementPatternFillerContext;
  class ElementVariableDeclarationContext;
  class IsLabelExpressionContext;
  class IsOrColonContext;
  class ElementPatternPredicateContext;
  class ElementPropertySpecificationContext;
  class PropertyKeyValuePairListContext;
  class PropertyKeyValuePairContext;
  class FullEdgePatternContext;
  class AbbreviatedEdgePatternContext;
  class ParenthesizedPathPatternExpressionContext;
  class LabelExpressionContext;
  class GraphPatternQuantifierContext;
  class SimplifiedPathPatternExpressionContext;
  class SimplifiedContentsContext;
  class SimplifiedTermContext;
  class SimplifiedFactorLowContext;
  class SimplifiedFactorHighContext;
  class SimplifiedTertiaryContext;
  class SimplifiedSecondaryContext;
  class SimplifiedPrimaryContext;
  class WhereClauseContext;
  class YieldClauseContext;
  class YieldItemContext;
  class GroupByClauseContext;
  class OrderByClauseContext;
  class SortSpecificationContext;
  class LimitClauseContext;
  class OffsetClauseContext;
  class SchemaReferenceContext;
  class AbsoluteCatalogSchemaReferenceContext;
  class CatalogSchemaParentAndNameContext;
  class RelativeCatalogSchemaReferenceContext;
  class AbsoluteDirectoryPathContext;
  class RelativeDirectoryPathContext;
  class SimpleDirectoryPathContext;
  class GraphReferenceContext;
  class CatalogGraphParentAndNameContext;
  class GraphTypeReferenceContext;
  class CatalogGraphTypeParentAndNameContext;
  class BindingTableReferenceContext;
  class ProcedureReferenceContext;
  class CatalogObjectParentReferenceContext;
  class NestedGraphTypeSpecificationContext;
  class ElementTypeSpecificationContext;
  class NodeTypeSpecificationContext;
  class NodeTypePhraseFillerContext;
  class NodeTypeFillerContext;
  class NodeTypeImpliedContentContext;
  class EdgeTypeSpecificationContext;
  class EdgeTypePhraseFillerContext;
  class EdgeTypeFillerContext;
  class EdgeTypeImpliedContentContext;
  class EdgeTypePatternDirectedContext;
  class EdgeTypePatternUndirectedContext;
  class ArcTypePointingRightContext;
  class ArcTypePointingLeftContext;
  class ArcTypeUndirectedContext;
  class SourceNodeTypeReferenceContext;
  class DestinationNodeTypeReferenceContext;
  class EdgeKindContext;
  class EndpointPairPhraseContext;
  class EndpointPairContext;
  class LabelSetPhraseContext;
  class LabelSetSpecificationContext;
  class PropertyTypesSpecificationContext;
  class PropertyValueTypeContext;
  class BindingTableTypeContext;
  class ValueTypeContext;
  class TypedContext;
  class PredefinedTypeContext;
  class BooleanTypeContext;
  class CharacterStringTypeContext;
  class ByteStringTypeContext;
  class MinLengthContext;
  class MaxLengthContext;
  class FixedLengthContext;
  class NumericTypeContext;
  class ExactNumericTypeContext;
  class BinaryExactNumericTypeContext;
  class SignedBinaryExactNumericTypeContext;
  class UnsignedBinaryExactNumericTypeContext;
  class VerboseBinaryExactNumericTypeContext;
  class DecimalExactNumericTypeContext;
  class PrecisionContext;
  class ScaleContext;
  class ApproximateNumericTypeContext;
  class TemporalTypeContext;
  class TemporalInstantTypeContext;
  class DatetimeTypeContext;
  class LocaldatetimeTypeContext;
  class DateTypeContext;
  class TimeTypeContext;
  class LocaltimeTypeContext;
  class TemporalDurationTypeContext;
  class ReferenceValueTypeContext;
  class ImmaterialValueTypeContext;
  class GraphReferenceValueTypeContext;
  class BindingTableReferenceValueTypeContext;
  class NodeReferenceValueTypeContext;
  class EdgeReferenceValueTypeContext;
  class PathValueTypeContext;
  class ListValueTypeNameContext;
  class RecordTypeContext;
  class FieldTypesSpecificationContext;
  class NotNullContext;
  class SearchConditionContext;
  class PredicateContext;
  class CompOpContext;
  class ValueExpressionContext;
  class ValueFunctionContext;
  class BooleanValueExpressionContext;
  class CharacterOrByteStringFunctionContext;
  class AggregatingValueExpressionContext;
  class ValueExpressionPrimaryContext;
  class ParenthesizedValueExpressionContext;
  class NonParenthesizedValueExpressionPrimarySpecialCaseContext;
  class UnsignedValueSpecificationContext;
  class NonNegativeIntegerSpecificationContext;
  class CaseExpressionContext;
  class SimpleWhenClauseContext;
  class SearchedWhenClauseContext;
  class ElseClauseContext;
  class CaseOperandContext;
  class WhenOperandContext;
  class ResultContext;
  class AggregateFunctionContext;
  class SetQuantifierContext;
  class BindingVariableReferenceContext;
  class ElementVariableReferenceContext;
  class PathValueExpressionContext;
  class PathValueConstructorContext;
  class ListValueExpressionContext;
  class ListValueFunctionContext;
  class ListValueConstructorContext;
  class RecordConstructorContext;
  class TruthValueContext;
  class NumericValueExpressionContext;
  class NumericValueFunctionContext;
  class CharacterStringValueExpressionContext;
  class ByteStringValueExpressionContext;
  class TrimOperandsContext;
  class StringLengthContext;
  class DatetimeValueExpressionContext;
  class DatetimeValueFunctionContext;
  class DurationValueExpressionContext;
  class DatetimeSubtractionContext;
  class DurationValueFunctionContext;
  class ObjectNameContext;
  class ObjectNameOrBindingVariableContext;
  class DirectoryNameContext;
  class SchemaNameContext;
  class GraphNameContext;
  class DelimitedGraphNameContext;
  class GraphTypeNameContext;
  class NodeTypeNameContext;
  class EdgeTypeNameContext;
  class BindingTableNameContext;
  class DelimitedBindingTableNameContext;
  class ProcedureNameContext;
  class LabelNameContext;
  class PropertyNameContext;
  class FieldNameContext;
  class ElementVariableContext;
  class PathVariableContext;
  class SubpathVariableContext;
  class BindingVariableContext;
  class UnsignedLiteralContext;
  class GeneralLiteralContext;
  class TemporalLiteralContext;
  class ListLiteralContext;
  class RecordLiteralContext;
  class IdentifierContext;
  class RegularIdentifierContext;
  class TimeZoneStringContext;
  class CharacterStringLiteralContext;
  class UnsignedNumericLiteralContext;
  class ExactNumericLiteralContext;
  class ApproximateNumericLiteralContext;
  class UnsignedIntegerContext;
  class UnsignedDecimalIntegerContext;
  class NullLiteralContext;
  class DateStringContext;
  class TimeStringContext;
  class DatetimeStringContext;
  class DurationLiteralContext;
  class DurationStringContext;
  class NodeSynonymContext;
  class EdgesSynonymContext;
  class EdgeSynonymContext;
  class NonReservedWordsContext; 

  class  GqlProgramContext : public antlr4::ParserRuleContext {
  public:
    GqlProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ProgramActivityContext *> programActivity();
    ProgramActivityContext* programActivity(size_t i);
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GqlProgramContext* gqlProgram();

  class  ProgramActivityContext : public antlr4::ParserRuleContext {
  public:
    ProgramActivityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SessionActivityContext *sessionActivity();
    TransactionActivityContext *transactionActivity();
    LinearCatalogModifyingStatementContext *linearCatalogModifyingStatement();
    CallProcedureStatementContext *callProcedureStatement();
    CompositeQueryStatementContext *compositeQueryStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramActivityContext* programActivity();

  class  SessionActivityContext : public antlr4::ParserRuleContext {
  public:
    SessionActivityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SessionResetCommandContext *> sessionResetCommand();
    SessionResetCommandContext* sessionResetCommand(size_t i);
    std::vector<SessionSetCommandContext *> sessionSetCommand();
    SessionSetCommandContext* sessionSetCommand(size_t i);
    antlr4::tree::TerminalNode *SESSION();
    antlr4::tree::TerminalNode *CLOSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SessionActivityContext* sessionActivity();

  class  TransactionActivityContext : public antlr4::ParserRuleContext {
  public:
    TransactionActivityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StartTransactionCommandContext *startTransactionCommand();
    ProcedureBodyContext *procedureBody();
    antlr4::tree::TerminalNode *ROLLBACK();
    antlr4::tree::TerminalNode *COMMIT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TransactionActivityContext* transactionActivity();

  class  SessionSetCommandContext : public antlr4::ParserRuleContext {
  public:
    SessionSetCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SESSION();
    antlr4::tree::TerminalNode *SET();
    SessionSetSchemaClauseContext *sessionSetSchemaClause();
    SessionSetGraphClauseContext *sessionSetGraphClause();
    SessionSetTimeZoneClauseContext *sessionSetTimeZoneClause();
    SessionSetParameterClauseContext *sessionSetParameterClause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SessionSetCommandContext* sessionSetCommand();

  class  SessionSetSchemaClauseContext : public antlr4::ParserRuleContext {
  public:
    SessionSetSchemaClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SCHEMA();
    SchemaReferenceContext *schemaReference();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SessionSetSchemaClauseContext* sessionSetSchemaClause();

  class  SessionSetGraphClauseContext : public antlr4::ParserRuleContext {
  public:
    SessionSetGraphClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GRAPH();
    GraphExpressionContext *graphExpression();
    antlr4::tree::TerminalNode *PROPERTY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SessionSetGraphClauseContext* sessionSetGraphClause();

  class  SessionSetTimeZoneClauseContext : public antlr4::ParserRuleContext {
  public:
    SessionSetTimeZoneClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TIME();
    antlr4::tree::TerminalNode *ZONE();
    TimeZoneStringContext *timeZoneString();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SessionSetTimeZoneClauseContext* sessionSetTimeZoneClause();

  class  SessionSetParameterClauseContext : public antlr4::ParserRuleContext {
  public:
    SessionSetParameterClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GRAPH();
    antlr4::tree::TerminalNode *GENERAL_PARAMETER_REFERENCE();
    antlr4::tree::TerminalNode *EQUALS_OPERATOR();
    GraphExpressionContext *graphExpression();
    antlr4::tree::TerminalNode *PROPERTY();
    GraphReferenceValueTypeContext *graphReferenceValueType();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *EXISTS();
    TypedContext *typed();
    antlr4::tree::TerminalNode *TABLE();
    BindingTableExpressionContext *bindingTableExpression();
    antlr4::tree::TerminalNode *BINDING();
    BindingTableReferenceValueTypeContext *bindingTableReferenceValueType();
    antlr4::tree::TerminalNode *VALUE();
    ValueExpressionContext *valueExpression();
    ValueTypeContext *valueType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SessionSetParameterClauseContext* sessionSetParameterClause();

  class  SessionResetCommandContext : public antlr4::ParserRuleContext {
  public:
    SessionResetCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SESSION();
    antlr4::tree::TerminalNode *RESET();
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *SCHEMA();
    antlr4::tree::TerminalNode *GRAPH();
    antlr4::tree::TerminalNode *TIME();
    antlr4::tree::TerminalNode *ZONE();
    antlr4::tree::TerminalNode *GENERAL_PARAMETER_REFERENCE();
    antlr4::tree::TerminalNode *PARAMETERS();
    antlr4::tree::TerminalNode *CHARACTERISTICS();
    antlr4::tree::TerminalNode *PROPERTY();
    antlr4::tree::TerminalNode *PARAMETER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SessionResetCommandContext* sessionResetCommand();

  class  StartTransactionCommandContext : public antlr4::ParserRuleContext {
  public:
    StartTransactionCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *START();
    antlr4::tree::TerminalNode *TRANSACTION();
    std::vector<TransactionAccessModeContext *> transactionAccessMode();
    TransactionAccessModeContext* transactionAccessMode(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartTransactionCommandContext* startTransactionCommand();

  class  TransactionAccessModeContext : public antlr4::ParserRuleContext {
  public:
    TransactionAccessModeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *ONLY();
    antlr4::tree::TerminalNode *WRITE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TransactionAccessModeContext* transactionAccessMode();

  class  NestedProcedureSpecificationContext : public antlr4::ParserRuleContext {
  public:
    NestedProcedureSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACE();
    ProcedureBodyContext *procedureBody();
    antlr4::tree::TerminalNode *RIGHT_BRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NestedProcedureSpecificationContext* nestedProcedureSpecification();

  class  ProcedureBodyContext : public antlr4::ParserRuleContext {
  public:
    ProcedureBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementBlockContext *statementBlock();
    AtSchemaClauseContext *atSchemaClause();
    std::vector<BindingVariableDefinitionContext *> bindingVariableDefinition();
    BindingVariableDefinitionContext* bindingVariableDefinition(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcedureBodyContext* procedureBody();

  class  StatementBlockContext : public antlr4::ParserRuleContext {
  public:
    StatementBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    std::vector<NextStatementContext *> nextStatement();
    NextStatementContext* nextStatement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementBlockContext* statementBlock();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LinearCatalogModifyingStatementContext *linearCatalogModifyingStatement();
    LinearDataModifyingStatementContext *linearDataModifyingStatement();
    CompositeQueryStatementContext *compositeQueryStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  NextStatementContext : public antlr4::ParserRuleContext {
  public:
    NextStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEXT();
    StatementContext *statement();
    YieldClauseContext *yieldClause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NextStatementContext* nextStatement();

  class  BindingVariableDefinitionContext : public antlr4::ParserRuleContext {
  public:
    BindingVariableDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GRAPH();
    BindingVariableContext *bindingVariable();
    antlr4::tree::TerminalNode *EQUALS_OPERATOR();
    GraphExpressionContext *graphExpression();
    antlr4::tree::TerminalNode *PROPERTY();
    GraphReferenceValueTypeContext *graphReferenceValueType();
    TypedContext *typed();
    antlr4::tree::TerminalNode *TABLE();
    BindingTableExpressionContext *bindingTableExpression();
    antlr4::tree::TerminalNode *BINDING();
    BindingTableReferenceValueTypeContext *bindingTableReferenceValueType();
    antlr4::tree::TerminalNode *VALUE();
    ValueExpressionContext *valueExpression();
    ValueTypeContext *valueType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BindingVariableDefinitionContext* bindingVariableDefinition();

  class  GraphExpressionContext : public antlr4::ParserRuleContext {
  public:
    GraphExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GraphReferenceContext *graphReference();
    antlr4::tree::TerminalNode *VARIABLE();
    ValueExpressionPrimaryContext *valueExpressionPrimary();
    ParenthesizedValueExpressionContext *parenthesizedValueExpression();
    NonParenthesizedValueExpressionPrimarySpecialCaseContext *nonParenthesizedValueExpressionPrimarySpecialCase();
    ObjectNameOrBindingVariableContext *objectNameOrBindingVariable();
    antlr4::tree::TerminalNode *CURRENT_PROPERTY_GRAPH();
    antlr4::tree::TerminalNode *CURRENT_GRAPH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphExpressionContext* graphExpression();

  class  BindingTableExpressionContext : public antlr4::ParserRuleContext {
  public:
    BindingTableExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NestedQuerySpecificationContext *nestedQuerySpecification();
    BindingTableReferenceContext *bindingTableReference();
    antlr4::tree::TerminalNode *VARIABLE();
    ValueExpressionPrimaryContext *valueExpressionPrimary();
    ParenthesizedValueExpressionContext *parenthesizedValueExpression();
    NonParenthesizedValueExpressionPrimarySpecialCaseContext *nonParenthesizedValueExpressionPrimarySpecialCase();
    ObjectNameOrBindingVariableContext *objectNameOrBindingVariable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BindingTableExpressionContext* bindingTableExpression();

  class  LinearCatalogModifyingStatementContext : public antlr4::ParserRuleContext {
  public:
    LinearCatalogModifyingStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PrimitiveCatalogModifyingStatementContext *> primitiveCatalogModifyingStatement();
    PrimitiveCatalogModifyingStatementContext* primitiveCatalogModifyingStatement(size_t i);
    std::vector<CallProcedureStatementContext *> callProcedureStatement();
    CallProcedureStatementContext* callProcedureStatement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LinearCatalogModifyingStatementContext* linearCatalogModifyingStatement();

  class  PrimitiveCatalogModifyingStatementContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveCatalogModifyingStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *SCHEMA();
    CatalogSchemaParentAndNameContext *catalogSchemaParentAndName();
    SchemaNameContext *schemaName();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *EXISTS();
    antlr4::tree::TerminalNode *DROP();
    CatalogGraphParentAndNameContext *catalogGraphParentAndName();
    antlr4::tree::TerminalNode *GRAPH();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *REPLACE();
    OpenGraphTypeContext *openGraphType();
    OfGraphTypeContext *ofGraphType();
    GraphSourceContext *graphSource();
    antlr4::tree::TerminalNode *PROPERTY();
    CatalogGraphTypeParentAndNameContext *catalogGraphTypeParentAndName();
    GraphTypeSourceContext *graphTypeSource();
    antlr4::tree::TerminalNode *TYPE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveCatalogModifyingStatementContext* primitiveCatalogModifyingStatement();

  class  OpenGraphTypeContext : public antlr4::ParserRuleContext {
  public:
    OpenGraphTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANY();
    TypedContext *typed();
    antlr4::tree::TerminalNode *GRAPH();
    antlr4::tree::TerminalNode *PROPERTY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OpenGraphTypeContext* openGraphType();

  class  OfGraphTypeContext : public antlr4::ParserRuleContext {
  public:
    OfGraphTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIKE();
    GraphExpressionContext *graphExpression();
    GraphTypeReferenceContext *graphTypeReference();
    TypedContext *typed();
    NestedGraphTypeSpecificationContext *nestedGraphTypeSpecification();
    antlr4::tree::TerminalNode *GRAPH();
    antlr4::tree::TerminalNode *PROPERTY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OfGraphTypeContext* ofGraphType();

  class  GraphTypeSourceContext : public antlr4::ParserRuleContext {
  public:
    GraphTypeSourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COPY();
    antlr4::tree::TerminalNode *OF();
    GraphTypeReferenceContext *graphTypeReference();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *LIKE();
    GraphExpressionContext *graphExpression();
    NestedGraphTypeSpecificationContext *nestedGraphTypeSpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphTypeSourceContext* graphTypeSource();

  class  GraphSourceContext : public antlr4::ParserRuleContext {
  public:
    GraphSourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *COPY();
    antlr4::tree::TerminalNode *OF();
    GraphExpressionContext *graphExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphSourceContext* graphSource();

  class  LinearDataModifyingStatementContext : public antlr4::ParserRuleContext {
  public:
    LinearDataModifyingStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FocusedLinearDataModifyingStatementContext *focusedLinearDataModifyingStatement();
    AmbientLinearDataModifyingStatementContext *ambientLinearDataModifyingStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LinearDataModifyingStatementContext* linearDataModifyingStatement();

  class  FocusedLinearDataModifyingStatementContext : public antlr4::ParserRuleContext {
  public:
    FocusedLinearDataModifyingStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UseGraphClauseContext *useGraphClause();
    std::vector<SimpleDataAccessingStatementContext *> simpleDataAccessingStatement();
    SimpleDataAccessingStatementContext* simpleDataAccessingStatement(size_t i);
    PrimitiveResultStatementContext *primitiveResultStatement();
    NestedProcedureSpecificationContext *nestedProcedureSpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FocusedLinearDataModifyingStatementContext* focusedLinearDataModifyingStatement();

  class  AmbientLinearDataModifyingStatementContext : public antlr4::ParserRuleContext {
  public:
    AmbientLinearDataModifyingStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SimpleDataAccessingStatementContext *> simpleDataAccessingStatement();
    SimpleDataAccessingStatementContext* simpleDataAccessingStatement(size_t i);
    PrimitiveResultStatementContext *primitiveResultStatement();
    NestedProcedureSpecificationContext *nestedProcedureSpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AmbientLinearDataModifyingStatementContext* ambientLinearDataModifyingStatement();

  class  SimpleDataAccessingStatementContext : public antlr4::ParserRuleContext {
  public:
    SimpleDataAccessingStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleQueryStatementContext *simpleQueryStatement();
    PrimitiveDataModifyingStatementContext *primitiveDataModifyingStatement();
    CallProcedureStatementContext *callProcedureStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleDataAccessingStatementContext* simpleDataAccessingStatement();

  class  PrimitiveDataModifyingStatementContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveDataModifyingStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INSERT();
    InsertGraphPatternContext *insertGraphPattern();
    antlr4::tree::TerminalNode *SET();
    std::vector<SetItemContext *> setItem();
    SetItemContext* setItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *REMOVE();
    std::vector<RemoveItemContext *> removeItem();
    RemoveItemContext* removeItem(size_t i);
    antlr4::tree::TerminalNode *DELETE();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *DETACH();
    antlr4::tree::TerminalNode *NODETACH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveDataModifyingStatementContext* primitiveDataModifyingStatement();

  class  SetItemContext : public antlr4::ParserRuleContext {
  public:
    SetItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BindingVariableReferenceContext *bindingVariableReference();
    antlr4::tree::TerminalNode *PERIOD();
    PropertyNameContext *propertyName();
    antlr4::tree::TerminalNode *EQUALS_OPERATOR();
    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    PropertyKeyValuePairListContext *propertyKeyValuePairList();
    IsOrColonContext *isOrColon();
    LabelNameContext *labelName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetItemContext* setItem();

  class  RemoveItemContext : public antlr4::ParserRuleContext {
  public:
    RemoveItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BindingVariableReferenceContext *bindingVariableReference();
    antlr4::tree::TerminalNode *PERIOD();
    PropertyNameContext *propertyName();
    IsOrColonContext *isOrColon();
    LabelNameContext *labelName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RemoveItemContext* removeItem();

  class  CompositeQueryStatementContext : public antlr4::ParserRuleContext {
  public:
    CompositeQueryStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CompositeQueryExpressionContext *compositeQueryExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompositeQueryStatementContext* compositeQueryStatement();

  class  CompositeQueryExpressionContext : public antlr4::ParserRuleContext {
  public:
    CompositeQueryExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LinearQueryStatementContext *linearQueryStatement();
    CompositeQueryExpressionContext *compositeQueryExpression();
    QueryConjunctionContext *queryConjunction();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompositeQueryExpressionContext* compositeQueryExpression();
  CompositeQueryExpressionContext* compositeQueryExpression(int precedence);
  class  QueryConjunctionContext : public antlr4::ParserRuleContext {
  public:
    QueryConjunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNION();
    antlr4::tree::TerminalNode *EXCEPT();
    antlr4::tree::TerminalNode *INTERSECT();
    SetQuantifierContext *setQuantifier();
    antlr4::tree::TerminalNode *OTHERWISE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QueryConjunctionContext* queryConjunction();

  class  LinearQueryStatementContext : public antlr4::ParserRuleContext {
  public:
    LinearQueryStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FocusedLinearQueryStatementContext *focusedLinearQueryStatement();
    AmbientLinearQueryStatementContext *ambientLinearQueryStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LinearQueryStatementContext* linearQueryStatement();

  class  FocusedLinearQueryStatementContext : public antlr4::ParserRuleContext {
  public:
    FocusedLinearQueryStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<UseGraphClauseContext *> useGraphClause();
    UseGraphClauseContext* useGraphClause(size_t i);
    PrimitiveResultStatementContext *primitiveResultStatement();
    std::vector<SimpleQueryStatementContext *> simpleQueryStatement();
    SimpleQueryStatementContext* simpleQueryStatement(size_t i);
    NestedQuerySpecificationContext *nestedQuerySpecification();
    SelectStatementContext *selectStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FocusedLinearQueryStatementContext* focusedLinearQueryStatement();

  class  AmbientLinearQueryStatementContext : public antlr4::ParserRuleContext {
  public:
    AmbientLinearQueryStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimitiveResultStatementContext *primitiveResultStatement();
    std::vector<SimpleQueryStatementContext *> simpleQueryStatement();
    SimpleQueryStatementContext* simpleQueryStatement(size_t i);
    NestedQuerySpecificationContext *nestedQuerySpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AmbientLinearQueryStatementContext* ambientLinearQueryStatement();

  class  NestedQuerySpecificationContext : public antlr4::ParserRuleContext {
  public:
    NestedQuerySpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    CompositeQueryStatementContext *compositeQueryStatement();
    antlr4::tree::TerminalNode *RIGHT_PAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NestedQuerySpecificationContext* nestedQuerySpecification();

  class  SimpleQueryStatementContext : public antlr4::ParserRuleContext {
  public:
    SimpleQueryStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimitiveQueryStatementContext *primitiveQueryStatement();
    CallProcedureStatementContext *callProcedureStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleQueryStatementContext* simpleQueryStatement();

  class  PrimitiveQueryStatementContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveQueryStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MatchStatementContext *matchStatement();
    antlr4::tree::TerminalNode *LET();
    std::vector<LetVariableDefinitionContext *> letVariableDefinition();
    LetVariableDefinitionContext* letVariableDefinition(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *FOR();
    std::vector<BindingVariableContext *> bindingVariable();
    BindingVariableContext* bindingVariable(size_t i);
    antlr4::tree::TerminalNode *IN();
    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *ORDINALITY();
    antlr4::tree::TerminalNode *OFFSET();
    antlr4::tree::TerminalNode *FILTER();
    WhereClauseContext *whereClause();
    SearchConditionContext *searchCondition();
    OrderByAndPageStatementContext *orderByAndPageStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveQueryStatementContext* primitiveQueryStatement();

  class  MatchStatementContext : public antlr4::ParserRuleContext {
  public:
    MatchStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MATCH();
    GraphPatternBindingTableContext *graphPatternBindingTable();
    antlr4::tree::TerminalNode *OPTIONAL();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    std::vector<MatchStatementContext *> matchStatement();
    MatchStatementContext* matchStatement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MatchStatementContext* matchStatement();

  class  LetVariableDefinitionContext : public antlr4::ParserRuleContext {
  public:
    LetVariableDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VALUE();
    BindingVariableContext *bindingVariable();
    antlr4::tree::TerminalNode *EQUALS_OPERATOR();
    ValueExpressionContext *valueExpression();
    ValueTypeContext *valueType();
    TypedContext *typed();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LetVariableDefinitionContext* letVariableDefinition();

  class  OrderByAndPageStatementContext : public antlr4::ParserRuleContext {
  public:
    OrderByAndPageStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OrderByClauseContext *orderByClause();
    OffsetClauseContext *offsetClause();
    LimitClauseContext *limitClause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrderByAndPageStatementContext* orderByAndPageStatement();

  class  PrimitiveResultStatementContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveResultStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *ASTERISK();
    std::vector<ReturnItemContext *> returnItem();
    ReturnItemContext* returnItem(size_t i);
    SetQuantifierContext *setQuantifier();
    GroupByClauseContext *groupByClause();
    OrderByAndPageStatementContext *orderByAndPageStatement();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *FINISH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveResultStatementContext* primitiveResultStatement();

  class  ReturnItemContext : public antlr4::ParserRuleContext {
  public:
    ReturnItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AggregatingValueExpressionContext *aggregatingValueExpression();
    antlr4::tree::TerminalNode *AS();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnItemContext* returnItem();

  class  SelectStatementContext : public antlr4::ParserRuleContext {
  public:
    SelectStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECT();
    antlr4::tree::TerminalNode *ASTERISK();
    std::vector<SelectItemContext *> selectItem();
    SelectItemContext* selectItem(size_t i);
    SetQuantifierContext *setQuantifier();
    SelectStatementBodyContext *selectStatementBody();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    WhereClauseContext *whereClause();
    GroupByClauseContext *groupByClause();
    HavingClauseContext *havingClause();
    OrderByClauseContext *orderByClause();
    OffsetClauseContext *offsetClause();
    LimitClauseContext *limitClause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectStatementContext* selectStatement();

  class  SelectItemContext : public antlr4::ParserRuleContext {
  public:
    SelectItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AggregatingValueExpressionContext *aggregatingValueExpression();
    antlr4::tree::TerminalNode *AS();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectItemContext* selectItem();

  class  HavingClauseContext : public antlr4::ParserRuleContext {
  public:
    HavingClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HAVING();
    SearchConditionContext *searchCondition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HavingClauseContext* havingClause();

  class  SelectStatementBodyContext : public antlr4::ParserRuleContext {
  public:
    SelectStatementBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FROM();
    std::vector<SelectGraphMatchContext *> selectGraphMatch();
    SelectGraphMatchContext* selectGraphMatch(size_t i);
    SelectQuerySpecificationContext *selectQuerySpecification();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectStatementBodyContext* selectStatementBody();

  class  SelectGraphMatchContext : public antlr4::ParserRuleContext {
  public:
    SelectGraphMatchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GraphExpressionContext *graphExpression();
    MatchStatementContext *matchStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectGraphMatchContext* selectGraphMatch();

  class  SelectQuerySpecificationContext : public antlr4::ParserRuleContext {
  public:
    SelectQuerySpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NestedQuerySpecificationContext *nestedQuerySpecification();
    GraphExpressionContext *graphExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectQuerySpecificationContext* selectQuerySpecification();

  class  CallProcedureStatementContext : public antlr4::ParserRuleContext {
  public:
    CallProcedureStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CALL();
    ProcedureCallContext *procedureCall();
    antlr4::tree::TerminalNode *OPTIONAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallProcedureStatementContext* callProcedureStatement();

  class  ProcedureCallContext : public antlr4::ParserRuleContext {
  public:
    ProcedureCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NestedProcedureSpecificationContext *nestedProcedureSpecification();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    std::vector<BindingVariableReferenceContext *> bindingVariableReference();
    BindingVariableReferenceContext* bindingVariableReference(size_t i);
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    ProcedureReferenceContext *procedureReference();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    YieldClauseContext *yieldClause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcedureCallContext* procedureCall();

  class  AtSchemaClauseContext : public antlr4::ParserRuleContext {
  public:
    AtSchemaClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    SchemaReferenceContext *schemaReference();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AtSchemaClauseContext* atSchemaClause();

  class  UseGraphClauseContext : public antlr4::ParserRuleContext {
  public:
    UseGraphClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USE();
    GraphExpressionContext *graphExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UseGraphClauseContext* useGraphClause();

  class  GraphPatternBindingTableContext : public antlr4::ParserRuleContext {
  public:
    GraphPatternBindingTableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GraphPatternContext *graphPattern();
    antlr4::tree::TerminalNode *YIELD();
    std::vector<BindingVariableReferenceContext *> bindingVariableReference();
    BindingVariableReferenceContext* bindingVariableReference(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphPatternBindingTableContext* graphPatternBindingTable();

  class  GraphPatternContext : public antlr4::ParserRuleContext {
  public:
    GraphPatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PathPatternContext *> pathPattern();
    PathPatternContext* pathPattern(size_t i);
    MatchModeContext *matchMode();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    KeepClauseContext *keepClause();
    antlr4::tree::TerminalNode *WHERE();
    SearchConditionContext *searchCondition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphPatternContext* graphPattern();

  class  MatchModeContext : public antlr4::ParserRuleContext {
  public:
    MatchModeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REPEATABLE();
    antlr4::tree::TerminalNode *ELEMENT();
    antlr4::tree::TerminalNode *ELEMENTS();
    antlr4::tree::TerminalNode *BINDINGS();
    antlr4::tree::TerminalNode *DIFFERENT();
    EdgeSynonymContext *edgeSynonym();
    EdgesSynonymContext *edgesSynonym();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MatchModeContext* matchMode();

  class  PathPatternContext : public antlr4::ParserRuleContext {
  public:
    PathPatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PathPatternExpressionContext *pathPatternExpression();
    PathVariableContext *pathVariable();
    antlr4::tree::TerminalNode *EQUALS_OPERATOR();
    PathPatternPrefixContext *pathPatternPrefix();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathPatternContext* pathPattern();

  class  KeepClauseContext : public antlr4::ParserRuleContext {
  public:
    KeepClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *KEEP();
    PathPatternPrefixContext *pathPatternPrefix();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KeepClauseContext* keepClause();

  class  InsertGraphPatternContext : public antlr4::ParserRuleContext {
  public:
    InsertGraphPatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InsertPathPatternContext *> insertPathPattern();
    InsertPathPatternContext* insertPathPattern(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InsertGraphPatternContext* insertGraphPattern();

  class  InsertPathPatternContext : public antlr4::ParserRuleContext {
  public:
    InsertPathPatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InsertNodePatternContext *> insertNodePattern();
    InsertNodePatternContext* insertNodePattern(size_t i);
    std::vector<InsertEdgePatternContext *> insertEdgePattern();
    InsertEdgePatternContext* insertEdgePattern(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InsertPathPatternContext* insertPathPattern();

  class  InsertNodePatternContext : public antlr4::ParserRuleContext {
  public:
    InsertNodePatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    InsertElementPatternFillerContext *insertElementPatternFiller();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InsertNodePatternContext* insertNodePattern();

  class  InsertEdgePatternContext : public antlr4::ParserRuleContext {
  public:
    InsertEdgePatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_ARROW_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_BRACKET_MINUS();
    InsertElementPatternFillerContext *insertElementPatternFiller();
    antlr4::tree::TerminalNode *MINUS_LEFT_BRACKET();
    antlr4::tree::TerminalNode *BRACKET_RIGHT_ARROW();
    antlr4::tree::TerminalNode *TILDE_LEFT_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_BRACKET_TILDE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InsertEdgePatternContext* insertEdgePattern();

  class  InsertElementPatternFillerContext : public antlr4::ParserRuleContext {
  public:
    InsertElementPatternFillerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ElementVariableDeclarationContext *elementVariableDeclaration();
    LabelAndPropertySetSpecificationContext *labelAndPropertySetSpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InsertElementPatternFillerContext* insertElementPatternFiller();

  class  LabelAndPropertySetSpecificationContext : public antlr4::ParserRuleContext {
  public:
    LabelAndPropertySetSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IsOrColonContext *isOrColon();
    LabelSetSpecificationContext *labelSetSpecification();
    ElementPropertySpecificationContext *elementPropertySpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelAndPropertySetSpecificationContext* labelAndPropertySetSpecification();

  class  PathPatternPrefixContext : public antlr4::ParserRuleContext {
  public:
    PathPatternPrefixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PathModePrefixContext *pathModePrefix();
    PathSearchPrefixContext *pathSearchPrefix();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathPatternPrefixContext* pathPatternPrefix();

  class  PathModePrefixContext : public antlr4::ParserRuleContext {
  public:
    PathModePrefixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WALK();
    antlr4::tree::TerminalNode *TRAIL();
    antlr4::tree::TerminalNode *SIMPLE();
    antlr4::tree::TerminalNode *ACYCLIC();
    antlr4::tree::TerminalNode *PATH();
    antlr4::tree::TerminalNode *PATHS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathModePrefixContext* pathModePrefix();

  class  PathSearchPrefixContext : public antlr4::ParserRuleContext {
  public:
    PathSearchPrefixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *WALK();
    antlr4::tree::TerminalNode *TRAIL();
    antlr4::tree::TerminalNode *SIMPLE();
    antlr4::tree::TerminalNode *ACYCLIC();
    antlr4::tree::TerminalNode *PATH();
    antlr4::tree::TerminalNode *PATHS();
    antlr4::tree::TerminalNode *ANY();
    NonNegativeIntegerSpecificationContext *nonNegativeIntegerSpecification();
    ShortestPathSearchContext *shortestPathSearch();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathSearchPrefixContext* pathSearchPrefix();

  class  ShortestPathSearchContext : public antlr4::ParserRuleContext {
  public:
    ShortestPathSearchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *SHORTEST();
    antlr4::tree::TerminalNode *WALK();
    antlr4::tree::TerminalNode *TRAIL();
    antlr4::tree::TerminalNode *SIMPLE();
    antlr4::tree::TerminalNode *ACYCLIC();
    antlr4::tree::TerminalNode *PATH();
    antlr4::tree::TerminalNode *PATHS();
    antlr4::tree::TerminalNode *ANY();
    NonNegativeIntegerSpecificationContext *nonNegativeIntegerSpecification();
    antlr4::tree::TerminalNode *GROUP();
    antlr4::tree::TerminalNode *GROUPS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShortestPathSearchContext* shortestPathSearch();

  class  PathPatternExpressionContext : public antlr4::ParserRuleContext {
  public:
    PathPatternExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PathPatternExpressionContext() = default;
    void copyFrom(PathPatternExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PpePatternUnionContext : public PathPatternExpressionContext {
  public:
    PpePatternUnionContext(PathPatternExpressionContext *ctx);

    std::vector<PathTermContext *> pathTerm();
    PathTermContext* pathTerm(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VERTICAL_BAR();
    antlr4::tree::TerminalNode* VERTICAL_BAR(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PpePathTermContext : public PathPatternExpressionContext {
  public:
    PpePathTermContext(PathPatternExpressionContext *ctx);

    PathTermContext *pathTerm();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PpeMultisetAlternationContext : public PathPatternExpressionContext {
  public:
    PpeMultisetAlternationContext(PathPatternExpressionContext *ctx);

    std::vector<PathTermContext *> pathTerm();
    PathTermContext* pathTerm(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MULTISET_ALTERNATION_OPERATOR();
    antlr4::tree::TerminalNode* MULTISET_ALTERNATION_OPERATOR(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PathPatternExpressionContext* pathPatternExpression();

  class  PathTermContext : public antlr4::ParserRuleContext {
  public:
    PathTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PathFactorContext *> pathFactor();
    PathFactorContext* pathFactor(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathTermContext* pathTerm();

  class  PathFactorContext : public antlr4::ParserRuleContext {
  public:
    PathFactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PathFactorContext() = default;
    void copyFrom(PathFactorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PfQuantifiedPathPrimaryContext : public PathFactorContext {
  public:
    PfQuantifiedPathPrimaryContext(PathFactorContext *ctx);

    PathPrimaryContext *pathPrimary();
    GraphPatternQuantifierContext *graphPatternQuantifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PfQuestionedPathPrimaryContext : public PathFactorContext {
  public:
    PfQuestionedPathPrimaryContext(PathFactorContext *ctx);

    PathPrimaryContext *pathPrimary();
    antlr4::tree::TerminalNode *QUESTION_MARK();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PfPathPrimaryContext : public PathFactorContext {
  public:
    PfPathPrimaryContext(PathFactorContext *ctx);

    PathPrimaryContext *pathPrimary();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PathFactorContext* pathFactor();

  class  PathPrimaryContext : public antlr4::ParserRuleContext {
  public:
    PathPrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PathPrimaryContext() = default;
    void copyFrom(PathPrimaryContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PpParenthesizedPathPatternExpressionContext : public PathPrimaryContext {
  public:
    PpParenthesizedPathPatternExpressionContext(PathPrimaryContext *ctx);

    ParenthesizedPathPatternExpressionContext *parenthesizedPathPatternExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PpElementPatternContext : public PathPrimaryContext {
  public:
    PpElementPatternContext(PathPrimaryContext *ctx);

    ElementPatternContext *elementPattern();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PpSimplifiedPathPatternExpressionContext : public PathPrimaryContext {
  public:
    PpSimplifiedPathPatternExpressionContext(PathPrimaryContext *ctx);

    SimplifiedPathPatternExpressionContext *simplifiedPathPatternExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PathPrimaryContext* pathPrimary();

  class  ElementPatternContext : public antlr4::ParserRuleContext {
  public:
    ElementPatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    ElementPatternFillerContext *elementPatternFiller();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    FullEdgePatternContext *fullEdgePattern();
    AbbreviatedEdgePatternContext *abbreviatedEdgePattern();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementPatternContext* elementPattern();

  class  ElementPatternFillerContext : public antlr4::ParserRuleContext {
  public:
    ElementPatternFillerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ElementVariableDeclarationContext *elementVariableDeclaration();
    IsLabelExpressionContext *isLabelExpression();
    ElementPatternPredicateContext *elementPatternPredicate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementPatternFillerContext* elementPatternFiller();

  class  ElementVariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ElementVariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ElementVariableContext *elementVariable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementVariableDeclarationContext* elementVariableDeclaration();

  class  IsLabelExpressionContext : public antlr4::ParserRuleContext {
  public:
    IsLabelExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IsOrColonContext *isOrColon();
    LabelExpressionContext *labelExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IsLabelExpressionContext* isLabelExpression();

  class  IsOrColonContext : public antlr4::ParserRuleContext {
  public:
    IsOrColonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *COLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IsOrColonContext* isOrColon();

  class  ElementPatternPredicateContext : public antlr4::ParserRuleContext {
  public:
    ElementPatternPredicateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHERE();
    SearchConditionContext *searchCondition();
    ElementPropertySpecificationContext *elementPropertySpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementPatternPredicateContext* elementPatternPredicate();

  class  ElementPropertySpecificationContext : public antlr4::ParserRuleContext {
  public:
    ElementPropertySpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACE();
    PropertyKeyValuePairListContext *propertyKeyValuePairList();
    antlr4::tree::TerminalNode *RIGHT_BRACE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementPropertySpecificationContext* elementPropertySpecification();

  class  PropertyKeyValuePairListContext : public antlr4::ParserRuleContext {
  public:
    PropertyKeyValuePairListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PropertyKeyValuePairContext *> propertyKeyValuePair();
    PropertyKeyValuePairContext* propertyKeyValuePair(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyKeyValuePairListContext* propertyKeyValuePairList();

  class  PropertyKeyValuePairContext : public antlr4::ParserRuleContext {
  public:
    PropertyKeyValuePairContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PropertyNameContext *propertyName();
    antlr4::tree::TerminalNode *COLON();
    ValueExpressionContext *valueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyKeyValuePairContext* propertyKeyValuePair();

  class  FullEdgePatternContext : public antlr4::ParserRuleContext {
  public:
    FullEdgePatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_ARROW_BRACKET();
    ElementPatternFillerContext *elementPatternFiller();
    antlr4::tree::TerminalNode *RIGHT_BRACKET_MINUS();
    antlr4::tree::TerminalNode *TILDE_LEFT_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_BRACKET_TILDE();
    antlr4::tree::TerminalNode *MINUS_LEFT_BRACKET();
    antlr4::tree::TerminalNode *BRACKET_RIGHT_ARROW();
    antlr4::tree::TerminalNode *LEFT_ARROW_TILDE_BRACKET();
    antlr4::tree::TerminalNode *BRACKET_TILDE_RIGHT_ARROW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FullEdgePatternContext* fullEdgePattern();

  class  AbbreviatedEdgePatternContext : public antlr4::ParserRuleContext {
  public:
    AbbreviatedEdgePatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_ARROW();
    antlr4::tree::TerminalNode *TILDE();
    antlr4::tree::TerminalNode *RIGHT_ARROW();
    antlr4::tree::TerminalNode *LEFT_ARROW_TILDE();
    antlr4::tree::TerminalNode *TILDE_RIGHT_ARROW();
    antlr4::tree::TerminalNode *LEFT_MINUS_RIGHT();
    antlr4::tree::TerminalNode *MINUS_SIGN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AbbreviatedEdgePatternContext* abbreviatedEdgePattern();

  class  ParenthesizedPathPatternExpressionContext : public antlr4::ParserRuleContext {
  public:
    ParenthesizedPathPatternExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    PathPatternExpressionContext *pathPatternExpression();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    SubpathVariableContext *subpathVariable();
    antlr4::tree::TerminalNode *EQUALS_OPERATOR();
    PathModePrefixContext *pathModePrefix();
    antlr4::tree::TerminalNode *WHERE();
    SearchConditionContext *searchCondition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParenthesizedPathPatternExpressionContext* parenthesizedPathPatternExpression();

  class  LabelExpressionContext : public antlr4::ParserRuleContext {
  public:
    LabelExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LabelExpressionContext() = default;
    void copyFrom(LabelExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LabelExpressionNegationContext : public LabelExpressionContext {
  public:
    LabelExpressionNegationContext(LabelExpressionContext *ctx);

    antlr4::tree::TerminalNode *EXCLAMATION_MARK();
    LabelExpressionContext *labelExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LabelExpressionDisjunctionContext : public LabelExpressionContext {
  public:
    LabelExpressionDisjunctionContext(LabelExpressionContext *ctx);

    std::vector<LabelExpressionContext *> labelExpression();
    LabelExpressionContext* labelExpression(size_t i);
    antlr4::tree::TerminalNode *VERTICAL_BAR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LabelExpressionParenthesizedContext : public LabelExpressionContext {
  public:
    LabelExpressionParenthesizedContext(LabelExpressionContext *ctx);

    antlr4::tree::TerminalNode *LEFT_PAREN();
    LabelExpressionContext *labelExpression();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LabelExpressionWildcardContext : public LabelExpressionContext {
  public:
    LabelExpressionWildcardContext(LabelExpressionContext *ctx);

    antlr4::tree::TerminalNode *PERCENT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LabelExpressionConjunctionContext : public LabelExpressionContext {
  public:
    LabelExpressionConjunctionContext(LabelExpressionContext *ctx);

    std::vector<LabelExpressionContext *> labelExpression();
    LabelExpressionContext* labelExpression(size_t i);
    antlr4::tree::TerminalNode *AMPERSAND();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LabelExpressionNameContext : public LabelExpressionContext {
  public:
    LabelExpressionNameContext(LabelExpressionContext *ctx);

    LabelNameContext *labelName();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LabelExpressionContext* labelExpression();
  LabelExpressionContext* labelExpression(int precedence);
  class  GraphPatternQuantifierContext : public antlr4::ParserRuleContext {
  public:
    GraphPatternQuantifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ASTERISK();
    antlr4::tree::TerminalNode *PLUS_SIGN();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    std::vector<UnsignedIntegerContext *> unsignedInteger();
    UnsignedIntegerContext* unsignedInteger(size_t i);
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphPatternQuantifierContext* graphPatternQuantifier();

  class  SimplifiedPathPatternExpressionContext : public antlr4::ParserRuleContext {
  public:
    SimplifiedPathPatternExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_MINUS_SLASH();
    SimplifiedContentsContext *simplifiedContents();
    antlr4::tree::TerminalNode *SLASH_MINUS();
    antlr4::tree::TerminalNode *TILDE_SLASH();
    antlr4::tree::TerminalNode *SLASH_TILDE();
    antlr4::tree::TerminalNode *MINUS_SLASH();
    antlr4::tree::TerminalNode *SLASH_MINUS_RIGHT();
    antlr4::tree::TerminalNode *LEFT_TILDE_SLASH();
    antlr4::tree::TerminalNode *SLASH_TILDE_RIGHT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimplifiedPathPatternExpressionContext* simplifiedPathPatternExpression();

  class  SimplifiedContentsContext : public antlr4::ParserRuleContext {
  public:
    SimplifiedContentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SimplifiedTermContext *> simplifiedTerm();
    SimplifiedTermContext* simplifiedTerm(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VERTICAL_BAR();
    antlr4::tree::TerminalNode* VERTICAL_BAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MULTISET_ALTERNATION_OPERATOR();
    antlr4::tree::TerminalNode* MULTISET_ALTERNATION_OPERATOR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimplifiedContentsContext* simplifiedContents();

  class  SimplifiedTermContext : public antlr4::ParserRuleContext {
  public:
    SimplifiedTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    SimplifiedTermContext() = default;
    void copyFrom(SimplifiedTermContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SimplifiedFactorLowLabelContext : public SimplifiedTermContext {
  public:
    SimplifiedFactorLowLabelContext(SimplifiedTermContext *ctx);

    SimplifiedFactorLowContext *simplifiedFactorLow();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SimplifiedConcatenationLabelContext : public SimplifiedTermContext {
  public:
    SimplifiedConcatenationLabelContext(SimplifiedTermContext *ctx);

    SimplifiedTermContext *simplifiedTerm();
    SimplifiedFactorLowContext *simplifiedFactorLow();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  SimplifiedTermContext* simplifiedTerm();
  SimplifiedTermContext* simplifiedTerm(int precedence);
  class  SimplifiedFactorLowContext : public antlr4::ParserRuleContext {
  public:
    SimplifiedFactorLowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    SimplifiedFactorLowContext() = default;
    void copyFrom(SimplifiedFactorLowContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SimplifiedConjunctionLabelContext : public SimplifiedFactorLowContext {
  public:
    SimplifiedConjunctionLabelContext(SimplifiedFactorLowContext *ctx);

    SimplifiedFactorLowContext *simplifiedFactorLow();
    antlr4::tree::TerminalNode *AMPERSAND();
    SimplifiedFactorHighContext *simplifiedFactorHigh();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SimplifiedFactorHighLabelContext : public SimplifiedFactorLowContext {
  public:
    SimplifiedFactorHighLabelContext(SimplifiedFactorLowContext *ctx);

    SimplifiedFactorHighContext *simplifiedFactorHigh();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  SimplifiedFactorLowContext* simplifiedFactorLow();
  SimplifiedFactorLowContext* simplifiedFactorLow(int precedence);
  class  SimplifiedFactorHighContext : public antlr4::ParserRuleContext {
  public:
    SimplifiedFactorHighContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimplifiedTertiaryContext *simplifiedTertiary();
    GraphPatternQuantifierContext *graphPatternQuantifier();
    antlr4::tree::TerminalNode *QUESTION_MARK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimplifiedFactorHighContext* simplifiedFactorHigh();

  class  SimplifiedTertiaryContext : public antlr4::ParserRuleContext {
  public:
    SimplifiedTertiaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_ANGLE_BRACKET();
    SimplifiedSecondaryContext *simplifiedSecondary();
    antlr4::tree::TerminalNode *TILDE();
    antlr4::tree::TerminalNode *RIGHT_ANGLE_BRACKET();
    antlr4::tree::TerminalNode *LEFT_ARROW_TILDE();
    antlr4::tree::TerminalNode *MINUS_SIGN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimplifiedTertiaryContext* simplifiedTertiary();

  class  SimplifiedSecondaryContext : public antlr4::ParserRuleContext {
  public:
    SimplifiedSecondaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimplifiedPrimaryContext *simplifiedPrimary();
    antlr4::tree::TerminalNode *EXCLAMATION_MARK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimplifiedSecondaryContext* simplifiedSecondary();

  class  SimplifiedPrimaryContext : public antlr4::ParserRuleContext {
  public:
    SimplifiedPrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LabelNameContext *labelName();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    SimplifiedContentsContext *simplifiedContents();
    antlr4::tree::TerminalNode *RIGHT_PAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimplifiedPrimaryContext* simplifiedPrimary();

  class  WhereClauseContext : public antlr4::ParserRuleContext {
  public:
    WhereClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHERE();
    SearchConditionContext *searchCondition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhereClauseContext* whereClause();

  class  YieldClauseContext : public antlr4::ParserRuleContext {
  public:
    YieldClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *YIELD();
    std::vector<YieldItemContext *> yieldItem();
    YieldItemContext* yieldItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  YieldClauseContext* yieldClause();

  class  YieldItemContext : public antlr4::ParserRuleContext {
  public:
    YieldItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FieldNameContext *fieldName();
    antlr4::tree::TerminalNode *AS();
    BindingVariableContext *bindingVariable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  YieldItemContext* yieldItem();

  class  GroupByClauseContext : public antlr4::ParserRuleContext {
  public:
    GroupByClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GROUP();
    antlr4::tree::TerminalNode *BY();
    std::vector<BindingVariableReferenceContext *> bindingVariableReference();
    BindingVariableReferenceContext* bindingVariableReference(size_t i);
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GroupByClauseContext* groupByClause();

  class  OrderByClauseContext : public antlr4::ParserRuleContext {
  public:
    OrderByClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ORDER();
    antlr4::tree::TerminalNode *BY();
    std::vector<SortSpecificationContext *> sortSpecification();
    SortSpecificationContext* sortSpecification(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrderByClauseContext* orderByClause();

  class  SortSpecificationContext : public antlr4::ParserRuleContext {
  public:
    SortSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AggregatingValueExpressionContext *aggregatingValueExpression();
    antlr4::tree::TerminalNode *NULLS();
    antlr4::tree::TerminalNode *ASC();
    antlr4::tree::TerminalNode *ASCENDING();
    antlr4::tree::TerminalNode *DESC();
    antlr4::tree::TerminalNode *DESCENDING();
    antlr4::tree::TerminalNode *FIRST();
    antlr4::tree::TerminalNode *LAST();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SortSpecificationContext* sortSpecification();

  class  LimitClauseContext : public antlr4::ParserRuleContext {
  public:
    LimitClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIMIT();
    NonNegativeIntegerSpecificationContext *nonNegativeIntegerSpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LimitClauseContext* limitClause();

  class  OffsetClauseContext : public antlr4::ParserRuleContext {
  public:
    OffsetClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NonNegativeIntegerSpecificationContext *nonNegativeIntegerSpecification();
    antlr4::tree::TerminalNode *OFFSET();
    antlr4::tree::TerminalNode *SKIP_RESERVED_WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OffsetClauseContext* offsetClause();

  class  SchemaReferenceContext : public antlr4::ParserRuleContext {
  public:
    SchemaReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AbsoluteCatalogSchemaReferenceContext *absoluteCatalogSchemaReference();
    RelativeCatalogSchemaReferenceContext *relativeCatalogSchemaReference();
    SchemaNameContext *schemaName();
    antlr4::tree::TerminalNode *SUBSTITUTED_PARAMETER_REFERENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SchemaReferenceContext* schemaReference();

  class  AbsoluteCatalogSchemaReferenceContext : public antlr4::ParserRuleContext {
  public:
    AbsoluteCatalogSchemaReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOLIDUS();
    AbsoluteDirectoryPathContext *absoluteDirectoryPath();
    SchemaNameContext *schemaName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AbsoluteCatalogSchemaReferenceContext* absoluteCatalogSchemaReference();

  class  CatalogSchemaParentAndNameContext : public antlr4::ParserRuleContext {
  public:
    CatalogSchemaParentAndNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AbsoluteDirectoryPathContext *absoluteDirectoryPath();
    SchemaNameContext *schemaName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatalogSchemaParentAndNameContext* catalogSchemaParentAndName();

  class  RelativeCatalogSchemaReferenceContext : public antlr4::ParserRuleContext {
  public:
    RelativeCatalogSchemaReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HOME_SCHEMA();
    antlr4::tree::TerminalNode *CURRENT_SCHEMA();
    antlr4::tree::TerminalNode *PERIOD();
    RelativeDirectoryPathContext *relativeDirectoryPath();
    SchemaNameContext *schemaName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelativeCatalogSchemaReferenceContext* relativeCatalogSchemaReference();

  class  AbsoluteDirectoryPathContext : public antlr4::ParserRuleContext {
  public:
    AbsoluteDirectoryPathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOLIDUS();
    SimpleDirectoryPathContext *simpleDirectoryPath();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AbsoluteDirectoryPathContext* absoluteDirectoryPath();

  class  RelativeDirectoryPathContext : public antlr4::ParserRuleContext {
  public:
    RelativeDirectoryPathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> DOUBLE_PERIOD();
    antlr4::tree::TerminalNode* DOUBLE_PERIOD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SOLIDUS();
    antlr4::tree::TerminalNode* SOLIDUS(size_t i);
    SimpleDirectoryPathContext *simpleDirectoryPath();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelativeDirectoryPathContext* relativeDirectoryPath();

  class  SimpleDirectoryPathContext : public antlr4::ParserRuleContext {
  public:
    SimpleDirectoryPathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DirectoryNameContext *> directoryName();
    DirectoryNameContext* directoryName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SOLIDUS();
    antlr4::tree::TerminalNode* SOLIDUS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleDirectoryPathContext* simpleDirectoryPath();

  class  GraphReferenceContext : public antlr4::ParserRuleContext {
  public:
    GraphReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CatalogObjectParentReferenceContext *catalogObjectParentReference();
    GraphNameContext *graphName();
    DelimitedGraphNameContext *delimitedGraphName();
    antlr4::tree::TerminalNode *HOME_PROPERTY_GRAPH();
    antlr4::tree::TerminalNode *HOME_GRAPH();
    antlr4::tree::TerminalNode *SUBSTITUTED_PARAMETER_REFERENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphReferenceContext* graphReference();

  class  CatalogGraphParentAndNameContext : public antlr4::ParserRuleContext {
  public:
    CatalogGraphParentAndNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GraphNameContext *graphName();
    CatalogObjectParentReferenceContext *catalogObjectParentReference();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatalogGraphParentAndNameContext* catalogGraphParentAndName();

  class  GraphTypeReferenceContext : public antlr4::ParserRuleContext {
  public:
    GraphTypeReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CatalogGraphTypeParentAndNameContext *catalogGraphTypeParentAndName();
    antlr4::tree::TerminalNode *SUBSTITUTED_PARAMETER_REFERENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphTypeReferenceContext* graphTypeReference();

  class  CatalogGraphTypeParentAndNameContext : public antlr4::ParserRuleContext {
  public:
    CatalogGraphTypeParentAndNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GraphTypeNameContext *graphTypeName();
    CatalogObjectParentReferenceContext *catalogObjectParentReference();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatalogGraphTypeParentAndNameContext* catalogGraphTypeParentAndName();

  class  BindingTableReferenceContext : public antlr4::ParserRuleContext {
  public:
    BindingTableReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CatalogObjectParentReferenceContext *catalogObjectParentReference();
    BindingTableNameContext *bindingTableName();
    DelimitedBindingTableNameContext *delimitedBindingTableName();
    antlr4::tree::TerminalNode *SUBSTITUTED_PARAMETER_REFERENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BindingTableReferenceContext* bindingTableReference();

  class  ProcedureReferenceContext : public antlr4::ParserRuleContext {
  public:
    ProcedureReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProcedureNameContext *procedureName();
    CatalogObjectParentReferenceContext *catalogObjectParentReference();
    antlr4::tree::TerminalNode *SUBSTITUTED_PARAMETER_REFERENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcedureReferenceContext* procedureReference();

  class  CatalogObjectParentReferenceContext : public antlr4::ParserRuleContext {
  public:
    CatalogObjectParentReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SchemaReferenceContext *schemaReference();
    antlr4::tree::TerminalNode *SOLIDUS();
    std::vector<ObjectNameContext *> objectName();
    ObjectNameContext* objectName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PERIOD();
    antlr4::tree::TerminalNode* PERIOD(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatalogObjectParentReferenceContext* catalogObjectParentReference();

  class  NestedGraphTypeSpecificationContext : public antlr4::ParserRuleContext {
  public:
    NestedGraphTypeSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACE();
    std::vector<ElementTypeSpecificationContext *> elementTypeSpecification();
    ElementTypeSpecificationContext* elementTypeSpecification(size_t i);
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NestedGraphTypeSpecificationContext* nestedGraphTypeSpecification();

  class  ElementTypeSpecificationContext : public antlr4::ParserRuleContext {
  public:
    ElementTypeSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NodeTypeSpecificationContext *nodeTypeSpecification();
    EdgeTypeSpecificationContext *edgeTypeSpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementTypeSpecificationContext* elementTypeSpecification();

  class  NodeTypeSpecificationContext : public antlr4::ParserRuleContext {
  public:
    NodeTypeSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    NodeSynonymContext *nodeSynonym();
    NodeTypeNameContext *nodeTypeName();
    RegularIdentifierContext *regularIdentifier();
    NodeTypeFillerContext *nodeTypeFiller();
    antlr4::tree::TerminalNode *TYPE();
    NodeTypePhraseFillerContext *nodeTypePhraseFiller();
    antlr4::tree::TerminalNode *AS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NodeTypeSpecificationContext* nodeTypeSpecification();

  class  NodeTypePhraseFillerContext : public antlr4::ParserRuleContext {
  public:
    NodeTypePhraseFillerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NodeTypeNameContext *nodeTypeName();
    NodeTypeFillerContext *nodeTypeFiller();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NodeTypePhraseFillerContext* nodeTypePhraseFiller();

  class  NodeTypeFillerContext : public antlr4::ParserRuleContext {
  public:
    NodeTypeFillerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPLIES();
    LabelSetPhraseContext *labelSetPhrase();
    NodeTypeImpliedContentContext *nodeTypeImpliedContent();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NodeTypeFillerContext* nodeTypeFiller();

  class  NodeTypeImpliedContentContext : public antlr4::ParserRuleContext {
  public:
    NodeTypeImpliedContentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LabelSetPhraseContext *labelSetPhrase();
    PropertyTypesSpecificationContext *propertyTypesSpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NodeTypeImpliedContentContext* nodeTypeImpliedContent();

  class  EdgeTypeSpecificationContext : public antlr4::ParserRuleContext {
  public:
    EdgeTypeSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EdgeTypePatternDirectedContext *edgeTypePatternDirected();
    EdgeTypePatternUndirectedContext *edgeTypePatternUndirected();
    EdgeSynonymContext *edgeSynonym();
    EdgeTypeNameContext *edgeTypeName();
    EdgeKindContext *edgeKind();
    antlr4::tree::TerminalNode *TYPE();
    EdgeTypePhraseFillerContext *edgeTypePhraseFiller();
    EndpointPairPhraseContext *endpointPairPhrase();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgeTypeSpecificationContext* edgeTypeSpecification();

  class  EdgeTypePhraseFillerContext : public antlr4::ParserRuleContext {
  public:
    EdgeTypePhraseFillerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EdgeTypeNameContext *edgeTypeName();
    EdgeTypeFillerContext *edgeTypeFiller();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgeTypePhraseFillerContext* edgeTypePhraseFiller();

  class  EdgeTypeFillerContext : public antlr4::ParserRuleContext {
  public:
    EdgeTypeFillerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPLIES();
    LabelSetPhraseContext *labelSetPhrase();
    EdgeTypeImpliedContentContext *edgeTypeImpliedContent();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgeTypeFillerContext* edgeTypeFiller();

  class  EdgeTypeImpliedContentContext : public antlr4::ParserRuleContext {
  public:
    EdgeTypeImpliedContentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LabelSetPhraseContext *labelSetPhrase();
    PropertyTypesSpecificationContext *propertyTypesSpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgeTypeImpliedContentContext* edgeTypeImpliedContent();

  class  EdgeTypePatternDirectedContext : public antlr4::ParserRuleContext {
  public:
    EdgeTypePatternDirectedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SourceNodeTypeReferenceContext *sourceNodeTypeReference();
    ArcTypePointingRightContext *arcTypePointingRight();
    DestinationNodeTypeReferenceContext *destinationNodeTypeReference();
    ArcTypePointingLeftContext *arcTypePointingLeft();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgeTypePatternDirectedContext* edgeTypePatternDirected();

  class  EdgeTypePatternUndirectedContext : public antlr4::ParserRuleContext {
  public:
    EdgeTypePatternUndirectedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SourceNodeTypeReferenceContext *sourceNodeTypeReference();
    ArcTypeUndirectedContext *arcTypeUndirected();
    DestinationNodeTypeReferenceContext *destinationNodeTypeReference();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgeTypePatternUndirectedContext* edgeTypePatternUndirected();

  class  ArcTypePointingRightContext : public antlr4::ParserRuleContext {
  public:
    ArcTypePointingRightContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS_LEFT_BRACKET();
    EdgeTypeFillerContext *edgeTypeFiller();
    antlr4::tree::TerminalNode *BRACKET_RIGHT_ARROW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArcTypePointingRightContext* arcTypePointingRight();

  class  ArcTypePointingLeftContext : public antlr4::ParserRuleContext {
  public:
    ArcTypePointingLeftContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_ARROW_BRACKET();
    EdgeTypeFillerContext *edgeTypeFiller();
    antlr4::tree::TerminalNode *RIGHT_BRACKET_MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArcTypePointingLeftContext* arcTypePointingLeft();

  class  ArcTypeUndirectedContext : public antlr4::ParserRuleContext {
  public:
    ArcTypeUndirectedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TILDE_LEFT_BRACKET();
    EdgeTypeFillerContext *edgeTypeFiller();
    antlr4::tree::TerminalNode *RIGHT_BRACKET_TILDE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArcTypeUndirectedContext* arcTypeUndirected();

  class  SourceNodeTypeReferenceContext : public antlr4::ParserRuleContext {
  public:
    SourceNodeTypeReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    RegularIdentifierContext *regularIdentifier();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    NodeTypeFillerContext *nodeTypeFiller();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SourceNodeTypeReferenceContext* sourceNodeTypeReference();

  class  DestinationNodeTypeReferenceContext : public antlr4::ParserRuleContext {
  public:
    DestinationNodeTypeReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    RegularIdentifierContext *regularIdentifier();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    NodeTypeFillerContext *nodeTypeFiller();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DestinationNodeTypeReferenceContext* destinationNodeTypeReference();

  class  EdgeKindContext : public antlr4::ParserRuleContext {
  public:
    EdgeKindContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DIRECTED();
    antlr4::tree::TerminalNode *UNDIRECTED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgeKindContext* edgeKind();

  class  EndpointPairPhraseContext : public antlr4::ParserRuleContext {
  public:
    EndpointPairPhraseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONNECTING();
    EndpointPairContext *endpointPair();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EndpointPairPhraseContext* endpointPairPhrase();

  class  EndpointPairContext : public antlr4::ParserRuleContext {
  public:
    EndpointPairContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    std::vector<RegularIdentifierContext *> regularIdentifier();
    RegularIdentifierContext* regularIdentifier(size_t i);
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *RIGHT_ARROW();
    antlr4::tree::TerminalNode *LEFT_ARROW();
    antlr4::tree::TerminalNode *TILDE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EndpointPairContext* endpointPair();

  class  LabelSetPhraseContext : public antlr4::ParserRuleContext {
  public:
    LabelSetPhraseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LABEL();
    std::vector<LabelNameContext *> labelName();
    LabelNameContext* labelName(size_t i);
    antlr4::tree::TerminalNode *LABELS();
    std::vector<antlr4::tree::TerminalNode *> AMPERSAND();
    antlr4::tree::TerminalNode* AMPERSAND(size_t i);
    IsOrColonContext *isOrColon();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelSetPhraseContext* labelSetPhrase();

  class  LabelSetSpecificationContext : public antlr4::ParserRuleContext {
  public:
    LabelSetSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LabelNameContext *> labelName();
    LabelNameContext* labelName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AMPERSAND();
    antlr4::tree::TerminalNode* AMPERSAND(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelSetSpecificationContext* labelSetSpecification();

  class  PropertyTypesSpecificationContext : public antlr4::ParserRuleContext {
  public:
    PropertyTypesSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    std::vector<PropertyNameContext *> propertyName();
    PropertyNameContext* propertyName(size_t i);
    std::vector<PropertyValueTypeContext *> propertyValueType();
    PropertyValueTypeContext* propertyValueType(size_t i);
    std::vector<TypedContext *> typed();
    TypedContext* typed(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyTypesSpecificationContext* propertyTypesSpecification();

  class  PropertyValueTypeContext : public antlr4::ParserRuleContext {
  public:
    PropertyValueTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueTypeContext *valueType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyValueTypeContext* propertyValueType();

  class  BindingTableTypeContext : public antlr4::ParserRuleContext {
  public:
    BindingTableTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TABLE();
    FieldTypesSpecificationContext *fieldTypesSpecification();
    antlr4::tree::TerminalNode *BINDING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BindingTableTypeContext* bindingTableType();

  class  ValueTypeContext : public antlr4::ParserRuleContext {
  public:
    ValueTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ValueTypeContext() = default;
    void copyFrom(ValueTypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DynamicPropertyValueTypeLabelContext : public ValueTypeContext {
  public:
    DynamicPropertyValueTypeLabelContext(ValueTypeContext *ctx);

    antlr4::tree::TerminalNode *PROPERTY();
    antlr4::tree::TerminalNode *VALUE();
    antlr4::tree::TerminalNode *ANY();
    NotNullContext *notNull();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ClosedDynamicUnionTypeAtl1Context : public ValueTypeContext {
  public:
    ClosedDynamicUnionTypeAtl1Context(ValueTypeContext *ctx);

    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *LEFT_ANGLE_BRACKET();
    std::vector<ValueTypeContext *> valueType();
    ValueTypeContext* valueType(size_t i);
    antlr4::tree::TerminalNode *RIGHT_ANGLE_BRACKET();
    antlr4::tree::TerminalNode *VALUE();
    std::vector<antlr4::tree::TerminalNode *> VERTICAL_BAR();
    antlr4::tree::TerminalNode* VERTICAL_BAR(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ClosedDynamicUnionTypeAtl2Context : public ValueTypeContext {
  public:
    ClosedDynamicUnionTypeAtl2Context(ValueTypeContext *ctx);

    std::vector<ValueTypeContext *> valueType();
    ValueTypeContext* valueType(size_t i);
    antlr4::tree::TerminalNode *VERTICAL_BAR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PathValueTypeLabelContext : public ValueTypeContext {
  public:
    PathValueTypeLabelContext(ValueTypeContext *ctx);

    PathValueTypeContext *pathValueType();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListValueTypeAlt3Context : public ValueTypeContext {
  public:
    ListValueTypeAlt3Context(ValueTypeContext *ctx);

    ListValueTypeNameContext *listValueTypeName();
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    MaxLengthContext *maxLength();
    antlr4::tree::TerminalNode *RIGHT_BRACKET();
    NotNullContext *notNull();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListValueTypeAlt2Context : public ValueTypeContext {
  public:
    ListValueTypeAlt2Context(ValueTypeContext *ctx);

    ValueTypeContext *valueType();
    ListValueTypeNameContext *listValueTypeName();
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    MaxLengthContext *maxLength();
    antlr4::tree::TerminalNode *RIGHT_BRACKET();
    NotNullContext *notNull();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListValueTypeAlt1Context : public ValueTypeContext {
  public:
    ListValueTypeAlt1Context(ValueTypeContext *ctx);

    ListValueTypeNameContext *listValueTypeName();
    antlr4::tree::TerminalNode *LEFT_ANGLE_BRACKET();
    ValueTypeContext *valueType();
    antlr4::tree::TerminalNode *RIGHT_ANGLE_BRACKET();
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    MaxLengthContext *maxLength();
    antlr4::tree::TerminalNode *RIGHT_BRACKET();
    NotNullContext *notNull();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PredefinedTypeLabelContext : public ValueTypeContext {
  public:
    PredefinedTypeLabelContext(ValueTypeContext *ctx);

    PredefinedTypeContext *predefinedType();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RecordTypeLabelContext : public ValueTypeContext {
  public:
    RecordTypeLabelContext(ValueTypeContext *ctx);

    RecordTypeContext *recordType();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OpenDynamicUnionTypeLabelContext : public ValueTypeContext {
  public:
    OpenDynamicUnionTypeLabelContext(ValueTypeContext *ctx);

    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *VALUE();
    NotNullContext *notNull();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ValueTypeContext* valueType();
  ValueTypeContext* valueType(int precedence);
  class  TypedContext : public antlr4::ParserRuleContext {
  public:
    TypedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOUBLE_COLON();
    antlr4::tree::TerminalNode *TYPED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypedContext* typed();

  class  PredefinedTypeContext : public antlr4::ParserRuleContext {
  public:
    PredefinedTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanTypeContext *booleanType();
    CharacterStringTypeContext *characterStringType();
    ByteStringTypeContext *byteStringType();
    NumericTypeContext *numericType();
    TemporalTypeContext *temporalType();
    ReferenceValueTypeContext *referenceValueType();
    ImmaterialValueTypeContext *immaterialValueType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PredefinedTypeContext* predefinedType();

  class  BooleanTypeContext : public antlr4::ParserRuleContext {
  public:
    BooleanTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *BOOLEAN();
    NotNullContext *notNull();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanTypeContext* booleanType();

  class  CharacterStringTypeContext : public antlr4::ParserRuleContext {
  public:
    CharacterStringTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    MaxLengthContext *maxLength();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    NotNullContext *notNull();
    MinLengthContext *minLength();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *CHAR();
    FixedLengthContext *fixedLength();
    antlr4::tree::TerminalNode *VARCHAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CharacterStringTypeContext* characterStringType();

  class  ByteStringTypeContext : public antlr4::ParserRuleContext {
  public:
    ByteStringTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BYTES();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    MaxLengthContext *maxLength();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    NotNullContext *notNull();
    MinLengthContext *minLength();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *BINARY();
    FixedLengthContext *fixedLength();
    antlr4::tree::TerminalNode *VARBINARY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ByteStringTypeContext* byteStringType();

  class  MinLengthContext : public antlr4::ParserRuleContext {
  public:
    MinLengthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedIntegerContext *unsignedInteger();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MinLengthContext* minLength();

  class  MaxLengthContext : public antlr4::ParserRuleContext {
  public:
    MaxLengthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedIntegerContext *unsignedInteger();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MaxLengthContext* maxLength();

  class  FixedLengthContext : public antlr4::ParserRuleContext {
  public:
    FixedLengthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedIntegerContext *unsignedInteger();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FixedLengthContext* fixedLength();

  class  NumericTypeContext : public antlr4::ParserRuleContext {
  public:
    NumericTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExactNumericTypeContext *exactNumericType();
    ApproximateNumericTypeContext *approximateNumericType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumericTypeContext* numericType();

  class  ExactNumericTypeContext : public antlr4::ParserRuleContext {
  public:
    ExactNumericTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BinaryExactNumericTypeContext *binaryExactNumericType();
    DecimalExactNumericTypeContext *decimalExactNumericType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExactNumericTypeContext* exactNumericType();

  class  BinaryExactNumericTypeContext : public antlr4::ParserRuleContext {
  public:
    BinaryExactNumericTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SignedBinaryExactNumericTypeContext *signedBinaryExactNumericType();
    UnsignedBinaryExactNumericTypeContext *unsignedBinaryExactNumericType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BinaryExactNumericTypeContext* binaryExactNumericType();

  class  SignedBinaryExactNumericTypeContext : public antlr4::ParserRuleContext {
  public:
    SignedBinaryExactNumericTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT8();
    NotNullContext *notNull();
    antlr4::tree::TerminalNode *INT16();
    antlr4::tree::TerminalNode *INT32();
    antlr4::tree::TerminalNode *INT64();
    antlr4::tree::TerminalNode *INT128();
    antlr4::tree::TerminalNode *INT256();
    antlr4::tree::TerminalNode *SMALLINT();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    PrecisionContext *precision();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *BIGINT();
    VerboseBinaryExactNumericTypeContext *verboseBinaryExactNumericType();
    antlr4::tree::TerminalNode *SIGNED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SignedBinaryExactNumericTypeContext* signedBinaryExactNumericType();

  class  UnsignedBinaryExactNumericTypeContext : public antlr4::ParserRuleContext {
  public:
    UnsignedBinaryExactNumericTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UINT8();
    NotNullContext *notNull();
    antlr4::tree::TerminalNode *UINT16();
    antlr4::tree::TerminalNode *UINT32();
    antlr4::tree::TerminalNode *UINT64();
    antlr4::tree::TerminalNode *UINT128();
    antlr4::tree::TerminalNode *UINT256();
    antlr4::tree::TerminalNode *USMALLINT();
    antlr4::tree::TerminalNode *UINT();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    PrecisionContext *precision();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *UBIGINT();
    antlr4::tree::TerminalNode *UNSIGNED();
    VerboseBinaryExactNumericTypeContext *verboseBinaryExactNumericType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnsignedBinaryExactNumericTypeContext* unsignedBinaryExactNumericType();

  class  VerboseBinaryExactNumericTypeContext : public antlr4::ParserRuleContext {
  public:
    VerboseBinaryExactNumericTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER8();
    NotNullContext *notNull();
    antlr4::tree::TerminalNode *INTEGER16();
    antlr4::tree::TerminalNode *INTEGER32();
    antlr4::tree::TerminalNode *INTEGER64();
    antlr4::tree::TerminalNode *INTEGER128();
    antlr4::tree::TerminalNode *INTEGER256();
    antlr4::tree::TerminalNode *SMALL();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    PrecisionContext *precision();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *BIG();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VerboseBinaryExactNumericTypeContext* verboseBinaryExactNumericType();

  class  DecimalExactNumericTypeContext : public antlr4::ParserRuleContext {
  public:
    DecimalExactNumericTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DECIMAL();
    antlr4::tree::TerminalNode *DEC();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    PrecisionContext *precision();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *COMMA();
    ScaleContext *scale();
    NotNullContext *notNull();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DecimalExactNumericTypeContext* decimalExactNumericType();

  class  PrecisionContext : public antlr4::ParserRuleContext {
  public:
    PrecisionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedDecimalIntegerContext *unsignedDecimalInteger();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrecisionContext* precision();

  class  ScaleContext : public antlr4::ParserRuleContext {
  public:
    ScaleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedDecimalIntegerContext *unsignedDecimalInteger();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScaleContext* scale();

  class  ApproximateNumericTypeContext : public antlr4::ParserRuleContext {
  public:
    ApproximateNumericTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FLOAT16();
    NotNullContext *notNull();
    antlr4::tree::TerminalNode *FLOAT32();
    antlr4::tree::TerminalNode *FLOAT64();
    antlr4::tree::TerminalNode *FLOAT128();
    antlr4::tree::TerminalNode *FLOAT256();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    PrecisionContext *precision();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *COMMA();
    ScaleContext *scale();
    antlr4::tree::TerminalNode *REAL();
    antlr4::tree::TerminalNode *DOUBLE();
    antlr4::tree::TerminalNode *PRECISION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ApproximateNumericTypeContext* approximateNumericType();

  class  TemporalTypeContext : public antlr4::ParserRuleContext {
  public:
    TemporalTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TemporalInstantTypeContext *temporalInstantType();
    TemporalDurationTypeContext *temporalDurationType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemporalTypeContext* temporalType();

  class  TemporalInstantTypeContext : public antlr4::ParserRuleContext {
  public:
    TemporalInstantTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DatetimeTypeContext *datetimeType();
    LocaldatetimeTypeContext *localdatetimeType();
    DateTypeContext *dateType();
    TimeTypeContext *timeType();
    LocaltimeTypeContext *localtimeType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemporalInstantTypeContext* temporalInstantType();

  class  DatetimeTypeContext : public antlr4::ParserRuleContext {
  public:
    DatetimeTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ZONED();
    antlr4::tree::TerminalNode *DATETIME();
    NotNullContext *notNull();
    antlr4::tree::TerminalNode *TIMESTAMP();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *TIME();
    antlr4::tree::TerminalNode *ZONE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DatetimeTypeContext* datetimeType();

  class  LocaldatetimeTypeContext : public antlr4::ParserRuleContext {
  public:
    LocaldatetimeTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOCAL();
    antlr4::tree::TerminalNode *DATETIME();
    NotNullContext *notNull();
    antlr4::tree::TerminalNode *TIMESTAMP();
    antlr4::tree::TerminalNode *WITHOUT();
    antlr4::tree::TerminalNode *TIME();
    antlr4::tree::TerminalNode *ZONE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LocaldatetimeTypeContext* localdatetimeType();

  class  DateTypeContext : public antlr4::ParserRuleContext {
  public:
    DateTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATE();
    NotNullContext *notNull();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DateTypeContext* dateType();

  class  TimeTypeContext : public antlr4::ParserRuleContext {
  public:
    TimeTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ZONED();
    std::vector<antlr4::tree::TerminalNode *> TIME();
    antlr4::tree::TerminalNode* TIME(size_t i);
    NotNullContext *notNull();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *ZONE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimeTypeContext* timeType();

  class  LocaltimeTypeContext : public antlr4::ParserRuleContext {
  public:
    LocaltimeTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOCAL();
    std::vector<antlr4::tree::TerminalNode *> TIME();
    antlr4::tree::TerminalNode* TIME(size_t i);
    NotNullContext *notNull();
    antlr4::tree::TerminalNode *WITHOUT();
    antlr4::tree::TerminalNode *ZONE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LocaltimeTypeContext* localtimeType();

  class  TemporalDurationTypeContext : public antlr4::ParserRuleContext {
  public:
    TemporalDurationTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DURATION();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *YEAR();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *MONTH();
    antlr4::tree::TerminalNode *DAY();
    antlr4::tree::TerminalNode *SECOND();
    NotNullContext *notNull();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemporalDurationTypeContext* temporalDurationType();

  class  ReferenceValueTypeContext : public antlr4::ParserRuleContext {
  public:
    ReferenceValueTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    GraphReferenceValueTypeContext *graphReferenceValueType();
    BindingTableReferenceValueTypeContext *bindingTableReferenceValueType();
    NodeReferenceValueTypeContext *nodeReferenceValueType();
    EdgeReferenceValueTypeContext *edgeReferenceValueType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReferenceValueTypeContext* referenceValueType();

  class  ImmaterialValueTypeContext : public antlr4::ParserRuleContext {
  public:
    ImmaterialValueTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NULL_KW();
    NotNullContext *notNull();
    antlr4::tree::TerminalNode *NOTHING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImmaterialValueTypeContext* immaterialValueType();

  class  GraphReferenceValueTypeContext : public antlr4::ParserRuleContext {
  public:
    GraphReferenceValueTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *GRAPH();
    antlr4::tree::TerminalNode *PROPERTY();
    NotNullContext *notNull();
    NestedGraphTypeSpecificationContext *nestedGraphTypeSpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphReferenceValueTypeContext* graphReferenceValueType();

  class  BindingTableReferenceValueTypeContext : public antlr4::ParserRuleContext {
  public:
    BindingTableReferenceValueTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BindingTableTypeContext *bindingTableType();
    NotNullContext *notNull();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BindingTableReferenceValueTypeContext* bindingTableReferenceValueType();

  class  NodeReferenceValueTypeContext : public antlr4::ParserRuleContext {
  public:
    NodeReferenceValueTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NodeSynonymContext *nodeSynonym();
    antlr4::tree::TerminalNode *ANY();
    NotNullContext *notNull();
    NodeTypeSpecificationContext *nodeTypeSpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NodeReferenceValueTypeContext* nodeReferenceValueType();

  class  EdgeReferenceValueTypeContext : public antlr4::ParserRuleContext {
  public:
    EdgeReferenceValueTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EdgeSynonymContext *edgeSynonym();
    antlr4::tree::TerminalNode *ANY();
    NotNullContext *notNull();
    EdgeTypeSpecificationContext *edgeTypeSpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgeReferenceValueTypeContext* edgeReferenceValueType();

  class  PathValueTypeContext : public antlr4::ParserRuleContext {
  public:
    PathValueTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PATH();
    NotNullContext *notNull();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathValueTypeContext* pathValueType();

  class  ListValueTypeNameContext : public antlr4::ParserRuleContext {
  public:
    ListValueTypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIST();
    antlr4::tree::TerminalNode *ARRAY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListValueTypeNameContext* listValueTypeName();

  class  RecordTypeContext : public antlr4::ParserRuleContext {
  public:
    RecordTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RECORD();
    antlr4::tree::TerminalNode *ANY();
    NotNullContext *notNull();
    FieldTypesSpecificationContext *fieldTypesSpecification();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecordTypeContext* recordType();

  class  FieldTypesSpecificationContext : public antlr4::ParserRuleContext {
  public:
    FieldTypesSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    std::vector<FieldNameContext *> fieldName();
    FieldNameContext* fieldName(size_t i);
    std::vector<ValueTypeContext *> valueType();
    ValueTypeContext* valueType(size_t i);
    std::vector<TypedContext *> typed();
    TypedContext* typed(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldTypesSpecificationContext* fieldTypesSpecification();

  class  NotNullContext : public antlr4::ParserRuleContext {
  public:
    NotNullContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *NULL_KW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NotNullContext* notNull();

  class  SearchConditionContext : public antlr4::ParserRuleContext {
  public:
    SearchConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanValueExpressionContext *booleanValueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SearchConditionContext* searchCondition();

  class  PredicateContext : public antlr4::ParserRuleContext {
  public:
    PredicateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXISTS();
    antlr4::tree::TerminalNode *LEFT_BRACE();
    GraphPatternContext *graphPattern();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    NestedQuerySpecificationContext *nestedQuerySpecification();
    std::vector<MatchStatementContext *> matchStatement();
    MatchStatementContext* matchStatement(size_t i);
    ValueExpressionPrimaryContext *valueExpressionPrimary();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *NULL_KW();
    antlr4::tree::TerminalNode *NOT();
    TypedContext *typed();
    ValueTypeContext *valueType();
    std::vector<ElementVariableReferenceContext *> elementVariableReference();
    ElementVariableReferenceContext* elementVariableReference(size_t i);
    antlr4::tree::TerminalNode *DIRECTED();
    LabelExpressionContext *labelExpression();
    antlr4::tree::TerminalNode *LABELED();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SOURCE();
    antlr4::tree::TerminalNode *OF();
    antlr4::tree::TerminalNode *DESTINATION();
    antlr4::tree::TerminalNode *ALL_DIFFERENT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *SAME();
    antlr4::tree::TerminalNode *PROPERTY_EXISTS();
    PropertyNameContext *propertyName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PredicateContext* predicate();

  class  CompOpContext : public antlr4::ParserRuleContext {
  public:
    CompOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQUALS_OPERATOR();
    antlr4::tree::TerminalNode *NOT_EQUALS_OPERATOR();
    antlr4::tree::TerminalNode *LEFT_ANGLE_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_ANGLE_BRACKET();
    antlr4::tree::TerminalNode *LESS_THAN_OR_EQUALS_OPERATOR();
    antlr4::tree::TerminalNode *GREATER_THAN_OR_EQUALS_OPERATOR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompOpContext* compOp();

  class  ValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    ValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ValueExpressionContext() = default;
    void copyFrom(ValueExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConjunctiveExprAltContext : public ValueExpressionContext {
  public:
    ConjunctiveExprAltContext(ValueExpressionContext *ctx);

    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *AND();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PropertyGraphExprAltContext : public ValueExpressionContext {
  public:
    PropertyGraphExprAltContext(ValueExpressionContext *ctx);

    antlr4::tree::TerminalNode *GRAPH();
    GraphExpressionContext *graphExpression();
    antlr4::tree::TerminalNode *PROPERTY();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultDivExprAltContext : public ValueExpressionContext {
  public:
    MultDivExprAltContext(ValueExpressionContext *ctx);

    antlr4::Token *operator_ = nullptr;
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *ASTERISK();
    antlr4::tree::TerminalNode *SOLIDUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BindingTableExprAltContext : public ValueExpressionContext {
  public:
    BindingTableExprAltContext(ValueExpressionContext *ctx);

    antlr4::tree::TerminalNode *TABLE();
    BindingTableExpressionContext *bindingTableExpression();
    antlr4::tree::TerminalNode *BINDING();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InExprAltContext : public ValueExpressionContext {
  public:
    InExprAltContext(ValueExpressionContext *ctx);

    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SignedExprAltContext : public ValueExpressionContext {
  public:
    SignedExprAltContext(ValueExpressionContext *ctx);

    antlr4::Token *sign = nullptr;
    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *PLUS_SIGN();
    antlr4::tree::TerminalNode *MINUS_SIGN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IsNotExprAltContext : public ValueExpressionContext {
  public:
    IsNotExprAltContext(ValueExpressionContext *ctx);

    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *IS();
    TruthValueContext *truthValue();
    antlr4::tree::TerminalNode *NOT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NormalizedPredicateExprAltContext : public ValueExpressionContext {
  public:
    NormalizedPredicateExprAltContext(ValueExpressionContext *ctx);

    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *NORMALIZED();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *NFC();
    antlr4::tree::TerminalNode *NFD();
    antlr4::tree::TerminalNode *NFKC();
    antlr4::tree::TerminalNode *NFKD();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotExprAltContext : public ValueExpressionContext {
  public:
    NotExprAltContext(ValueExpressionContext *ctx);

    antlr4::tree::TerminalNode *NOT();
    ValueExpressionContext *valueExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ValueFunctionExprAltContext : public ValueExpressionContext {
  public:
    ValueFunctionExprAltContext(ValueExpressionContext *ctx);

    ValueFunctionContext *valueFunction();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConcatenationExprAltContext : public ValueExpressionContext {
  public:
    ConcatenationExprAltContext(ValueExpressionContext *ctx);

    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *CONCATENATION_OPERATOR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DisjunctiveExprAltContext : public ValueExpressionContext {
  public:
    DisjunctiveExprAltContext(ValueExpressionContext *ctx);

    antlr4::Token *operator_ = nullptr;
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *XOR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ComparisonExprAltContext : public ValueExpressionContext {
  public:
    ComparisonExprAltContext(ValueExpressionContext *ctx);

    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    CompOpContext *compOp();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrimaryExprAltContext : public ValueExpressionContext {
  public:
    PrimaryExprAltContext(ValueExpressionContext *ctx);

    ValueExpressionPrimaryContext *valueExpressionPrimary();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddSubtractExprAltContext : public ValueExpressionContext {
  public:
    AddSubtractExprAltContext(ValueExpressionContext *ctx);

    antlr4::Token *operator_ = nullptr;
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *PLUS_SIGN();
    antlr4::tree::TerminalNode *MINUS_SIGN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PredicateExprAltContext : public ValueExpressionContext {
  public:
    PredicateExprAltContext(ValueExpressionContext *ctx);

    PredicateContext *predicate();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ValueExpressionContext* valueExpression();
  ValueExpressionContext* valueExpression(int precedence);
  class  ValueFunctionContext : public antlr4::ParserRuleContext {
  public:
    ValueFunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumericValueFunctionContext *numericValueFunction();
    DatetimeSubtractionContext *datetimeSubtraction();
    DatetimeValueFunctionContext *datetimeValueFunction();
    DurationValueFunctionContext *durationValueFunction();
    CharacterOrByteStringFunctionContext *characterOrByteStringFunction();
    ListValueFunctionContext *listValueFunction();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueFunctionContext* valueFunction();

  class  BooleanValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    BooleanValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueExpressionContext *valueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanValueExpressionContext* booleanValueExpression();

  class  CharacterOrByteStringFunctionContext : public antlr4::ParserRuleContext {
  public:
    CharacterOrByteStringFunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    StringLengthContext *stringLength();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *LEFT();
    antlr4::tree::TerminalNode *RIGHT();
    antlr4::tree::TerminalNode *TRIM();
    TrimOperandsContext *trimOperands();
    antlr4::tree::TerminalNode *UPPER();
    antlr4::tree::TerminalNode *LOWER();
    antlr4::tree::TerminalNode *BTRIM();
    antlr4::tree::TerminalNode *LTRIM();
    antlr4::tree::TerminalNode *RTRIM();
    antlr4::tree::TerminalNode *NORMALIZE();
    antlr4::tree::TerminalNode *NFC();
    antlr4::tree::TerminalNode *NFD();
    antlr4::tree::TerminalNode *NFKC();
    antlr4::tree::TerminalNode *NFKD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CharacterOrByteStringFunctionContext* characterOrByteStringFunction();

  class  AggregatingValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    AggregatingValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueExpressionContext *valueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AggregatingValueExpressionContext* aggregatingValueExpression();

  class  ValueExpressionPrimaryContext : public antlr4::ParserRuleContext {
  public:
    ValueExpressionPrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParenthesizedValueExpressionContext *parenthesizedValueExpression();
    AggregateFunctionContext *aggregateFunction();
    UnsignedValueSpecificationContext *unsignedValueSpecification();
    PathValueConstructorContext *pathValueConstructor();
    antlr4::tree::TerminalNode *VALUE();
    NestedQuerySpecificationContext *nestedQuerySpecification();
    CaseExpressionContext *caseExpression();
    antlr4::tree::TerminalNode *CAST();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *AS();
    ValueTypeContext *valueType();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    ValueExpressionContext *valueExpression();
    NullLiteralContext *nullLiteral();
    antlr4::tree::TerminalNode *ELEMENT_ID();
    ElementVariableReferenceContext *elementVariableReference();
    antlr4::tree::TerminalNode *LET();
    std::vector<LetVariableDefinitionContext *> letVariableDefinition();
    LetVariableDefinitionContext* letVariableDefinition(size_t i);
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *END();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    BindingVariableReferenceContext *bindingVariableReference();
    ValueExpressionPrimaryContext *valueExpressionPrimary();
    antlr4::tree::TerminalNode *PERIOD();
    PropertyNameContext *propertyName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ValueExpressionPrimaryContext* valueExpressionPrimary();
  ValueExpressionPrimaryContext* valueExpressionPrimary(int precedence);
  class  ParenthesizedValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    ParenthesizedValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *RIGHT_PAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParenthesizedValueExpressionContext* parenthesizedValueExpression();

  class  NonParenthesizedValueExpressionPrimarySpecialCaseContext : public antlr4::ParserRuleContext {
  public:
    NonParenthesizedValueExpressionPrimarySpecialCaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AggregateFunctionContext *aggregateFunction();
    UnsignedValueSpecificationContext *unsignedValueSpecification();
    PathValueConstructorContext *pathValueConstructor();
    ValueExpressionPrimaryContext *valueExpressionPrimary();
    antlr4::tree::TerminalNode *PERIOD();
    PropertyNameContext *propertyName();
    antlr4::tree::TerminalNode *VALUE();
    NestedQuerySpecificationContext *nestedQuerySpecification();
    CaseExpressionContext *caseExpression();
    antlr4::tree::TerminalNode *CAST();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *AS();
    ValueTypeContext *valueType();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    ValueExpressionContext *valueExpression();
    NullLiteralContext *nullLiteral();
    antlr4::tree::TerminalNode *ELEMENT_ID();
    ElementVariableReferenceContext *elementVariableReference();
    antlr4::tree::TerminalNode *LET();
    std::vector<LetVariableDefinitionContext *> letVariableDefinition();
    LetVariableDefinitionContext* letVariableDefinition(size_t i);
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *END();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NonParenthesizedValueExpressionPrimarySpecialCaseContext* nonParenthesizedValueExpressionPrimarySpecialCase();

  class  UnsignedValueSpecificationContext : public antlr4::ParserRuleContext {
  public:
    UnsignedValueSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedLiteralContext *unsignedLiteral();
    antlr4::tree::TerminalNode *GENERAL_PARAMETER_REFERENCE();
    antlr4::tree::TerminalNode *SESSION_USER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnsignedValueSpecificationContext* unsignedValueSpecification();

  class  NonNegativeIntegerSpecificationContext : public antlr4::ParserRuleContext {
  public:
    NonNegativeIntegerSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedIntegerContext *unsignedInteger();
    antlr4::tree::TerminalNode *GENERAL_PARAMETER_REFERENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NonNegativeIntegerSpecificationContext* nonNegativeIntegerSpecification();

  class  CaseExpressionContext : public antlr4::ParserRuleContext {
  public:
    CaseExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NULLIF();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *COALESCE();
    antlr4::tree::TerminalNode *CASE();
    CaseOperandContext *caseOperand();
    antlr4::tree::TerminalNode *END();
    std::vector<SimpleWhenClauseContext *> simpleWhenClause();
    SimpleWhenClauseContext* simpleWhenClause(size_t i);
    ElseClauseContext *elseClause();
    std::vector<SearchedWhenClauseContext *> searchedWhenClause();
    SearchedWhenClauseContext* searchedWhenClause(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseExpressionContext* caseExpression();

  class  SimpleWhenClauseContext : public antlr4::ParserRuleContext {
  public:
    SimpleWhenClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    std::vector<WhenOperandContext *> whenOperand();
    WhenOperandContext* whenOperand(size_t i);
    antlr4::tree::TerminalNode *THEN();
    ResultContext *result();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleWhenClauseContext* simpleWhenClause();

  class  SearchedWhenClauseContext : public antlr4::ParserRuleContext {
  public:
    SearchedWhenClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    SearchConditionContext *searchCondition();
    antlr4::tree::TerminalNode *THEN();
    ResultContext *result();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SearchedWhenClauseContext* searchedWhenClause();

  class  ElseClauseContext : public antlr4::ParserRuleContext {
  public:
    ElseClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    ResultContext *result();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElseClauseContext* elseClause();

  class  CaseOperandContext : public antlr4::ParserRuleContext {
  public:
    CaseOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NonParenthesizedValueExpressionPrimarySpecialCaseContext *nonParenthesizedValueExpressionPrimarySpecialCase();
    ElementVariableReferenceContext *elementVariableReference();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseOperandContext* caseOperand();

  class  WhenOperandContext : public antlr4::ParserRuleContext {
  public:
    WhenOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NonParenthesizedValueExpressionPrimarySpecialCaseContext *nonParenthesizedValueExpressionPrimarySpecialCase();
    CompOpContext *compOp();
    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *NULL_KW();
    antlr4::tree::TerminalNode *NOT();
    TypedContext *typed();
    ValueTypeContext *valueType();
    antlr4::tree::TerminalNode *NORMALIZED();
    antlr4::tree::TerminalNode *NFC();
    antlr4::tree::TerminalNode *NFD();
    antlr4::tree::TerminalNode *NFKC();
    antlr4::tree::TerminalNode *NFKD();
    antlr4::tree::TerminalNode *DIRECTED();
    LabelExpressionContext *labelExpression();
    antlr4::tree::TerminalNode *LABELED();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SOURCE();
    antlr4::tree::TerminalNode *OF();
    ElementVariableReferenceContext *elementVariableReference();
    antlr4::tree::TerminalNode *DESTINATION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhenOperandContext* whenOperand();

  class  ResultContext : public antlr4::ParserRuleContext {
  public:
    ResultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueExpressionContext *valueExpression();
    NullLiteralContext *nullLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResultContext* result();

  class  AggregateFunctionContext : public antlr4::ParserRuleContext {
  public:
    AggregateFunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COUNT();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *ASTERISK();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *AVG();
    antlr4::tree::TerminalNode *MAX();
    antlr4::tree::TerminalNode *MIN();
    antlr4::tree::TerminalNode *SUM();
    antlr4::tree::TerminalNode *COLLECT_LIST();
    antlr4::tree::TerminalNode *STDDEV_SAMP();
    antlr4::tree::TerminalNode *STDDEV_POP();
    SetQuantifierContext *setQuantifier();
    std::vector<NumericValueExpressionContext *> numericValueExpression();
    NumericValueExpressionContext* numericValueExpression(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *PERCENTILE_CONT();
    antlr4::tree::TerminalNode *PERCENTILE_DISC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AggregateFunctionContext* aggregateFunction();

  class  SetQuantifierContext : public antlr4::ParserRuleContext {
  public:
    SetQuantifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DISTINCT();
    antlr4::tree::TerminalNode *ALL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetQuantifierContext* setQuantifier();

  class  BindingVariableReferenceContext : public antlr4::ParserRuleContext {
  public:
    BindingVariableReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BindingVariableContext *bindingVariable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BindingVariableReferenceContext* bindingVariableReference();

  class  ElementVariableReferenceContext : public antlr4::ParserRuleContext {
  public:
    ElementVariableReferenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BindingVariableReferenceContext *bindingVariableReference();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementVariableReferenceContext* elementVariableReference();

  class  PathValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    PathValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueExpressionContext *valueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathValueExpressionContext* pathValueExpression();

  class  PathValueConstructorContext : public antlr4::ParserRuleContext {
  public:
    PathValueConstructorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PATH();
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *RIGHT_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathValueConstructorContext* pathValueConstructor();

  class  ListValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    ListValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueExpressionContext *valueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListValueExpressionContext* listValueExpression();

  class  ListValueFunctionContext : public antlr4::ParserRuleContext {
  public:
    ListValueFunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRIM();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    ListValueExpressionContext *listValueExpression();
    antlr4::tree::TerminalNode *COMMA();
    NumericValueExpressionContext *numericValueExpression();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *ELEMENTS();
    PathValueExpressionContext *pathValueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListValueFunctionContext* listValueFunction();

  class  ListValueConstructorContext : public antlr4::ParserRuleContext {
  public:
    ListValueConstructorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_BRACKET();
    ListValueTypeNameContext *listValueTypeName();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListValueConstructorContext* listValueConstructor();

  class  RecordConstructorContext : public antlr4::ParserRuleContext {
  public:
    RecordConstructorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    antlr4::tree::TerminalNode *RECORD();
    std::vector<FieldNameContext *> fieldName();
    FieldNameContext* fieldName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecordConstructorContext* recordConstructor();

  class  TruthValueContext : public antlr4::ParserRuleContext {
  public:
    TruthValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOLEAN_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TruthValueContext* truthValue();

  class  NumericValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *sign = nullptr;
    antlr4::Token *operator_ = nullptr;
    NumericValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<NumericValueExpressionContext *> numericValueExpression();
    NumericValueExpressionContext* numericValueExpression(size_t i);
    antlr4::tree::TerminalNode *PLUS_SIGN();
    antlr4::tree::TerminalNode *MINUS_SIGN();
    ValueExpressionPrimaryContext *valueExpressionPrimary();
    NumericValueFunctionContext *numericValueFunction();
    antlr4::tree::TerminalNode *ASTERISK();
    antlr4::tree::TerminalNode *SOLIDUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumericValueExpressionContext* numericValueExpression();
  NumericValueExpressionContext* numericValueExpression(int precedence);
  class  NumericValueFunctionContext : public antlr4::ParserRuleContext {
  public:
    NumericValueFunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_PAREN();
    CharacterStringValueExpressionContext *characterStringValueExpression();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *CHAR_LENGTH();
    antlr4::tree::TerminalNode *CHARACTER_LENGTH();
    ByteStringValueExpressionContext *byteStringValueExpression();
    antlr4::tree::TerminalNode *BYTE_LENGTH();
    antlr4::tree::TerminalNode *OCTET_LENGTH();
    antlr4::tree::TerminalNode *PATH_LENGTH();
    PathValueExpressionContext *pathValueExpression();
    antlr4::tree::TerminalNode *CARDINALITY();
    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *SIZE();
    ListValueExpressionContext *listValueExpression();
    antlr4::tree::TerminalNode *ABS();
    antlr4::tree::TerminalNode *MOD();
    std::vector<NumericValueExpressionContext *> numericValueExpression();
    NumericValueExpressionContext* numericValueExpression(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *SIN();
    antlr4::tree::TerminalNode *COS();
    antlr4::tree::TerminalNode *TAN();
    antlr4::tree::TerminalNode *COT();
    antlr4::tree::TerminalNode *SINH();
    antlr4::tree::TerminalNode *COSH();
    antlr4::tree::TerminalNode *TANH();
    antlr4::tree::TerminalNode *ASIN();
    antlr4::tree::TerminalNode *ACOS();
    antlr4::tree::TerminalNode *ATAN();
    antlr4::tree::TerminalNode *DEGREES();
    antlr4::tree::TerminalNode *RADIANS();
    antlr4::tree::TerminalNode *LOG_KW();
    antlr4::tree::TerminalNode *LOG10();
    antlr4::tree::TerminalNode *LN();
    antlr4::tree::TerminalNode *EXP();
    antlr4::tree::TerminalNode *POWER();
    antlr4::tree::TerminalNode *SQRT();
    antlr4::tree::TerminalNode *FLOOR();
    antlr4::tree::TerminalNode *CEIL();
    antlr4::tree::TerminalNode *CEILING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumericValueFunctionContext* numericValueFunction();

  class  CharacterStringValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    CharacterStringValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueExpressionContext *valueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CharacterStringValueExpressionContext* characterStringValueExpression();

  class  ByteStringValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    ByteStringValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueExpressionContext *valueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ByteStringValueExpressionContext* byteStringValueExpression();

  class  TrimOperandsContext : public antlr4::ParserRuleContext {
  public:
    TrimOperandsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *LEADING();
    antlr4::tree::TerminalNode *TRAILING();
    antlr4::tree::TerminalNode *BOTH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TrimOperandsContext* trimOperands();

  class  StringLengthContext : public antlr4::ParserRuleContext {
  public:
    StringLengthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumericValueExpressionContext *numericValueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringLengthContext* stringLength();

  class  DatetimeValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    DatetimeValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueExpressionContext *valueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DatetimeValueExpressionContext* datetimeValueExpression();

  class  DatetimeValueFunctionContext : public antlr4::ParserRuleContext {
  public:
    DatetimeValueFunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CURRENT_DATE();
    antlr4::tree::TerminalNode *DATE();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    DateStringContext *dateString();
    RecordConstructorContext *recordConstructor();
    antlr4::tree::TerminalNode *CURRENT_TIME();
    antlr4::tree::TerminalNode *ZONED_TIME();
    TimeStringContext *timeString();
    antlr4::tree::TerminalNode *LOCAL_TIME();
    antlr4::tree::TerminalNode *CURRENT_TIMESTAMP();
    antlr4::tree::TerminalNode *ZONED_DATETIME();
    DatetimeStringContext *datetimeString();
    antlr4::tree::TerminalNode *LOCAL_TIMESTAMP();
    antlr4::tree::TerminalNode *LOCAL_DATETIME();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DatetimeValueFunctionContext* datetimeValueFunction();

  class  DurationValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    DurationValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ValueExpressionContext *valueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DurationValueExpressionContext* durationValueExpression();

  class  DatetimeSubtractionContext : public antlr4::ParserRuleContext {
  public:
    DatetimeSubtractionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DURATION_BETWEEN();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    std::vector<DatetimeValueExpressionContext *> datetimeValueExpression();
    DatetimeValueExpressionContext* datetimeValueExpression(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    antlr4::tree::TerminalNode *YEAR();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *MONTH();
    antlr4::tree::TerminalNode *DAY();
    antlr4::tree::TerminalNode *SECOND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DatetimeSubtractionContext* datetimeSubtraction();

  class  DurationValueFunctionContext : public antlr4::ParserRuleContext {
  public:
    DurationValueFunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DURATION();
    antlr4::tree::TerminalNode *LEFT_PAREN();
    antlr4::tree::TerminalNode *RIGHT_PAREN();
    DurationStringContext *durationString();
    RecordConstructorContext *recordConstructor();
    antlr4::tree::TerminalNode *ABS();
    ValueExpressionContext *valueExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DurationValueFunctionContext* durationValueFunction();

  class  ObjectNameContext : public antlr4::ParserRuleContext {
  public:
    ObjectNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ObjectNameContext* objectName();

  class  ObjectNameOrBindingVariableContext : public antlr4::ParserRuleContext {
  public:
    ObjectNameOrBindingVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RegularIdentifierContext *regularIdentifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ObjectNameOrBindingVariableContext* objectNameOrBindingVariable();

  class  DirectoryNameContext : public antlr4::ParserRuleContext {
  public:
    DirectoryNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DirectoryNameContext* directoryName();

  class  SchemaNameContext : public antlr4::ParserRuleContext {
  public:
    SchemaNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SchemaNameContext* schemaName();

  class  GraphNameContext : public antlr4::ParserRuleContext {
  public:
    GraphNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RegularIdentifierContext *regularIdentifier();
    DelimitedGraphNameContext *delimitedGraphName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphNameContext* graphName();

  class  DelimitedGraphNameContext : public antlr4::ParserRuleContext {
  public:
    DelimitedGraphNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOUBLE_QUOTED_CHARACTER_SEQUENCE();
    antlr4::tree::TerminalNode *ACCENT_QUOTED_CHARACTER_SEQUENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DelimitedGraphNameContext* delimitedGraphName();

  class  GraphTypeNameContext : public antlr4::ParserRuleContext {
  public:
    GraphTypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GraphTypeNameContext* graphTypeName();

  class  NodeTypeNameContext : public antlr4::ParserRuleContext {
  public:
    NodeTypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NodeTypeNameContext* nodeTypeName();

  class  EdgeTypeNameContext : public antlr4::ParserRuleContext {
  public:
    EdgeTypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgeTypeNameContext* edgeTypeName();

  class  BindingTableNameContext : public antlr4::ParserRuleContext {
  public:
    BindingTableNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RegularIdentifierContext *regularIdentifier();
    DelimitedBindingTableNameContext *delimitedBindingTableName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BindingTableNameContext* bindingTableName();

  class  DelimitedBindingTableNameContext : public antlr4::ParserRuleContext {
  public:
    DelimitedBindingTableNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOUBLE_QUOTED_CHARACTER_SEQUENCE();
    antlr4::tree::TerminalNode *ACCENT_QUOTED_CHARACTER_SEQUENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DelimitedBindingTableNameContext* delimitedBindingTableName();

  class  ProcedureNameContext : public antlr4::ParserRuleContext {
  public:
    ProcedureNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcedureNameContext* procedureName();

  class  LabelNameContext : public antlr4::ParserRuleContext {
  public:
    LabelNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LabelNameContext* labelName();

  class  PropertyNameContext : public antlr4::ParserRuleContext {
  public:
    PropertyNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyNameContext* propertyName();

  class  FieldNameContext : public antlr4::ParserRuleContext {
  public:
    FieldNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldNameContext* fieldName();

  class  ElementVariableContext : public antlr4::ParserRuleContext {
  public:
    ElementVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BindingVariableContext *bindingVariable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementVariableContext* elementVariable();

  class  PathVariableContext : public antlr4::ParserRuleContext {
  public:
    PathVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BindingVariableContext *bindingVariable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathVariableContext* pathVariable();

  class  SubpathVariableContext : public antlr4::ParserRuleContext {
  public:
    SubpathVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RegularIdentifierContext *regularIdentifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubpathVariableContext* subpathVariable();

  class  BindingVariableContext : public antlr4::ParserRuleContext {
  public:
    BindingVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RegularIdentifierContext *regularIdentifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BindingVariableContext* bindingVariable();

  class  UnsignedLiteralContext : public antlr4::ParserRuleContext {
  public:
    UnsignedLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedNumericLiteralContext *unsignedNumericLiteral();
    GeneralLiteralContext *generalLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnsignedLiteralContext* unsignedLiteral();

  class  GeneralLiteralContext : public antlr4::ParserRuleContext {
  public:
    GeneralLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOLEAN_LITERAL();
    CharacterStringLiteralContext *characterStringLiteral();
    antlr4::tree::TerminalNode *BYTE_STRING_LITERAL();
    TemporalLiteralContext *temporalLiteral();
    DurationLiteralContext *durationLiteral();
    NullLiteralContext *nullLiteral();
    ListLiteralContext *listLiteral();
    RecordLiteralContext *recordLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GeneralLiteralContext* generalLiteral();

  class  TemporalLiteralContext : public antlr4::ParserRuleContext {
  public:
    TemporalLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DATE();
    DateStringContext *dateString();
    antlr4::tree::TerminalNode *TIME();
    TimeStringContext *timeString();
    DatetimeStringContext *datetimeString();
    antlr4::tree::TerminalNode *DATETIME();
    antlr4::tree::TerminalNode *TIMESTAMP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemporalLiteralContext* temporalLiteral();

  class  ListLiteralContext : public antlr4::ParserRuleContext {
  public:
    ListLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ListValueConstructorContext *listValueConstructor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ListLiteralContext* listLiteral();

  class  RecordLiteralContext : public antlr4::ParserRuleContext {
  public:
    RecordLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RecordConstructorContext *recordConstructor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RecordLiteralContext* recordLiteral();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RegularIdentifierContext *regularIdentifier();
    antlr4::tree::TerminalNode *DOUBLE_QUOTED_CHARACTER_SEQUENCE();
    antlr4::tree::TerminalNode *ACCENT_QUOTED_CHARACTER_SEQUENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();

  class  RegularIdentifierContext : public antlr4::ParserRuleContext {
  public:
    RegularIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REGULAR_IDENTIFIER();
    NonReservedWordsContext *nonReservedWords();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RegularIdentifierContext* regularIdentifier();

  class  TimeZoneStringContext : public antlr4::ParserRuleContext {
  public:
    TimeZoneStringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CharacterStringLiteralContext *characterStringLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimeZoneStringContext* timeZoneString();

  class  CharacterStringLiteralContext : public antlr4::ParserRuleContext {
  public:
    CharacterStringLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SINGLE_QUOTED_CHARACTER_SEQUENCE();
    antlr4::tree::TerminalNode *DOUBLE_QUOTED_CHARACTER_SEQUENCE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CharacterStringLiteralContext* characterStringLiteral();

  class  UnsignedNumericLiteralContext : public antlr4::ParserRuleContext {
  public:
    UnsignedNumericLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExactNumericLiteralContext *exactNumericLiteral();
    ApproximateNumericLiteralContext *approximateNumericLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnsignedNumericLiteralContext* unsignedNumericLiteral();

  class  ExactNumericLiteralContext : public antlr4::ParserRuleContext {
  public:
    ExactNumericLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_EXACT_NUMBER_SUFFIX();
    antlr4::tree::TerminalNode *UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_EXACT_NUMBER_SUFFIX();
    antlr4::tree::TerminalNode *UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITHOUT_SUFFIX();
    antlr4::tree::TerminalNode *UNSIGNED_DECIMAL_INTEGER_WITH_EXACT_NUMBER_SUFFIX();
    UnsignedIntegerContext *unsignedInteger();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExactNumericLiteralContext* exactNumericLiteral();

  class  ApproximateNumericLiteralContext : public antlr4::ParserRuleContext {
  public:
    ApproximateNumericLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX();
    antlr4::tree::TerminalNode *UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITHOUT_SUFFIX();
    antlr4::tree::TerminalNode *UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX();
    antlr4::tree::TerminalNode *UNSIGNED_DECIMAL_INTEGER_WITH_APPROXIMATE_NUMBER_SUFFIX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ApproximateNumericLiteralContext* approximateNumericLiteral();

  class  UnsignedIntegerContext : public antlr4::ParserRuleContext {
  public:
    UnsignedIntegerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNSIGNED_DECIMAL_INTEGER();
    antlr4::tree::TerminalNode *UNSIGNED_HEXADECIMAL_INTEGER();
    antlr4::tree::TerminalNode *UNSIGNED_OCTAL_INTEGER();
    antlr4::tree::TerminalNode *UNSIGNED_BINARY_INTEGER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnsignedIntegerContext* unsignedInteger();

  class  UnsignedDecimalIntegerContext : public antlr4::ParserRuleContext {
  public:
    UnsignedDecimalIntegerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNSIGNED_DECIMAL_INTEGER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnsignedDecimalIntegerContext* unsignedDecimalInteger();

  class  NullLiteralContext : public antlr4::ParserRuleContext {
  public:
    NullLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NULL_KW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NullLiteralContext* nullLiteral();

  class  DateStringContext : public antlr4::ParserRuleContext {
  public:
    DateStringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CharacterStringLiteralContext *characterStringLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DateStringContext* dateString();

  class  TimeStringContext : public antlr4::ParserRuleContext {
  public:
    TimeStringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CharacterStringLiteralContext *characterStringLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimeStringContext* timeString();

  class  DatetimeStringContext : public antlr4::ParserRuleContext {
  public:
    DatetimeStringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CharacterStringLiteralContext *characterStringLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DatetimeStringContext* datetimeString();

  class  DurationLiteralContext : public antlr4::ParserRuleContext {
  public:
    DurationLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DURATION();
    DurationStringContext *durationString();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DurationLiteralContext* durationLiteral();

  class  DurationStringContext : public antlr4::ParserRuleContext {
  public:
    DurationStringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CharacterStringLiteralContext *characterStringLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DurationStringContext* durationString();

  class  NodeSynonymContext : public antlr4::ParserRuleContext {
  public:
    NodeSynonymContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NODE();
    antlr4::tree::TerminalNode *VERTEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NodeSynonymContext* nodeSynonym();

  class  EdgesSynonymContext : public antlr4::ParserRuleContext {
  public:
    EdgesSynonymContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EDGES();
    antlr4::tree::TerminalNode *RELATIONSHIPS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgesSynonymContext* edgesSynonym();

  class  EdgeSynonymContext : public antlr4::ParserRuleContext {
  public:
    EdgeSynonymContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EDGE();
    antlr4::tree::TerminalNode *RELATIONSHIP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgeSynonymContext* edgeSynonym();

  class  NonReservedWordsContext : public antlr4::ParserRuleContext {
  public:
    NonReservedWordsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACYCLIC();
    antlr4::tree::TerminalNode *BINDING();
    antlr4::tree::TerminalNode *BINDINGS();
    antlr4::tree::TerminalNode *CONNECTING();
    antlr4::tree::TerminalNode *DESTINATION();
    antlr4::tree::TerminalNode *DIFFERENT();
    antlr4::tree::TerminalNode *DIRECTED();
    antlr4::tree::TerminalNode *EDGE();
    antlr4::tree::TerminalNode *EDGES();
    antlr4::tree::TerminalNode *ELEMENT();
    antlr4::tree::TerminalNode *ELEMENTS();
    antlr4::tree::TerminalNode *FIRST();
    antlr4::tree::TerminalNode *GRAPH();
    antlr4::tree::TerminalNode *GROUPS();
    antlr4::tree::TerminalNode *KEEP();
    antlr4::tree::TerminalNode *LABEL();
    antlr4::tree::TerminalNode *LABELED();
    antlr4::tree::TerminalNode *LABELS();
    antlr4::tree::TerminalNode *LAST();
    antlr4::tree::TerminalNode *NFC();
    antlr4::tree::TerminalNode *NFD();
    antlr4::tree::TerminalNode *NFKC();
    antlr4::tree::TerminalNode *NFKD();
    antlr4::tree::TerminalNode *NO();
    antlr4::tree::TerminalNode *NODE();
    antlr4::tree::TerminalNode *NORMALIZED();
    antlr4::tree::TerminalNode *ONLY();
    antlr4::tree::TerminalNode *ORDINALITY();
    antlr4::tree::TerminalNode *PROPERTY();
    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *RELATIONSHIP();
    antlr4::tree::TerminalNode *RELATIONSHIPS();
    antlr4::tree::TerminalNode *REPEATABLE();
    antlr4::tree::TerminalNode *SHORTEST();
    antlr4::tree::TerminalNode *SIMPLE();
    antlr4::tree::TerminalNode *SOURCE();
    antlr4::tree::TerminalNode *TABLE();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *TRAIL();
    antlr4::tree::TerminalNode *TRANSACTION();
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *UNDIRECTED();
    antlr4::tree::TerminalNode *VERTEX();
    antlr4::tree::TerminalNode *WALK();
    antlr4::tree::TerminalNode *WITHOUT();
    antlr4::tree::TerminalNode *WRITE();
    antlr4::tree::TerminalNode *ZONE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NonReservedWordsContext* nonReservedWords();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool compositeQueryExpressionSempred(CompositeQueryExpressionContext *_localctx, size_t predicateIndex);
  bool labelExpressionSempred(LabelExpressionContext *_localctx, size_t predicateIndex);
  bool simplifiedTermSempred(SimplifiedTermContext *_localctx, size_t predicateIndex);
  bool simplifiedFactorLowSempred(SimplifiedFactorLowContext *_localctx, size_t predicateIndex);
  bool valueTypeSempred(ValueTypeContext *_localctx, size_t predicateIndex);
  bool valueExpressionSempred(ValueExpressionContext *_localctx, size_t predicateIndex);
  bool valueExpressionPrimarySempred(ValueExpressionPrimaryContext *_localctx, size_t predicateIndex);
  bool numericValueExpressionSempred(NumericValueExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

