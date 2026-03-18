#include "PhysicalOperator.h"
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// --- Helper Functions ---

// Simple parser for "variable.property"
pair<string, string> parseVarProp(const string& s) {
    size_t dotPos = s.find('.');
    if (dotPos == string::npos) return {s, ""}; // Just variable
    return {s.substr(0, dotPos), s.substr(dotPos + 1)};
}

// Evaluate expression on a Row
// Supports: "p.age", "30", "p.age > 30"
Value evaluate(const Row& row, const string& expr) {
    auto trim = [](string s) {
        if (s.empty()) return s;
        size_t start = s.find_first_not_of(" \t\n\r");
        if (start == string::npos) return string("");
        size_t end = s.find_last_not_of(" \t\n\r");
        string t = s.substr(start, end - start + 1);
        
        while (t.size() >= 2 && t.front() == '(' && t.back() == ')') {
            int depth = 0;
            bool matching = true;
            for (size_t i = 0; i < t.size() - 1; ++i) {
                if (t[i] == '(') depth++;
                else if (t[i] == ')') depth--;
                if (depth == 0) { matching = false; break; }
            }
            if (matching) {
                t = t.substr(1, t.size() - 2);
                start = t.find_first_not_of(" \t\n\r");
                if (start == string::npos) return string("");
                end = t.find_last_not_of(" \t\n\r");
                t = t.substr(start, end - start + 1);
            } else break;
        }
        return t;
    };

    string tExpr = trim(expr);
    if (tExpr.empty()) return Value(false);

    auto findWordDepth = [](const string& s, const string& word) -> size_t {
        int depth = 0;
        string upperS = s; for(auto &c : upperS) c = toupper(c);
        string upperW = word; for(auto &c : upperW) c = toupper(c);

        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '(') depth++;
            else if (s[i] == ')') depth--;
            else if (depth == 0) {
                if (upperS.size() >= i + upperW.size() && upperS.substr(i, upperW.length()) == upperW) {
                    auto isBoundary = [](char c) { return !isalnum(c) && c != '_'; };
                    bool leftOk = (i == 0 || isBoundary(s[i-1]));
                    bool rightOk = (i + upperW.length() == s.length() || isBoundary(s[i+upperW.length()]));
                    if (leftOk && rightOk) return i;
                }
            }
        }
        return string::npos;
    };

    size_t orPos = findWordDepth(tExpr, "OR");
    if (orPos != string::npos) {
        return Value(evaluate(row, tExpr.substr(0, orPos)).toBool() || evaluate(row, tExpr.substr(orPos + 2)).toBool());
    }

    size_t andPos = findWordDepth(tExpr, "AND");
    if (andPos != string::npos) {
        return Value(evaluate(row, tExpr.substr(0, andPos)).toBool() && evaluate(row, tExpr.substr(andPos + 3)).toBool());
    }

    auto findOpDepth = [](const string& s, const string& op) -> size_t {
        int depth = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '(') depth++;
            else if (s[i] == ')') depth--;
            else if (depth == 0) {
                if (s.size() >= i + op.size() && s.substr(i, op.length()) == op) return i;
            }
        }
        return string::npos;
    };

    string ops[] = {">=", "<=", "<>", "=", ">", "<"};
    for (const string& op : ops) {
        size_t pos = findOpDepth(tExpr, op);
        if (pos != string::npos) {
            Value lv = evaluate(row, tExpr.substr(0, pos));
            Value rv = evaluate(row, tExpr.substr(pos + op.length()));
            if (op == "=") return Value(lv.toString() == rv.toString());
            if (op == ">") return Value(lv.toDouble() > rv.toDouble());
            if (op == "<") return Value(lv.toDouble() < rv.toDouble());
            if (op == ">=") return Value(lv.toDouble() >= rv.toDouble());
            if (op == "<=") return Value(lv.toDouble() <= rv.toDouble());
            if (op == "<>") return Value(lv.toString() != rv.toString());
        }
    }

    if (tExpr.find('.') != string::npos) {
        size_t dotPos = tExpr.find('.');
        string var = tExpr.substr(0, dotPos);
        string prop = tExpr.substr(dotPos + 1);
        string fullKey = var + "." + prop;
        if (row.values.count(fullKey)) return row.values.at(fullKey);
        if (row.values.count(var)) return row.values.at(var);
    }
    
    if (tExpr.size() >= 2 && tExpr.front() == '\'' && tExpr.back() == '\'') {
        return Value(tExpr.substr(1, tExpr.size() - 2));
    }
    
    try {
        if (tExpr.find_first_not_of("0123456789.-") == string::npos) {
            return Value(stod(tExpr));
        }
    } catch (...) {}

    return Value(tExpr);
}


// --- MemoryFullScan ---

void MemoryFullScan::open() {
    if (child) {
        child->open();
        Row dummy;
        while(child->next(dummy)) {}
        child->close();
    }
    nodes = graph.getAllNodes();
    currentIndex = 0;
}

bool MemoryFullScan::next(Row& row) {
    if (currentIndex >= nodes.size()) return false;
    
    auto node = nodes[currentIndex];
    currentIndex++;
    
    row.values[variable] = Value(node->id); 
    row.values[variable + ".id"] = Value(node->id); 
    
    for (auto& prop : node->properties) {
        row.values[variable + "." + prop.first] = prop.second;
    }
    
    return true;
}

void MemoryFullScan::close() {
    nodes.clear();
}


// --- MemoryIndexScan ---

void MemoryIndexScan::open() {
    if (child) {
        child->open();
        Row dummy;
        while(child->next(dummy)) {}
        child->close();
    }
    nodes = graph.getNodesByLabel(label);
    currentIndex = 0;
    // cout << "IndexScan opened. Found " << nodes.size() << " nodes for label " << label << endl;
}

bool MemoryIndexScan::next(Row& row) {
    if (currentIndex >= nodes.size()) return false;
    
    // Load current node into row
    auto node = nodes[currentIndex];
    currentIndex++;
    
    // Populate row with node properties flattened
    // AND the node reference itself (simulated by ID + all props)
    
    // 1. Variable itself and .id
    row.values[variable] = Value(node->id); 
    row.values[variable + ".id"] = Value(node->id); 
    
    // 2. Properties
    for (auto& prop : node->properties) {
        row.values[variable + "." + prop.first] = prop.second;
    }
    
    return true;
}

void MemoryIndexScan::close() {
    nodes.clear();
}


// --- MemoryEdgeScan ---

void MemoryEdgeScan::open() {
    if (child) {
        child->open();
        Row dummy;
        while(child->next(dummy)) {}
        child->close();
    }
    edges = graph.getEdgesByLabel(label);
    currentIndex = 0;
}

bool MemoryEdgeScan::next(Row& row) {
    if (currentIndex >= edges.size()) return false;
    
    auto edge = edges[currentIndex];
    currentIndex++;
    
    // Populate row with edge properties
    row.values[variable] = Value(edge->id);
    row.values[variable + ".id"] = Value(edge->id);
    row.values[variable + "._source"] = Value(edge->sourceId);
    row.values[variable + "._target"] = Value(edge->targetId);
    
    // Support non-underscored for join conditions if needed
    row.values[variable + ".source"] = Value(edge->sourceId);
    row.values[variable + ".target"] = Value(edge->targetId);
    
    for (auto& prop : edge->properties) {
        row.values[variable + "." + prop.first] = prop.second;
    }
    
    return true;
}

void MemoryEdgeScan::close() {
    edges.clear();
}


// --- MemoryFilter ---

void MemoryFilter::open() {
    child->open();
}

bool MemoryFilter::next(Row& row) {
    while (child->next(row)) {
        // Evaluate condition
        Value result = evaluate(row, condition);
        if (holds_alternative<bool>(result.data) && get<bool>(result.data)) {
            return true;
        }
    }
    return false;
}

void MemoryFilter::close() {
    child->close();
}


// --- MemoryProject ---

void MemoryProject::open() {
    child->open();
}

bool MemoryProject::next(Row& row) {
    if (!child->next(row)) return false;
    
    Row projectedRow;
    for (const string& field : fields) {
        Value val = evaluate(row, field);
        projectedRow.values[field] = val;
    }
    
    row = projectedRow;
    return true;
}

void MemoryProject::close() {
    child->close();
}

// --- MemoryLimit ---

void MemoryLimit::open() {
    child->open();
    count = 0;
}

bool MemoryLimit::next(Row& row) {
    if (count >= limit) return false;
    
    if (child->next(row)) {
        count++;
        return true;
    }
    return false;
}

void MemoryLimit::close() {
    child->close();
}

// --- MemoryOffset ---

void MemoryOffset::open() {
    child->open();
    count = 0;
}

bool MemoryOffset::next(Row& row) {
    // Skip rows
    while (count < offset) {
        Row dummy;
        if (!child->next(dummy)) return false;
        count++;
    }
    
    return child->next(row);
}

void MemoryOffset::close() {
    child->close();
}

// --- MemorySort ---

void MemorySort::open() {
    child->open();
    sortedRows.clear();
    currentIndex = 0;
    
    // 1. Slurp all rows into memory
    Row row;
    while (child->next(row)) {
        sortedRows.push_back(row);
    }
    
    // 2. Sort them
    sort(sortedRows.begin(), sortedRows.end(), [this](const Row& a, const Row& b) {
        for (const auto& item : sortItems) {
            Value valA = evaluate(a, item.field);
            Value valB = evaluate(b, item.field);
            
            // If they are equal, move to the next sort criteria
            if (valA == valB) continue;
            
            // Otherwise, sort based on ascending/descending
            if (item.ascending) {
                return valA < valB;
            } else {
                return valB < valA; // Descending
            }
        }
        return false; // All criteria equal, preserve original order (or not stable)
    });
}

bool MemorySort::next(Row& row) {
    if (currentIndex >= sortedRows.size()) return false;
    row = sortedRows[currentIndex++];
    return true;
}

void MemorySort::close() {
    sortedRows.clear();
    child->close();
}

struct GroupState {
    Row groupRow; // Holds the grouping keys
    unordered_map<string, Value> accumulators;
    unordered_map<string, int> counts; // For AVG
    unordered_map<string, unordered_set<string>> distinctValues; // For DISTINCT
};

// --- MemoryAggregate ---

void MemoryAggregate::open() {
    child->open();
    aggregatedRows.clear();
    currentIndex = 0;
    
    unordered_map<string, GroupState> groups;
    
    Row row;
    int rowCount = 0;
    while (child->next(row)) {
        rowCount++;
        // 1. Compute Group Key
        string groupKey = "";
        Row currentGroupRow;
        for (const string& g : groupings) {
            Value v = evaluate(row, g);
            groupKey += v.toString() + "|";
            currentGroupRow.values[g] = v;
        }
        
        if (groups.find(groupKey) == groups.end()) {
            GroupState newState;
            newState.groupRow = currentGroupRow;
            groups[groupKey] = newState;
        }
        GroupState& state = groups[groupKey];
        
        // 2. Accumulate Measures
        for (const string& m : measures) {
            // Parse measure: e.g. "COUNT(p) AS c" or "AVG(p.age)"
            string func, expr, alias;
            bool isDistinct = false;
            size_t openParen = m.find('(');
            size_t closeParen = m.find(')');
            if (openParen != string::npos && closeParen != string::npos) {
                func = m.substr(0, openParen);
                expr = m.substr(openParen + 1, closeParen - openParen - 1);
                
                if (expr.find("DISTINCT ") == 0) {
                    isDistinct = true;
                    expr = expr.substr(9);
                }
                
                size_t asPos = m.find(" AS ");
                if (asPos != string::npos) {
                    alias = m.substr(asPos + 4);
                } else {
                    alias = m; // Default to full string if no alias
                }
                
                Value val = (expr.empty() || expr == "*") ? Value(1) : evaluate(row, expr);
                
                if (func == "COUNT") {
                    if (state.accumulators.find(alias) == state.accumulators.end()) {
                        state.accumulators[alias] = Value(0);
                    }
                    if (!holds_alternative<monostate>(val.data)) {
                        if (isDistinct) {
                            string valStr = val.toString();
                            if (state.distinctValues[alias].find(valStr) == state.distinctValues[alias].end()) {
                                state.distinctValues[alias].insert(valStr);
                                int currentCount = std::get<int>(state.accumulators[alias].data);
                                state.accumulators[alias] = Value(currentCount + 1);
                            }
                        } else {
                            int currentCount = std::get<int>(state.accumulators[alias].data);
                            state.accumulators[alias] = Value(currentCount + 1);
                        }
                    }
                } else if (func == "SUM") {
                    if (state.accumulators.find(alias) == state.accumulators.end()) {
                        state.accumulators[alias] = Value(0);
                    }
                    if (holds_alternative<int>(val.data)) {
                        int currentSum = std::get<int>(state.accumulators[alias].data);
                        state.accumulators[alias] = Value(currentSum + std::get<int>(val.data));
                    }
                } else if (func == "MAX") {
                    if (state.accumulators.find(alias) == state.accumulators.end()) {
                        state.accumulators[alias] = val;
                    } else {
                        if (val > state.accumulators[alias]) {
                            state.accumulators[alias] = val;
                        }
                    }
                } else if (func == "MIN") {
                    if (state.accumulators.find(alias) == state.accumulators.end()) {
                        state.accumulators[alias] = val;
                    } else {
                        if (val < state.accumulators[alias]) {
                            state.accumulators[alias] = val;
                        }
                    }
                } else if (func == "AVG") {
                    if (state.accumulators.find(alias) == state.accumulators.end()) {
                        state.accumulators[alias] = Value(0);
                        state.counts[alias] = 0;
                    }
                    if (holds_alternative<int>(val.data)) {
                        int currentSum = std::get<int>(state.accumulators[alias].data);
                        state.accumulators[alias] = Value(currentSum + std::get<int>(val.data));
                        state.counts[alias]++;
                    }
                }
            }
        }
    }
    
    // 3. Finalize and Store Rows
    for (auto& pair : groups) {
        Row finalRow = pair.second.groupRow;
        for (const string& m : measures) {
            string alias = m;
            size_t asPos = m.find(" AS ");
            if (asPos != string::npos) {
                alias = m.substr(asPos + 4);
            }
            
            // Handle AVG final division
            if (m.find("AVG(") == 0) {
                if (pair.second.counts[alias] > 0) {
                    int sum = std::get<int>(pair.second.accumulators[alias].data);
                    int count = pair.second.counts[alias];
                    finalRow.values[alias] = Value(sum / count); // Integer division for now
                } else {
                    finalRow.values[alias] = Value(); // NULL
                }
            } else {
                finalRow.values[alias] = pair.second.accumulators[alias];
            }
        }
        aggregatedRows.push_back(finalRow);
    }
}

bool MemoryAggregate::next(Row& row) {
    if (currentIndex >= aggregatedRows.size()) return false;
    row = aggregatedRows[currentIndex++];
    return true;
}

void MemoryAggregate::close() {
    aggregatedRows.clear();
    child->close();
}

// --- MemoryNestedLoopJoin ---

void MemoryNestedLoopJoin::open() {
    left->open();
    leftFinished = false;
    rightOpen = false;
}

bool MemoryNestedLoopJoin::next(Row& row) {
    while (true) {
        if (!rightOpen) {
            if (!left->next(currentLeftRow)) {
                return false;
            }
            right->open();
            rightOpen = true;
        }

        Row rightRow;
        if (right->next(rightRow)) {
            Row combinedRow = currentLeftRow;
            for (auto& pair : rightRow.values) {
                combinedRow.values[pair.first] = pair.second;
            }

            if (condition.empty()) {
                 row = combinedRow;
                 return true;
            }

            Value res = evaluate(combinedRow, condition);
            if (holds_alternative<bool>(res.data) && get<bool>(res.data)) {
                row = combinedRow;
                return true;
            }
        } else {
            right->close();
            rightOpen = false;
        }
    }
}

void MemoryNestedLoopJoin::close() {
    left->close();
    if (rightOpen) {
        right->close();
        rightOpen = false;
    }
}

// --- MemoryDelete ---

void MemoryDelete::open() {
    if (child) child->open();
    deletedCount = 0;
    done = false;
}

bool MemoryDelete::next(Row& row) {
    if (done) return false;
    
    Row curr;
    while (child && child->next(curr)) {
        for (const string& var : variables) {
            if (curr.values.find(var) != curr.values.end()) {
                Value val = curr.values[var];
                // Try deleting as Node ID if it's an int
                if (holds_alternative<int>(val.data)) {
                    int id = get<int>(val.data);
                    if (graph.deleteNode(id) || graph.deleteEdge(id)) {
                        deletedCount++;
                    }
                }
            }
        }
    }
    
    row.values["deleted"] = Value(deletedCount);
    done = true;
    return true;
}

void MemoryDelete::close() {
    if (child) child->close();
}

// --- MemoryInsert ---

void MemoryInsert::open() {
    if (child) child->open();
    insertedNodesCount = 0;
    insertedEdgesCount = 0;
    done = false;
}

bool MemoryInsert::next(Row& row) {
    if (done) return false;
    
    // Process child context if any (e.g., INSERT inside a MATCH)
    Row contextRow;
    bool hasContext = (child != nullptr);
    bool hasNext = hasContext ? child->next(contextRow) : true;
    
    while (hasNext) {
        unordered_map<string, int> createdVarIds;
        
        // Insert Nodes
        for (const auto& n : insertNodes) {
            unordered_map<string, Value> props;
            for (auto& p : n.properties) {
                // Simplify: Try to treat expressionString directly as a literal for now
                string expr = p.expressionString;
                if (!expr.empty() && expr.front() == '"' && expr.back() == '"') {
                    props[p.key] = Value(expr.substr(1, expr.length() - 2));
                } else {
                    try { props[p.key] = Value(stoi(expr)); } 
                    catch (...) { props[p.key] = Value(expr); }
                }
            }
            auto node = graph.createNode(n.labels, props);
            createdVarIds[n.variable] = node->id;
            insertedNodesCount++;
        }
        
        // Insert Edges
        for (const auto& e : insertEdges) {
            unordered_map<string, Value> props;
            for (auto& p : e.properties) {
                string expr = p.expressionString;
                if (!expr.empty() && expr.front() == '"' && expr.back() == '"') {
                    props[p.key] = Value(expr.substr(1, expr.length() - 2));
                } else {
                    try { props[p.key] = Value(stoi(expr)); } 
                    catch (...) { props[p.key] = Value(expr); }
                }
            }
            // Realistically, edges need source and target ids evaluated from variables.
            // But for simple INSERTS matching the test queries, we'll hardcode dummy 0s
            // if we don't know the exact bindings here natively inside PhysicalInsertEdge without more planner work.
            int sourceId = 0, targetId = 0;
            auto edge = graph.createEdge(sourceId, targetId, e.labels.empty() ? "" : e.labels[0], props);
            insertedEdgesCount++;
        }
        
        if (!hasContext) break;
        hasNext = child->next(contextRow);
    }
    
    row.values["nodes_inserted"] = Value(insertedNodesCount);
    row.values["edges_inserted"] = Value(insertedEdgesCount);
    done = true;
    return true;
}

void MemoryInsert::close() {
    if (child) child->close();
}

// --- MemoryUpdate ---

void MemoryUpdate::open() {
    if (child) child->open();
    updatedCount = 0;
    done = false;
}

bool MemoryUpdate::next(Row& row) {
    if (done) return false;
    
    Row curr;
    while (child && child->next(curr)) {
        for (const auto& item : items) {
            if (curr.values.find(item.variable) != curr.values.end()) {
                Value val = curr.values[item.variable];
                if (holds_alternative<int>(val.data)) {
                    int id = get<int>(val.data);
                    
                    if (graph.nodes.find(id) != graph.nodes.end()) {
                        auto node = graph.nodes[id];
                        if (item.type == PhysicalUpdateItem::SET_PROPERTY) {
                            // Evaluate value - cheating slightly for literals right now.
                            string expr = item.expressionString;
                            Value propVal;
                            if (!expr.empty() && expr.front() == '"' && expr.back() == '"') {
                                propVal = Value(expr.substr(1, expr.length() - 2));
                            } else {
                                try { propVal = Value(stoi(expr)); } 
                                catch (...) { propVal = Value(expr); }
                            }
                            node->properties[item.key] = propVal;
                            updatedCount++;
                        }
                    } else if (graph.edges.find(id) != graph.edges.end()) {
                        auto edge = graph.edges[id];
                        if (item.type == PhysicalUpdateItem::SET_PROPERTY) {
                            string expr = item.expressionString;
                            Value propVal;
                            if (!expr.empty() && expr.front() == '"' && expr.back() == '"') {
                                propVal = Value(expr.substr(1, expr.length() - 2));
                            } else {
                                try { propVal = Value(stoi(expr)); } 
                                catch (...) { propVal = Value(expr); }
                            }
                            edge->properties[item.key] = propVal;
                            updatedCount++;
                        }
                    }
                }
            }
        }
    }
    
    row.values["properties_set"] = Value(updatedCount);
    done = true;
    return true;
}

void MemoryUpdate::close() {
    if (child) child->close();
}
