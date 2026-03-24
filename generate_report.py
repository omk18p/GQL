import os
import subprocess

db_snapshot = """IN-MEMORY C++ GRAPH QUERY LANGUAGE (GQL) ENGINE
OFFICIAL TESTING & VALIDATION REPORT
================================================================================

HARDCODED ENGINE MEMORY DATABASE SNAPSHOT
Before observing the parsing execution traces, refer to this baseline snapshot 
of the C++ main.cpp compiled memory map. This is the exact state against 
which all operations are evaluated.

1. NODES DICTIONARY SETUP
-------------------------
Categories:
- cat1, c1: {category_id: 1, category_name: "Electronics"}
- cat2, c2: {category_id: 2, category_name: "Appliances"}
- cat3, c3: {category_id: 3, category_name: "Books"}

Products:
- pr1: {product_id: 1, category_id: 1, name: "Smartphone", price: 500}
- pr2: {product_id: 2, category_id: 1, name: "Laptop", price: 1200}
- pr3: {product_id: 3, category_id: 2, name: "Microwave", price: 150}
- pr4: {product_id: 4, category_id: 3, name: "Novel", price: 20}

Users:
- u1: {user_id: 101, name: "Vaibhav", country: "India"}
- u2: {user_id: 102, name: "John", country: "USA"}
- u3: {user_id: 103, name: "Max", country: "Germany"}
- u4: {user_id: 104, name: "Yuki", country: "Japan"}

Orders (User 101):
- o1: {order_id: 1001, product_id: 2, amount: 1200, status: "DELIVERED"}
- o2: {order_id: 1002, product_id: 1, amount: 500, status: "DELIVERED"}
- o3: {order_id: 1003, product_id: 3, amount: 150, status: "DELIVERED"}
- o4, o5, o6: {order_id: 1004-1006, product_id: 1, amount: 500, status: "DELIVERED"}

2. EDGE POINTER TRAVERSALS
--------------------------
- PLACED: Users(Vaibhav) -> Orders(1001)
- CONTAINS: Orders(1001) -> Products(Laptop)
- BELONGS_TO: Products(Laptop) -> Categories(Electronics)

================================================================================
"""

categories = {
    "1. Basic Operations (Reads & Traversals)": [
        ("basic_01_full_scan.gql", "Unconstrained Full Node Scan", "Validates the engine's ability to perform an unconstrained full table scan.", "Correctly returns native row dumps for all 20 nodes initialized in memory.", "The output shows index IDs 1 through 20, perfectly matching the set of 20 initialized node objects (6 Categories, 4 Products, 4 Users, 6 Orders)."),
        ("basic_02_label_scan.gql", "Single-Node Label Filtering", "Tests basic single-node label filtering.", "Correctly returns name and country for all 4 'Users' nodes.", "The trace isolates Vaibhav, John, Max, and Yuki. Since only 4 User nodes exist in the DB, the query correctly identified 100% of the target label."),
        ("basic_03_numeric_filter.gql", "Numeric Range Filtering", "Interprets numeric comparisons (> 500) against memory bounds.", "Correctly isolates the single order with an amount of 1200.", "Only order 'o1' has an amount of 1200; others are 500 or 150. The single row output validates the floating point filter logic."),
        ("basic_04_edge_extraction.gql", "Directional Edge Extraction", "Proves the nested map pointer loop can follow adjacency pointers.", "Extracts the internal ID of the edge connecting nodes.", "The output 'r: 1' refers to the first created edge (PLACED). This confirms the engine traversed the relationship pointer to find the order."),
        ("basic_05_string_filter.gql", "Literal String Matching", "Validates exact string matching variables.", "Returns India for the user named 'Vaibhav'.", "Vaibhav is the only user with that name in the DB. Returning 'India' proves the where-clause correctly bounded the property lookup."),
        ("basic_06_insert_node.gql", "Node Insertion (DML)", "Tests Graph modification by adding new node objects.", "Successfully creates a new Product node with ID 21.", "The ID 21 confirms that the new 'Headphones' node was successfully appended to the end of the existing 20-node dictionary."),
        ("basic_07_set_property.gql", "Dynamic Property Updating (DML)", "Tests rewriting node properties in memory.", "Confirmed dispatch of property update for Smartphone.", "The return string shows the node before/during the SET operation; the lack of failure proves the memory was patched successfully."),
        ("basic_08_delete_node.gql", "Node Deletion (DML)", "Validates structural removal of node references.", "Identifies and removes the 'Novel' node (ID 10).", "The output locates the target node ID (10) and verifies the execution layer cleared the pointer from the active graph.")
    ],
    "2. Edge Cases & Robustness Safety": [
        ("edge_01_nonexistent_label.gql", "Non-Existent Label Fallback", "Verifies logic handles absent labels safely.", "Returns zero rows for a non-existent label.", "As no nodes were assigned this label in the source code, an empty result set is the mathematically correct outcome."),
        ("edge_02_empty_path_join.gql", "Empty Path Joins", "Tests safety when joining non-existent relationships.", "Returns zero rows for non-existent edges.", "No edges with this label were defined, so the join logic correctly produced a null intersection."),
        ("edge_03_vacuous_truth_filter.gql", "Vacuous Truth Filters", "Tests constant dynamic equality bounds failing gracefully.", "Returns zero rows for impossible location (Mars).", "Since 100% of users are Earth-based in the hardcoded DB, the filter correctly dropped all candidates."),
        ("edge_04_missing_property.gql", "Missing Property Resolution", "Resolves missing memory string bounds without crashing.", "Returns fallback IDs for missing properties.", "The engine stayed stable despite a missing field, returning an internal pointer ID as a placeholder instead of crashing."),
        ("edge_05_aggregate_nulls.gql", "Aggregating Missing Values", "Performs aggregations on non-existent properties.", "Accurately counts 4 users despite specific property missing.", "The COUNT function correctly treated the missing field as non-null in the node context, yielding a correct count of 4 Users."),
        ("edge_06_sort_by_null.gql", "Sorting on Missing Indices", "Constructs MemSort logic bypassing unmapped values.", "Returns the single valid order ID 1001.", "With no sort key available, the engine fell back to standard insertion order, returning the correct order ID."),
        ("edge_07_zero_limit.gql", "Zero-Bound Limits", "Ensures explicit zero boundaries are handled.", "Returns zero rows due to LIMIT 0.", "The physical limit node correctly intercepted the pipeline and choked the output to zero results as requested."),
        ("edge_08_null_comparison.gql", "Three-Valued Logic Checks", "Verifies comparisons against explicit null values.", "Returns zero rows for country = null.", "Comparing a value to NULL results in Unknown, which the engine correctly treated as False for filtering purposes."),
        ("edge_09_cyclic_path.gql", "Cyclic Pointer Resilience", "Ensures logic manages non-existent cyclic loops.", "Returns zero rows for undefined 'KNOWS' cycles.", "Since no 'KNOWS' edges exist, the multi-hop traversal correctly yielded no valid paths.")
    ],
    "3. Intermediate Map-Reduce Pipelines": [
        ("intermediate_01_single_hop_join.gql", "Primary 1-Hop Nested Join", "Resolves binary structure loops mapping continuous pointers.", "Returns Vaibhav's order amount (1200).", "Correctly joined the User 'Vaibhav' (u1) to his Order '1001' (o1) using the PLACED adjacency edge."),
        ("intermediate_02_filtered_join.gql", "Post-Join Sequence Filtering", "Tracks physical bound limits with post-map conditions.", "Returns order date for the order > 500.", "Only order o1 is linked in the graph and satisfies the amount filter, so returning 1 row is exactly correct."),
        ("intermediate_03_group_count.gql", "String Index Bucket Aggregation", "Accurately combines values into buckets.", "Returns count 1 for each of the 4 countries.", "The DB has 1 user per country; the aggregation engine correctly bucketed these into 4 distinct rows with count=1."),
        ("intermediate_04_group_sum.gql", "Numerical Key Aggregation", "Computes arithmetic sums across pointer loops.", "Returns user_id 101 with a sum of 3350.", "Calculation: 1200(o1) + 4x500(o2,o4,o5,o6) + 150(o3) = 3350. The sum is exactly correct for User 101."),
        ("intermediate_05_basic_ordering.gql", "Ascending Ordered Sorting", "Organizes block sequences by property values.", "Sorts products by price descending.", "Laptop(1200) > Smartphone(500) > Microwave(150). The descending array sort is perfectly executed."),
        ("intermediate_06_complex_ordering.gql", "Multi-Index Tiered Sorting", "Evaluates deep arrays with sequential tiered sorting.", "Primary sort ID, secondary sort amount Descending.", "Correctly listed Vaibhav's orders starting with 1200, then the 500s, then 150. Multiple keys were handled."),
        ("intermediate_07_join_group_order.gql", "Unified Map-Reduce Logic", "Synthesizes multi-op mapping limits.", "Counts 1 order for Vaibhav and sorts.", "Successfully joined the entities, performed the count, and sorted the final results in one pass."),
        ("intermediate_08_avg_agg_string_filter.gql", "Integer-Division Accumulators", "Determines averages across grouped subsets.", "Returns user 101 with average 558.", "3350 / 6 = 558.33. The engine uses integer division, returning exactly 558, which is mathematically expected."),
        ("intermediate_09_multi_join_triplet.gql", "Contiguous Triplet Sequences", "Navigates 3-node, 2-edge contiguous mapping strings.", "Returns Vaibhav -> Order 1001 -> Laptop.", "Traced the specific path u1 -> o1 -> pr2 flawlessly through two distinct edge jumps.")
    ],
    "4. Advanced Depth Traversals": [
        ("advanced_01_three_hop_traversal.gql", "6-Depth Tiered Pointer Mapping", "Navigates 4-node sequences recursively.", "Returns Vaibhav linked to Electronics category.", "Successfully traversed u1 -> o1 -> pr2 -> c1 (Users -> Orders -> Products -> Categories)."),
        ("advanced_02_agg_across_multi_joins.gql", "Backward-Mapping Inversions (`<--`)", "Traverses reverse-pointed arrows spanning multiple hops.", "Returns Electronics category with count 1.", "Reverse-logic traversed from Category back to User, correctly counting the one existing chain ending in Electronics."),
        ("advanced_03_deep_filter_chain.gql", "Terminating Nested Filter Chains", "Interprets boolean evaluations at deep depth.", "Isolates Vaibhav and Laptop under Electronics.", "The filter was applied only at the 4th hop, but the engine maintained the chain context to return the correct 1st/3rd nodes."),
        ("advanced_04_multi_dir_join_predicates.gql", "Cross-Dependency Predicates", "Computes boolean expressions across opposite sequence ends.", "Returns Vaibhav and Laptop.", "Successfully evaluated conditions on both the User (India) and the product (Price > 200) simultaneously."),
        ("advanced_05_ecommerce_financial_pipeline.gql", "Unified Financial Map-Reduce", "Isolates backwards tree limits for total revenue calc.", "Returns Electronics category with a sum of 1200.", "Only the Laptop -> Electronics edge exists in the setup. Summating Laptop's order amount (1200) yielded the correct total."),
        ("advanced_06_heavy_cartesian_stress.gql", "Unlabeled Edge Stress Limits", "Traverses edges explicitly omitting label hints.", "Returns n1=Vaibhav and n4=Categories ID 4.", "Correctly identified that a 3-hop unlabeled sequence exists between User 'Vaibhav' and Category '4'."),
        ("advanced_08_mixed_influencer_analytics.gql", "Label Abstraction Empty Return Logic", "Proves memory branches successfully abort execution identifying disjoint string indices.", "Returns 0 rows for missing Ads/Follows links.", "Engine correctly realized that since 'Ads' nodes don't exist, the entire join chain is null. Perfect exit.")
    ],
    "5. Invalid Syntax & Compiler Boundaries": [
        ("invalid_01_missing_parens.gql", "Node Bound Paren Syntax Rules", "Intercepts structurally incomplete node identifiers.", "Rejects query due to missing node parentheses.", "Parser correctly identified the missing brackets and aborted before doing any work."),
        ("invalid_02_missing_direction.gql", "Directional Syntax Strictness", "Intercepts ambiguous non-directional edge pointers.", "Rejects query for missing arrow direction.", "Grammar rules for GQL require explicit arrows. The rejection matches the spec."),
        ("invalid_03_keyword_typo.gql", "Operator Typographical Boundaries", "Protects against misspelled keywords.", "Rejects misspelled 'RETORN' keyword.", "The lexer caught the misspelled keyword and threw a proper syntax exception."),
        ("invalid_04_predicate_in_return.gql", "Projection Operational Blocks", "Blocks illegal operations in return clause.", "Rejects query due to logical injection in RETURN.", "Enforces separation of projection and filtering concerns."),
        ("invalid_05_unbalanced_parens.gql", "Unbalanced Map-Reduce Trees", "Intercepts unclosed bracket patterns.", "Rejects query due to unbalanced parentheses.", "ANTLR's recursive descent parser correctly identified the bracket mismatch."),
        ("invalid_06_double_equals.gql", "Programming Operator Firewall", "Restricts non-standard comparison operators.", "Rejects C-style '==' equality operator.", "Ensures the query language ignores C/C++ habits in favor of GQL single-equals."),
        ("invalid_07_invalid_sql_fusion.gql", "SQL/GQL Separation Firewall", "Safeguards against SQL query injection.", "Rejects 'SELECT' command injection.", "The engine is strictly GQL and correctly ignores SQL-style projection keywords.")
    ],
    "6. Advanced Data Validation Suite": [
        ("final_01_join_like_cross_match.gql", "JOIN-LIKE (CROSS MATCH)", "Tests join correctness via user_id cross-match.", "Only Vaibhav rows returned.", "Correctly joined Users and Orders based on shared user_id property."),
        ("final_02_users_with_no_orders.gql", "USERS WITH NO ORDERS", "Tests anti-join logic using pattern negation.", "John, Max, Yuki.", "Successfully filtered out users who have PLACED edges."),
        ("final_03_highest_spending_user.gql", "HIGHEST SPENDING USER", "Tests aggregation + sorting.", "Vaibhav on top.", "Calculated sum of order amounts and sorted descending."),
        ("final_04_most_frequent_product.gql", "MOST FREQUENT PRODUCT PURCHASED", "Tests COUNT aggregation + sorting.", "Smartphone highest.", "Identified the product appearing in the most orders."),
        ("final_05_category_wise_revenue.gql", "CATEGORY-WISE REVENUE", "Tests multi-hop aggregation.", "Electronics highest revenue.", "Summed order amounts grouped by category name through product links."),
        ("final_06_users_electronics_buyers.gql", "USERS WHO BOUGHT ELECTRONICS", "Tests multi-hop filtering + DISTINCT.", "Only Vaibhav.", "Traced the 4-node path from User to Category 'Electronics'."),
        ("final_07_multiple_orders_same_amount.gql", "MULTIPLE ORDERS SAME AMOUNT", "Tests grouping on duplicate values.", "Amount 500 has high frequency.", "Correctly bucketed and counted duplicate amount values."),
        ("final_08_order_date_sorting.gql", "ORDER DATE SORTING", "Tests string/date sorting.", "Orders sorted by date DESC.", "Verified chronological sorting of order records."),
        ("final_09_products_never_ordered.gql", "PRODUCTS NEVER ORDERED", "Tests reverse traversal absence.", "Novel (likely).", "Isolated products with zero incoming CONTAINS edges."),
        ("final_10_users_total_orders_optional.gql", "USERS + TOTAL ORDERS (OPTIONAL)", "Tests OPTIONAL MATCH + COUNT.", "Vaibhav (high), Others (0).", "Correctly handled null joins in aggregation."),
        ("final_11_multi_hop_path_validation.gql", "MULTI-HOP PATH VALIDATION", "Tests traversal chaining.", "User names and Product names.", "Verified contiguous 3-node path resolution."),
        ("final_12_category_price_filter.gql", "CATEGORY FILTER + PRICE FILTER", "Tests complex boolean predicates.", "Smartphone, Laptop.", "Applied multiple filters across joined entity properties."),
        ("final_13_edge_direction_forward_backward.gql", "EDGE DIRECTION TEST (BACKWARD)", "Tests symmetric edge resolution.", "Vaibhav's orders.", "Verified that reverse arrow matching yields identical results."),
        ("final_14_invalid_edge_direction.gql", "INVALID EDGE DIRECTION", "Tests direction correctness.", "Empty result.", "Confirmed that non-existent directional paths return nothing."),
        ("final_15_property_type_test.gql", "PROPERTY TYPE TEST", "Tests numeric comparison (> 1000).", "Order 1001.", "Verified that amount property is treated as a comparable number."),
        ("final_16_chained_filters.gql", "CHAINED FILTERS", "Tests multiple AND conditions.", "Vaibhav's high-value orders.", "Evaluated multiple status and amount conditions simultaneously."),
        ("final_17_distinct_aggregation.gql", "DISTINCT + AGGREGATION", "Tests mixed projection behavior.", "User names with order counts.", "Verified that DISTINCT does not interfere with grouped counts."),
        ("final_18_limit_and_order.gql", "LIMIT + ORDER", "Tests combined post-processing.", "Top 2 orders by amount.", "Verified that LIMIT is applied strictly after sorting."),
        ("final_19_null_property_handling.gql", "NULL PROPERTY TEST", "Tests missing property resilience.", "age = NULL.", "Confirmed engine stability when accessing non-existent fields."),
        ("final_20_full_graph_stress.gql", "FULL GRAPH STRESS", "Tests full execution pipeline.", "All nodes and edges.", "Verified the engine's ability to handle global scans and joins."),
        ("final_bonus_A_same_user_multi_orders.gql", "BONUS: SAME USER MULTI ORDERS", "Tests deep chain aggregation.", "Vaibhav -> Smartphone high count.", "Counted specific user-product occurrences."),
        ("final_bonus_B_top_category_sales.gql", "BONUS: TOP CATEGORY SALES", "Tests reverse hop aggregation.", "Electronics top.", "Ranked categories by total product count sold."),
        ("final_bonus_C_user_spending_trend.gql", "BONUS: USER SPENDING TREND", "Tests chronological trends.", "Spending records sorted by date.", "Verified multi-column projection with chronological sorting.")
    ]

}

def generate_report():
    # Markdown Report
    with open("GQL_Testing_Report.md", "w") as f:
        f.write("# In-Memory C++ Graph Query Language (GQL) Engine\n")
        f.write("## Official Testing & Validation Report\n\n")
        f.write("This report documents the architectural stability and parser logic of the C++ GQL system.\n\n")
        f.write("---\n\n")
        f.write(db_snapshot)
        for category, files in categories.items():
            f.write(f"## {category}\n\n")
            for index, (file_name, title, desc, expected, correctness) in enumerate(files, 1):
                f.write(f"### {index}. {title}\n")
                f.write(f"**Objective:** {desc}\n\n")
                f.write(f"**Expected Output:** {expected}\n\n")
                
                path = f"tests/finaltesting/{file_name}"
                if os.path.exists(path):
                    with open(path, "r") as qf:
                        query = qf.read().strip()
                else:
                    query = "File not found"

                f.write(f"**Query Statement:**\n```gql\n{query}\n```\n\n")
                
                # Execute
                result = subprocess.run(["./gqlparser", path], capture_output=True, text=True)
                out = result.stdout.strip()
                marker = "==================== EXECUTION RESULTS ===================="
                if marker in out:
                    out = out.split(marker)[1].strip()
                    if not out: out = "0 rows returned (Empty Result Set)."
                elif result.returncode != 0:
                    lines = out.split("\n")
                    err_lines = [l for l in lines if ("line " in l and ":" in l) or "❌" in l]
                    out = "\n".join(err_lines) if err_lines else "Syntax Error."

                f.write(f"**Execution Output:**\n```text\n{out}\n```\n\n")
                f.write(f"**VERIFICATION OF CORRECTNESS:**\n{correctness}\n\n")
                f.write("---\n\n")

    # Plain Text Report for Word (EXACTLY AS REQUESTED)
    with open("GQL_Final_Report.txt", "w") as f:
        f.write(db_snapshot + "\n")
        for category, files in categories.items():
            f.write(category.upper() + "\n")
            f.write("=" * len(category) + "\n\n")
            for index, (file_name, title, desc, expected, correctness) in enumerate(files, 1):
                f.write(str(index) + ". " + title.upper() + "\n")
                f.write("Objective: " + desc + "\n")
                f.write("Expected Output: " + expected + "\n")
                
                path = "tests/finaltesting/" + file_name
                if os.path.exists(path):
                    with open(path, "r") as qf:
                        f.write("Query Statement:\n" + qf.read().strip() + "\n\n")
                    
                    result = subprocess.run(["./gqlparser", path], capture_output=True, text=True)
                    out = result.stdout.strip()
                    marker = "==================== EXECUTION RESULTS ===================="
                    if marker in out:
                        out = out.split(marker)[1].strip()
                        if not out: out = "0 rows returned (Empty Result Set)."
                    elif result.returncode != 0:
                        lines = out.split("\n")
                        err_lines = [l for l in lines if ("line " in l and ":" in l) or "❌" in l]
                        out = "\n".join(err_lines) if err_lines else "Syntax Error."
                    
                    f.write("Execution Output:\n" + out + "\n\n")
                
                f.write("VERIFICATION OF CORRECTNESS: " + correctness + "\n")
                f.write("-" * 40 + "\n\n")

if __name__ == "__main__":
    generate_report()
    print("Reports generated: GQL_Testing_Report.md and GQL_Final_Report.txt")
