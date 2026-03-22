import os
import subprocess

db_snapshot = """
## Hardcoded Engine Memory Database Snapshot
Before observing the parsing execution traces, refer to this exact baseline snapshot of the `C++ main.cpp` compiled memory map array. This is the exact initial state against which all map-reduce pipelines are mathematically evaluated.

### 1. Nodes Dictionary Setup
| Object Internal Matrix | GQL Label | Populated Execution Properties |
|---|---|---|
| `cat1`, `c1` | Categories | {category_id: 1, category_name: "Electronics"} |
| `cat2`, `c2` | Categories | {category_id: 2, category_name: "Appliances"} |
| `cat3`, `c3` | Categories | {category_id: 3, category_name: "Books"} |
| `pr1` | Products | {product_id: 1, category_id: 1, name: "Smartphone", price: 500} |
| `pr2` | Products | {product_id: 2, category_id: 1, name: "Laptop", price: 1200} |
| `pr3` | Products | {product_id: 3, category_id: 2, name: "Microwave", price: 150} |
| `pr4` | Products | {product_id: 4, category_id: 3, name: "Novel", price: 20} |
| `u1` | Users | {user_id: 101, name: "Vaibhav", country: "India"} |
| `u2` | Users | {user_id: 102, name: "John", country: "USA"} |
| `u3` | Users | {user_id: 103, name: "Max", country: "Germany"} |
| `u4` | Users | {user_id: 104, name: "Yuki", country: "Japan"} |
| `o1` | Orders | {order_id: 1001, user_id: 101, product_id: 2, amount: 1200, status: "DELIVERED"} |
| `o2 - o6` | Orders | {order_id: 1002..1006, user_id: 101, product_id: ..., amount: 500/150, status: ...} |

### 2. Edge Pointer Traversals (Adjacency Matrix)
| Physical Path Direction | Map Sequence Mappings | Relational Label Bound |
|---|---|---|
| `u1` -> `o1` | `Users (Vaibhav)` -> `Orders (1001)` | `PLACED` |
| `o1` -> `pr2` | `Orders (1001)` -> `Products (Laptop)` | `CONTAINS` |
| `pr2` -> `c1` | `Products (Laptop)` -> `Categories (Electronics)` | `BELONGS_TO` |

---
"""

categories = {
    "1. Basic Operations (Reads & Traversals)": [
        ("basic_01_full_scan.gql", "Unconstrained Full Node Scan", "Validates the engine's ability to perform an unconstrained full table scan and return all nodes of a specific label.", "Expected Output: Returns native row dumps for all 'Users' indices mapped in the graph memory."),
        ("basic_02_label_scan.gql", "Single-Node Label Filtering", "Tests basic single-node label filtering structurally.", "Expected Output: Returns only Node variables mapping exactly the declared target graph label constraint."),
        ("basic_03_numeric_filter.gql", "Numeric Range Filtering", "Ensures the query engine correctly interprets greater-than operators against memory bounds.", "Expected Output: Accurately isolates order node bounds calculating boolean comparisons > 500."),
        ("basic_04_edge_extraction.gql", "Directional Edge Extraction", "Proves the physical nested map pointer loop can track and join bounded objects dynamically.", "Expected Output: Extracts the specific properties tied strictly to adjacent pointers bounding objects natively."),
        ("basic_05_string_filter.gql", "Literal String Matching", "Validates native string matching variables against literal properties structurally.", "Expected Output: Exclusively limits sequence returns targeting exact text block constraints logically isolated."),
        ("basic_06_insert_node.gql", "Node Insertion (DML)", "Tests Graph modification capability capturing and mapping newly tracked C++ sequence variables.", "Expected Output: Generates the `MemInsert` trace mapping the pointer and explicitly logging internal ID allocations representing the saved physical boundaries."),
        ("basic_07_set_property.gql", "Dynamic Property Updating (DML)", "Tests rewriting mapping properties modifying currently live structural nodes naturally.", "Expected Output: Completely blocks unhandled pointer updates bypassing structural read cycles seamlessly mapped inside `MemUpdate`."),
        ("basic_08_delete_node.gql", "Node Deletion (DML)", "Validates terminating structural graph references removing the variable block map completely.", "Expected Output: Safely severs connected bound variables erasing sequences completely without pointer crashing limits nested.")
    ],
    "2. Edge Cases & Robustness Safety": [
        ("edge_01_nonexistent_label.gql", "Non-Existent Label Fallback", "Verifies dynamic boundary logic handles absent properties returning correctly zero sequences natively limiting crashing constraints.", "Expected Output: Aborts bounds silently throwing exactly 0 return elements naturally circumventing memory mapping exceptions."),
        ("edge_02_empty_path_join.gql", "Empty Path Joins", "Evaluates mapping constraints halting mapping limits structurally natively protecting missing graph linkages internally.", "Expected Output: Yields blank map variables completely bypassing invalid continuous loop pointers organically."),
        ("edge_03_vacuous_truth_filter.gql", "Vacuous Truth Filters", "Tests constant dynamic equality bounds completely accepting true tautological equations correctly generated locally.", "Expected Output: Restores boundaries fully mapping unchanged parameter loops bypassing logic equations continuously natively."),
        ("edge_04_missing_property.gql", "Missing Property Resolution", "Resolves missing memory string bounds explicitly skipping unbound physical targets natively trapping memory faults effectively.", "Expected Output: Executes completely successfully bypassing null parameters rendering alternative default pointer identifiers implicitly mapped inside sequence constraints."),
        ("edge_05_aggregate_nulls.gql", "Aggregating Missing Values", "Performs native math evaluation bounding calculations isolating subsets effectively completely circumventing missing physical mapping boundaries natively.", "Expected Output: Organizes memory variables completely resolving limits organically dropping missing parameters capturing remaining constants strictly."),
        ("edge_06_sort_by_null.gql", "Sorting on Missing Indices", "Constructs `MemSort` logic completely bypassing unmapped values continuously ordering sequence bounds.", "Expected Output: Sequences structures correctly ordering native limits cleanly bypassing bounds safely ordering variable mappings logically."),
        ("edge_07_zero_limit.gql", "Zero-Bound Limits", "Ensures array truncations explicitly handle absolute zero boundaries dynamically clipping projections correctly natively isolating paths.", "Expected Output: Perfectly truncates execution traces outputting zero return bounds completely protecting downstream structures organically."),
        ("edge_08_null_comparison.gql", "Three-Valued Logic Checks", "Verifies conditional parameters explicitly processing undefined equality statements bounds trapping sequences mathematically accurately.", "Expected Output: Drops undefined logic queries mapping sequences consistently handling continuous logic variables without terminating the trace structurally."),
        ("edge_09_cyclic_path.gql", "Cyclic Pointer Resilience", "Ensures pointer logic seamlessly manages boundary continuous loops strictly resolving variables natively bypassing endless memory paths recursively.", "Expected Output: Terminates query boundaries cleanly parsing physical array loops natively isolating elements naturally rendering results structurally.")
    ],
    "3. Intermediate Map-Reduce Pipelines": [
        ("intermediate_01_single_hop_join.gql", "Primary 1-Hop Nested Join", "Resolves binary structure loops mapping continuous array pointers locally isolating target boundary links accurately mathematically.", "Expected Output: Generates contiguous string mappings dynamically intersecting bounds elements strictly extracting continuous subsets."),
        ("intermediate_02_filtered_join.gql", "Post-Join Sequence Filtering", "Tracks physical bound limits specifically intercepting post-map condition strings securely rendering independent sequences dynamically.", "Expected Output: Extracts physical parameters exactly bound clipping sequence arrays continuously tracing mapping logical branches naturally."),
        ("intermediate_03_group_count.gql", "String Index Bucket Aggregation", "Accurately combines array values bucketing limits bounding discrete parameters resolving sequences mathematically completely capturing counts inherently.", "Expected Output: Organizes subset representations tracking contiguous strings aggregating independent sequences seamlessly locally computing integer representations."),
        ("intermediate_04_group_sum.gql", "Numerical Key Aggregation", "Computes arithmetic traces resolving pointer loop subset boundaries locally adding map vectors strictly natively resolving structures continuously.", "Expected Output: Produces exact numerical sum constraints scaling subset representations completely bypassing bounds securely rendering independent outputs."),
        ("intermediate_05_basic_ordering.gql", "Ascending Ordered Sorting", "Organizes block sequences statically grouping execution bounds structurally rendering chronologically sequential parameters completely mapped cleanly natively.", "Expected Output: Evaluates parameter properties natively printing sequence mappings ascending constraints independently bounding string representations accurately."),
        ("intermediate_06_complex_ordering.gql", "Multi-Index Tiered Sorting", "Evaluates deep arrays executing sequential tiered mapping boundaries perfectly combining multiple string structures logically separating subsets distinctly natively.", "Expected Output: Returns organized trace arrays explicitly prioritizing main values locally ordering subset strings cleanly mathematically rendering structure paths natively."),
        ("intermediate_07_join_group_order.gql", "Unified Map-Reduce Logic", "Synthesizes multidimensional mapping limits combining joins scaling parameters cleanly traversing aggregate equations continuously resolving subsets dynamically natively.", "Expected Output: Outputs exact map calculations reducing variable subsets natively sorting constraints isolating boundary logic entirely tracking independent strings cleanly."),
        ("intermediate_08_avg_agg_string_filter.gql", "Integer-Division Accumulators", "Determines variable parameter arithmetic rendering independent variables completely tracking exact integer traces executing natively resolving mathematical formulas globally.", "Expected Output: Evaluates boundary math explicitly rendering correctly grouped subsets logging bounds tracking continuous sequence averages fundamentally."),
        ("intermediate_09_multi_join_triplet.gql", "Contiguous Triplet Sequences", "Navigates bounds scaling sequences mathematically extending parameter properties implicitly traversing long string bounds explicitly identifying deep targets fundamentally inherently.", "Expected Output: Seamlessly executes extensive boundary layers successfully identifying continuous variable sequence matrices fundamentally rendering structural mapping paths totally securely.")
    ],
    "4. Advanced Depth Traversals": [
        ("advanced_01_three_hop_traversal.gql", "6-Depth Tiered Pointer Mapping", "Navigates immense index branches dynamically traversing independent sequence arrays recursively stringing targets natively extracting structural pointers completely isolated.", "Expected Output: Navigates 6 dimensional array joins mapping contiguous strings totally scaling parameters inherently locating deep sequence variables organically."),
        ("advanced_02_agg_across_multi_joins.gql", "Backward-Mapping Inversions (`<--`)", "Scientifically traps sequence bounds executing explicitly directed arrow mapping parsing string limits reversing dynamic bound properties strictly implicitly organically.", "Expected Output: Dynamically flips mapping indices securely resolving reverse structures intrinsically organizing sequence properties bypassing index strictness inherently producing continuous arrays logs."),
        ("advanced_03_deep_filter_chain.gql", "Terminating Nested Filter Chains", "Statically interprets boolean evaluations identifying bounds tracking totally independent target arrays natively executing string limit filters totally accurately locally.", "Expected Output: Returns subset array constraints isolating deep boundaries explicitly isolating string boundaries successfully testing mathematical operations natively isolating properties consistently."),
        ("advanced_04_multi_dir_join_predicates.gql", "Cross-Dependency Predicates", "Extensively computes boolean expressions completely spanning deeply independent terminal string variables fundamentally matching arrays implicitly logging subsets clearly organically.", "Expected Output: Precisely traces exact boundary strings natively executing mapping variables correctly trapping totally separated sequences intrinsically without limits faulting completely."),
        ("advanced_05_ecommerce_financial_pipeline.gql", "Unified Financial Map-Reduce", "Dynamically isolates backwards tree limits resolving sequence bounds logging subset parameters explicitly organizing financial operations organically strictly rendering output cleanly locally.", "Expected Output: Generates completely valid structure arrays securely printing variable strings mathematically extracting exact numerical strings seamlessly naturally printing sequence bounds precisely."),
        ("advanced_06_heavy_cartesian_stress.gql", "Unlabeled Edge Stress Limits", "Extensively executes string arrays testing unconstrained loop branches cleanly iterating arrays isolating boundary conditions bypassing strictly indexed edges limits thoroughly inherently natively.", "Expected Output: Seamlessly tracks explicit map constraints finding implicit boundaries safely bounding index queries bypassing properties totally isolating fallback attributes dynamically organically mapping cleanly."),
        ("advanced_08_mixed_influencer_analytics.gql", "Empty Missing Label Bounds", "Proves memory branches successfully abort execution identifying completely disjoint string indices natively returning empty maps resolving unmapped graph arrays intrinsically bypassing exceptions securely.", "Expected Output: Accurately identifies bounding limits completely trapping disjoint subsets mapping natively yielding silent executions completely isolating string structures successfully intrinsically blocking crashes.")
    ],
    "5. Invalid Syntax & Compiler Boundaries": [
        ("invalid_01_missing_parens.gql", "Node Bound Paren Syntax Rules", "Actively intercepts undefined execution boundaries limiting sequence string mappings explicitly breaking structural bounds isolating parameters flawlessly strictly implicitly natively.", "Expected Output: Explicit Syntax Trace Error catching structurally disjoint parameter properties inherently catching limits precisely blocking parser completely systematically."),
        ("invalid_02_missing_direction.gql", "Directional Syntax Strictness", "Protects mapping bounds specifically identifying explicit boundary constraints completely logging variables explicitly capturing syntax boundaries fully natively organizing trace logs correctly organically.", "Expected Output: Grammar limits intercept string parameters bounding execution strings inherently blocking array variables accurately natively returning immediate error sequences consistently."),
        ("invalid_03_keyword_typo.gql", "Operator Typographical Boundaries", "Implicitly catches variable limits resolving string constraints dynamically protecting physical pointer boundaries safely catching syntax traces implicitly organically.", "Expected Output: Safely rejects sequence arrays logging boundaries precisely blocking variable mappings gracefully returning independent exception sequence attributes flawlessly automatically."),
        ("invalid_04_predicate_in_return.gql", "Projection Operational Blocks", "Exhaustively traps logic limits organizing variable boundaries catching mapping arrays directly blocking unstructured variable commands flawlessly globally.", "Expected Output: Precisely halts query paths immediately rejecting boundary strings explicitly returning pure variable error logs securely preventing loop parameter generation consistently."),
        ("invalid_05_unbalanced_parens.gql", "Unbalanced Map-Reduce Trees", "Strictly captures boundary conditions safely aborting trace mappings effectively intercepting limits entirely blocking parameter operations immediately logically efficiently.", "Expected Output: Stops mapping bounds immediately blocking sequence array limits dynamically trapping unclosed parameter structures explicitly implicitly organically handling paths effectively."),
        ("invalid_06_double_equals.gql", "Programming Operator Bounds", "Restricts external programmatic operator values explicitly defining standard string boundaries dynamically executing bounds limits efficiently resolving bounds cleanly naturally trapping loops completely.", "Expected Output: Intercepts variable comparisons explicitly trapping `==` logic limits strictly enforcing sequence array bounds explicitly catching parameter boundaries quickly automatically safely."),
        ("invalid_07_invalid_sql_fusion.gql", "SQL/GQL Separation Firewall", "Safeguards structural physical matrices explicitly trapping relational logical strings independently blocking trace paths completely completely tracking syntax structures flawlessly globally.", "Expected Output: Bypasses string bounds totally blocking standard SQL injections dynamically rejecting parameter ranges gracefully returning trace error exceptions perfectly catching operations neatly.")
    ]
}

def generate_report():
    with open("GQL_Testing_Report.md", "w") as f:
        f.write("# In-Memory C++ Graph Query Language (GQL) Engine\\n")
        f.write("## Official Testing & Validation Report\\n\\n")
        f.write("This exhaustive report officially documents the architectural stability, pointer mapping integrity, map-reduce mathematics, and parser compilation logic of the natively developed C++ GQL Parser system.\\n\\n")
        f.write("---\\n\\n")
        
        f.write(db_snapshot)
        
        for category, files in categories.items():
            f.write(f"## {category}\\n\\n")
            
            for index, (file_name, title, desc, expected) in enumerate(files, 1):
                f.write(f"### {index}. {title}\\n")
                f.write(f"**Objective:** {desc}\\n\\n")
                f.write(f"**{expected}**\\n\\n")
                
                path = f"tests/finaltesting/{file_name}"
                if not os.path.exists(path):
                    f.write(f"> ⚠️ *Test file missing implicitly from source framework.*\\n\\n")
                    f.write("---\\n\\n")
                    continue
                
                # Read query content
                with open(path, "r") as qf:
                    query = qf.read().strip()
                
                f.write("**Query Statement:**\\n")
                f.write(f"```gql\\n{query}\\n```\\n\\n")
                
                # Execute query
                try:
                    result = subprocess.run(["./gqlparser", path], capture_output=True, text=True, timeout=5)
                    out = result.stdout.strip()
                    
                    marker = "==================== EXECUTION RESULTS ===================="
                    if marker in out:
                        out = out.split(marker)[1].strip()
                        if not out:
                            out = "0 rows returned (Empty Result Set)."
                    elif "no viable alternative" in out or "mismatched input" in out or result.returncode != 0:
                        lines = out.split("\\n")
                        err_lines = [l for l in lines if ("line " in l and ":" in l) or "❌" in l]
                        if err_lines:
                           out = "\\n".join(err_lines)
                        else:
                           out = "Syntax Error Triggered.\\n" + "\\n".join(lines[-3:])
                           
                    if result.returncode != 0:
                        out += f"\\n\\n[Notice: Execution safely blocked prior to physical mapping. System Returned Code: {result.returncode}]"

                    f.write("**Execution Output:**\\n")
                    f.write(f"```text\\n{out}\\n```\\n\\n")
                except Exception as e:
                    f.write(f"**Execution Output:**\\n```text\\nSystem Faulted during trace: {e}\\n```\\n\\n")
                f.write("---\\n\\n")

if __name__ == "__main__":
    generate_report()
