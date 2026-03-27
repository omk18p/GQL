#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <map>
#include "Value.h"

using namespace std;

struct Node {
    int id;
    vector<string> labels;
    unordered_map<string, Value> properties;

    bool hasLabel(const string& label) const {
        for (const auto& l : labels) {
            if (l == label) return true;
        }
        return false;
    }
};

struct Edge {
    int id;
    int sourceId;
    int targetId;
    string sourceLabel; // Track source label for output
    string targetLabel; // Track target label for output
    string label;
    unordered_map<string, Value> properties;
};

class Graph {
public:
    unordered_map<int, shared_ptr<Node>> nodes;
    unordered_map<int, shared_ptr<Edge>> edges;
    int nextNodeId = 1;
    int nextEdgeId = 1;

    // Indexes: Label -> [NodeId]
    unordered_map<string, vector<int>> labelIndex;
    unordered_map<string, vector<int>> edgeLabelIndex;

    // Adjacency: sourceId -> [EdgeId]
    unordered_map<int, vector<int>> outEdges;

    // Uniqueness Constraints: Label -> Unique Property Key
    unordered_map<string, string> uniquePropertyKeys = {
        {"Users", "user_id"},
        {"Products", "product_id"},
        {"Orders", "order_id"},
        {"Categories", "category_id"}
    };

    // Uniqueness Index: Label -> (Unique Value -> NodeId)
    unordered_map<string, map<Value, int>> uniqueIndex;

    bool validateNode(const vector<string>& labels, const unordered_map<string, Value>& properties) {
        if (labels.empty()) {
            cerr << "[Validation Error] Node must have at least one label." << endl;
            return false;
        }
        if (properties.empty()) {
            cerr << "[Validation Error] Node must have properties (empty nodes not allowed)." << endl;
            return false;
        }

        for (const string& label : labels) {
            if (label == "Users") {
                if (!properties.count("user_id") || !properties.count("name") || !properties.count("country")) {
                    cerr << "[Schema Error] Users node missing required fields (user_id, name, country)." << endl;
                    return false;
                }
            } else if (label == "Products") {
                if (!properties.count("product_id") || !properties.count("name") || !properties.count("price") || !properties.count("category_id")) {
                    cerr << "[Schema Error] Products node missing required fields (product_id, name, price, category_id)." << endl;
                    return false;
                }
            } else if (label == "Orders") {
                if (!properties.count("order_id") || !properties.count("user_id") || !properties.count("product_id") || !properties.count("amount")) {
                    cerr << "[Schema Error] Orders node missing required fields (order_id, user_id, product_id, amount)." << endl;
                    return false;
                }
            } else if (label == "Categories") {
                if (!properties.count("category_id") || !properties.count("category_name")) {
                    cerr << "[Schema Error] Categories node missing required fields (category_id, category_name)." << endl;
                    return false;
                }
            } else if (label == "Node") {
                cerr << "[Validation Error] Generic 'Node' label is not allowed." << endl;
                return false;
            }
        }
        return true;
    }

    void addNode(shared_ptr<Node> node) {
        nodes[node->id] = node;
        for (const auto& label : node->labels) {
            labelIndex[label].push_back(node->id);
            
            // Index the unique property if it exists
            if (uniquePropertyKeys.count(label)) {
                string uniqueKey = uniquePropertyKeys[label];
                if (node->properties.count(uniqueKey)) {
                    uniqueIndex[label][node->properties[uniqueKey]] = node->id;
                }
            }
        }
    }

    void addEdge(shared_ptr<Edge> edge) {
        edges[edge->id] = edge;
        edgeLabelIndex[edge->label].push_back(edge->id);
        outEdges[edge->sourceId].push_back(edge->id);
    }

    shared_ptr<Node> findNodeByUniqueKey(const string& label, const unordered_map<string, Value>& props) {
        if (!uniquePropertyKeys.count(label)) return nullptr;
        
        string uniqueKey = uniquePropertyKeys[label];
        if (!props.count(uniqueKey)) return nullptr;
        
        Value targetValue = props.at(uniqueKey);
        
        // 1. Try index first
        if (uniqueIndex.count(label) && uniqueIndex[label].count(targetValue)) {
            int id = uniqueIndex[label][targetValue];
            if (nodes.count(id)) return nodes[id];
        }
        
        // 2. Fallback to scan (should not happen often if index is maintained)
        auto candidates = getNodesByLabel(label);
        for (auto& node : candidates) {
            if (node->properties.count(uniqueKey)) {
                if (compareValues(node->properties.at(uniqueKey), targetValue)) {
                    // Update index if it was missing
                    uniqueIndex[label][targetValue] = node->id;
                    return node;
                }
            }
        }
        return nullptr;
    }

    shared_ptr<Node> createNode(vector<string> labels, unordered_map<string, Value> props) {
        if (!validateNode(labels, props)) return nullptr;
        
        // Check uniqueness before creation
        for (const string& label : labels) {
            shared_ptr<Node> existing = findNodeByUniqueKey(label, props);
            if (existing) {
                // cout << "[Graph Debug] Reusing existing node for uniqueness (label: " << label << ", id: " << existing->id << ")" << endl;
                return existing;
            }
        }

        auto node = make_shared<Node>();
        node->id = nextNodeId++;
        node->labels = labels;
        node->properties = props;
        addNode(node);
        return node;
    }

    shared_ptr<Edge> createEdge(int sourceId, int targetId, string label, unordered_map<string, Value> props) {
        auto edge = make_shared<Edge>();
        edge->id = nextEdgeId++;
        edge->sourceId = sourceId;
        edge->targetId = targetId;
        edge->label = label;
        edge->properties = props;
        
        // Track labels for output formatting
        if (nodes.count(sourceId) && !nodes[sourceId]->labels.empty()) {
            edge->sourceLabel = nodes[sourceId]->labels[0];
        } else {
            edge->sourceLabel = "Node";
        }
        
        if (nodes.count(targetId) && !nodes[targetId]->labels.empty()) {
            edge->targetLabel = nodes[targetId]->labels[0];
        } else {
            edge->targetLabel = "Node";
        }

        addEdge(edge);
        return edge;
    }

    // scans
    vector<shared_ptr<Node>> getNodesByLabel(const string& label) {
        vector<shared_ptr<Node>> result;
        if (labelIndex.find(label) != labelIndex.end()) {
            for (int id : labelIndex[label]) {
                result.push_back(nodes[id]);
            }
        }
        return result;
    }

    vector<shared_ptr<Edge>> getEdgesByLabel(const string& label) {
        vector<shared_ptr<Edge>> result;
        if (edgeLabelIndex.find(label) != edgeLabelIndex.end()) {
            for (int id : edgeLabelIndex[label]) {
                result.push_back(edges[id]);
            }
        }
        return result;
    }
    
    vector<shared_ptr<Node>> getAllNodes() {
        vector<shared_ptr<Node>> result;
        for (auto& pair : nodes) {
            result.push_back(pair.second);
        }
        return result;
    }

    vector<shared_ptr<Edge>> getAllEdges() {
        vector<shared_ptr<Edge>> result;
        for (auto& pair : edges) {
            result.push_back(pair.second);
        }
        return result;
    }
    // updates
    bool deleteNode(int id) {
        if (nodes.find(id) == nodes.end()) return false;
        
        // Remove from label index
        auto node = nodes[id];
        for (const auto& label : node->labels) {
            auto& vec = labelIndex[label];
            vec.erase(remove(vec.begin(), vec.end(), id), vec.end());
            if (vec.empty()) labelIndex.erase(label);
        }
        
        // Find all connected edges
        vector<int> edgesToDelete;
        for (const auto& pair : edges) {
            if (pair.second->sourceId == id || pair.second->targetId == id) {
                edgesToDelete.push_back(pair.first);
            }
        }
        
        // Delete connected edges
        for (int edgeId : edgesToDelete) {
            deleteEdge(edgeId);
        }
        
        nodes.erase(id);
        return true;
    }

    bool deleteEdge(int id) {
        if (edges.find(id) == edges.end()) return false;
        
        auto edge = edges[id];
        
        // Remove from label index
        auto& vec = edgeLabelIndex[edge->label];
        vec.erase(remove(vec.begin(), vec.end(), id), vec.end());
        if (vec.empty()) edgeLabelIndex.erase(edge->label);
        
        // Remove from outEdges index
        auto& outVec = outEdges[edge->sourceId];
        outVec.erase(remove(outVec.begin(), outVec.end(), id), outVec.end());
        if (outVec.empty()) outEdges.erase(edge->sourceId);
        
        edges.erase(id);
        return true;
    }

    // Persistence
    string jsonEscape(const string& s) {
        string res;
        for (char c : s) {
            if (c == '"') res += "\\\"";
            else if (c == '\\') res += "\\\\";
            else if (c == '\b') res += "\\b";
            else if (c == '\f') res += "\\f";
            else if (c == '\n') res += "\\n";
            else if (c == '\r') res += "\\r";
            else if (c == '\t') res += "\\t";
            else res += c;
        }
        return res;
    }

    string serializeValue(const Value& v) {
        if (holds_alternative<int>(v.data)) return to_string(get<int>(v.data));
        if (holds_alternative<double>(v.data)) return to_string(get<double>(v.data));
        if (holds_alternative<bool>(v.data)) return get<bool>(v.data) ? "true" : "false";
        if (holds_alternative<string>(v.data)) return "\"" + jsonEscape(get<string>(v.data)) + "\"";
        if (holds_alternative<monostate>(v.data)) return "null";
        return "\"<Object>\"";
    }

    void save(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "[Storage Error] Could not open " << filename << " for writing." << endl;
            return;
        }

        cerr << "[Storage] Saving " << nodes.size() << " nodes and " << edges.size() << " edges to " << filename << "..." << endl;
        file << "{\n";
        file << "  \"metadata\": {\n";
        file << "    \"nextNodeId\": " << nextNodeId << ",\n";
        file << "    \"nextEdgeId\": " << nextEdgeId << "\n";
        file << "  },\n";

        // Nodes
        file << "  \"nodes\": [\n";
        bool firstNode = true;
        for (const auto& pair : nodes) {
            if (!firstNode) file << ",\n";
            firstNode = false;
            auto n = pair.second;
            file << "    {\n";
            file << "      \"id\": " << n->id << ",\n";
            file << "      \"labels\": [";
            for (size_t i = 0; i < n->labels.size(); ++i) {
                file << "\"" << jsonEscape(n->labels[i]) << "\"" << (i == n->labels.size() - 1 ? "" : ", ");
            }
            file << "],\n";
            file << "      \"properties\": {\n";
            bool firstProp = true;
            for (const auto& prop : n->properties) {
                if (!firstProp) file << ",\n";
                firstProp = false;
                file << "        \"" << jsonEscape(prop.first) << "\": " << serializeValue(prop.second);
            }
            file << "\n      }\n";
            file << "    }";
        }
        file << "\n  ],\n";

        // Edges
        file << "  \"edges\": [\n";
        bool firstEdge = true;
        for (const auto& pair : edges) {
            if (!firstEdge) file << ",\n";
            firstEdge = false;
            auto e = pair.second;
            file << "    {\n";
            file << "      \"id\": " << e->id << ",\n";
            file << "      \"sourceId\": " << e->sourceId << ",\n";
            file << "      \"targetId\": " << e->targetId << ",\n";
            file << "      \"label\": \"" << jsonEscape(e->label) << "\",\n";
            file << "      \"properties\": {\n";
            bool firstProp = true;
            for (const auto& prop : e->properties) {
                if (!firstProp) file << ",\n";
                firstProp = false;
                file << "        \"" << jsonEscape(prop.first) << "\": " << serializeValue(prop.second);
            }
            file << "\n      }\n";
            file << "    }";
        }
        file << "\n  ]\n";
        file << "}\n";
    }

    // JSON Parsing primitives for load()
    struct Token {
        enum Type { OBJ_OPEN, OBJ_CLOSE, ARR_OPEN, ARR_CLOSE, COLON, COMMA, STRING, NUMBER, BOOL, NULL_VAL, EOF_TOK };
        Type type;
        string value;
    };

    vector<Token> tokenize(const string& content) {
        vector<Token> tokens;
        size_t i = 0;
        while (i < content.size()) {
            char c = content[i];
            if (isspace(c)) { i++; continue; }
            if (c == '{') tokens.push_back({Token::OBJ_OPEN, "{"});
            else if (c == '}') tokens.push_back({Token::OBJ_CLOSE, "}"});
            else if (c == '[') tokens.push_back({Token::ARR_OPEN, "["});
            else if (c == ']') tokens.push_back({Token::ARR_CLOSE, "]"});
            else if (c == ':') tokens.push_back({Token::COLON, ":"});
            else if (c == ',') tokens.push_back({Token::COMMA, ","});
            else if (c == '"') {
                string s; i++;
                while (i < content.size() && content[i] != '"') {
                    if (content[i] == '\\' && i+1 < content.size()) {
                        i++;
                        if (content[i] == 'n') s += '\n';
                        else if (content[i] == '"') s += '"';
                        else if (content[i] == '\\') s += '\\';
                        else s += content[i];
                    } else s += content[i];
                    i++;
                }
                tokens.push_back({Token::STRING, s});
            } else if (isdigit(c) || c == '-') {
                string n;
                while (i < content.size() && (isdigit(content[i]) || content[i] == '.' || content[i] == '-' || content[i] == 'e' || content[i] == 'E')) {
                    n += content[i]; i++;
                }
                tokens.push_back({Token::NUMBER, n}); i--;
            } else if (content.substr(i, 4) == "true") { tokens.push_back({Token::BOOL, "true"}); i += 3; }
            else if (content.substr(i, 5) == "false") { tokens.push_back({Token::BOOL, "false"}); i += 4; }
            else if (content.substr(i, 4) == "null") { tokens.push_back({Token::NULL_VAL, "null"}); i += 3; }
            i++;
        }
        tokens.push_back({Token::EOF_TOK, ""});
        return tokens;
    }

    void load(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) return;

        stringstream buffer;
        buffer << file.rdbuf();
        string content = buffer.str();
        vector<Token> tokens = tokenize(content);
        size_t pos = 0;
        cerr << "[Storage] Tokenized file: " << tokens.size() << " tokens found." << endl;

        // Reset Graph
        nodes.clear();
        edges.clear();
        labelIndex.clear();
        edgeLabelIndex.clear();
        outEdges.clear();

        auto expect = [&](Token::Type t) {
            if (pos < tokens.size() && tokens[pos].type == t) {
                pos++; return true;
            }
            return false;
        };

        auto skipComma = [&]() {
            if (pos < tokens.size() && tokens[pos].type == Token::COMMA) {
                pos++;
            }
        };

        if (!expect(Token::OBJ_OPEN)) return;

        while (pos < tokens.size() && tokens[pos].type != Token::OBJ_CLOSE) {
            if (tokens[pos].type == Token::STRING) {
                string key = tokens[pos].value; pos++;
                expect(Token::COLON);
                if (key == "metadata") {
                    if (expect(Token::OBJ_OPEN)) {
                        while (pos < tokens.size() && tokens[pos].type != Token::OBJ_CLOSE) {
                            string metaKey = tokens[pos].value;
                            expect(Token::STRING); expect(Token::COLON);
                            if (metaKey == "nextNodeId") {
                                try { nextNodeId = stoi(tokens[pos].value); } catch(...) {}
                                pos++;
                            } else if (metaKey == "nextEdgeId") {
                                try { nextEdgeId = stoi(tokens[pos].value); } catch(...) {}
                                pos++;
                            } else {
                                pos++;
                            }
                            skipComma();
                        }
                        expect(Token::OBJ_CLOSE);
                    }
                } else if (key == "nodes") {
                    if (expect(Token::ARR_OPEN)) {
                        while (pos < tokens.size() && tokens[pos].type != Token::ARR_CLOSE) {
                            if (expect(Token::OBJ_OPEN)) {
                                auto node = make_shared<Node>();
                                while (pos < tokens.size() && tokens[pos].type != Token::OBJ_CLOSE) {
                                    string nKey = tokens[pos].value;
                                    expect(Token::STRING); expect(Token::COLON);
                                    if (nKey == "id") {
                                        try { node->id = stoi(tokens[pos].value); } catch(...) {}
                                        pos++;
                                    } else if (nKey == "labels") {
                                        if (expect(Token::ARR_OPEN)) {
                                            while (pos < tokens.size() && tokens[pos].type != Token::ARR_CLOSE) {
                                                if (tokens[pos].type == Token::STRING) {
                                                    node->labels.push_back(tokens[pos].value);
                                                    pos++;
                                                }
                                                skipComma();
                                            }
                                            expect(Token::ARR_CLOSE);
                                        }
                                    } else if (nKey == "properties") {
                                        if (expect(Token::OBJ_OPEN)) {
                                            while (pos < tokens.size() && tokens[pos].type != Token::OBJ_CLOSE) {
                                                string pKey = tokens[pos].value;
                                                expect(Token::STRING); expect(Token::COLON);
                                                if (tokens[pos].type == Token::NUMBER) {
                                                    try {
                                                        if (tokens[pos].value.find('.') != string::npos) node->properties[pKey] = Value(stod(tokens[pos].value));
                                                        else node->properties[pKey] = Value(stoi(tokens[pos].value));
                                                    } catch(...) {}
                                                } else if (tokens[pos].type == Token::STRING) {
                                                    node->properties[pKey] = Value(tokens[pos].value);
                                                } else if (tokens[pos].type == Token::BOOL) {
                                                    node->properties[pKey] = Value(tokens[pos].value == "true");
                                                }
                                                pos++;
                                                skipComma();
                                            }
                                            expect(Token::OBJ_CLOSE);
                                        }
                                    } else {
                                        pos++;
                                    }
                                    skipComma();
                                }
                                if (validateNode(node->labels, node->properties)) {
                                    addNode(node);
                                } else {
                                    cerr << "[Storage Warning] Skipping invalid node id " << node->id << " during load." << endl;
                                }
                                expect(Token::OBJ_CLOSE);
                            }
                            skipComma();
                        }
                        expect(Token::ARR_CLOSE);
                    }
                } else if (key == "edges") {
                    if (expect(Token::ARR_OPEN)) {
                        while (pos < tokens.size() && tokens[pos].type != Token::ARR_CLOSE) {
                            if (expect(Token::OBJ_OPEN)) {
                                auto edge = make_shared<Edge>();
                                while (pos < tokens.size() && tokens[pos].type != Token::OBJ_CLOSE) {
                                    string eKey = tokens[pos].value;
                                    expect(Token::STRING); expect(Token::COLON);
                                    if (eKey == "id") {
                                        try { edge->id = stoi(tokens[pos].value); } catch(...) {}
                                        pos++;
                                    } else if (eKey == "sourceId") {
                                        try { edge->sourceId = stoi(tokens[pos].value); } catch(...) {}
                                        pos++;
                                    } else if (eKey == "targetId") {
                                        try { edge->targetId = stoi(tokens[pos].value); } catch(...) {}
                                        pos++;
                                    } else if (eKey == "label") {
                                        edge->label = tokens[pos].value;
                                        pos++;
                                    } else if (eKey == "properties") {
                                        if (expect(Token::OBJ_OPEN)) {
                                            while (pos < tokens.size() && tokens[pos].type != Token::OBJ_CLOSE) {
                                                string pKey = tokens[pos].value;
                                                expect(Token::STRING); expect(Token::COLON);
                                                if (tokens[pos].type == Token::NUMBER) {
                                                    try {
                                                        if (tokens[pos].value.find('.') != string::npos) edge->properties[pKey] = Value(stod(tokens[pos].value));
                                                        else edge->properties[pKey] = Value(stoi(tokens[pos].value));
                                                    } catch(...) {}
                                                } else if (tokens[pos].type == Token::STRING) {
                                                    edge->properties[pKey] = Value(tokens[pos].value);
                                                } else if (tokens[pos].type == Token::BOOL) {
                                                    edge->properties[pKey] = Value(tokens[pos].value == "true");
                                                }
                                                pos++;
                                                skipComma();
                                            }
                                            expect(Token::OBJ_CLOSE);
                                        }
                                    } else {
                                        pos++;
                                    }
                                    skipComma();
                                }
                                // Re-track source/target labels for display
                                if (nodes.count(edge->sourceId) && !nodes[edge->sourceId]->labels.empty()) edge->sourceLabel = nodes[edge->sourceId]->labels[0];
                                else edge->sourceLabel = "Node";
                                if (nodes.count(edge->targetId) && !nodes[edge->targetId]->labels.empty()) edge->targetLabel = nodes[edge->targetId]->labels[0];
                                else edge->targetLabel = "Node";
                                
                                addEdge(edge);
                                expect(Token::OBJ_CLOSE);
                            }
                            skipComma();
                        }
                        expect(Token::ARR_CLOSE);
                    }
                }
            }
            expect(Token::COMMA);
        }
    }

    void cleanupInvalidNodes() {
        vector<int> toDelete;
        for (auto& pair : nodes) {
            if (!validateNode(pair.second->labels, pair.second->properties)) {
                toDelete.push_back(pair.first);
            }
        }
        
        if (!toDelete.empty()) {
            cerr << "[Storage] Cleaning up " << toDelete.size() << " invalid nodes..." << endl;
            for (int id : toDelete) {
                deleteNode(id);
            }
        }
    }
};
