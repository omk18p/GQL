# AST Implementation Roadmap

## Overview
This roadmap outlines the steps to make the AST layer complete for handling ALL types of GQL queries. The implementation is organized by priority and query type.

---

## ✅ CURRENT STATUS - What Has Been Implemented

### Foundation & Infrastructure
- ✅ **AST Node Base Classes** (`ASTNodes.h`)
  - Base `ASTNode` class with type enum
  - `QueryNode` as root container
  - Visitor pattern support (`ASTVisitor`, `accept()` methods)

- ✅ **AST Builder Infrastructure** (`ASTBuilder.cpp`)
  - `ASTBuilder` class extending `GQLBaseVisitor`
  - `build()` method to construct AST from parse tree
  - Basic visitor pattern implementation

- ✅ **AST Printer** (`ASTPrinter.cpp`)
  - Printer class implementing `ASTVisitor`
  - Pretty-printing with indentation for all defined node types
  - Visualization of AST structure

### Session & Transaction Management
- ✅ **Session Commands**
  - `visitSessionActivity()` - routes session commands
  - `visitSessionSetCommand()` - creates `SessionSetNode`
  - `visitSessionResetCommand()` - creates `SessionResetNode`
  - `visitGqlProgram()` - handles `SESSION CLOSE`
  - ⚠️ **Limitation**: Session parameters stored as raw text (not parsed)

- ✅ **Transaction Commands**
  - `visitTransactionActivity()` - handles transaction blocks
  - `visitStartTransactionCommand()` - creates `TransactionNode("START")`
  - `visitTransactionActivity()` - handles `COMMIT` and `ROLLBACK`
  - Transaction nodes properly created and added to AST

### Program Structure
- ✅ **Program Hierarchy**
  - `visitGqlProgram()` - top-level program visitor
  - `visitProgramActivity()` - routes session/transaction activities
  - `visitProcedureBody()` - handles procedure body structure
  - `visitStatementBlock()` - handles statement sequences
  - `visitStatement()` - routes to different statement types

### MATCH Statement - Partial Implementation
- ✅ **Basic MATCH Structure**
  - `visitMatchStatement()` - creates `MatchStatementNode`
  - `visitGraphPattern()` - visits graph patterns (routes to path patterns)
  - `visitPathPattern()` - visits path patterns (routes to path pattern expressions)
  - ⚠️ **Issues**: 
    - Patterns not attached to `MatchStatementNode->patterns`
    - Missing path traversal (PathPatternExpression, PathTerm, PathFactor, PathPrimary)
    - No tracking of current match statement context

- ✅ **Node Pattern Extraction** (`visitElementPattern()`)
  - Extracts variable name from `elementVariableDeclaration`
  - Extracts labels from `isLabelExpression`
  - Extracts properties from `elementPatternPredicate`
  - ⚠️ **Issues**:
    - Labels stored with colon prefix (e.g., `:Person` instead of `Person`)
    - Properties stored as raw text (not parsed key-value pairs)
    - Only handles node patterns, doesn't handle edge patterns
    - Nodes added to root instead of current match statement

- ⚠️ **Edge Patterns - NOT IMPLEMENTED**
  - `visitFullEdgePattern()` - missing
  - `visitAbbreviatedEdgePattern()` - missing
  - Edge direction not extracted
  - Edge variables/labels/properties not extracted

### WHERE Clause - Partial Implementation
- ✅ **Basic WHERE Visitor**
  - `visitWhereClause()` - creates `WhereClauseNode`
  - Extracts `searchCondition` as text
  - Creates `ExpressionNode` with type "CONDITION"
  - ⚠️ **Issues**:
    - Condition stored as raw text (not parsed expression tree)
    - WHERE clause added to root instead of current match statement
    - No binary operation tree structure

### RETURN Statement - Partial Implementation
- ✅ **Basic RETURN Visitor**
  - `visitPrimitiveResultStatement()` - handles `RETURN` keyword
  - Creates `ReturnStatementNode`
  - Extracts `DISTINCT` modifier
  - Visits return items
  - ⚠️ **Issues**:
    - Return statement added to root instead of current match statement
    - Return items not properly attached to return statement

- ✅ **Return Item Visitor** (`visitReturnItem()`)
  - Extracts `aggregatingValueExpression` as text
  - Creates `ExpressionNode` with type "VARIABLE"
  - ⚠️ **Issues**:
    - Expression stored as text (not parsed)
    - Return item added to root instead of return statement's expressions vector

### AST Node Types Defined
- ✅ **Core Node Types**
  - `QueryNode`, `SessionSetNode`, `SessionResetNode`, `SessionCloseNode`
  - `TransactionNode`, `ProcedureCallNode`, `CatalogStatementNode`
  - `MatchStatementNode`, `NodePatternNode`, `EdgePatternNode`
  - `ReturnStatementNode`, `WhereClauseNode`, `ExpressionNode`

- ⚠️ **Missing Node Types** (not yet defined):
  - `LetStatementNode`, `ForStatementNode`, `FilterStatementNode`
  - `OrderByStatementNode`, `InsertStatementNode`, `SetStatementNode`
  - `RemoveStatementNode`, `DeleteStatementNode`, `CompositeQueryNode`
  - `SelectStatementNode`, `UseGraphNode`

### Expression Parsing - Basic Only
- ✅ **Expression Node Structure**
  - `ExpressionNode` class with fields: `type`, `value`, `operator_`, `left`, `right`
  - Supports basic expression storage
  - ⚠️ **Limitations**:
    - Expressions stored as text strings (not parsed into tree)
    - No binary operation tree construction
    - No property access parsing
    - No function call parsing
    - No literal parsing (numbers, strings, booleans)

### Statement Routing - Partial
- ✅ **Basic Statement Routing**
  - `visitStatement()` - routes to catalog, data modifying, or composite queries
  - `visitPrimitiveQueryStatement()` - handles MATCH (but not LET, FOR, FILTER, ORDER BY)
  - ⚠️ **Missing Routers**:
    - `visitLinearDataModifyingStatement()` - missing
    - `visitSimpleDataAccessingStatement()` - missing
    - `visitPrimitiveDataModifyingStatement()` - missing
    - `visitCompositeQueryStatement()` - missing
    - `visitSimpleQueryStatement()` - missing

---

## 📊 Implementation Summary

### ✅ Fully Working (5%)
- Session commands (SET, RESET, CLOSE)
- Transaction commands (START, COMMIT, ROLLBACK)
- Basic program structure navigation
- AST node type definitions
- AST printing infrastructure

### ⚠️ Partially Implemented (30%)
- MATCH statement structure (created but patterns not collected properly)
- Node pattern extraction (extracts data but with issues)
- WHERE clause visitor (creates node but doesn't attach correctly)
- RETURN statement visitor (creates node but doesn't attach correctly)
- Expression nodes (structure exists but only stores text)

### ❌ Not Implemented (65%)
- Edge pattern extraction (full and abbreviated)
- Path pattern traversal (missing intermediate visitors)
- Label expression parsing (complex expressions not handled)
- Property parsing (stores raw text)
- LET, FOR, FILTER, ORDER BY statements
- INSERT, SET, REMOVE, DELETE statements
- Composite queries (UNION, EXCEPT, INTERSECT)
- SELECT statements
- USE GRAPH clauses
- Expression tree construction (binary ops, property access, function calls)
- Proper AST structure (patterns attached to match statements, etc.)

---

## 🔴 CRITICAL ISSUES (Current AST Incompleteness)

### Phase 1: Fix MATCH Statement Implementation
**Priority: HIGHEST** - Without this, basic queries don't work correctly.

#### 1.1 Pattern Collection Structure
- [ ] **Track current MatchStatementNode during traversal**
  - Add `MatchStatementNode* currentMatchNode` member to ASTBuilder
  - Set it when entering `visitMatchStatement()`
  - Clear it when leaving

#### 1.2 Graph Pattern Binding Table
- [ ] **Implement `visitGraphPatternBindingTable()`**
  - Currently missing - needed to connect MATCH to graph pattern

#### 1.3 Path Pattern Traversal
- [ ] **Implement missing path pattern visitors:**
  - `visitPathPatternExpression()` - traverse path terms
  - `visitPathTerm()` - traverse path factors  
  - `visitPathFactor()` - traverse path primaries
  - `visitPathPrimary()` - route to element patterns

#### 1.4 Edge Pattern Extraction
- [ ] **Implement `visitFullEdgePattern()`**
  - Extract edge variable, labels, properties
  - Determine direction (`-->`, `<--`, `<->`, etc.)
  - Add to `currentMatchNode->patterns`

- [ ] **Implement `visitAbbreviatedEdgePattern()`**
  - Handle simple edges like `-`, `->`, `<-`

#### 1.5 WHERE Clause Attachment
- [ ] **Fix WHERE clause handling in `visitGraphPattern()`**
  - Create `WhereClauseNode` when `searchCondition` exists
  - Attach to `currentMatchNode->whereClause` (not root!)
  - Build proper expression tree for conditions

#### 1.6 Label Expression Parsing
- [ ] **Fix label extraction in `visitElementPattern()`**
  - Extract actual label name (not `:Person`, just `Person`)
  - Handle complex label expressions (conjunctions, disjunctions)
  - Support multiple labels per node

#### 1.7 Return Statement Integration
- [ ] **Fix RETURN statement attachment**
  - Attach `ReturnStatementNode` to `currentMatchNode->returnStatement`
  - Handle when RETURN is part of MATCH query

---

## 🟡 QUERY STATEMENT TYPES (Missing Implementations)

### Phase 2: Primitive Query Statements
**Priority: HIGH** - Core query operations.

#### 2.1 LET Statement
- [ ] **Add LET node type to ASTNodes.h**
  ```cpp
  enum Type { ..., LET_STATEMENT };
  class LetStatementNode : public ASTNode {
      std::vector<LetVariableDefinition> definitions;
  };
  ```
- [ ] **Implement `visitPrimitiveQueryStatement()` - LET branch**
  - Handle `LET letVariableDefinition (COMMA letVariableDefinition)*`
  - Create `LetStatementNode` with variable definitions
  - Store variable name, type (optional), and expression

#### 2.2 FOR Statement
- [ ] **Add FOR node type to ASTNodes.h**
  ```cpp
  enum Type { ..., FOR_STATEMENT };
  class ForStatementNode : public ASTNode {
      std::string variable;
      std::unique_ptr<ASTNode> collectionExpression;
      bool withOrdinality = false;
      bool withOffset = false;
      std::string ordinalityVar;
  };
  ```
- [ ] **Implement FOR visitor**
  - Handle `FOR bindingVariable IN valueExpression`
  - Handle optional `WITH (ORDINALITY | OFFSET) bindingVariable`

#### 2.3 FILTER Statement
- [ ] **Add FILTER node type to ASTNodes.h**
  ```cpp
  enum Type { ..., FILTER_STATEMENT };
  class FilterStatementNode : public ASTNode {
      std::unique_ptr<ASTNode> condition; // WhereClause or Expression
  };
  ```
- [ ] **Implement FILTER visitor**
  - Handle `FILTER (whereClause | searchCondition)`
  - Can reuse `WhereClauseNode` or create condition expression

#### 2.4 ORDER BY and Pagination
- [ ] **Add ORDER BY node types to ASTNodes.h**
  ```cpp
  enum Type { ..., ORDER_BY_STATEMENT };
  class OrderByStatementNode : public ASTNode {
      std::vector<SortSpecification> sortSpecs;
      std::unique_ptr<ASTNode> offset; // ExpressionNode
      std::unique_ptr<ASTNode> limit;  // ExpressionNode
  };
  ```
- [ ] **Implement `visitOrderByAndPageStatement()`**
  - Handle `orderByClause offsetClause? limitClause?`
  - Handle `offsetClause limitClause?`
  - Handle `limitClause`
- [ ] **Implement sorting specification extraction**
  - Extract sort key expressions
  - Extract ASC/DESC direction

#### 2.5 OPTIONAL MATCH
- [ ] **Update `MatchStatementNode`**
  - Add `bool optional = false` field
- [ ] **Update `visitMatchStatement()`**
  - Check for `OPTIONAL` keyword
  - Set optional flag on MatchStatementNode

---

## 🟢 DATA MODIFYING STATEMENTS

### Phase 3: Data Modification Operations
**Priority: MEDIUM-HIGH** - CRUD operations.

#### 3.1 INSERT Statement
- [ ] **Add INSERT node type to ASTNodes.h**
  ```cpp
  enum Type { ..., INSERT_STATEMENT };
  class InsertStatementNode : public ASTNode {
      std::vector<std::unique_ptr<ASTNode>> insertPatterns; // Node/Edge patterns
  };
  ```
- [ ] **Implement `visitPrimitiveDataModifyingStatement()` - INSERT branch**
  - Handle `INSERT insertGraphPattern`
  - Visit `insertPathPattern` elements
  - Extract node and edge patterns for insertion

#### 3.2 SET Statement
- [ ] **Add SET node type to ASTNodes.h**
  ```cpp
  enum Type { ..., SET_STATEMENT };
  class SetStatementNode : public ASTNode {
      std::vector<SetItem> items;
  };
  ```
- [ ] **Implement SET visitor**
  - Handle `SET setItem (COMMA setItem)*`
  - Extract property assignments, label additions
  - Handle different SET item types:
    - `variable.property = expression`
    - `variable = {key: value, ...}`
    - `variable:label` (label addition)

#### 3.3 REMOVE Statement
- [ ] **Add REMOVE node type to ASTNodes.h**
  ```cpp
  enum Type { ..., REMOVE_STATEMENT };
  class RemoveStatementNode : public ASTNode {
      std::vector<RemoveItem> items;
  };
  ```
- [ ] **Implement REMOVE visitor**
  - Handle `REMOVE removeItem (COMMA removeItem)*`
  - Extract property removals, label removals
  - Handle `variable.property` and `variable:label`

#### 3.4 DELETE Statement
- [ ] **Add DELETE node type to ASTNodes.h**
  ```cpp
  enum Type { ..., DELETE_STATEMENT };
  class DeleteStatementNode : public ASTNode {
      std::vector<std::unique_ptr<ASTNode>> expressions; // Variables to delete
      bool detach = false; // DETACH DELETE
      bool nodetach = false; // NODETACH DELETE
  };
  ```
- [ ] **Implement DELETE visitor**
  - Handle `(DETACH | NODETACH)? DELETE valueExpression (COMMA valueExpression)*`
  - Extract variables/expressions to delete
  - Track DETACH vs NODETACH flags

#### 3.5 Statement Chain Handling
- [ ] **Implement `visitLinearDataModifyingStatement()`**
  - Handle sequences like `MATCH ... DELETE ... RETURN ...`
  - Ensure proper ordering of statements
- [ ] **Implement `visitAmbientLinearDataModifyingStatement()`**
  - Handle `simpleDataAccessingStatement+ primitiveResultStatement?`
- [ ] **Implement `visitSimpleDataAccessingStatement()`**
  - Route to `simpleQueryStatement` or `primitiveDataModifyingStatement`

---

## 🔵 COMPOSITE QUERIES

### Phase 4: Query Composition
**Priority: MEDIUM** - UNION, EXCEPT, INTERSECT.

#### 4.1 Composite Query Nodes
- [ ] **Add composite query node types to ASTNodes.h**
  ```cpp
  enum Type { ..., COMPOSITE_QUERY, UNION, EXCEPT, INTERSECT, OTHERWISE };
  class CompositeQueryNode : public ASTNode {
      std::unique_ptr<ASTNode> left;
      std::unique_ptr<ASTNode> right;
      std::string operator_; // "UNION", "EXCEPT", "INTERSECT", "OTHERWISE"
      bool distinct = false; // UNION DISTINCT, etc.
  };
  ```
- [ ] **Implement `visitCompositeQueryStatement()`**
- [ ] **Implement `visitCompositeQueryExpression()`**
  - Handle recursive composition: `compositeQueryExpression queryConjunction linearQueryStatement`
  - Build left-associative tree
- [ ] **Implement `visitQueryConjunction()`**
  - Extract operator (UNION, EXCEPT, INTERSECT, OTHERWISE)
  - Extract DISTINCT/ALL quantifier

---

## 🟣 ADVANCED QUERY FEATURES

### Phase 5: SELECT Statements
**Priority: MEDIUM** - SQL-like queries.

#### 5.1 SELECT Node Types
- [ ] **Add SELECT node types to ASTNodes.h**
  ```cpp
  enum Type { ..., SELECT_STATEMENT };
  class SelectStatementNode : public ASTNode {
      std::vector<std::unique_ptr<ASTNode>> selectItems;
      std::unique_ptr<ASTNode> fromClause; // MatchStatement or SelectGraphMatch
      std::unique_ptr<ASTNode> whereClause;
      std::unique_ptr<ASTNode> groupByClause;
      std::unique_ptr<ASTNode> havingClause;
      std::unique_ptr<ASTNode> orderByClause;
      bool distinct = false;
  };
  ```
- [ ] **Implement `visitSelectStatement()`**
- [ ] **Implement `visitSelectStatementBody()`**
- [ ] **Implement `visitSelectGraphMatch()`**
- [ ] **Implement GROUP BY and HAVING**

### Phase 6: Procedure Calls
**Priority: LOW-MEDIUM** - Already partially implemented.

#### 6.1 Procedure Call Completion
- [ ] **Verify `ProcedureCallNode` is complete**
- [ ] **Implement `visitCallProcedureStatement()`**
- [ ] **Extract procedure arguments properly**
- [ ] **Handle OPTIONAL CALL**

### Phase 7: USE Graph Clause
**Priority: MEDIUM** - Graph context.

#### 7.1 USE Graph Node
- [ ] **Add USE_GRAPH node type to ASTNodes.h**
  ```cpp
  enum Type { ..., USE_GRAPH };
  class UseGraphNode : public ASTNode {
      std::unique_ptr<ASTNode> graphExpression;
  };
  ```
- [ ] **Implement `visitUseGraphClause()`**
- [ ] **Handle graph expression extraction**

---

## 🟤 EXPRESSION PARSING

### Phase 8: Complete Expression Tree
**Priority: HIGH** - Needed for WHERE, RETURN, etc.

#### 8.1 Binary Operations
- [ ] **Enhance `ExpressionNode` for binary ops**
  - Parse `left operator right` structure
  - Support: `=`, `!=`, `>`, `<`, `>=`, `<=`, `AND`, `OR`, `+`, `-`, `*`, `/`, etc.
  - Build proper expression tree (not just text)

#### 8.2 Property Access
- [ ] **Handle `variable.property`**
  - Create proper AST structure for property access
  - Support nested properties

#### 8.3 Function Calls
- [ ] **Add function call support**
  - Extract function name
  - Extract arguments as expression nodes

#### 8.4 Aggregations
- [ ] **Handle aggregation functions**
  - COUNT, SUM, AVG, MIN, MAX, etc.
  - GROUP BY integration

#### 8.5 Literals
- [ ] **Parse literals properly**
  - Numbers (integers, floats)
  - Strings
  - Booleans
  - NULL

---

## 🟠 PATTERN DETAILS

### Phase 9: Pattern Element Details
**Priority: MEDIUM** - Enhance pattern extraction.

#### 9.1 Property Parsing
- [ ] **Parse property maps properly**
  - Currently stores as "raw" text
  - Should parse `{key: value, key2: value2}`
  - Convert values to ExpressionNodes

#### 9.2 Variable Extraction
- [ ] **Improve variable name extraction**
  - Currently may miss some contexts
  - Ensure all variable references are captured

#### 9.3 Label Expression Complexity
- [ ] **Handle complex label expressions**
  - `:Person|Movie` (disjunction)
  - `:Person&Actor` (conjunction)
  - `!Label` (negation)
  - Parenthesized expressions

#### 9.4 Quantifiers
- [ ] **Handle pattern quantifiers**
  - `*`, `+`, `{n}`, `{n,m}` in path patterns
  - Implement `visitGraphPatternQuantifier()`

#### 9.5 Simplified Path Patterns
- [ ] **Handle simplified syntax**
  - Implement `visitSimplifiedPathPatternExpression()`
  - Parse `/.../` patterns

---

## ⚪ AUXILIARY FEATURES

### Phase 10: Session & Transaction
**Priority: LOW** - Already mostly done.

#### 10.1 Session Commands
- [ ] **Verify all session commands work**
- [ ] **Parse session parameters properly** (currently just text)

#### 10.2 Catalog Statements
- [ ] **Verify catalog statements** (CREATE/DROP SCHEMA/GRAPH)
- [ ] **Parse catalog statement details**

---

## 📋 IMPLEMENTATION CHECKLIST BY FILE

### ASTNodes.h
- [ ] Add missing node types (LET, FOR, FILTER, ORDER_BY, INSERT, SET, REMOVE, DELETE, COMPOSITE_QUERY, SELECT, USE_GRAPH)
- [ ] Add node classes for each type
- [ ] Ensure all nodes have proper fields for their semantics

### ASTBuilder.h
- [ ] Add `currentMatchNode` pointer member
- [ ] Declare all missing visitor methods
- [ ] Organize visitors by category (Query, Pattern, Expression, etc.)

### ASTBuilder.cpp
#### MATCH Statement Fixes:
- [ ] Set/clear `currentMatchNode` in `visitMatchStatement()`
- [ ] Implement `visitGraphPatternBindingTable()`
- [ ] Implement path pattern traversal (PathPatternExpression, PathTerm, PathFactor, PathPrimary)
- [ ] Implement `visitFullEdgePattern()`
- [ ] Implement `visitAbbreviatedEdgePattern()`
- [ ] Fix WHERE clause attachment in `visitGraphPattern()`
- [ ] Fix label extraction (remove `:` prefix)
- [ ] Fix RETURN statement attachment

#### Query Statements:
- [ ] Implement LET statement visitor
- [ ] Implement FOR statement visitor
- [ ] Implement FILTER statement visitor
- [ ] Implement ORDER BY visitor
- [ ] Handle OPTIONAL MATCH

#### Data Modifying:
- [ ] Implement INSERT visitor
- [ ] Implement SET visitor
- [ ] Implement REMOVE visitor
- [ ] Implement DELETE visitor
- [ ] Implement statement chain visitors

#### Composite Queries:
- [ ] Implement composite query visitors
- [ ] Build proper query composition tree

#### Expressions:
- [ ] Enhance expression tree building
- [ ] Parse binary operations properly
- [ ] Parse property access
- [ ] Parse function calls
- [ ] Parse literals

### ASTPrinter.cpp
- [ ] Add print methods for all new node types
- [ ] Ensure proper indentation
- [ ] Print all fields clearly

### ASTVisitor.h
- [ ] Add visitor methods for all new node types

### ASTNodes.cpp
- [ ] Implement `accept()` methods for all new node types

---

## 🎯 PRIORITY ORDER

1. **Phase 1** - Fix MATCH statement (blocks basic queries)
2. **Phase 8** - Expression parsing (needed everywhere)
3. **Phase 2** - Primitive queries (LET, FOR, FILTER, ORDER BY)
4. **Phase 3** - Data modifying (INSERT, SET, REMOVE, DELETE)
5. **Phase 9** - Pattern details (enhancements)
6. **Phase 4** - Composite queries (UNION, etc.)
7. **Phase 5** - SELECT statements
8. **Phase 6-7, 10** - Advanced features

---

## 📝 NOTES

- Test each phase with sample queries before moving to next
- Use `test queries/` directory for validation
- Consider adding unit tests for AST construction
- Document any assumptions about query semantics
- Ensure AST can be traversed for query execution/optimization

---

## ✅ COMPLETION CRITERIA

The AST is "complete" when:
1. ✅ All query types can be parsed into AST nodes
2. ✅ Pattern information (nodes, edges, labels, properties) is fully captured
3. ✅ WHERE clauses are properly structured as expression trees
4. ✅ RETURN clauses extract all return items correctly
5. ✅ Data modifying statements (INSERT, SET, REMOVE, DELETE) are represented
6. ✅ Expression trees are properly structured (not just text)
7. ✅ Composite queries build correct tree structures
8. ✅ All AST nodes can be visited and printed
9. ✅ No critical information is lost from parse tree to AST
10. ✅ AST can be used for query optimization/execution

