#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "GQLLexer.h"
#include "GQLParser.h"
#include "ASTBuilder.h"
#include "ASTPrinter.h"
#include "LogicalPlanBuilder.h"
#include "LogicalPlanPrinter.h"
#include "PhysicalPlanner.h"
#include "Value.h"
#include "Graph.h"
#include "PhysicalOperator.h"
#include "ExecutionBuilder.h"

using namespace antlr4;
using namespace std;

// Helper to escape strings for JSON
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
        else if (c >= 0 && c <= 0x1f) {
            // control characters (ignore or hex likely not needed for this simple case)
        } else {
            res += c;
        }
    }
    return res;
}

// Helper to escape strings for display
string escapeText(const string& s) {
    string res;
    for (char c : s) {
        if (c == '\n') res += "\\n";
        else if (c == '\r') res += "\\r";
        else if (c == '\t') res += "\\t";
        else res += c;
    }
    return res;
}

// Helper to print the parse tree in ASCII style
void printTree(antlr4::tree::ParseTree* t, antlr4::Parser* recognizer, string prefix = "", bool isLast = true) {
    // 1. Determine the name of the current node
    string nodeName;
    bool isRule = (dynamic_cast<antlr4::RuleContext*>(t) != nullptr);
    
    if (isRule) {
        antlr4::RuleContext* ctx = dynamic_cast<antlr4::RuleContext*>(t);
        size_t ruleIndex = ctx->getRuleIndex();
        const vector<string>& ruleNames = recognizer->getRuleNames();
        nodeName = (ruleIndex < ruleNames.size()) ? ruleNames[ruleIndex] : "UnknownRule";
    } else {
        string text = t->getText();
        if (text == "<EOF>") text = "EOF";
        nodeName = "'" + escapeText(text) + "'";
    }

    // 2. Print current node
    cout << prefix;
    cout << (isLast ? "└── " : "├── ");
    cout << nodeName << endl;

    // 3. Prepare prefix for children
    string childPrefix = prefix + (isLast ? "    " : "│   ");

    for (size_t i = 0; i < t->children.size(); i++) {
        printTree(t->children[i], recognizer, childPrefix, i == t->children.size() - 1);
    }
}

void populateGraph(Graph& graph) {
    auto cat1 = graph.createNode({"Categories"}, {{"category_id", Value(1)}, {"category_name", Value("Electronics")}});
    auto cat2 = graph.createNode({"Categories"}, {{"category_id", Value(2)}, {"category_name", Value("Appliances")}});
    auto cat3 = graph.createNode({"Categories"}, {{"category_id", Value(3)}, {"category_name", Value("Books")}});

    auto pr1 = graph.createNode({"Products"}, {{"product_id", Value(1)}, {"category_id", Value(1)}, {"name", Value("Smartphone")}, {"price", Value(500)}});
    auto pr2 = graph.createNode({"Products"}, {{"product_id", Value(2)}, {"category_id", Value(1)}, {"name", Value("Laptop")}, {"price", Value(1200)}});
    auto pr3 = graph.createNode({"Products"}, {{"product_id", Value(3)}, {"category_id", Value(2)}, {"name", Value("Microwave")}, {"price", Value(150)}});
    auto pr4 = graph.createNode({"Products"}, {{"product_id", Value(4)}, {"category_id", Value(3)}, {"name", Value("Novel")}, {"price", Value(20)}});

    auto u1 = graph.createNode({"Users"}, {{"user_id", Value(101)}, {"name", Value("Vaibhav")}, {"country", Value("India")}});
    auto u2 = graph.createNode({"Users"}, {{"user_id", Value(102)}, {"name", Value("John")}, {"country", Value("USA")}});
    auto u3 = graph.createNode({"Users"}, {{"user_id", Value(103)}, {"name", Value("Max")}, {"country", Value("Germany")}});
    auto u4 = graph.createNode({"Users"}, {{"user_id", Value(104)}, {"name", Value("Yuki")}, {"country", Value("Japan")}});

    auto o1 = graph.createNode({"Orders"}, {{"order_id", Value(1001)}, {"user_id", Value(101)}, {"product_id", Value(2)}, {"amount", Value(1200)}, {"order_date", Value("2023-05-01")}, {"status", Value("DELIVERED")}});
    auto o2 = graph.createNode({"Orders"}, {{"order_id", Value(1002)}, {"user_id", Value(101)}, {"product_id", Value(1)}, {"amount", Value(500)}, {"order_date", Value("2023-01-10")}, {"status", Value("DELIVERED")}});
    auto o3 = graph.createNode({"Orders"}, {{"order_id", Value(1003)}, {"user_id", Value(101)}, {"product_id", Value(3)}, {"amount", Value(150)}, {"order_date", Value("2023-02-15")}, {"status", Value("DELIVERED")}});
    auto o4 = graph.createNode({"Orders"}, {{"order_id", Value(1004)}, {"user_id", Value(101)}, {"product_id", Value(1)}, {"amount", Value(500)}, {"order_date", Value("2023-03-20")}, {"status", Value("DELIVERED")}});
    auto o5 = graph.createNode({"Orders"}, {{"order_id", Value(1005)}, {"user_id", Value(101)}, {"product_id", Value(1)}, {"amount", Value(500)}, {"order_date", Value("2023-04-25")}, {"status", Value("DELIVERED")}});
    auto o6 = graph.createNode({"Orders"}, {{"order_id", Value(1006)}, {"user_id", Value(101)}, {"product_id", Value(1)}, {"amount", Value(500)}, {"order_date", Value("2023-05-30")}, {"status", Value("DELIVERED")}});

    if (u1 && o1) graph.createEdge(u1->id, o1->id, "PLACED", {});
    if (o1 && pr2) graph.createEdge(o1->id, pr2->id, "CONTAINS", {});
    if (pr2 && cat1) graph.createEdge(pr2->id, cat1->id, "BELONGS_TO", {});

    if (u1 && o2) graph.createEdge(u1->id, o2->id, "PLACED", {});
    if (o2 && pr1) graph.createEdge(o2->id, pr1->id, "CONTAINS", {});
    if (pr1 && cat1) graph.createEdge(pr1->id, cat1->id, "BELONGS_TO", {});

    if (u1 && o3) graph.createEdge(u1->id, o3->id, "PLACED", {});
    if (o3 && pr3) graph.createEdge(o3->id, pr3->id, "CONTAINS", {});
    if (pr3 && cat2) graph.createEdge(pr3->id, cat2->id, "BELONGS_TO", {});

    if (u1 && o4) graph.createEdge(u1->id, o4->id, "PLACED", {});
    if (o4 && pr1) graph.createEdge(o4->id, pr1->id, "CONTAINS", {});

    if (u1 && o5) graph.createEdge(u1->id, o5->id, "PLACED", {});
    if (o5 && pr1) graph.createEdge(o5->id, pr1->id, "CONTAINS", {});

    if (u1 && o6) graph.createEdge(u1->id, o6->id, "PLACED", {});
    if (o6 && pr1) graph.createEdge(o6->id, pr1->id, "CONTAINS", {});
}

void dumpGraphJSON(Graph& graph) {
    cout << "{\"nodes\":[";
    bool firstNode = true;
    for (const auto& pair : graph.nodes) {
        if (!firstNode) cout << ",";
        firstNode = false;
        auto n = pair.second;
        cout << "{\"id\":\"n" << n->id << "\",\"labels\":[";
        bool fl = true;
        for (const auto& l : n->labels) { if(!fl) cout<<","; fl=false; cout << "\"" << jsonEscape(l) << "\""; }
        cout << "],\"properties\":{";
        bool fp = true;
        for (const auto& prop : n->properties) {
            if(!fp) cout<<","; fp=false;
            cout << "\"" << jsonEscape(prop.first) << "\":\"" << jsonEscape(prop.second.toString()) << "\"";
        }
        cout << "}}";
    }
    cout << "],\"links\":[";
    bool firstEdge = true;
    for (const auto& pair : graph.edges) {
        if (!firstEdge) cout << ",";
        firstEdge = false;
        auto e = pair.second;
        cout << "{\"id\":\"e" << e->id << "\",\"source\":\"n" << e->sourceId << "\",\"target\":\"n" << e->targetId 
             << "\",\"label\":\"" << jsonEscape(e->label) << "\"}";
    }
    cout << "]}" << endl;
}

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input-file> OR --dump" << endl;
        return 1;
    }

    if (string(argv[1]) == "--dump") {
        Graph graph;
        populateGraph(graph);
        dumpGraphJSON(graph);
        return 0;
    }

    ifstream stream(argv[1]);
    if (!stream.is_open()) {
        cerr << "Could not open file: " << argv[1] << endl;
        return 1;
    }

    ANTLRInputStream input(stream);
    GQLLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    GQLParser parser(&tokens);

    // ✅ Correct type here
    GQLParser::GqlProgramContext* tree = parser.gqlProgram();

    // FAIL FAST: Check for syntax errors
    if (parser.getNumberOfSyntaxErrors() > 0) {
        cerr << "\n❌ Query failed due to " << parser.getNumberOfSyntaxErrors() << " syntax error(s)." << endl;
        return 1;
    }

    // ✅ Build AST correctly
    ASTBuilder builder;
    auto ast = builder.build(tree);

    cout << "\n==================== PARSE TREE ====================\n";
    if (tree) {
        printTree(tree, &parser);
    }
    cout << endl; // Extra newline at end 

    cout << "\n==================== AST ====================\n";
    if (ast) {
        ASTPrinter printer;
        ast->accept(&printer);  // ✅ Correct visitor pattern
    } else {
        cout << "(No AST generated)\n";
    }

    // ✅ Build Logical Plan from AST
    cout << "\n==================== LOGICAL PLAN ====================\n";
    if (ast) {
        LogicalPlanBuilder planBuilder;
        auto logicalPlan = planBuilder.build(ast.get());
        
        if (logicalPlan) {
            LogicalPlanPrinter planPrinter;
            planPrinter.print(logicalPlan.get());

            // ✅ Build Physical Plan from Logical Plan
            cout << "\n==================== PHYSICAL PLAN ====================\n";
            PhysicalPlanner phyPlanner;
            auto phyPlan = phyPlanner.build(logicalPlan.get());
            if (phyPlan) {
                phyPlan->print();

                // ✅ EXECUTION ENGINE
                cout << "\n==================== EXECUTION RESULTS ====================\n";
                // 1. Init Graph
                Graph graph;
                populateGraph(graph);


                // 2. Build Execution Tree
                // ExecutionBuilder execBuilder(graph);
                ExecutionBuilder execBuilder(graph);
                unique_ptr<PhysicalOperator> rootOp = execBuilder.build(phyPlan.get());

                // 3. Run Pipeline
                if (rootOp) {
                    rootOp->open();
                    
                    Row row;
                    int rowCount = 0;
                    while (rootOp->next(row)) {
                        rowCount++;
                        cout << "Row " << rowCount << ": { ";
                        bool first = true;
                        for (const auto& pair : row.values) {
                            if (!first) cout << ", ";
                            cout << pair.first << ": " << pair.second.toString();
                            first = false;
                        }
                        cout << " }" << endl;
                    }
                    
                    rootOp->close();
                } else {
                    cout << "Failed to build execution tree." << endl;
                }

            } else {
                cout << "(No physical plan generated)\n";
            }

        } else {
            cout << "(No logical plan generated)\n";
        }
    }

    return 0;
}

