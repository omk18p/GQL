#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <map>

using namespace std;

// Logical Plan Nodes for reference (if needed directly in physical plan, though ideally decoupled)
// For now we'll just use strings/simple structures or forward declare if we need to keep a reference.
// But for a pure physical plan, we usually copy strict necessary info.

enum class PhysicalOperatorType {
    MEM_SCAN_FULL,
    MEM_SCAN_LABEL,
    MEM_SCAN_EDGE,
    MEM_FILTER,
    MEM_PROJECT,
    MEM_NESTED_LOOP_JOIN,
    MEM_HASH_JOIN,
    MEM_SORT,
    MEM_LIMIT,
    MEM_OFFSET,
    MEM_AGGREGATE,
    MEM_UNION,
    MEM_DELETE,
    MEM_INSERT,
    MEM_UPDATE,
    MEM_DISTINCT,
    MEM_VALUES
};

class PhysicalPlanNode {
public:
    PhysicalOperatorType type;
    vector<unique_ptr<PhysicalPlanNode>> children;

    PhysicalPlanNode(PhysicalOperatorType t) : type(t) {}
    virtual ~PhysicalPlanNode() = default;

    // Helper for printing the tree
    virtual string toString() const = 0;

    void print(int indent = 0) const {
        string indentation(indent * 2, ' ');
        cout << indentation << toString() << endl;
        for (const auto& child : children) {
            child->print(indent + 1);
        }
    }
};

// --- Scans ---

class PhysicalFullScan : public PhysicalPlanNode {
public:
    string variable;
    map<string, string> properties;

    PhysicalFullScan(string v) 
        : PhysicalPlanNode(PhysicalOperatorType::MEM_SCAN_FULL), variable(v) {}

    string toString() const override {
        string res = "MemFullScan(variable: " + variable;
        if (!properties.empty()) {
            res += ", properties: {";
            for (auto const& [key, val] : properties) res += key + ": " + val + ", ";
            res.pop_back(); res.pop_back(); res += "}";
        }
        res += ")";
        return res;
    }
};

class PhysicalLabelScan : public PhysicalPlanNode {
public:
    string label;
    string variable;
    map<string, string> properties;

    PhysicalLabelScan(string l, string v) 
        : PhysicalPlanNode(PhysicalOperatorType::MEM_SCAN_LABEL), label(l), variable(v) {}

    string toString() const override {
        string res = "MemLabelScan(label: " + label + ", variable: " + variable;
        if (!properties.empty()) {
            res += ", properties: {";
            for (auto const& [key, val] : properties) res += key + ": " + val + ", ";
            res.pop_back(); res.pop_back(); res += "}";
        }
        res += ")";
        return res;
    }
};

class PhysicalEdgeScan : public PhysicalPlanNode {
public:
    string label;
    string variable;
    string direction; // "OUT", "IN", "BOTH" - simplified

    PhysicalEdgeScan(string l, string v, string dir) 
        : PhysicalPlanNode(PhysicalOperatorType::MEM_SCAN_EDGE), label(l), variable(v), direction(dir) {}

    string toString() const override {
        return "MemEdgeScan(label: " + label + ", variable: " + variable + ", direction: " + direction + ")";
    }
};

// --- Core Operators ---

class PhysicalFilter : public PhysicalPlanNode {
public:
    string conditionDescription; // Simplified for now, just the string representation of condition

    PhysicalFilter(string condDesc) 
        : PhysicalPlanNode(PhysicalOperatorType::MEM_FILTER), conditionDescription(condDesc) {}

    string toString() const override {
        return "MemFilter(condition: " + conditionDescription + ")";
    }
};

class PhysicalProject : public PhysicalPlanNode {
public:
    vector<string> fields;

    PhysicalProject(vector<string> f) 
        : PhysicalPlanNode(PhysicalOperatorType::MEM_PROJECT), fields(f) {}

    string toString() const override {
        string s = "MemProject([";
        for (size_t i = 0; i < fields.size(); ++i) {
            s += fields[i];
            if (i < fields.size() - 1) s += ", ";
        }
        s += "])";
        return s;
    }
};

// --- Joins ---

class PhysicalNestedLoopJoin : public PhysicalPlanNode {
public:
    string joinType; // INNER, LEFT, etc.
    string condition; 

    PhysicalNestedLoopJoin(string type, string cond) 
        : PhysicalPlanNode(PhysicalOperatorType::MEM_NESTED_LOOP_JOIN), joinType(type), condition(cond) {}

    string toString() const override {
        return "MemNestedLoopJoin(type: " + joinType + ", condition: " + condition + ")";
    }
};

// --- Other ---

class PhysicalSort : public PhysicalPlanNode {
public:
    struct SortItem {
        string field;
        bool ascending;
    };
    vector<SortItem> items;

    PhysicalSort(vector<SortItem> i) 
        : PhysicalPlanNode(PhysicalOperatorType::MEM_SORT), items(i) {}

    string toString() const override {
        string s = "MemSort([";
        for (size_t i = 0; i < items.size(); ++i) {
            s += items[i].field + (items[i].ascending ? " ASC" : " DESC");
            if (i < items.size() - 1) s += ", ";
        }
        s += "])";
        return s;
    }
};

class PhysicalLimit : public PhysicalPlanNode {
public:
    int limit;
    PhysicalLimit(int l) : PhysicalPlanNode(PhysicalOperatorType::MEM_LIMIT), limit(l) {}
    string toString() const override { return "MemLimit(" + to_string(limit) + ")"; }
};

class PhysicalOffset : public PhysicalPlanNode {
public:
    int offset;
    PhysicalOffset(int o) : PhysicalPlanNode(PhysicalOperatorType::MEM_OFFSET), offset(o) {}
    string toString() const override { return "MemOffset(" + to_string(offset) + ")"; }
};

class PhysicalAggregate : public PhysicalPlanNode {
public:
    vector<string> groupings;
    vector<string> measures; // e.g. "COUNT(p)", "SUM(age)"

    PhysicalAggregate(vector<string> g, vector<string> m)
        : PhysicalPlanNode(PhysicalOperatorType::MEM_AGGREGATE), groupings(g), measures(m) {}

    string toString() const override {
        string s = "MemAggregate(GroupBy: [";
        for (size_t i = 0; i < groupings.size(); ++i) {
            s += groupings[i];
            if (i < groupings.size() - 1) s += ", ";
        }
        s += "], Measures: [";
         for (size_t i = 0; i < measures.size(); ++i) {
            s += measures[i];
            if (i < measures.size() - 1) s += ", ";
        }
        s += "])";
        return s;
    }
};

class PhysicalValues : public PhysicalPlanNode {
public:
    vector<string> values;

    PhysicalValues(vector<string> v)
        : PhysicalPlanNode(PhysicalOperatorType::MEM_VALUES), values(v) {}
    
    string toString() const override {
        return "MemValues(...)";
    }
};

// --- Modification ---

// Structs to mirror AST but independent of AST Nodes to decouple dependencies
struct PhysicalProperty {
    string key;
    string expressionString; // E.g., "\"Dan\"" or "50" from ASTNode
};

struct PhysicalInsertNode {
    string variable;
    vector<string> labels;
    vector<PhysicalProperty> properties;
};

struct PhysicalInsertEdge {
    string variable;
    string sourceVar;
    string targetVar;
    string direction; // "->", "<-"
    vector<string> labels;
    vector<PhysicalProperty> properties;
};

class PhysicalInsert : public PhysicalPlanNode {
public:
    vector<PhysicalInsertNode> insertNodes;
    vector<PhysicalInsertEdge> insertEdges;

    PhysicalInsert() : PhysicalPlanNode(PhysicalOperatorType::MEM_INSERT) {}
    
    string toString() const override { 
        string s = "MemInsert(Nodes: " + to_string(insertNodes.size()) + ", Edges: " + to_string(insertEdges.size()) + ")"; 
        return s;
    }
};

class PhysicalDelete : public PhysicalPlanNode {
public:
    vector<string> variables;
    bool detach;
    PhysicalDelete(vector<string> vars, bool d) 
        : PhysicalPlanNode(PhysicalOperatorType::MEM_DELETE), variables(vars), detach(d) {}
    string toString() const override { 
        string s = "MemDelete(vars: [";
        for(auto& v : variables) s += v + " ";
        s += "], detach: " + (detach ? string("true") : string("false")) + ")";
        return s;
    }
};

struct PhysicalUpdateItem {
    enum Type { SET_PROPERTY, SET_LABEL, REMOVE_PROPERTY, REMOVE_LABEL };
    Type type;
    string variable;
    string key; // Property name or Label name
    string expressionString;
};

class PhysicalUpdate : public PhysicalPlanNode {
public: 
    vector<PhysicalUpdateItem> items;
    
    PhysicalUpdate() : PhysicalPlanNode(PhysicalOperatorType::MEM_UPDATE) {}
    string toString() const override { 
        string s = "MemUpdate(Items: " + to_string(items.size()) + ")"; 
        for (auto& i : items) {
            s += "\n    - " + i.variable + "." + i.key + " = " + i.expressionString;
        }
        return s; 
    }
};

class PhysicalDistinct : public PhysicalPlanNode {
public:
    PhysicalDistinct() : PhysicalPlanNode(PhysicalOperatorType::MEM_DISTINCT) {}
    string toString() const override { return "MemDistinct"; }
};

class PhysicalUnion : public PhysicalPlanNode {
public:
    bool distinct;
    PhysicalUnion(bool d) : PhysicalPlanNode(PhysicalOperatorType::MEM_UNION), distinct(d) {}
    string toString() const override { return distinct ? "MemUnionDistinct" : "MemUnionAll"; }
};
