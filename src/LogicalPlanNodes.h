#pragma once
#include <memory>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Forward declaration
class LogicalPlanVisitor;

// Base class for all logical plan nodes
class LogicalPlanNode {
public:
    enum Type {
        NODE_SCAN,        // Scan nodes by label (e.g., NodeScan(Person))
        EDGE_SCAN,        // Scan edges by label
        FILTER,           // Filter rows based on condition
        PROJECT,          // Project/select specific fields
        JOIN,             // Join two data sources
        NESTED_LOOP_JOIN, // Join using nested loops
        HASH_JOIN,        // Join using hash table
        SORT,             // Sort results
        LIMIT,            // Limit number of results
        OFFSET,           // Skip results
        AGGREGATE,        // Group by and aggregate (COUNT, SUM, etc.)
        UNION,            // Union of two queries
        DISTINCT,         // Remove duplicates
        DELETE_OP,        // Delete operation
        INSERT_OP,        // Insert operation
        UPDATE_OP,        // Update operation
        BINARY_EXPRESSION,// Binary expression (AND, OR, >, =, etc.)
        PROPERTY_ACCESS,  // Property access (p.age)
        VARIABLE_REF,     // Variable reference (p)
        LITERAL           // Literal value (25, "London")
    };
    
    Type type;
    vector<unique_ptr<LogicalPlanNode>> children; // Child operations
    
    LogicalPlanNode(Type t) : type(t) {}
    virtual ~LogicalPlanNode() = default;
    virtual void accept(LogicalPlanVisitor* visitor) = 0;
};

// ========== SCAN OPERATIONS ==========

class NodeScanNode : public LogicalPlanNode {
public:
    string label;           // Label to scan (e.g., "Person")
    string variable;        // Variable name (e.g., "p")
    map<string, string> properties; // Property filters
    
    NodeScanNode() : LogicalPlanNode(NODE_SCAN) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

class EdgeScanNode : public LogicalPlanNode {
public:
    string label;           // Edge label (e.g., "ACTED_IN")
    string variable;        // Variable name (e.g., "r")
    string sourceVar;       // Variable of left node
    string targetVar;       // Variable of right node
    string direction;       // "->", "<-", "<->"
    map<string, string> properties; // Property filters
    
    EdgeScanNode() : LogicalPlanNode(EDGE_SCAN) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

// ========== FILTER OPERATION ==========

class FilterNode : public LogicalPlanNode {
public:
    unique_ptr<LogicalPlanNode> condition; // Condition expression tree
    
    FilterNode() : LogicalPlanNode(FILTER) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

// ========== PROJECT OPERATION ==========

class ProjectNode : public LogicalPlanNode {
public:
    vector<string> fields;  // Field names to project
    vector<unique_ptr<LogicalPlanNode>> expressions; // Expressions to project
    
    ProjectNode() : LogicalPlanNode(PROJECT) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

// ========== JOIN OPERATIONS ==========

class JoinNode : public LogicalPlanNode {
public:
    string joinType;  // "INNER", "LEFT", "RIGHT", "FULL"
    unique_ptr<LogicalPlanNode> condition; // Join condition
    
    JoinNode() : LogicalPlanNode(JOIN) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

// ========== AGGREGATE OPERATION ==========

class AggregateNode : public LogicalPlanNode {
public:
    // Grouping expressions
    vector<unique_ptr<LogicalPlanNode>> groupingExpressions;
    vector<string> groupingAliases;
    
    // Aggregate items
    struct AggregateItem {
        string functionName;
        unique_ptr<LogicalPlanNode> expression;
        string alias;
        bool distinct = false;
    };
    vector<AggregateItem> aggregateItems;
    
    AggregateNode() : LogicalPlanNode(AGGREGATE) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

// ========== SORT OPERATION ==========

class SortNode : public LogicalPlanNode {
public:
    struct SortField {
        string field;
        string direction; // "ASC" or "DESC"
    };
    vector<SortField> sortFields;
    
    SortNode() : LogicalPlanNode(SORT) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

// ========== LIMIT/OFFSET OPERATIONS ==========

class LimitNode : public LogicalPlanNode {
public:
    int limit;
    
    LimitNode(int l) : LogicalPlanNode(LIMIT), limit(l) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

class OffsetNode : public LogicalPlanNode {
public:
    int offset;
    
    OffsetNode(int o) : LogicalPlanNode(OFFSET), offset(o) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

// ========== SET OPERATIONS ==========

class UnionNode : public LogicalPlanNode {
public:
    bool distinct; // UNION DISTINCT vs UNION ALL
    
    UnionNode() : LogicalPlanNode(UNION), distinct(false) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

// ========== MODIFY OPERATIONS ==========

class DeleteOpNode : public LogicalPlanNode {
public:
    vector<string> variables; // Variables to delete
    bool detach; // DETACH DELETE
    
    DeleteOpNode() : LogicalPlanNode(DELETE_OP), detach(false) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

class InsertOpNode : public LogicalPlanNode {
public:
    vector<unique_ptr<LogicalPlanNode>> patterns; // Patterns to insert
    
    InsertOpNode() : LogicalPlanNode(INSERT_OP) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

class UpdateOpNode : public LogicalPlanNode {
public:
    enum UpdateType { SET_PROPERTY, SET_LABEL, REMOVE_PROPERTY, REMOVE_LABEL, SET_MAP };
    
    struct UpdateItem {
        UpdateType type;
        string variable;
        string key;      // property name or label name
        unique_ptr<LogicalPlanNode> value; // for SET_PROPERTY/SET_MAP
    };
    
    vector<UpdateItem> items;
    
    UpdateOpNode() : LogicalPlanNode(UPDATE_OP) {}
    void accept(LogicalPlanVisitor* visitor) override;
};
// ========== EXPRESSION OPERATIONS ==========

class LogicalExpressionNode : public LogicalPlanNode {
public:
    LogicalExpressionNode(Type t) : LogicalPlanNode(t) {}
};

class BinaryExpressionNode : public LogicalExpressionNode {
public:
    string op; // ">", "=", "AND", "OR", etc.
    unique_ptr<LogicalPlanNode> left;
    unique_ptr<LogicalPlanNode> right;
    
    BinaryExpressionNode() : LogicalExpressionNode(BINARY_EXPRESSION) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

class PropertyAccessNode : public LogicalExpressionNode {
public:
    string variable; // "p"
    string property; // "age"
    
    PropertyAccessNode(string var, string prop) 
        : LogicalExpressionNode(PROPERTY_ACCESS), variable(var), property(prop) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

class VariableReferenceNode : public LogicalExpressionNode {
public:
    string variable; // "p"
    
    VariableReferenceNode(string var) 
        : LogicalExpressionNode(VARIABLE_REF), variable(var) {}
    void accept(LogicalPlanVisitor* visitor) override;
};

class LiteralNode : public LogicalExpressionNode {
public:
    string value; // "25", "London"
    string literalType; // "NUMBER", "STRING", "BOOLEAN"
    
    LiteralNode(string val, string type) 
        : LogicalExpressionNode(LITERAL), value(val), literalType(type) {}
    void accept(LogicalPlanVisitor* visitor) override;
};
