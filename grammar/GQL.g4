/*
 * Compressed ISO GQL Grammar for ANTLR4
 * Based on ISO/IEC 39075:2024 Graph Query Language (GQL)
 *
 * COMPRESSION SUMMARY:
 * ====================
 * This grammar has been optimized by removing intermediate rules while preserving
 * exact syntax and semantics. The following types of rules were compressed:
 *
 * 1. SIMPLE PASS-THROUGH RULES (inlined directly):
 *    - endTransactionCommand -> rollbackCommand | commitCommand
 *    - compositeQueryPrimary -> linearQueryStatement  
 *    - deleteItem -> valueExpression
 *    - graphInitializer -> EQUALS_OPERATOR graphExpression
 *    - bindingTableInitializer -> EQUALS_OPERATOR bindingTableExpression
 *    - valueInitializer -> EQUALS_OPERATOR valueExpression
 *    - currentGraph -> CURRENT_PROPERTY_GRAPH | CURRENT_GRAPH
 *    - copyOfGraphType -> COPY OF graphTypeReference
 *    - graphTypeLikeGraph -> LIKE graphExpression
 *
 * 2. TERMINAL WRAPPER RULES (inlined):
 *    - rollbackCommand -> ROLLBACK
 *    - commitCommand -> COMMIT
 *    - sessionCloseCommand -> SESSION CLOSE
 *    - insertStatement -> INSERT insertGraphPattern
 *
 * 3. SINGLE-USE INTERMEDIATE RULES (merged with parent):
 *    - Many *Part2 rules in predicates
 *    - Simple type wrapper rules
 *    - Single-alternative rules used only once
 *
 * 4. SIMPLIFIED HIERARCHIES:
 *    - Flattened deeply nested expression hierarchies where safe
 *    - Combined related alternative rules
 *    - Merged simple container rules with their contents
 *
 * PRESERVED ELEMENTS:
 * ===================
 * - All terminal tokens and lexer rules (unchanged)
 * - Type-checking semantics (no runtime type checking added)
 * - All language constructs and syntax variations
 * - ISO GQL compliance maintained
 * - Parser tree structure for semantically distinct constructs
 *
 * RESULT: Reduced from ~400 parser rules to ~280 rules (~30% reduction)
 * while maintaining identical language recognition.
 */

grammar GQL;

options { caseInsensitive = true; }

// ===============================================================
// 6 <GQL-program> - Core program structure
// ===============================================================

gqlProgram
    : programActivity (SEMICOLON? programActivity)* EOF
    ;

programActivity
    : sessionActivity
    | transactionActivity
    | linearCatalogModifyingStatement
    | callProcedureStatement
    | compositeQueryStatement
    ;

sessionActivity
    : sessionResetCommand
    | sessionSetCommand
    | SESSION CLOSE
    | sessionResetCommand+ sessionSetCommand*
    | sessionSetCommand+ sessionResetCommand*
    ;

transactionActivity
    : startTransactionCommand (procedureBody (ROLLBACK | COMMIT)?)?
    | procedureBody (ROLLBACK | COMMIT)?
    | (ROLLBACK | COMMIT)
    ;

// ===============================================================
// 7.1 <session set command> - Session management (compressed)
// ===============================================================

sessionSetCommand
    : SESSION SET (sessionSetSchemaClause | sessionSetGraphClause | sessionSetTimeZoneClause | sessionSetParameterClause)
    ;

sessionSetSchemaClause
    : SCHEMA schemaReference
    ;

sessionSetGraphClause
    : PROPERTY? GRAPH graphExpression
    ;

sessionSetTimeZoneClause
    : TIME ZONE timeZoneString
    ;

sessionSetParameterClause
    : PROPERTY? GRAPH ((IF NOT EXISTS)? GENERAL_PARAMETER_REFERENCE) (typed? graphReferenceValueType)? (EQUALS_OPERATOR graphExpression)
    | BINDING? TABLE ((IF NOT EXISTS)? GENERAL_PARAMETER_REFERENCE) (typed? bindingTableReferenceValueType)? (EQUALS_OPERATOR bindingTableExpression)
    | VALUE ((IF NOT EXISTS)? GENERAL_PARAMETER_REFERENCE) (typed? valueType)? (EQUALS_OPERATOR valueExpression)
    ;

// ===============================================================
// 7.2 <session reset command> - Simplified
// ===============================================================

sessionResetCommand
    : SESSION RESET (ALL | ALL? (PARAMETERS | CHARACTERISTICS) | SCHEMA | PROPERTY? GRAPH | TIME ZONE | PARAMETER? GENERAL_PARAMETER_REFERENCE)?
    ;

// ===============================================================
// 8.1 <start transaction command> - Transaction control
// ===============================================================

startTransactionCommand
    : START TRANSACTION (transactionAccessMode (COMMA transactionAccessMode)*)?
    ;

transactionAccessMode
    : READ ONLY
    | READ WRITE
    ;

// ===============================================================
// 9.1 <nested procedure specification> - Procedures
// ===============================================================

nestedProcedureSpecification
    : LEFT_BRACE procedureBody RIGHT_BRACE
    ;

procedureBody
    : atSchemaClause? bindingVariableDefinition* statementBlock
    ;

statementBlock
    : statement nextStatement*
    ;

statement
    : linearCatalogModifyingStatement
    | linearDataModifyingStatement
    | compositeQueryStatement
    ;

nextStatement
    : NEXT yieldClause? statement
    ;

// ===============================================================
// 10.1 <graph variable definition> - Variable definitions (compressed)
// ===============================================================

bindingVariableDefinition
    : PROPERTY? GRAPH bindingVariable (typed? graphReferenceValueType)? (EQUALS_OPERATOR graphExpression)
    | BINDING? TABLE bindingVariable (typed? bindingTableReferenceValueType)? (EQUALS_OPERATOR bindingTableExpression)
    | VALUE bindingVariable (typed? valueType)? (EQUALS_OPERATOR valueExpression)
    ;

// ===============================================================
// 11.1 <graph expression> - Graph expressions (compressed)
// ===============================================================

graphExpression
    : graphReference
    | VARIABLE valueExpressionPrimary
    | parenthesizedValueExpression
    | nonParenthesizedValueExpressionPrimarySpecialCase
    | objectNameOrBindingVariable
    | CURRENT_PROPERTY_GRAPH
    | CURRENT_GRAPH
    ;

// ===============================================================
// 11.2 <binding table expression> - Table expressions
// ===============================================================

bindingTableExpression
    : nestedQuerySpecification
    | bindingTableReference
    | VARIABLE valueExpressionPrimary
    | parenthesizedValueExpression
    | nonParenthesizedValueExpressionPrimarySpecialCase
    | objectNameOrBindingVariable
    ;

// ===============================================================
// 12.1 <linear catalog-modifying statement> - Schema operations (compressed)
// ===============================================================

linearCatalogModifyingStatement
    : (primitiveCatalogModifyingStatement | callProcedureStatement)+
    ;

primitiveCatalogModifyingStatement
    : CREATE SCHEMA (IF NOT EXISTS)? (catalogSchemaParentAndName | schemaName)
    | DROP SCHEMA (IF EXISTS)? (catalogSchemaParentAndName | schemaName)
    | CREATE (PROPERTY? GRAPH (IF NOT EXISTS)? | OR REPLACE PROPERTY? GRAPH) catalogGraphParentAndName (openGraphType | ofGraphType)? graphSource?
    | DROP PROPERTY? GRAPH (IF EXISTS)? catalogGraphParentAndName
    | CREATE (PROPERTY? GRAPH TYPE (IF NOT EXISTS)? | OR REPLACE PROPERTY? GRAPH TYPE) catalogGraphTypeParentAndName graphTypeSource
    | DROP PROPERTY? GRAPH TYPE (IF EXISTS)? catalogGraphTypeParentAndName
    ;

openGraphType
    : typed? ANY (PROPERTY? GRAPH)?
    ;

ofGraphType
    : LIKE graphExpression
    | typed? graphTypeReference
    | typed? (PROPERTY? GRAPH)? nestedGraphTypeSpecification
    ;

graphTypeSource
    : AS? (COPY OF graphTypeReference)
    | LIKE graphExpression
    | AS? nestedGraphTypeSpecification
    ;

graphSource
    : AS COPY OF graphExpression
    ;

// ===============================================================
// 13.1 <linear data-modifying statement> - Data operations (compressed)
// ===============================================================

linearDataModifyingStatement
    : focusedLinearDataModifyingStatement
    | ambientLinearDataModifyingStatement
    ;

focusedLinearDataModifyingStatement
    : useGraphClause simpleDataAccessingStatement+ primitiveResultStatement?
    | useGraphClause nestedProcedureSpecification
    ;

ambientLinearDataModifyingStatement
    : simpleDataAccessingStatement+ primitiveResultStatement?
    | nestedProcedureSpecification
    ;

simpleDataAccessingStatement
    : simpleQueryStatement
    | primitiveDataModifyingStatement
    | callProcedureStatement
    ;

primitiveDataModifyingStatement
    : INSERT insertGraphPattern
    | SET setItem (COMMA setItem)*
    | REMOVE removeItem (COMMA removeItem)*
    | (DETACH | NODETACH)? DELETE valueExpression (COMMA valueExpression)*
    ;

// ===============================================================
// 13.2-13.5 <set/remove operations> - Property operations (compressed)
// ===============================================================

setItem
    : bindingVariableReference PERIOD propertyName EQUALS_OPERATOR valueExpression
    | bindingVariableReference EQUALS_OPERATOR LEFT_BRACE propertyKeyValuePairList? RIGHT_BRACE
    | bindingVariableReference isOrColon labelName
    ;

removeItem
    : bindingVariableReference PERIOD propertyName
    | bindingVariableReference isOrColon labelName
    ;

// ===============================================================
// 14.1 <composite query statement> - Query composition (compressed)
// ===============================================================

compositeQueryStatement
    : compositeQueryExpression
    ;

compositeQueryExpression
    : compositeQueryExpression queryConjunction linearQueryStatement
    | linearQueryStatement
    ;

queryConjunction
    : (UNION | EXCEPT | INTERSECT) setQuantifier?
    | OTHERWISE
    ;

// ===============================================================
// 14.3 <linear query statement> - Query structure (compressed)
// ===============================================================

linearQueryStatement
    : focusedLinearQueryStatement
    | ambientLinearQueryStatement
    ;

focusedLinearQueryStatement
    : (useGraphClause simpleQueryStatement+)* useGraphClause simpleQueryStatement+ primitiveResultStatement
    | useGraphClause primitiveResultStatement
    | useGraphClause nestedQuerySpecification
    | selectStatement
    ;

ambientLinearQueryStatement
    : simpleQueryStatement* primitiveResultStatement
    | nestedQuerySpecification
    ;

nestedQuerySpecification
    : LEFT_PAREN compositeQueryStatement RIGHT_PAREN
    ;

simpleQueryStatement
    : primitiveQueryStatement
    | callProcedureStatement
    ;

primitiveQueryStatement
    : matchStatement
    | LET letVariableDefinition (COMMA letVariableDefinition)*
    | FOR bindingVariable IN valueExpression (WITH (ORDINALITY | OFFSET) bindingVariable)?
    | FILTER (whereClause | searchCondition)
    | orderByAndPageStatement
    ;

// ===============================================================
// 14.4 <match statement> - Pattern matching
// ===============================================================

matchStatement
    : MATCH graphPatternBindingTable
    | OPTIONAL (MATCH graphPatternBindingTable | LEFT_BRACE matchStatement+ RIGHT_BRACE | LEFT_PAREN matchStatement+ RIGHT_PAREN)
    ;

// ===============================================================
// 14.7 <let statement> - Variable binding (compressed)
// ===============================================================

letVariableDefinition
    : VALUE bindingVariable (typed? valueType)? (EQUALS_OPERATOR valueExpression)
    | bindingVariable EQUALS_OPERATOR valueExpression
    ;

// ===============================================================
// 14.9 <order by and page statement> - Result ordering
// ===============================================================

orderByAndPageStatement
    : orderByClause offsetClause? limitClause?
    | offsetClause limitClause?
    | limitClause
    ;

// ===============================================================
// 14.10 <primitive result statement> - Result handling
// ===============================================================

primitiveResultStatement
    : RETURN setQuantifier? (ASTERISK | returnItem (COMMA returnItem)*) groupByClause? orderByAndPageStatement?
    | FINISH
    ;

returnItem
    : aggregatingValueExpression (AS identifier)?
    ;

// ===============================================================
// 14.12 <select statement> - SQL-style selection
// ===============================================================

selectStatement
    : SELECT setQuantifier? (ASTERISK | selectItem (COMMA selectItem)*) (selectStatementBody whereClause? groupByClause? havingClause? orderByClause? offsetClause? limitClause?)?
    ;

selectItem
    : aggregatingValueExpression (AS identifier)?
    ;

havingClause
    : HAVING searchCondition
    ;

selectStatementBody
    : FROM (selectGraphMatch (COMMA selectGraphMatch)* | selectQuerySpecification)
    ;

selectGraphMatch
    : graphExpression matchStatement
    ;

selectQuerySpecification
    : nestedQuerySpecification
    | graphExpression nestedQuerySpecification
    ;

// ===============================================================
// 15.1 <call procedure statement> - Procedure calls
// ===============================================================

callProcedureStatement
    : OPTIONAL? CALL procedureCall
    ;

procedureCall
    : (LEFT_PAREN bindingVariableReference (COMMA bindingVariableReference)* RIGHT_PAREN)? nestedProcedureSpecification
    | procedureReference LEFT_PAREN (valueExpression (COMMA valueExpression)*)? RIGHT_PAREN yieldClause?
    ;

// ===============================================================
// 16.1 <at schema clasue> - Schema context
// ===============================================================

atSchemaClause
    : AT schemaReference
    ;

// ===============================================================
// 16.2 <use graph clause> - Graph context
// ===============================================================

useGraphClause
    : USE graphExpression
    ;

// ===============================================================
// 16.3 <graph pattern binding table> - Pattern binding
// ===============================================================

graphPatternBindingTable
    : graphPattern (YIELD bindingVariableReference (COMMA bindingVariableReference)*)?
    ;

// ===============================================================
// 16.4 <graph pattern> - Graph pattern structure
// ===============================================================

graphPattern
    : matchMode? pathPattern (COMMA pathPattern)* keepClause? (WHERE searchCondition)?
    ;

matchMode
    : REPEATABLE (ELEMENT BINDINGS? | ELEMENTS)
    | DIFFERENT (edgeSynonym BINDINGS? | edgesSynonym)
    ;

pathPattern
    : (pathVariable EQUALS_OPERATOR)? pathPatternPrefix? pathPatternExpression
    ;

keepClause
    : KEEP pathPatternPrefix
    ;

// ===============================================================
// 16.5 <insert graph pattern> - Insert patterns
// ===============================================================

insertGraphPattern
    : insertPathPattern (COMMA insertPathPattern)*
    ;

insertPathPattern
    : insertNodePattern (insertEdgePattern insertNodePattern)*
    ;

insertNodePattern
    : LEFT_PAREN insertElementPatternFiller? RIGHT_PAREN
    ;

insertEdgePattern
    : LEFT_ARROW_BRACKET insertElementPatternFiller? RIGHT_BRACKET_MINUS
    | MINUS_LEFT_BRACKET insertElementPatternFiller? BRACKET_RIGHT_ARROW
    | TILDE_LEFT_BRACKET insertElementPatternFiller? RIGHT_BRACKET_TILDE
    ;

insertElementPatternFiller
    : elementVariableDeclaration labelAndPropertySetSpecification?
    | elementVariableDeclaration? labelAndPropertySetSpecification
    ;

labelAndPropertySetSpecification
    : isOrColon labelSetSpecification elementPropertySpecification?
    | (isOrColon labelSetSpecification)? elementPropertySpecification
    ;

// ===============================================================
// 16.6 <path pattern prefix> - Path search modes
// ===============================================================

pathPatternPrefix
    : pathModePrefix
    | pathSearchPrefix
    ;

pathModePrefix
    : (WALK | TRAIL | SIMPLE | ACYCLIC) (PATH | PATHS)?
    ;

pathSearchPrefix
    : ALL (WALK | TRAIL | SIMPLE | ACYCLIC)? (PATH | PATHS)?
    | ANY nonNegativeIntegerSpecification? (WALK | TRAIL | SIMPLE | ACYCLIC)? (PATH | PATHS)?
    | shortestPathSearch
    ;

shortestPathSearch
    : ALL SHORTEST (WALK | TRAIL | SIMPLE | ACYCLIC)? (PATH | PATHS)?
    | ANY SHORTEST (WALK | TRAIL | SIMPLE | ACYCLIC)? (PATH | PATHS)?
    | SHORTEST nonNegativeIntegerSpecification (WALK | TRAIL | SIMPLE | ACYCLIC)? (PATH | PATHS)?
    | SHORTEST nonNegativeIntegerSpecification? (WALK | TRAIL | SIMPLE | ACYCLIC)? (PATH | PATHS)? (GROUP | GROUPS)
    ;

// ===============================================================
// 16.7 <path pattern expression> - Path expressions
// ===============================================================

pathPatternExpression
    : pathTerm                                              #ppePathTerm
    | pathTerm (MULTISET_ALTERNATION_OPERATOR pathTerm)+    #ppeMultisetAlternation
    | pathTerm (VERTICAL_BAR pathTerm)+                     #ppePatternUnion
    ;

pathTerm
    : pathFactor+
    ;

pathFactor
    : pathPrimary                           #pfPathPrimary
    | pathPrimary graphPatternQuantifier    #pfQuantifiedPathPrimary
    | pathPrimary QUESTION_MARK             #pfQuestionedPathPrimary
    ;

pathPrimary
    : elementPattern                        #ppElementPattern
    | parenthesizedPathPatternExpression    #ppParenthesizedPathPatternExpression
    | simplifiedPathPatternExpression       #ppSimplifiedPathPatternExpression
    ;

elementPattern
    : LEFT_PAREN elementPatternFiller RIGHT_PAREN
    | fullEdgePattern
    | abbreviatedEdgePattern
    ;

elementPatternFiller
    : elementVariableDeclaration? isLabelExpression? elementPatternPredicate?
    ;

elementVariableDeclaration
    : elementVariable
    ;

isLabelExpression
    : isOrColon labelExpression
    ;

isOrColon
    : IS
    | COLON
    ;

elementPatternPredicate
    : WHERE searchCondition
    | elementPropertySpecification
    ;

elementPropertySpecification
    : LEFT_BRACE propertyKeyValuePairList RIGHT_BRACE
    ;

propertyKeyValuePairList
    : propertyKeyValuePair (COMMA propertyKeyValuePair)*
    ;

propertyKeyValuePair
    : propertyName COLON valueExpression
    ;

fullEdgePattern
    : LEFT_ARROW_BRACKET elementPatternFiller RIGHT_BRACKET_MINUS
    | TILDE_LEFT_BRACKET elementPatternFiller RIGHT_BRACKET_TILDE
    | MINUS_LEFT_BRACKET elementPatternFiller BRACKET_RIGHT_ARROW
    | LEFT_ARROW_TILDE_BRACKET elementPatternFiller RIGHT_BRACKET_TILDE
    | TILDE_LEFT_BRACKET elementPatternFiller BRACKET_TILDE_RIGHT_ARROW
    | LEFT_ARROW_BRACKET elementPatternFiller BRACKET_RIGHT_ARROW
    | MINUS_LEFT_BRACKET elementPatternFiller RIGHT_BRACKET_MINUS
    ;

abbreviatedEdgePattern
    : LEFT_ARROW
    | TILDE
    | RIGHT_ARROW
    | LEFT_ARROW_TILDE
    | TILDE_RIGHT_ARROW
    | LEFT_MINUS_RIGHT
    | MINUS_SIGN
    ;

parenthesizedPathPatternExpression
    : LEFT_PAREN (subpathVariable EQUALS_OPERATOR)? pathModePrefix? pathPatternExpression (WHERE searchCondition)? RIGHT_PAREN
    ;

// ===============================================================
// 16.8 <label expression> - Label matching
// ===============================================================

labelExpression
    : EXCLAMATION_MARK labelExpression                  #labelExpressionNegation
    | labelExpression AMPERSAND labelExpression         #labelExpressionConjunction
    | labelExpression VERTICAL_BAR labelExpression      #labelExpressionDisjunction
    | labelName                                         #labelExpressionName
    | PERCENT                                           #labelExpressionWildcard
    | LEFT_PAREN labelExpression RIGHT_PAREN            #labelExpressionParenthesized
    ;

// ===============================================================
// 16.11 <graph pattern quantifier> - Quantification
// ===============================================================

graphPatternQuantifier
    : ASTERISK
    | PLUS_SIGN
    | LEFT_BRACE unsignedInteger RIGHT_BRACE
    | LEFT_BRACE unsignedInteger? COMMA unsignedInteger? RIGHT_BRACE
    ;

// ===============================================================
// 16.12 <simplified path pattern expression> - Simplified patterns (compressed)
// ===============================================================

simplifiedPathPatternExpression
    : LEFT_MINUS_SLASH simplifiedContents SLASH_MINUS
    | TILDE_SLASH simplifiedContents SLASH_TILDE
    | MINUS_SLASH simplifiedContents SLASH_MINUS_RIGHT
    | LEFT_TILDE_SLASH simplifiedContents SLASH_TILDE
    | TILDE_SLASH simplifiedContents SLASH_TILDE_RIGHT
    | LEFT_MINUS_SLASH simplifiedContents SLASH_MINUS_RIGHT
    | MINUS_SLASH simplifiedContents SLASH_MINUS
    ;

simplifiedContents
    : simplifiedTerm
    | simplifiedTerm VERTICAL_BAR simplifiedTerm (VERTICAL_BAR simplifiedTerm)*
    | simplifiedTerm MULTISET_ALTERNATION_OPERATOR simplifiedTerm (MULTISET_ALTERNATION_OPERATOR simplifiedTerm)*
    ;

simplifiedTerm
    : simplifiedFactorLow                        #simplifiedFactorLowLabel
    | simplifiedTerm simplifiedFactorLow      #simplifiedConcatenationLabel
    ;

simplifiedFactorLow
    : simplifiedFactorHigh                                     #simplifiedFactorHighLabel
    | simplifiedFactorLow AMPERSAND simplifiedFactorHigh #simplifiedConjunctionLabel
    ;

simplifiedFactorHigh
    : simplifiedTertiary
    | simplifiedTertiary graphPatternQuantifier
    | simplifiedTertiary QUESTION_MARK
    ;

simplifiedTertiary
    : LEFT_ANGLE_BRACKET simplifiedSecondary
    | TILDE simplifiedSecondary
    | simplifiedSecondary RIGHT_ANGLE_BRACKET
    | LEFT_ARROW_TILDE simplifiedSecondary
    | TILDE simplifiedSecondary RIGHT_ANGLE_BRACKET
    | LEFT_ANGLE_BRACKET simplifiedSecondary RIGHT_ANGLE_BRACKET
    | MINUS_SIGN simplifiedSecondary
    | simplifiedSecondary
    ;

simplifiedSecondary
    : simplifiedPrimary
    | EXCLAMATION_MARK simplifiedPrimary
    ;

simplifiedPrimary
    : labelName
    | LEFT_PAREN simplifiedContents RIGHT_PAREN
    ;

// ===============================================================
// 16.13 <where clause> - Filtering
// ===============================================================

whereClause
    : WHERE searchCondition
    ;

// ===============================================================
// 16.14 <yield clause> - Output specification
// ===============================================================

yieldClause
    : YIELD yieldItem (COMMA yieldItem)*
    ;

yieldItem
    : fieldName (AS bindingVariable)?
    ;

// ===============================================================
// 16.15 <group by clasue> - Grouping
// ===============================================================

groupByClause
    : GROUP BY (bindingVariableReference (COMMA bindingVariableReference)* | LEFT_PAREN RIGHT_PAREN)
    ;

// ===============================================================
// 16.16 <order by clasue> - Sorting
// ===============================================================

orderByClause
    : ORDER BY sortSpecification (COMMA sortSpecification)*
    ;

sortSpecification
    : aggregatingValueExpression (ASC | ASCENDING | DESC | DESCENDING)? (NULLS (FIRST | LAST))?
    ;

// ===============================================================
// 16.18 <limit clause> - Result limiting
// ===============================================================

limitClause
    : LIMIT nonNegativeIntegerSpecification
    ;

// ===============================================================
// 16.19 <offset clause> - Result offsetting
// ===============================================================

offsetClause
    : (OFFSET | SKIP_RESERVED_WORD) nonNegativeIntegerSpecification
    ;

// ===============================================================
// 17.1 <schema reference> - Schema references (compressed)
// ===============================================================

schemaReference
    : absoluteCatalogSchemaReference
    | relativeCatalogSchemaReference
    | schemaName
    | SUBSTITUTED_PARAMETER_REFERENCE
    ;

absoluteCatalogSchemaReference
    : SOLIDUS
    | absoluteDirectoryPath schemaName
    ;

catalogSchemaParentAndName
    : absoluteDirectoryPath schemaName
    ;

relativeCatalogSchemaReference
    : HOME_SCHEMA
    | CURRENT_SCHEMA
    | PERIOD
    | relativeDirectoryPath schemaName
    ;

absoluteDirectoryPath
    : SOLIDUS simpleDirectoryPath?
    ;

relativeDirectoryPath
    : DOUBLE_PERIOD (SOLIDUS DOUBLE_PERIOD)* SOLIDUS simpleDirectoryPath?
    ;

simpleDirectoryPath
    : (directoryName SOLIDUS)+
    ;

// ===============================================================
// 17.2 <graph reference> - Graph references (compressed)
// ===============================================================

graphReference
    : catalogObjectParentReference graphName
    | delimitedGraphName
    | HOME_PROPERTY_GRAPH
    | HOME_GRAPH
    | SUBSTITUTED_PARAMETER_REFERENCE
    ;

catalogGraphParentAndName
    : catalogObjectParentReference? graphName
    ;

// ===============================================================
// 17.3 <graph type reference> - Graph type references (compressed)
// ===============================================================

graphTypeReference
    : catalogGraphTypeParentAndName
    | SUBSTITUTED_PARAMETER_REFERENCE
    ;

catalogGraphTypeParentAndName
    : catalogObjectParentReference? graphTypeName
    ;

// ===============================================================
// 17.4 <binding table reference> - Table references (compressed)
// ===============================================================

bindingTableReference
    : catalogObjectParentReference bindingTableName
    | delimitedBindingTableName
    | SUBSTITUTED_PARAMETER_REFERENCE
    ;

// ===============================================================
// 17.5 <procedure reference> - Procedure references (compressed)
// ===============================================================

procedureReference
    : catalogObjectParentReference? procedureName
    | SUBSTITUTED_PARAMETER_REFERENCE
    ;

// ===============================================================
// 17.6 <catalog object parent reference> - Object references
// ===============================================================

catalogObjectParentReference
    : schemaReference SOLIDUS? (objectName PERIOD)*
    |  (objectName PERIOD)+
    ;

// ===============================================================
// 18.1 <nested graph type specification> - Type specifications
// ===============================================================

nestedGraphTypeSpecification
    : LEFT_BRACE elementTypeSpecification (COMMA elementTypeSpecification)* RIGHT_BRACE
    ;

elementTypeSpecification
    : nodeTypeSpecification
    | edgeTypeSpecification
    ;

// ===============================================================
// 18.2 <node type specification> - Node types
// ===============================================================

nodeTypeSpecification
    : (nodeSynonym TYPE? nodeTypeName)? LEFT_PAREN regularIdentifier? nodeTypeFiller? RIGHT_PAREN
    | nodeSynonym TYPE? nodeTypePhraseFiller (AS regularIdentifier)?
    ;

nodeTypePhraseFiller
    : nodeTypeName nodeTypeFiller?
    | nodeTypeFiller
    ;

nodeTypeFiller
    : labelSetPhrase? IMPLIES nodeTypeImpliedContent?
    | nodeTypeImpliedContent
    ;

nodeTypeImpliedContent
    : labelSetPhrase propertyTypesSpecification?
    | propertyTypesSpecification
    ;

// ===============================================================
// 18.3 <edge type specification> - Edge types
// ===============================================================

edgeTypeSpecification
    : (edgeKind? edgeSynonym TYPE? edgeTypeName)? (edgeTypePatternDirected | edgeTypePatternUndirected)
    | edgeKind edgeSynonym TYPE? edgeTypePhraseFiller endpointPairPhrase
    ;

edgeTypePhraseFiller
    : edgeTypeName edgeTypeFiller?
    | edgeTypeFiller
    ;

edgeTypeFiller
    : labelSetPhrase? IMPLIES edgeTypeImpliedContent?
    | edgeTypeImpliedContent
    ;

edgeTypeImpliedContent
    : labelSetPhrase propertyTypesSpecification?
    | propertyTypesSpecification
    ;

edgeTypePatternDirected
    : sourceNodeTypeReference arcTypePointingRight destinationNodeTypeReference
    | destinationNodeTypeReference arcTypePointingLeft sourceNodeTypeReference
    ;

edgeTypePatternUndirected
    : sourceNodeTypeReference arcTypeUndirected destinationNodeTypeReference
    ;

arcTypePointingRight
    : MINUS_LEFT_BRACKET edgeTypeFiller BRACKET_RIGHT_ARROW
    ;

arcTypePointingLeft
    : LEFT_ARROW_BRACKET edgeTypeFiller RIGHT_BRACKET_MINUS
    ;

arcTypeUndirected
    : TILDE_LEFT_BRACKET edgeTypeFiller RIGHT_BRACKET_TILDE
    ;

sourceNodeTypeReference
    : LEFT_PAREN regularIdentifier RIGHT_PAREN
    | LEFT_PAREN nodeTypeFiller? RIGHT_PAREN
    ;

destinationNodeTypeReference
    : LEFT_PAREN regularIdentifier RIGHT_PAREN
    | LEFT_PAREN nodeTypeFiller? RIGHT_PAREN
    ;

edgeKind
    : DIRECTED
    | UNDIRECTED
    ;

endpointPairPhrase
    : CONNECTING endpointPair
    ;

endpointPair
    : LEFT_PAREN regularIdentifier (TO | RIGHT_ARROW) regularIdentifier RIGHT_PAREN
    | LEFT_PAREN regularIdentifier LEFT_ARROW regularIdentifier RIGHT_PAREN
    | LEFT_PAREN regularIdentifier (TO | TILDE) regularIdentifier RIGHT_PAREN
    ;

// ===============================================================
// 18.4 <label set phrase> - Label specifications (compressed)
// ===============================================================

labelSetPhrase
    : LABEL labelName
    | LABELS labelName (AMPERSAND labelName)*
    | isOrColon labelName (AMPERSAND labelName)*
    ;

labelSetSpecification
    : labelName (AMPERSAND labelName)*
    ;

// ===============================================================
// 18.5 <property types specification> - Property types
// ===============================================================

propertyTypesSpecification
    : LEFT_BRACE (propertyName typed? propertyValueType (COMMA propertyName typed? propertyValueType)*)? RIGHT_BRACE
    ;

// ===============================================================
// 18.6 <property value type> - Value types (compressed)
// ===============================================================

propertyValueType
    : valueType
    ;

// ===============================================================
// 18.8 <binding table type> - Table types
// ===============================================================

bindingTableType
    : BINDING? TABLE fieldTypesSpecification
    ;

// ===============================================================
// 18.9 <value type> - Type system
// ===============================================================

valueType
    : predefinedType                                                                                                                              #predefinedTypeLabel
    // <constructed value type>
    | pathValueType                                                                                                                               #pathValueTypeLabel
    | listValueTypeName LEFT_ANGLE_BRACKET valueType RIGHT_ANGLE_BRACKET (LEFT_BRACKET maxLength RIGHT_BRACKET)? notNull?     #listValueTypeAlt1
    | valueType listValueTypeName (LEFT_BRACKET maxLength RIGHT_BRACKET)? notNull?                                                    #listValueTypeAlt2
    | listValueTypeName (LEFT_BRACKET maxLength RIGHT_BRACKET)? notNull?                                                                #listValueTypeAlt3
    | recordType                                                                                                                                   #recordTypeLabel
    // <dynamic union type>
    | ANY VALUE? notNull?                                                                                                                        #openDynamicUnionTypeLabel
    | ANY? PROPERTY VALUE notNull?                                                                                                             #dynamicPropertyValueTypeLabel
    // <closed dynamic union type>
    | ANY VALUE? LEFT_ANGLE_BRACKET valueType (VERTICAL_BAR valueType)* RIGHT_ANGLE_BRACKET                                         #closedDynamicUnionTypeAtl1
    | valueType VERTICAL_BAR valueType                                                                                                        #closedDynamicUnionTypeAtl2
    ;

typed
    : DOUBLE_COLON
    | TYPED
    ;

predefinedType
    : booleanType
    | characterStringType
    | byteStringType
    | numericType
    | temporalType
    | referenceValueType
    | immaterialValueType
    ;

booleanType
    : (BOOL | BOOLEAN) notNull?
    ;

characterStringType
    : STRING (LEFT_PAREN (minLength COMMA)? maxLength RIGHT_PAREN)? notNull?
    | CHAR (LEFT_PAREN fixedLength RIGHT_PAREN)? notNull?
    | VARCHAR (LEFT_PAREN maxLength RIGHT_PAREN)? notNull?
    ;

byteStringType
    : BYTES (LEFT_PAREN (minLength COMMA)? maxLength RIGHT_PAREN)? notNull?
    | BINARY (LEFT_PAREN fixedLength RIGHT_PAREN)? notNull?
    | VARBINARY (LEFT_PAREN maxLength RIGHT_PAREN)? notNull?
    ;

minLength
    : unsignedInteger
    ;

maxLength
    : unsignedInteger
    ;

fixedLength
    : unsignedInteger
    ;

numericType
    : exactNumericType
    | approximateNumericType
    ;

exactNumericType
    : binaryExactNumericType
    | decimalExactNumericType
    ;

binaryExactNumericType
    : signedBinaryExactNumericType
    | unsignedBinaryExactNumericType
    ;

signedBinaryExactNumericType
    : INT8 notNull?
    | INT16 notNull?
    | INT32 notNull?
    | INT64 notNull?
    | INT128 notNull?
    | INT256 notNull?
    | SMALLINT notNull?
    | INT (LEFT_PAREN precision RIGHT_PAREN)? notNull?
    | BIGINT notNull?
    | SIGNED? verboseBinaryExactNumericType
    ;

unsignedBinaryExactNumericType
    : UINT8 notNull?
    | UINT16 notNull?
    | UINT32 notNull?
    | UINT64 notNull?
    | UINT128 notNull?
    | UINT256 notNull?
    | USMALLINT notNull?
    | UINT (LEFT_PAREN precision RIGHT_PAREN)? notNull?
    | UBIGINT notNull?
    | UNSIGNED verboseBinaryExactNumericType
    ;

verboseBinaryExactNumericType
    : INTEGER8 notNull?
    | INTEGER16 notNull?
    | INTEGER32 notNull?
    | INTEGER64 notNull?
    | INTEGER128 notNull?
    | INTEGER256 notNull?
    | SMALL INTEGER notNull?
    | INTEGER (LEFT_PAREN precision RIGHT_PAREN)? notNull?
    | BIG INTEGER notNull?
    ;

decimalExactNumericType
    : (DECIMAL | DEC) (LEFT_PAREN precision (COMMA scale)? RIGHT_PAREN notNull?)?
    ;

precision
    : unsignedDecimalInteger
    ;

scale
    : unsignedDecimalInteger
    ;

approximateNumericType
    : FLOAT16 notNull?
    | FLOAT32 notNull?
    | FLOAT64 notNull?
    | FLOAT128 notNull?
    | FLOAT256 notNull?
    | FLOAT (LEFT_PAREN precision (COMMA scale)? RIGHT_PAREN)? notNull?
    | REAL notNull?
    | DOUBLE PRECISION? notNull?
    ;

temporalType
    : temporalInstantType
    | temporalDurationType
    ;

temporalInstantType
    : datetimeType
    | localdatetimeType
    | dateType
    | timeType
    | localtimeType
    ;

datetimeType
    : ZONED DATETIME notNull?
    | TIMESTAMP WITH TIME ZONE notNull?
    ;

localdatetimeType
    : LOCAL DATETIME notNull?
    | TIMESTAMP (WITHOUT TIME ZONE)? notNull?
    ;

dateType
    : DATE notNull?
    ;

timeType
    : ZONED TIME notNull?
    | TIME WITH TIME ZONE notNull?
    ;

localtimeType
    : LOCAL TIME notNull?
    | TIME WITHOUT TIME ZONE notNull?
    ;

temporalDurationType
    : DURATION LEFT_PAREN (YEAR TO MONTH | DAY TO SECOND) RIGHT_PAREN notNull?
    ;

referenceValueType
    : graphReferenceValueType
    | bindingTableReferenceValueType
    | nodeReferenceValueType
    | edgeReferenceValueType
    ;

immaterialValueType
    : NULL_KW
    | NULL_KW notNull
    | NOTHING
    ;

graphReferenceValueType
    : ANY PROPERTY? GRAPH notNull?
    | PROPERTY? GRAPH nestedGraphTypeSpecification notNull?
    ;

bindingTableReferenceValueType
    : bindingTableType notNull?
    ;

nodeReferenceValueType
    : ANY? nodeSynonym notNull?
    | nodeTypeSpecification notNull?
    ;

edgeReferenceValueType
    : ANY? edgeSynonym notNull?
    | edgeTypeSpecification notNull?
    ;

pathValueType
    : PATH notNull?
    ;

listValueTypeName
    : LIST
    | ARRAY
    ;

recordType
    : ANY? RECORD notNull?
    | RECORD? fieldTypesSpecification notNull?
    ;

fieldTypesSpecification
    : LEFT_BRACE (fieldName typed? valueType (COMMA fieldName typed? valueType)*)? RIGHT_BRACE
    ;

notNull
    :  NOT NULL_KW
    ;

// ===============================================================
// 19.1 <search condition> - Search and predicates (compressed)
// ===============================================================

searchCondition
    : booleanValueExpression
    ;

predicate
    : EXISTS (LEFT_BRACE graphPattern RIGHT_BRACE | LEFT_PAREN graphPattern RIGHT_PAREN | LEFT_BRACE matchStatement+ RIGHT_BRACE | LEFT_PAREN matchStatement+ RIGHT_PAREN | nestedQuerySpecification)
    | valueExpressionPrimary IS NOT? NULL_KW
    | valueExpressionPrimary IS NOT? typed valueType
    | elementVariableReference IS NOT? DIRECTED
    | elementVariableReference (IS NOT? LABELED | COLON) labelExpression
    | elementVariableReference IS NOT? SOURCE OF elementVariableReference
    | elementVariableReference IS NOT? DESTINATION OF elementVariableReference
    | ALL_DIFFERENT LEFT_PAREN elementVariableReference COMMA elementVariableReference (COMMA elementVariableReference)* RIGHT_PAREN
    | SAME LEFT_PAREN elementVariableReference COMMA elementVariableReference (COMMA elementVariableReference)* RIGHT_PAREN
    | PROPERTY_EXISTS LEFT_PAREN elementVariableReference COMMA propertyName RIGHT_PAREN
    ;

// ===============================================================
// 19.3 <comparison predicate> - Comparison operators
// ===============================================================

compOp
    : EQUALS_OPERATOR
    | NOT_EQUALS_OPERATOR
    | LEFT_ANGLE_BRACKET
    | RIGHT_ANGLE_BRACKET
    | LESS_THAN_OR_EQUALS_OPERATOR
    | GREATER_THAN_OR_EQUALS_OPERATOR
    ;

// ===============================================================
// 20.1 <value expression> - Expression system
// ===============================================================

valueExpression
    : sign = (PLUS_SIGN | MINUS_SIGN) valueExpression                       #signedExprAlt
    | valueExpression operator = (ASTERISK | SOLIDUS) valueExpression       #multDivExprAlt
    | valueExpression operator = (PLUS_SIGN | MINUS_SIGN) valueExpression   #addSubtractExprAlt
    | valueExpression CONCATENATION_OPERATOR valueExpression                #concatenationExprAlt
    | valueExpression compOp valueExpression                                #comparisonExprAlt
    | predicate                                                             #predicateExprAlt
    | valueExpression IS NOT? (NFC | NFD | NFKC | NFKD)? NORMALIZED         #normalizedPredicateExprAlt
    | NOT valueExpression                                                   #notExprAlt
    | valueExpression IS NOT? truthValue                                    #isNotExprAlt
    | valueExpression AND valueExpression                                   #conjunctiveExprAlt
    | valueExpression operator = (OR | XOR) valueExpression                 #disjunctiveExprAlt
    | PROPERTY? GRAPH graphExpression                                       #propertyGraphExprAlt
    | BINDING? TABLE bindingTableExpression                                 #bindingTableExprAlt
    | valueFunction                                                         #valueFunctionExprAlt
    | valueExpression IN LEFT_PAREN valueExpression (COMMA valueExpression)* RIGHT_PAREN   #inExprAlt
    | valueExpressionPrimary                                                #primaryExprAlt
    ;

valueFunction
    : numericValueFunction
    | datetimeSubtraction
    | datetimeValueFunction
    | durationValueFunction
    | characterOrByteStringFunction
    | listValueFunction
    ;

booleanValueExpression
    : valueExpression
    ;

characterOrByteStringFunction
    : (LEFT | RIGHT) LEFT_PAREN valueExpression COMMA stringLength RIGHT_PAREN
    | TRIM LEFT_PAREN trimOperands RIGHT_PAREN
    | (UPPER | LOWER) LEFT_PAREN valueExpression RIGHT_PAREN
    | (BTRIM | LTRIM | RTRIM) LEFT_PAREN valueExpression (COMMA valueExpression)? RIGHT_PAREN
    | NORMALIZE LEFT_PAREN valueExpression (COMMA (NFC | NFD | NFKC | NFKD))? RIGHT_PAREN
    ;

aggregatingValueExpression
    : valueExpression
    ;

// ===============================================================
// 20.2 <value expression primary> - Primary expressions (compressed)
// ===============================================================

valueExpressionPrimary
    : parenthesizedValueExpression
    | aggregateFunction
    | unsignedValueSpecification
    | pathValueConstructor
    | valueExpressionPrimary PERIOD propertyName
    | VALUE nestedQuerySpecification
    | caseExpression
    | CAST LEFT_PAREN (valueExpression | nullLiteral) AS valueType RIGHT_PAREN
    | ELEMENT_ID LEFT_PAREN elementVariableReference RIGHT_PAREN
    | LET letVariableDefinition (COMMA letVariableDefinition)* IN valueExpression END
    | bindingVariableReference
    ;

parenthesizedValueExpression
    : LEFT_PAREN valueExpression RIGHT_PAREN
    ;

nonParenthesizedValueExpressionPrimarySpecialCase
    : aggregateFunction
    | unsignedValueSpecification
    | pathValueConstructor
    | valueExpressionPrimary PERIOD propertyName
    | VALUE nestedQuerySpecification
    | caseExpression
    | CAST LEFT_PAREN (valueExpression | nullLiteral) AS valueType RIGHT_PAREN
    | ELEMENT_ID LEFT_PAREN elementVariableReference RIGHT_PAREN
    | LET letVariableDefinition (COMMA letVariableDefinition)* IN valueExpression END
    ;

// ===============================================================
// 20.3 <value specification> - Value specifications (compressed)
// ===============================================================

unsignedValueSpecification
    : unsignedLiteral
    | GENERAL_PARAMETER_REFERENCE
    | SESSION_USER
    ;

nonNegativeIntegerSpecification
    : unsignedInteger
    | GENERAL_PARAMETER_REFERENCE
    ;

// ===============================================================
// 20.7 <case expression> - Case expressions (compressed)
// ===============================================================

caseExpression
    : NULLIF LEFT_PAREN valueExpression COMMA valueExpression RIGHT_PAREN
    | COALESCE LEFT_PAREN valueExpression (COMMA valueExpression)+ RIGHT_PAREN
    | CASE caseOperand simpleWhenClause+ elseClause? END
    | CASE searchedWhenClause+ elseClause? END
    ;

simpleWhenClause
    : WHEN whenOperand (COMMA whenOperand)* THEN result
    ;

searchedWhenClause
    : WHEN searchCondition THEN result
    ;

elseClause
    : ELSE result
    ;

caseOperand
    : nonParenthesizedValueExpressionPrimarySpecialCase
    | elementVariableReference
    ;

whenOperand
    : nonParenthesizedValueExpressionPrimarySpecialCase
    | compOp valueExpression
    | IS NOT? NULL_KW
    | IS NOT? typed valueType
    | IS NOT? (NFC | NFD | NFKC | NFKD)? NORMALIZED
    | IS NOT? DIRECTED
    | (IS NOT? LABELED | COLON) labelExpression
    | IS NOT? SOURCE OF elementVariableReference
    | IS NOT? DESTINATION OF elementVariableReference
    ;

result
    : valueExpression
    | nullLiteral
    ;

// ===============================================================
// 20.9 <aggregate function> - Aggregation (compressed)
// ===============================================================

aggregateFunction
    : COUNT LEFT_PAREN ASTERISK RIGHT_PAREN
    | (AVG | COUNT | MAX | MIN | SUM | COLLECT_LIST | STDDEV_SAMP | STDDEV_POP) LEFT_PAREN setQuantifier? valueExpression RIGHT_PAREN
    | (PERCENTILE_CONT | PERCENTILE_DISC) LEFT_PAREN setQuantifier? numericValueExpression COMMA numericValueExpression RIGHT_PAREN
    ;

setQuantifier
    : DISTINCT
    | ALL
    ;

// ===============================================================
// 20.12 <binding variable reference> - Variable references
// ===============================================================

bindingVariableReference
    : bindingVariable
    ;

elementVariableReference
    : bindingVariableReference
    ;

pathValueExpression
    : valueExpression
    ;

// ===============================================================
// 20.14 <path value constructor> - Path construction
// ===============================================================

pathValueConstructor
    : PATH LEFT_BRACKET valueExpression (COMMA valueExpression COMMA valueExpression)* RIGHT_BRACKET
    ;

listValueExpression
    : valueExpression
    ;

// ===============================================================
// 20.16 <list value function> - List functions
// ===============================================================

listValueFunction
    : TRIM LEFT_PAREN listValueExpression COMMA numericValueExpression RIGHT_PAREN
    | ELEMENTS LEFT_PAREN pathValueExpression RIGHT_PAREN
    ;

// ===============================================================
// 20.17 <list value constructor> - List construction
// ===============================================================

listValueConstructor
    : listValueTypeName? LEFT_BRACKET (valueExpression (COMMA valueExpression)*)? RIGHT_BRACKET
    ;

// ===============================================================
// 20.18 <record constructor> - Record construction
// ===============================================================

recordConstructor
    : RECORD? LEFT_BRACE (fieldName COLON valueExpression (COMMA fieldName COLON valueExpression)*)? RIGHT_BRACE
    ;

// ===============================================================
// 20.20 <boolean value expression> - Boolean values
// ===============================================================

truthValue
    : BOOLEAN_LITERAL
    ;

// ===============================================================
// 20.21 <numeric value expression> - Numeric expressions
// ===============================================================

numericValueExpression
    : sign = (PLUS_SIGN | MINUS_SIGN) numericValueExpression
    | numericValueExpression operator = (ASTERISK | SOLIDUS) numericValueExpression
    | numericValueExpression operator = (PLUS_SIGN | MINUS_SIGN) numericValueExpression
    | valueExpressionPrimary
    | numericValueFunction
    ;

// ===============================================================
// 20.22 <numeric value function> - Numeric functions (compressed)
// ===============================================================

numericValueFunction
    : (CHAR_LENGTH | CHARACTER_LENGTH) LEFT_PAREN characterStringValueExpression RIGHT_PAREN
    | (BYTE_LENGTH | OCTET_LENGTH) LEFT_PAREN byteStringValueExpression RIGHT_PAREN
    | PATH_LENGTH LEFT_PAREN pathValueExpression RIGHT_PAREN
    | CARDINALITY LEFT_PAREN valueExpression RIGHT_PAREN
    | SIZE LEFT_PAREN listValueExpression RIGHT_PAREN
    | ABS LEFT_PAREN valueExpression RIGHT_PAREN
    | MOD LEFT_PAREN numericValueExpression COMMA numericValueExpression RIGHT_PAREN
    | (SIN | COS | TAN | COT | SINH | COSH | TANH | ASIN | ACOS | ATAN | DEGREES | RADIANS) LEFT_PAREN numericValueExpression RIGHT_PAREN
    | LOG_KW LEFT_PAREN numericValueExpression COMMA numericValueExpression RIGHT_PAREN
    | LOG10 LEFT_PAREN numericValueExpression RIGHT_PAREN
    | LN LEFT_PAREN numericValueExpression RIGHT_PAREN
    | EXP LEFT_PAREN numericValueExpression RIGHT_PAREN
    | POWER LEFT_PAREN numericValueExpression COMMA numericValueExpression RIGHT_PAREN
    | SQRT LEFT_PAREN numericValueExpression RIGHT_PAREN
    | FLOOR LEFT_PAREN numericValueExpression RIGHT_PAREN
    | (CEIL | CEILING) LEFT_PAREN numericValueExpression RIGHT_PAREN
    ;

// ===============================================================
// 20.23 <string value expression> - String expressions
// ===============================================================

characterStringValueExpression
    : valueExpression
    ;

byteStringValueExpression
    : valueExpression
    ;

// ===============================================================
// 20.24 <string value function> - String function support
// ===============================================================

trimOperands
    : ((LEADING | TRAILING | BOTH)? valueExpression? FROM)? valueExpression
    ;

stringLength
    : numericValueExpression
    ;

// ===============================================================
// 20.26 <datetime value expression> - Datetime expressions
// ===============================================================

datetimeValueExpression
     : valueExpression
     ;

// ===============================================================
// 20.27 <datetime value function> - Datetime functions (compressed)
// ===============================================================

datetimeValueFunction
    : CURRENT_DATE
    | DATE LEFT_PAREN (dateString | recordConstructor)? RIGHT_PAREN
    | CURRENT_TIME
    | ZONED_TIME LEFT_PAREN (timeString | recordConstructor)? RIGHT_PAREN
    | LOCAL_TIME (LEFT_PAREN (timeString | recordConstructor)? RIGHT_PAREN)?
    | CURRENT_TIMESTAMP
    | ZONED_DATETIME LEFT_PAREN (datetimeString | recordConstructor)? RIGHT_PAREN
    | LOCAL_TIMESTAMP
    | LOCAL_DATETIME LEFT_PAREN (datetimeString | recordConstructor)? RIGHT_PAREN
    ;

// ===============================================================
// 20.28 <duration value expression> - Duration expressions
// ===============================================================

durationValueExpression
    : valueExpression
    ;

datetimeSubtraction
    : DURATION_BETWEEN LEFT_PAREN datetimeValueExpression COMMA datetimeValueExpression RIGHT_PAREN (YEAR TO MONTH | DAY TO SECOND)?
    ;

// ===============================================================
// 20.29 <duration value function> - Duration functions
// ===============================================================

durationValueFunction
    : DURATION LEFT_PAREN (durationString | recordConstructor) RIGHT_PAREN
    | ABS LEFT_PAREN valueExpression RIGHT_PAREN
    ;

// ===============================================================
// 21.1 Names and Variables - Identifiers and names (compressed)
// ===============================================================

objectName
    : identifier
    ;

objectNameOrBindingVariable
    : regularIdentifier
    ;

directoryName
    : identifier
    ;

schemaName
    : identifier
    ;

graphName
    : regularIdentifier
    | delimitedGraphName
    ;

delimitedGraphName
    : DOUBLE_QUOTED_CHARACTER_SEQUENCE
    | ACCENT_QUOTED_CHARACTER_SEQUENCE
    ;

graphTypeName
    : identifier
    ;

nodeTypeName
    : identifier
    ;

edgeTypeName
    : identifier
    ;

bindingTableName
    : regularIdentifier
    | delimitedBindingTableName
    ;

delimitedBindingTableName
     : DOUBLE_QUOTED_CHARACTER_SEQUENCE
     | ACCENT_QUOTED_CHARACTER_SEQUENCE
     ;

procedureName
    : identifier
    ;

labelName
    : identifier
    ;

propertyName
    : identifier
    ;

fieldName
    : identifier
    ;

elementVariable
    : bindingVariable
    ;

pathVariable
    : bindingVariable
    ;

subpathVariable
    : regularIdentifier
    ;

bindingVariable
    : regularIdentifier
    ;

// ===============================================================
// 21.2 <literal> - Literal values (compressed)
// ===============================================================

unsignedLiteral
    : unsignedNumericLiteral
    | generalLiteral
    ;

generalLiteral
    : BOOLEAN_LITERAL
    | characterStringLiteral
    | BYTE_STRING_LITERAL
    | temporalLiteral
    | durationLiteral
    | nullLiteral
    | listLiteral
    | recordLiteral
    ;

temporalLiteral
    : DATE dateString
    | TIME timeString
    | (DATETIME | TIMESTAMP) datetimeString
    ;

listLiteral
    : listValueConstructor
    ;

recordLiteral
    : recordConstructor
    ;

identifier
    : regularIdentifier
    | DOUBLE_QUOTED_CHARACTER_SEQUENCE
    | ACCENT_QUOTED_CHARACTER_SEQUENCE
    ;

regularIdentifier
    : REGULAR_IDENTIFIER
    | nonReservedWords
    ;

timeZoneString
    : characterStringLiteral
    ;

characterStringLiteral
    : SINGLE_QUOTED_CHARACTER_SEQUENCE
    | DOUBLE_QUOTED_CHARACTER_SEQUENCE
    ;

unsignedNumericLiteral
    : exactNumericLiteral
    | approximateNumericLiteral
    ;

exactNumericLiteral
    : UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_EXACT_NUMBER_SUFFIX
    | UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_EXACT_NUMBER_SUFFIX
    | UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITHOUT_SUFFIX
    | UNSIGNED_DECIMAL_INTEGER_WITH_EXACT_NUMBER_SUFFIX
    | unsignedInteger
    ;

approximateNumericLiteral
    : UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX
    | UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITHOUT_SUFFIX
    | UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX
    | UNSIGNED_DECIMAL_INTEGER_WITH_APPROXIMATE_NUMBER_SUFFIX
    ;

unsignedInteger
    : UNSIGNED_DECIMAL_INTEGER
    | UNSIGNED_HEXADECIMAL_INTEGER
    | UNSIGNED_OCTAL_INTEGER
    | UNSIGNED_BINARY_INTEGER
    ;

unsignedDecimalInteger
    : UNSIGNED_DECIMAL_INTEGER
    ;

nullLiteral
    : NULL_KW
    ;

dateString
    : characterStringLiteral
    ;

timeString
    : characterStringLiteral
    ;

datetimeString
    : characterStringLiteral
    ;

durationLiteral
    : DURATION durationString
    ;

durationString
    : characterStringLiteral
    ;

nodeSynonym
    : NODE
    | VERTEX
    ;

edgesSynonym
    : EDGES
    | RELATIONSHIPS
    ;

edgeSynonym
    : EDGE
    | RELATIONSHIP
    ;

// ===============================================================
// LEXER RULES - All terminal symbols (unchanged from original)
// ===============================================================

// 21.1 Names and Variables

IMPLIES
    : RIGHT_DOUBLE_ARROW
    | 'IMPLIES'
    ;

fragment PARAMETER_NAME
    : SEPARATED_IDENTIFIER
    ;

// 21.2 <literal>

nonReservedWords
    : ACYCLIC
    | BINDING
    | BINDINGS
    | CONNECTING
    | DESTINATION
    | DIFFERENT
    | DIRECTED
    | EDGE
    | EDGES
    | ELEMENT
    | ELEMENTS
    | FIRST
    | GRAPH
    | GROUPS
    | KEEP
    | LABEL
    | LABELED
    | LABELS
    | LAST
    | NFC
    | NFD
    | NFKC
    | NFKD
    | NO
    | NODE
    | NORMALIZED
    | ONLY
    | ORDINALITY
    | PROPERTY
    | READ
    | RELATIONSHIP
    | RELATIONSHIPS
    | REPEATABLE
    | SHORTEST
    | SIMPLE
    | SOURCE
    | TABLE
    | TO
    | TRAIL
    | TRANSACTION
    | TYPE
    | UNDIRECTED
    | VERTEX
    | WALK
    | WITHOUT
    | WRITE
    | ZONE
    ;

BOOLEAN_LITERAL
    : 'TRUE'
    | 'FALSE'
    | 'UNKNOWN'
    ;

SINGLE_QUOTED_CHARACTER_SEQUENCE
    : NO_ESCAPE? UNBROKEN_SINGLE_QUOTED_CHARACTER_SEQUENCE
    ;

DOUBLE_QUOTED_CHARACTER_SEQUENCE
    : NO_ESCAPE? UNBROKEN_DOUBLE_QUOTED_CHARACTER_SEQUENCE
    ;

ACCENT_QUOTED_CHARACTER_SEQUENCE
    :NO_ESCAPE? UNBROKEN_ACCENT_QUOTED_CHARACTER_SEQUENCE
    ;

NO_ESCAPE
    : COMMERCIAL_AT
    ;

fragment UNBROKEN_SINGLE_QUOTED_CHARACTER_SEQUENCE
    : QUOTE SINGLE_QUOTED_CHARACTER_REPRESENTATION* QUOTE
    ;

fragment UNBROKEN_DOUBLE_QUOTED_CHARACTER_SEQUENCE
    : DOUBLE_QUOTE DOUBLE_QUOTED_CHARACTER_REPRESENTATION* DOUBLE_QUOTE
    ;

fragment UNBROKEN_ACCENT_QUOTED_CHARACTER_SEQUENCE
    : GRAVE_ACCENT ACCENT_QUOTED_CHARACTER_REPRESENTATION* GRAVE_ACCENT
    ;

fragment SINGLE_QUOTED_CHARACTER_REPRESENTATION:
	(ESCAPED_CHARACTER | ~['\\\r\n] | '\'\'')+
	;

fragment DOUBLE_QUOTED_CHARACTER_REPRESENTATION:
	(ESCAPED_CHARACTER | ~["\\\r\n] | '""')+
	;

fragment ACCENT_QUOTED_CHARACTER_REPRESENTATION:
	(ESCAPED_CHARACTER | ~[`\\\r\n] | '``')+
	;

fragment ESCAPED_CHARACTER
    : ESCAPED_REVERSE_SOLIDUS
	| ESCAPED_QUOTE
	| ESCAPED_DOUBLE_QUOTE
	| ESCAPED_GRAVE_ACCENT
	| ESCAPED_TAB
	| ESCAPED_BACKSPACE
	| ESCAPED_NEW_LINE
	| ESCAPED_CARRIAGE_RETURN
	| ESCAPED_FORM_FEED
	| ESCAPED_UNICODE4_DIGIT_VALUE
	| ESCAPED_UNICODE6_DIGIT_VALUE
	;

fragment ESCAPED_REVERSE_SOLIDUS: REVERSE_SOLIDUS REVERSE_SOLIDUS;
fragment ESCAPED_QUOTE: REVERSE_SOLIDUS QUOTE;
fragment ESCAPED_DOUBLE_QUOTE: REVERSE_SOLIDUS DOUBLE_QUOTE;
fragment ESCAPED_GRAVE_ACCENT: REVERSE_SOLIDUS GRAVE_ACCENT;
fragment ESCAPED_TAB options { caseInsensitive=false; }: REVERSE_SOLIDUS 't';
fragment ESCAPED_BACKSPACE options { caseInsensitive=false; }: REVERSE_SOLIDUS 'b';
fragment ESCAPED_NEW_LINE options { caseInsensitive=false; }: REVERSE_SOLIDUS 'n';
fragment ESCAPED_CARRIAGE_RETURN options { caseInsensitive=false; }: REVERSE_SOLIDUS 'r';
fragment ESCAPED_FORM_FEED options { caseInsensitive=false; }: REVERSE_SOLIDUS 'f';
fragment ESCAPED_UNICODE4_DIGIT_VALUE:
	START_UNICODE4 HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT;
fragment ESCAPED_UNICODE6_DIGIT_VALUE:
	START_UNICODE6 HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT;
fragment START_UNICODE4  options { caseInsensitive=false; }: REVERSE_SOLIDUS 'u';
fragment START_UNICODE6  options { caseInsensitive=false; }: REVERSE_SOLIDUS 'U';

BYTE_STRING_LITERAL
    : 'X' QUOTE SPACE* (HEX_DIGIT SPACE* HEX_DIGIT SPACE*)* QUOTE
    ;

UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_EXACT_NUMBER_SUFFIX
    : UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION EXACT_NUMBER_SUFFIX
    ;

UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITHOUT_SUFFIX
    : UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION
    ;

UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX
    : UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION APPROXIMATE_NUMBER_SUFFIX
    ;

UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_EXACT_NUMBER_SUFFIX
    : UNSIGNED_DECIMAL_IN_COMMON_NOTATION EXACT_NUMBER_SUFFIX
    ;

UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITHOUT_SUFFIX
    : UNSIGNED_DECIMAL_IN_COMMON_NOTATION
    ;

UNSIGNED_DECIMAL_IN_COMMON_NOTATION_WITH_APPROXIMATE_NUMBER_SUFFIX
    : UNSIGNED_DECIMAL_IN_COMMON_NOTATION APPROXIMATE_NUMBER_SUFFIX
    ;

UNSIGNED_DECIMAL_INTEGER_WITH_EXACT_NUMBER_SUFFIX
    : UNSIGNED_DECIMAL_INTEGER EXACT_NUMBER_SUFFIX
    ;

UNSIGNED_DECIMAL_INTEGER_WITH_APPROXIMATE_NUMBER_SUFFIX
    : UNSIGNED_DECIMAL_INTEGER APPROXIMATE_NUMBER_SUFFIX
    ;

UNSIGNED_DECIMAL_INTEGER
    : DIGIT (UNDERSCORE? DIGIT)*
    ;

fragment EXACT_NUMBER_SUFFIX
    : 'M'
    ;

fragment UNSIGNED_DECIMAL_IN_SCIENTIFIC_NOTATION
    : MANTISSA 'E' EXPONENT
    ;

fragment MANTISSA
    : UNSIGNED_DECIMAL_IN_COMMON_NOTATION
    | UNSIGNED_DECIMAL_INTEGER
    ;

fragment EXPONENT
    : SIGNED_DECIMAL_INTEGER
    ;

fragment UNSIGNED_DECIMAL_IN_COMMON_NOTATION
    : UNSIGNED_DECIMAL_INTEGER (PERIOD UNSIGNED_DECIMAL_INTEGER?)
    | PERIOD UNSIGNED_DECIMAL_INTEGER
    ;

fragment SIGNED_DECIMAL_INTEGER
    : (PLUS_SIGN | MINUS_SIGN)? UNSIGNED_DECIMAL_INTEGER
    ;

UNSIGNED_HEXADECIMAL_INTEGER
    : START_HEX ('_'? HEX_DIGIT)+
    ;
fragment START_HEX options { caseInsensitive=false; }: '0x';

UNSIGNED_OCTAL_INTEGER
    : START_OCTAL ('_'? OCTAL_DIGIT)+
    ;
fragment START_OCTAL options { caseInsensitive=false; }: '0o';

UNSIGNED_BINARY_INTEGER
    : START_BIN ('_'? BINARY_DIGIT)+
    ;
fragment START_BIN options { caseInsensitive=false; }: '0b';

fragment APPROXIMATE_NUMBER_SUFFIX
    : 'F'
    | 'D'
    ;

// 21.3 <token>, <separator>, and <identifier>

// Reserved words
ABS: 'ABS';
ACOS: 'ACOS';
ALL: 'ALL';
ALL_DIFFERENT: 'ALL_DIFFERENT';
AND: 'AND';
ANY: 'ANY';
ARRAY: 'ARRAY';
AS: 'AS';
ASC: 'ASC';
ASCENDING: 'ASCENDING';
ASIN: 'ASIN';
AT: 'AT';
ATAN: 'ATAN';
AVG: 'AVG';
BIG: 'BIG';
BIGINT: 'BIGINT';
BINARY: 'BINARY';
BOOL: 'BOOL';
BOOLEAN: 'BOOLEAN';
BOTH: 'BOTH';
BTRIM: 'BTRIM';
BY: 'BY';
BYTE_LENGTH: 'BYTE_LENGTH';
BYTES: 'BYTES';
CALL: 'CALL';
CARDINALITY: 'CARDINALITY';
CASE: 'CASE';
CAST: 'CAST';
CEIL: 'CEIL';
CEILING: 'CEILING';
CHAR: 'CHAR';
CHAR_LENGTH: 'CHAR_LENGTH';
CHARACTER_LENGTH: 'CHARACTER_LENGTH';
CHARACTERISTICS: 'CHARACTERISTICS';
CLOSE: 'CLOSE';
COALESCE: 'COALESCE';
COLLECT_LIST: 'COLLECT_LIST';
COMMIT: 'COMMIT';
COPY: 'COPY';
COS: 'COS';
COSH: 'COSH';
COT: 'COT';
COUNT: 'COUNT';
CREATE: 'CREATE';
CURRENT_DATE: 'CURRENT_DATE';
CURRENT_GRAPH: 'CURRENT_GRAPH';
CURRENT_PROPERTY_GRAPH: 'CURRENT_PROPERTY_GRAPH';
CURRENT_SCHEMA: 'CURRENT_SCHEMA';
CURRENT_TIME: 'CURRENT_TIME';
CURRENT_TIMESTAMP: 'CURRENT_TIMESTAMP';
DATE: 'DATE';
DATETIME: 'DATETIME';
DAY: 'DAY';
DEC: 'DEC';
DECIMAL: 'DECIMAL';
DEGREES: 'DEGREES';
DELETE: 'DELETE';
DESC: 'DESC';
DESCENDING: 'DESCENDING';
DETACH: 'DETACH';
DISTINCT: 'DISTINCT';
DOUBLE: 'DOUBLE';
DROP: 'DROP';
DURATION: 'DURATION';
DURATION_BETWEEN: 'DURATION_BETWEEN';
ELEMENT_ID: 'ELEMENT_ID';
ELSE: 'ELSE';
END: 'END';
EXCEPT: 'EXCEPT';
EXISTS: 'EXISTS';
EXP: 'EXP';
FILTER: 'FILTER';
FINISH: 'FINISH';
FLOAT: 'FLOAT';
FLOAT16: 'FLOAT16';
FLOAT32: 'FLOAT32';
FLOAT64: 'FLOAT64';
FLOAT128: 'FLOAT128';
FLOAT256: 'FLOAT256';
FLOOR: 'FLOOR';
FOR: 'FOR';
FROM: 'FROM';
GROUP: 'GROUP';
HAVING: 'HAVING';
HOME_GRAPH: 'HOME_GRAPH';
HOME_PROPERTY_GRAPH: 'HOME_PROPERTY_GRAPH';
HOME_SCHEMA: 'HOME_SCHEMA';
HOUR: 'HOUR';
IF: 'IF';
IN: 'IN';
INSERT: 'INSERT';
INT: 'INT';
INTEGER: 'INTEGER';
INT8: 'INT8';
INTEGER8: 'INTEGER8';
INT16: 'INT16';
INTEGER16: 'INTEGER16';
INT32: 'INT32';
INTEGER32: 'INTEGER32';
INT64: 'INT64';
INTEGER64: 'INTEGER64';
INT128: 'INT128';
INTEGER128: 'INTEGER128';
INT256: 'INT256';
INTEGER256: 'INTEGER256';
INTERSECT: 'INTERSECT';
INTERVAL: 'INTERVAL';
IS: 'IS';
LEADING: 'LEADING';
LEFT: 'LEFT';
LET: 'LET';
LIKE: 'LIKE';
LIMIT: 'LIMIT';
LIST: 'LIST';
LN: 'LN';
LOCAL: 'LOCAL';
LOCAL_DATETIME: 'LOCAL_DATETIME';
LOCAL_TIME: 'LOCAL_TIME';
LOCAL_TIMESTAMP: 'LOCAL_TIMESTAMP';
LOG_KW: 'LOG';
LOG10: 'LOG10';
LOWER: 'LOWER';
LTRIM: 'LTRIM';
MATCH: 'MATCH';
MAX: 'MAX';
MIN: 'MIN';
MINUTE: 'MINUTE';
MOD: 'MOD';
MONTH: 'MONTH';
NEXT: 'NEXT';
NODETACH: 'NODETACH';
NORMALIZE: 'NORMALIZE';
NOT: 'NOT';
NOTHING: 'NOTHING';
NULL_KW: 'NULL';
NULLS: 'NULLS';
NULLIF: 'NULLIF';
OCTET_LENGTH: 'OCTET_LENGTH';
OF: 'OF';
OFFSET: 'OFFSET';
OPTIONAL: 'OPTIONAL';
OR: 'OR';
ORDER: 'ORDER';
OTHERWISE: 'OTHERWISE';
PARAMETER: 'PARAMETER';
PARAMETERS: 'PARAMETERS';
PATH: 'PATH';
PATH_LENGTH: 'PATH_LENGTH';
PATHS: 'PATHS';
PERCENTILE_CONT: 'PERCENTILE_CONT';
PERCENTILE_DISC: 'PERCENTILE_DISC';
POWER: 'POWER';
PRECISION: 'PRECISION';
PROPERTY_EXISTS: 'PROPERTY_EXISTS';
RADIANS: 'RADIANS';
REAL: 'REAL';
RECORD: 'RECORD';
REMOVE: 'REMOVE';
REPLACE: 'REPLACE';
RESET: 'RESET';
RETURN: 'RETURN';
RIGHT: 'RIGHT';
ROLLBACK: 'ROLLBACK';
RTRIM: 'RTRIM';
SAME: 'SAME';
SCHEMA: 'SCHEMA';
SECOND: 'SECOND';
SELECT: 'SELECT';
SESSION: 'SESSION';
SESSION_USER: 'SESSION_USER';
SET: 'SET';
SIGNED: 'SIGNED';
SIN: 'SIN';
SINH: 'SINH';
SIZE: 'SIZE';
SKIP_RESERVED_WORD: 'SKIP';
SMALL: 'SMALL';
SMALLINT: 'SMALLINT';
SQRT: 'SQRT';
START: 'START';
STDDEV_POP: 'STDDEV_POP';
STDDEV_SAMP: 'STDDEV_SAMP';
STRING: 'STRING';
SUM: 'SUM';
TAN: 'TAN';
TANH: 'TANH';
THEN: 'THEN';
TIME: 'TIME';
TIMESTAMP: 'TIMESTAMP';
TRAILING: 'TRAILING';
TRIM: 'TRIM';
TYPED: 'TYPED';
UBIGINT: 'UBIGINT';
UINT: 'UINT';
UINT8: 'UINT8';
UINT16: 'UINT16';
UINT32: 'UINT32';
UINT64: 'UINT64';
UINT128: 'UINT128';
UINT256: 'UINT256';
UNION: 'UNION';
UNSIGNED: 'UNSIGNED';
UPPER: 'UPPER';
USE: 'USE';
USMALLINT: 'USMALLINT';
VALUE: 'VALUE';
VARBINARY: 'VARBINARY';
VARCHAR: 'VARCHAR';
VARIABLE: 'VARIABLE';
WHEN: 'WHEN';
WHERE: 'WHERE';
WITH: 'WITH';
XOR: 'XOR';
YEAR: 'YEAR';
YIELD: 'YIELD';
ZONED: 'ZONED';
ZONED_DATETIME: 'ZONED_DATETIME';
ZONED_TIME: 'ZONED_TIME';

// Prereserved words
ABSTRACT: 'ABSTRACT';
AGGREGATE: 'AGGREGATE';
AGGREGATES: 'AGGREGATES';
ALTER: 'ALTER';
CATALOG: 'CATALOG';
CLEAR: 'CLEAR';
CLONE: 'CLONE';
CONSTRAINT: 'CONSTRAINT';
CURRENT_ROLE: 'CURRENT_ROLE';
CURRENT_USER: 'CURRENT_USER';
DATA: 'DATA';
DIRECTORY: 'DIRECTORY';
DRYRUN: 'DRYRUN';
EXACT: 'EXACT';
EXISTING: 'EXISTING';
FUNCTION: 'FUNCTION';
GQLSTATUS: 'GQLSTATUS';
GRANT: 'GRANT';
INSTANT: 'INSTANT';
INFINITY_KW: 'INFINITY';
NUMBER: 'NUMBER';
NUMERIC: 'NUMERIC';
ON: 'ON';
OPEN: 'OPEN';
PARTITION: 'PARTITION';
PROCEDURE: 'PROCEDURE';
PRODUCT: 'PRODUCT';
PROJECT: 'PROJECT';
QUERY: 'QUERY';
RECORDS: 'RECORDS';
REFERENCE: 'REFERENCE';
RENAME: 'RENAME';
REVOKE: 'REVOKE';
SUBSTRING: 'SUBSTRING';
SYSTEM_USER: 'SYSTEM_USER';
TEMPORAL: 'TEMPORAL';
UNIQUE: 'UNIQUE';
UNIT: 'UNIT';
VALUES: 'VALUES';

// Nonreserved words
ACYCLIC: 'ACYCLIC';
BINDING: 'BINDING';
BINDINGS: 'BINDINGS';
CONNECTING: 'CONNECTING';
DESTINATION: 'DESTINATION';
DIFFERENT: 'DIFFERENT';
DIRECTED: 'DIRECTED';
EDGE: 'EDGE';
EDGES: 'EDGES';
ELEMENT: 'ELEMENT';
ELEMENTS: 'ELEMENTS';
FIRST: 'FIRST';
GRAPH: 'GRAPH';
GROUPS: 'GROUPS';
KEEP: 'KEEP';
LABEL: 'LABEL';
LABELED: 'LABELED';
LABELS: 'LABELS';
LAST: 'LAST';
NFC: 'NFC';
NFD: 'NFD';
NFKC: 'NFKC';
NFKD: 'NFKD';
NO: 'NO';
NODE: 'NODE';
NORMALIZED: 'NORMALIZED';
ONLY: 'ONLY';
ORDINALITY: 'ORDINALITY';
PROPERTY: 'PROPERTY';
READ: 'READ';
RELATIONSHIP: 'RELATIONSHIP';
RELATIONSHIPS: 'RELATIONSHIPS';
REPEATABLE: 'REPEATABLE';
SHORTEST: 'SHORTEST';
SIMPLE: 'SIMPLE';
SOURCE: 'SOURCE';
TABLE: 'TABLE';
TO: 'TO';
TRAIL: 'TRAIL';
TRANSACTION: 'TRANSACTION';
TYPE: 'TYPE';
UNDIRECTED: 'UNDIRECTED';
VERTEX: 'VERTEX';
WALK: 'WALK';
WITHOUT: 'WITHOUT';
WRITE: 'WRITE';
ZONE: 'ZONE';

fragment SEPARATED_IDENTIFIER
    : DELIMITED_IDENTIFIER
    | EXTENDED_IDENTIFIER
    ;

REGULAR_IDENTIFIER
    : IDENTIFIER_START IDENTIFIER_EXTEND*
    ;

fragment EXTENDED_IDENTIFIER
    : IDENTIFIER_EXTEND+
    ;

fragment DELIMITED_IDENTIFIER
    : DOUBLE_QUOTED_CHARACTER_SEQUENCE
    | ACCENT_QUOTED_CHARACTER_SEQUENCE
    ;

SUBSTITUTED_PARAMETER_REFERENCE
    : DOUBLE_DOLLAR_SIGN PARAMETER_NAME
    ;

GENERAL_PARAMETER_REFERENCE
    : DOLLAR_SIGN PARAMETER_NAME
    ;

fragment IDENTIFIER_START
    : ID_Start
    | Pc
    ;

fragment IDENTIFIER_EXTEND
    : ID_Continue
    ;

fragment ID_Start
    : [\p{ID_Start}]
    ;

fragment ID_Continue
    : [\p{ID_Continue}]
    ;

MULTISET_ALTERNATION_OPERATOR: '|+|';

BRACKET_RIGHT_ARROW: ']->';
BRACKET_TILDE_RIGHT_ARROW: ']~>';
CONCATENATION_OPERATOR: '||';
DOUBLE_COLON: '::';
DOUBLE_DOLLAR_SIGN: '$$';
DOUBLE_PERIOD: '..';
GREATER_THAN_OR_EQUALS_OPERATOR: '>=';
LEFT_ARROW: '<-';
LEFT_ARROW_TILDE: '<~';
LEFT_ARROW_BRACKET: '<-[';
LEFT_ARROW_TILDE_BRACKET: '<~[';
LEFT_MINUS_RIGHT: '<->';
LEFT_MINUS_SLASH: '<-/';
LEFT_TILDE_SLASH: '<~/';
LESS_THAN_OR_EQUALS_OPERATOR: '<=';
MINUS_LEFT_BRACKET: '-[';
MINUS_SLASH: '-/';
NOT_EQUALS_OPERATOR: '<>';
RIGHT_ARROW: '->';
RIGHT_BRACKET_MINUS: ']-';
RIGHT_BRACKET_TILDE: ']~';
RIGHT_DOUBLE_ARROW: '=>';
SLASH_MINUS: '/-';
SLASH_MINUS_RIGHT: '/->';
SLASH_TILDE: '/~';
SLASH_TILDE_RIGHT: '/~>';
TILDE_LEFT_BRACKET: '~[';
TILDE_RIGHT_ARROW: '~>';
TILDE_SLASH: '~/';

// 21.4 GQL terminal characters

AMPERSAND: '&';
ASTERISK: '*';
COLON: ':';
COMMA: ',';
COMMERCIAL_AT: '@';
DOLLAR_SIGN: '$';
DOUBLE_QUOTE: '"';
EQUALS_OPERATOR: '=';
EXCLAMATION_MARK: '!';
RIGHT_ANGLE_BRACKET: '>';
GRAVE_ACCENT: '`';
LEFT_BRACE: '{';
LEFT_BRACKET: '[';
LEFT_PAREN: '(';
LEFT_ANGLE_BRACKET: '<';
MINUS_SIGN: '-';
PERCENT: '%';
PERIOD: '.';
PLUS_SIGN: '+';
QUESTION_MARK: '?';
QUOTE: '\'';
REVERSE_SOLIDUS: '\\';
RIGHT_BRACE: '}';
RIGHT_BRACKET: ']';
RIGHT_PAREN: ')';
SOLIDUS: '/';
TILDE: '~';
UNDERSCORE: '_';
VERTICAL_BAR: '|';
SEMICOLON: ';';

fragment HEX_DIGIT
    : [0-9a-f]
    ;

fragment DIGIT
    : [0-9]
    ;

fragment OCTAL_DIGIT
    : [0-7]
    ;

fragment BINARY_DIGIT
    : [0-1]
    ;

SP
  : (WHITESPACE)+
  -> channel(HIDDEN)
  ;

WHITESPACE
    : SPACE
    | TAB
    | LF
    | VT
    | FF
    | CR
    | FS
    | GS
    | RS
    | US
    | '\u1680'
    | '\u180e'
    | '\u2000'
    | '\u2001'
    | '\u2002'
    | '\u2003'
    | '\u2004'
    | '\u2005'
    | '\u2006'
    | '\u2008'
    | '\u2009'
    | '\u200a'
    | '\u2028'
    | '\u2029'
    | '\u205f'
    | '\u3000'
    | '\u00a0'
    | '\u2007'
    | '\u202f'
    ;

BRACKETED_COMMENT: '/*' .*? '*/' -> channel(HIDDEN);

SIMPLE_COMMENT_SOLIDUS: '//' ~[\r\n]* -> channel(HIDDEN);

SIMPLE_COMMENT_MINUS: '--' ~[\r\n]* -> channel(HIDDEN);

fragment GS : [\u001D];

fragment FS : [\u001C];

fragment CR : [\r];

fragment Sc : [\p{Sc}];

fragment SPACE : [ ];

fragment Pc : [\p{Pc}];

fragment TAB : [\t];

fragment LF : [\n];

fragment VT : [\u000B];

fragment US : [\u001F];

fragment FF: [\f];

fragment RS: [\u001E];

