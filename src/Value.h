#pragma once
#include <string>
#include <variant>
#include <unordered_map>
#include <iostream>

using namespace std;

// specialized implementation of variant for Value
using ValueType = variant<monostate, int, double, string, bool>;

struct Value {
    ValueType data;

    Value() : data(monostate{}) {}
    Value(int v) : data(v) {}
    Value(double v) : data(v) {}
    Value(string v) : data(v) {}
    Value(const char* v) : data(string(v)) {}
    Value(bool v) : data(v) {}

    string toString() const {
        if (auto pval = get_if<int>(&data)) return to_string(*pval);
        if (auto pval = get_if<double>(&data)) return to_string(*pval);
        if (auto pval = get_if<string>(&data)) return *pval; // Should we quote?
        if (auto pval = get_if<bool>(&data)) return *pval ? "true" : "false";
        return "NULL";
    }

    double toDouble() const {
        if (auto pval = get_if<int>(&data)) return (double)*pval;
        if (auto pval = get_if<double>(&data)) return *pval;
        if (auto pval = get_if<string>(&data)) {
            try { return stod(*pval); } catch(...) { return 0.0; }
        }
        return 0.0;
    }

    bool toBool() const {
        if (auto pval = get_if<bool>(&data)) return *pval;
        if (auto pval = get_if<int>(&data)) return *pval != 0;
        if (auto pval = get_if<string>(&data)) return *pval == "true" || *pval == "TRUE";
        return false;
    }
    
    // Comparison helpers
    bool operator>(const Value& other) const {
         if (holds_alternative<int>(data) && holds_alternative<int>(other.data)) {
             return get<int>(data) > get<int>(other.data);
         }
         if (holds_alternative<double>(data) && holds_alternative<double>(other.data)) {
             return get<double>(data) > get<double>(other.data);
         }
         if (holds_alternative<string>(data) && holds_alternative<string>(other.data)) {
             return get<string>(data) > get<string>(other.data);
         }
         return false; 
    }

    bool operator<(const Value& other) const {
         if (holds_alternative<int>(data) && holds_alternative<int>(other.data)) {
             return get<int>(data) < get<int>(other.data);
         }
         if (holds_alternative<double>(data) && holds_alternative<double>(other.data)) {
             return get<double>(data) < get<double>(other.data);
         }
         if (holds_alternative<string>(data) && holds_alternative<string>(other.data)) {
             return get<string>(data) < get<string>(other.data);
         }
         return false; 
    }

    bool operator==(const Value& other) const {
         if (holds_alternative<int>(data) && holds_alternative<int>(other.data)) {
             return get<int>(data) == get<int>(other.data);
         }
         if (holds_alternative<double>(data) && holds_alternative<double>(other.data)) {
             return get<double>(data) == get<double>(other.data);
         }
         if (holds_alternative<string>(data) && holds_alternative<string>(other.data)) {
             return get<string>(data) == get<string>(other.data);
         }
         if (holds_alternative<bool>(data) && holds_alternative<bool>(other.data)) {
             return get<bool>(data) == get<bool>(other.data);
         }
         return false; 
    }
};

struct Row {
    unordered_map<string, Value> values; // key: "variable.property" or just "variable" for node objects? 
    // In GQL, usually variables map to Nodes/Edges. But for this simple engine
    // let's say logical plan uses flattened names or we store Nodes as Values.
    
    // Actually, the prompt says:
    // struct Row { std::unordered_map<std::string, Value> values; };
    // And executing: MATCH (p:Person) ...
    // The "p" should probably be a Value containing the whole Node, 
    // OR we flat map "p.age", "p.name" etc.
    // Given "MemoryProject" extracts fields, it implies "p" might be the object.
    // Let's store "Node" as a Value type? Or just Map<Property, Value>?
    // For simplicity: "p" -> Value(NodePtr) ?
    // Or just store "p.age" -> 30, "p.name" -> "Alice".
    // "p" refers to the graph node.
    // If I just store properties flattened, it's easier for "p.age".
    // But "RETURN p" returns the whole node.
    
    // Let's add a generic "Object" or "Pointer" type to Value if needed, 
    // or just assume for this "Scan->Filter->Project" flow on properties, 
    // we can stick to simple types for properties.
    // But `IndexScan` returns a "Node".
    // Let's add a "Node*" to Value? Or just keep it as a map of properties for now.
    // The prompt says: "MemoryIndexScan ... next() returns one node at a time".
    // So Row should contain "p" -> Node.
};
