#pragma once
#include <memory>
#include <vector>
#include <string>
#include <map>

class ASTVisitor;

class ASTNode {
public:
    enum Type {
        QUERY,
        SESSION_SET,
        SESSION_RESET,
        SESSION_CLOSE,
        TRANSACTION,
        // Phase 2 additions:
        PROCEDURE_CALL,
        CATALOG_STATEMENT,
        // MATCH statement additions:
        MATCH_STATEMENT,
        NODE_PATTERN,
        EDGE_PATTERN,
        RETURN_STATEMENT,
        WHERE_CLAUSE,
        EXPRESSION,
        // Phase 2: Primitive query statements
        LET_STATEMENT,
        FOR_STATEMENT,
        FILTER_STATEMENT,
        ORDER_BY_STATEMENT,
        // Phase 3: Data modifying statements
        INSERT_STATEMENT,
        SET_STATEMENT,
        REMOVE_STATEMENT,
        DELETE_STATEMENT,
        // Phase 4: Composite query statements
        COMPOSITE_QUERY,
        // Phase 5: SELECT statements
        SELECT_STATEMENT,
        GROUP_BY_CLAUSE,
        HAVING_CLAUSE,
        // Phase 7: USE Graph clause
        USE_GRAPH
    };
    Type type;
    ASTNode(Type t) : type(t) {}
    virtual ~ASTNode() = default;
    virtual void accept(ASTVisitor* v) = 0;
};

// Root Query node
class QueryNode : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> children;
    QueryNode() : ASTNode(QUERY) {}
    void accept(ASTVisitor* v) override;
};

// Session Set
class SessionSetNode : public ASTNode {
public:
    std::string text;
    SessionSetNode(const std::string& t) : ASTNode(SESSION_SET), text(t) {}
    void accept(ASTVisitor* v) override;
};

// Session Reset
class SessionResetNode : public ASTNode {
public:
    std::string text;
    SessionResetNode(const std::string& t) : ASTNode(SESSION_RESET), text(t) {}
    void accept(ASTVisitor* v) override;
};

// Session Close
class SessionCloseNode : public ASTNode {
public:
    SessionCloseNode() : ASTNode(SESSION_CLOSE) {}
    void accept(ASTVisitor* v) override;
};

// Transaction
class TransactionNode : public ASTNode {
public:
    std::string action; // START / COMMIT / ROLLBACK
    TransactionNode(const std::string& act) : ASTNode(TRANSACTION), action(act) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Procedure Call ----------
class ProcedureCallNode : public ASTNode {
public:
    std::string name; // either "procName(...)" or "<inline>"
    std::vector<std::unique_ptr<ASTNode>> arguments;
    bool optional = false; // from OPTIONAL CALL

    ProcedureCallNode() : ASTNode(PROCEDURE_CALL) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Catalog Statement ----------
class CatalogStatementNode : public ASTNode {
public:
    std::string action;     // CREATE / DROP
    std::string objectType; // SCHEMA / GRAPH / GRAPH_TYPE
    std::string name;       // object name (we'll just store text for now)

    CatalogStatementNode() : ASTNode(CATALOG_STATEMENT) {}
    void accept(ASTVisitor* v) override;
};

// ---------- MATCH Statement ----------
class MatchStatementNode : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> patterns;  // NodePattern and EdgePattern nodes
    std::unique_ptr<ASTNode> whereClause;           // Optional WHERE clause
    std::unique_ptr<ASTNode> returnStatement;       // RETURN statement
    std::unique_ptr<ASTNode> graphExpression;      // Graph expression (for SELECT FROM MATCH)
    bool optional = false;  // OPTIONAL MATCH flag
    
    MatchStatementNode() : ASTNode(MATCH_STATEMENT) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Node Pattern ----------
class NodePatternNode : public ASTNode {
public:
    std::string variable;    // Variable name (e.g., "p", "m")
    std::vector<std::string> labels;  // Labels (e.g., "Person", "Movie")
    std::map<std::string, std::string> properties;  // Properties {key: value}
    
    NodePatternNode() : ASTNode(NODE_PATTERN) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Edge Pattern ----------
class EdgePatternNode : public ASTNode {
public:
    std::string variable;    // Variable name (e.g., "r")
    std::vector<std::string> labels;  // Relationship labels (e.g., "ACTED_IN")
    std::map<std::string, std::string> properties;  // Properties {key: value}
    std::string direction;  // "->", "<-", "<->", etc.
    
    EdgePatternNode() : ASTNode(EDGE_PATTERN) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Return Statement ----------
class ReturnStatementNode : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> expressions;  // Return expressions
    bool distinct = false;  // DISTINCT modifier
    
    ReturnStatementNode() : ASTNode(RETURN_STATEMENT) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Where Clause ----------
class WhereClauseNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> condition;  // Boolean expression
    
    WhereClauseNode() : ASTNode(WHERE_CLAUSE) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Expression ----------
class ExpressionNode : public ASTNode {
public:
    std::string type;        // "VARIABLE", "PROPERTY", "LITERAL", "BINARY_OP", "FUNCTION_CALL", "PROPERTY_ACCESS", etc.
    std::string value;       // The actual value/text (for literals, variable names, function names)
    std::string operator_;   // For binary operations: "=", ">", "<", "AND", "OR", "+", "-", "*", "/", etc.
    std::unique_ptr<ASTNode> left;   // Left operand (for binary ops)
    std::unique_ptr<ASTNode> right; // Right operand (for binary ops)
    std::unique_ptr<ASTNode> object; // Object for property access (variable.property)
    std::string propertyName; // Property name for property access
    std::vector<std::unique_ptr<ASTNode>> arguments; // Function call arguments
    std::string literalType; // "INTEGER", "FLOAT", "STRING", "BOOLEAN", "NULL" for literals
    
    ExpressionNode() : ASTNode(EXPRESSION) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Let Statement ----------
class LetStatementNode : public ASTNode {
public:
    struct LetVariableDefinition {
        std::string variable;
        std::string type;  // Optional type
        std::unique_ptr<ASTNode> valueExpression;  // Optional value expression
        bool hasType = false;
        bool hasValue = false;
    };
    std::vector<LetVariableDefinition> definitions;
    
    LetStatementNode() : ASTNode(LET_STATEMENT) {}
    void accept(ASTVisitor* v) override;
};

// ---------- For Statement ----------
class ForStatementNode : public ASTNode {
public:
    std::string variable;  // Binding variable
    std::unique_ptr<ASTNode> collectionExpression;  // valueExpression to iterate over
    bool withOrdinality = false;
    bool withOffset = false;
    std::string ordinalityVar;  // Variable for ordinality/offset
    
    ForStatementNode() : ASTNode(FOR_STATEMENT) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Filter Statement ----------
class FilterStatementNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> condition;  // WhereClause or Expression
    
    FilterStatementNode() : ASTNode(FILTER_STATEMENT) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Order By Statement ----------
class OrderByStatementNode : public ASTNode {
public:
    struct SortSpecification {
        std::unique_ptr<ASTNode> sortKey;  // Expression to sort by
        std::string direction;  // "ASC" or "DESC", empty for default
    };
    std::vector<SortSpecification> sortSpecs;
    std::unique_ptr<ASTNode> offset;  // ExpressionNode for OFFSET
    std::unique_ptr<ASTNode> limit;   // ExpressionNode for LIMIT
    
    OrderByStatementNode() : ASTNode(ORDER_BY_STATEMENT) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Insert Statement ----------
class InsertStatementNode : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> insertPatterns;  // NodePattern and EdgePattern nodes for insertion
    
    InsertStatementNode() : ASTNode(INSERT_STATEMENT) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Set Statement ----------
class SetStatementNode : public ASTNode {
public:
    struct SetItem {
        std::string variable;  // bindingVariableReference
        std::string type;  // "PROPERTY", "MAP", "LABEL"
        std::string propertyName;  // For property assignment
        std::unique_ptr<ASTNode> valueExpression;  // For property/map assignment
        std::string labelName;  // For label addition
        std::map<std::string, std::string> propertyMap;  // For map assignment (raw for now)
    };
    std::vector<SetItem> items;
    
    SetStatementNode() : ASTNode(SET_STATEMENT) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Remove Statement ----------
class RemoveStatementNode : public ASTNode {
public:
    struct RemoveItem {
        std::string variable;  // bindingVariableReference
        std::string type;  // "PROPERTY" or "LABEL"
        std::string propertyName;  // For property removal
        std::string labelName;  // For label removal
    };
    std::vector<RemoveItem> items;
    
    RemoveStatementNode() : ASTNode(REMOVE_STATEMENT) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Delete Statement ----------
class DeleteStatementNode : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> expressions;  // Variables/expressions to delete
    bool detach = false;  // DETACH DELETE
    bool nodetach = false;  // NODETACH DELETE
    
    DeleteStatementNode() : ASTNode(DELETE_STATEMENT) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Composite Query Statement ----------
class CompositeQueryNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> left;   // Left query (can be another CompositeQueryNode or linearQueryStatement)
    std::unique_ptr<ASTNode> right;  // Right query (linearQueryStatement)
    std::string operator_;           // "UNION", "EXCEPT", "INTERSECT", "OTHERWISE"
    bool distinct = false;           // UNION DISTINCT, EXCEPT DISTINCT, etc.
    bool all = false;                // UNION ALL, EXCEPT ALL, etc.
    
    CompositeQueryNode() : ASTNode(COMPOSITE_QUERY) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Select Statement ----------
class SelectStatementNode : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> selectItems;  // Select items (expressions with optional aliases)
    std::vector<std::unique_ptr<ASTNode>> fromMatches;  // FROM MATCH statements
    std::unique_ptr<ASTNode> whereClause;               // WHERE clause
    std::unique_ptr<ASTNode> groupByClause;             // GROUP BY clause
    std::unique_ptr<ASTNode> havingClause;              // HAVING clause
    std::unique_ptr<ASTNode> orderByClause;             // ORDER BY clause (reuse OrderByStatementNode)
    std::unique_ptr<ASTNode> offset;                    // OFFSET
    std::unique_ptr<ASTNode> limit;                     // LIMIT
    bool distinct = false;                              // SELECT DISTINCT
    bool selectAll = false;                             // SELECT *
    
    SelectStatementNode() : ASTNode(SELECT_STATEMENT) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Group By Clause ----------
class GroupByClauseNode : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> groupingExpressions;  // Expressions to group by
    
    GroupByClauseNode() : ASTNode(GROUP_BY_CLAUSE) {}
    void accept(ASTVisitor* v) override;
};

// ---------- Having Clause ----------
class HavingClauseNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> condition;  // Search condition (expression)
    
    HavingClauseNode() : ASTNode(HAVING_CLAUSE) {}
    void accept(ASTVisitor* v) override;
};

// ---------- USE Graph Clause ----------
class UseGraphNode : public ASTNode {
public:
    std::unique_ptr<ASTNode> graphExpression;  // Graph expression (for now stored as ExpressionNode)
    
    UseGraphNode() : ASTNode(USE_GRAPH) {}
    void accept(ASTVisitor* v) override;
};
