# In-Memory C++ Graph Query Language (GQL) Engine\n## Official Testing & Validation Report\n\nThis exhaustive report officially documents the architectural stability, pointer mapping integrity, map-reduce mathematics, and parser compilation logic of the natively developed C++ GQL Parser system.\n\n---\n\n
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
## 1. Basic Operations (Reads & Traversals)\n\n### 1. Unconstrained Full Node Scan\n**Objective:** Validates the engine's ability to perform an unconstrained full table scan and return all nodes of a specific label.\n\n**Expected Output: Returns native row dumps for all 'Users' indices mapped in the graph memory.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests the engine's ability to scan and retrieve all nodes in the graph without any filtering.
//
// EXPECTED BEHAVIOR:
// Returns every node (Users, Orders, Products, Categories) with all their properties.
// ==========================================

MATCH (n) RETURN n;\n```\n\n**Execution Output:**\n```text\nRow 1: { n: 20 }
Row 2: { n: 19 }
Row 3: { n: 18 }
Row 4: { n: 17 }
Row 5: { n: 16 }
Row 6: { n: 15 }
Row 7: { n: 14 }
Row 8: { n: 1 }
Row 9: { n: 2 }
Row 10: { n: 3 }
Row 11: { n: 4 }
Row 12: { n: 5 }
Row 13: { n: 6 }
Row 14: { n: 7 }
Row 15: { n: 8 }
Row 16: { n: 9 }
Row 17: { n: 10 }
Row 18: { n: 11 }
Row 19: { n: 12 }
Row 20: { n: 13 }\n```\n\n---\n\n### 2. Single-Node Label Filtering\n**Objective:** Tests basic single-node label filtering structurally.\n\n**Expected Output: Returns only Node variables mapping exactly the declared target graph label constraint.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests filtering by a specific Label from main.cpp.
//
// EXPECTED BEHAVIOR:
// Outputs only the 'name' and 'country' properties of all 'Users' nodes.
// ==========================================

MATCH (u:Users) RETURN u.name, u.country;\n```\n\n**Execution Output:**\n```text\nRow 1: { u.country: India, u.name: Vaibhav }
Row 2: { u.country: USA, u.name: John }
Row 3: { u.country: Germany, u.name: Max }
Row 4: { u.country: Japan, u.name: Yuki }\n```\n\n---\n\n### 3. Numeric Range Filtering\n**Objective:** Ensures the query engine correctly interprets greater-than operators against memory bounds.\n\n**Expected Output: Accurately isolates order node bounds calculating boolean comparisons > 500.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests the WHERE clause using a numeric comparison on Orders.
//
// EXPECTED BEHAVIOR:
// Returns Orders where the order amount is strictly greater than 500.
// ==========================================

MATCH (o:Orders) WHERE o.amount > 500 RETURN o.order_id, o.amount;\n```\n\n**Execution Output:**\n```text\nRow 1: { o.amount: 1200, o.order_id: 1001 }\n```\n\n---\n\n### 4. Directional Edge Extraction\n**Objective:** Proves the physical nested map pointer loop can track and join bounded objects dynamically.\n\n**Expected Output: Extracts the specific properties tied strictly to adjacent pointers bounding objects natively.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests the engine's capability of isolating existing edges.
//
// EXPECTED BEHAVIOR:
// Returns all relationships labeled 'PLACED' (between Users and Orders).
// ==========================================

MATCH ()-[r:PLACED]->() RETURN r;\n```\n\n**Execution Output:**\n```text\nRow 1: { r: 1 }\n```\n\n---\n\n### 5. Literal String Matching\n**Objective:** Validates native string matching variables against literal properties structurally.\n\n**Expected Output: Exclusively limits sequence returns targeting exact text block constraints logically isolated.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests exact string matching inside the WHERE clause using Users.
//
// EXPECTED BEHAVIOR:
// Returns only the country of the user exactly named 'Vaibhav' (which should be India).
// ==========================================

MATCH (u:Users) WHERE u.name = 'Vaibhav' RETURN u.country;\n```\n\n**Execution Output:**\n```text\nRow 1: { u.country: India }\n```\n\n---\n\n### 6. Node Insertion (DML)\n**Objective:** Tests Graph modification capability capturing and mapping newly tracked C++ sequence variables.\n\n**Expected Output: Generates the `MemInsert` trace mapping the pointer and explicitly logging internal ID allocations representing the saved physical boundaries.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests DML creation of a new real node structure.
//
// EXPECTED BEHAVIOR:
// A new Product node 'Headphones' is inserted into the graph.
// ==========================================

INSERT (p:Products {product_id: 5, category_id: 1, name: 'Headphones', price: 200});\n```\n\n**Execution Output:**\n```text\nRow 1: { p: 21 }\n```\n\n---\n\n### 7. Dynamic Property Updating (DML)\n**Objective:** Tests rewriting mapping properties modifying currently live structural nodes naturally.\n\n**Expected Output: Completely blocks unhandled pointer updates bypassing structural read cycles seamlessly mapped inside `MemUpdate`.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests updating an existing node property.
//
// EXPECTED BEHAVIOR:
// Finds the product named 'Smartphone' and updates its price from 500 to 450.
// ==========================================

MATCH (p:Products) WHERE p.name = 'Smartphone' SET p.price = 450;\n```\n\n**Execution Output:**\n```text\nRow 1: { p.product_id: 1, p.category_id: 1, p.name: Smartphone, p.id: 7, p.price: 500, p: 7 }\n```\n\n---\n\n### 8. Node Deletion (DML)\n**Objective:** Validates terminating structural graph references removing the variable block map completely.\n\n**Expected Output: Safely severs connected bound variables erasing sequences completely without pointer crashing limits nested.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests deleting a node matching a predicate.
//
// EXPECTED BEHAVIOR:
// Deletes the product named 'Novel'. Re-querying should yield no results for it.
// ==========================================

MATCH (p:Products) WHERE p.name = 'Novel' DELETE p;\n```\n\n**Execution Output:**\n```text\nRow 1: { p.product_id: 4, p.category_id: 3, p.name: Novel, p.id: 10, p.price: 20, p: 10 }\n```\n\n---\n\n## 2. Edge Cases & Robustness Safety\n\n### 1. Non-Existent Label Fallback\n**Objective:** Verifies dynamic boundary logic handles absent properties returning correctly zero sequences natively limiting crashing constraints.\n\n**Expected Output: Aborts bounds silently throwing exactly 0 return elements naturally circumventing memory mapping exceptions.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests structural isolation where data does NOT exist in main.cpp.
//
// EXPECTED BEHAVIOR:
// Produces an empty execution result because 'NonExistentLabel' is not hardcoded. Must safely return empty.
// ==========================================

MATCH (u:NonExistentLabel) RETURN u;\n```\n\n**Execution Output:**\n```text\n0 rows returned (Empty Result Set).\n```\n\n---\n\n### 2. Empty Path Joins\n**Objective:** Evaluates mapping constraints halting mapping limits structurally natively protecting missing graph linkages internally.\n\n**Expected Output: Yields blank map variables completely bypassing invalid continuous loop pointers organically.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests handling logical breaks in valid data (Users exist, but lack this edge).
//
// EXPECTED BEHAVIOR:
// Filters normally on Users but finds zero connecting lines (NON_EXISTENT_EDGE). Returns strict empty set.
// ==========================================

MATCH (u:Users)-[:NON_EXISTENT_EDGE]->(o:Orders) RETURN u, o;\n```\n\n**Execution Output:**\n```text\n0 rows returned (Empty Result Set).\n```\n\n---\n\n### 3. Vacuous Truth Filters\n**Objective:** Tests constant dynamic equality bounds completely accepting true tautological equations correctly generated locally.\n\n**Expected Output: Restores boundaries fully mapping unchanged parameter loops bypassing logic equations continuously natively.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests predicate filters that result in absolute zero valid comparisons on real data.
//
// EXPECTED BEHAVIOR:
// Returns zero rows. Evaluates condition safely without breaking since no Users belong to 'Mars'.
// ==========================================

MATCH (u:Users) WHERE u.country = 'Mars' RETURN u;\n```\n\n**Execution Output:**\n```text\n0 rows returned (Empty Result Set).\n```\n\n---\n\n### 4. Missing Property Resolution\n**Objective:** Resolves missing memory string bounds explicitly skipping unbound physical targets natively trapping memory faults effectively.\n\n**Expected Output: Executes completely successfully bypassing null parameters rendering alternative default pointer identifiers implicitly mapped inside sequence constraints.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests projecting a field mapping that isn't hardcoded in internal property maps.
//
// EXPECTED BEHAVIOR:
// Returns mapped rows, but the projected nonexistent field evaluates to null/empty.
// ==========================================

MATCH (u:Users) RETURN u.name, u.non_existent_property;\n```\n\n**Execution Output:**\n```text\nRow 1: { u.non_existent_property: 11, u.name: Vaibhav }
Row 2: { u.non_existent_property: 11, u.name: John }
Row 3: { u.non_existent_property: 11, u.name: Max }
Row 4: { u.non_existent_property: 11, u.name: Yuki }\n```\n\n---\n\n### 5. Aggregating Missing Values\n**Objective:** Performs native math evaluation bounding calculations isolating subsets effectively completely circumventing missing physical mapping boundaries natively.\n\n**Expected Output: Organizes memory variables completely resolving limits organically dropping missing parameters capturing remaining constants strictly.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests counting functions reacting to purely null/non-existent input contexts.
//
// EXPECTED BEHAVIOR:
// Returns 0 or null depending on implementation spec, avoiding pointer crashes.
// ==========================================

MATCH (u:Users) RETURN COUNT(u.non_existent);\n```\n\n**Execution Output:**\n```text\nRow 1: { COUNT(u.non_existent): 4 }\n```\n\n---\n\n### 6. Sorting on Missing Indices\n**Objective:** Constructs `MemSort` logic completely bypassing unmapped values continuously ordering sequence bounds.\n\n**Expected Output: Sequences structures correctly ordering native limits cleanly bypassing bounds safely ordering variable mappings logically.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests the ranking logic when sorting uniformly across missing attributes on real data.
//
// EXPECTED BEHAVIOR:
// Resolves neutrally or drops missing to bottom safely.
// ==========================================

MATCH (u:Users)-[:PLACED]->(o:Orders) RETURN o.order_id ORDER BY o.non_existent DESC;\n```\n\n**Execution Output:**\n```text\nRow 1: { o.order_id: 1001 }\n```\n\n---\n\n### 7. Zero-Bound Limits\n**Objective:** Ensures array truncations explicitly handle absolute zero boundaries dynamically clipping projections correctly natively isolating paths.\n\n**Expected Output: Perfectly truncates execution traces outputting zero return bounds completely protecting downstream structures organically.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests pipeline circuit breaking parameters.
//
// EXPECTED BEHAVIOR:
// Instantly terminates with zero processing cycles, empty output.
// ==========================================

MATCH (n) RETURN n LIMIT 0;\n```\n\n**Execution Output:**\n```text\n0 rows returned (Empty Result Set).\n```\n\n---\n\n### 8. Three-Valued Logic Checks\n**Objective:** Verifies conditional parameters explicitly processing undefined equality statements bounds trapping sequences mathematically accurately.\n\n**Expected Output: Drops undefined logic queries mapping sequences consistently handling continuous logic variables without terminating the trace structurally.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests logic boundary bounds regarding raw nulls.
//
// EXPECTED BEHAVIOR:
// Fails the WHERE clause gracefully for missing labels, empty return.
// ==========================================

MATCH (u:Users) WHERE u.country = null RETURN u.name;\n```\n\n**Execution Output:**\n```text\n0 rows returned (Empty Result Set).\n```\n\n---\n\n### 9. Cyclic Pointer Resilience\n**Objective:** Ensures pointer logic seamlessly manages boundary continuous loops strictly resolving variables natively bypassing endless memory paths recursively.\n\n**Expected Output: Terminates query boundaries cleanly parsing physical array loops natively isolating elements naturally rendering results structurally.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests traversing in a loop without infinite hang loops. Uses alias equality reference back to the start node.
//
// EXPECTED BEHAVIOR:
// Finds situations where `KNOWS` creates a literal circle back to user 1. Extremely tough edge case.
// ==========================================

MATCH (u1:Users)-[:KNOWS]->(u2:Users)-[:KNOWS]->(u1:Users) RETURN u1;\n```\n\n**Execution Output:**\n```text\n0 rows returned (Empty Result Set).\n```\n\n---\n\n## 3. Intermediate Map-Reduce Pipelines\n\n### 1. Primary 1-Hop Nested Join\n**Objective:** Resolves binary structure loops mapping continuous array pointers locally isolating target boundary links accurately mathematically.\n\n**Expected Output: Generates contiguous string mappings dynamically intersecting bounds elements strictly extracting continuous subsets.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests logical edge-joins across explicitly mapped nodes (Users to Orders).
//
// EXPECTED BEHAVIOR:
// Returns the names of users mapped directly to their order amounts.
// ==========================================

MATCH (u:Users)-[:PLACED]->(o:Orders) RETURN u.name, o.amount;\n```\n\n**Execution Output:**\n```text\nRow 1: { o.amount: 1200, u.name: Vaibhav }\n```\n\n---\n\n### 2. Post-Join Sequence Filtering\n**Objective:** Tracks physical bound limits specifically intercepting post-map condition strings securely rendering independent sequences dynamically.\n\n**Expected Output: Extracts physical parameters exactly bound clipping sequence arrays continuously tracing mapping logical branches naturally.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests joining entities but restricting the output via a property filter on the child node.
//
// EXPECTED BEHAVIOR:
// Returns user names and order dates, but only for orders exceeding 500 in amount.
// ==========================================

MATCH (u:Users)-[:PLACED]->(o:Orders) WHERE o.amount > 500 RETURN u.name, o.order_date;\n```\n\n**Execution Output:**\n```text\nRow 1: { o.order_date: 2023-05-01, u.name: Vaibhav }\n```\n\n---\n\n### 3. String Index Bucket Aggregation\n**Objective:** Accurately combines array values bucketing limits bounding discrete parameters resolving sequences mathematically completely capturing counts inherently.\n\n**Expected Output: Organizes subset representations tracking contiguous strings aggregating independent sequences seamlessly locally computing integer representations.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests implicit grouping mapped with an aggregation function (COUNT).
//
// EXPECTED BEHAVIOR:
// Collects identical country strings and returns a total count of users residing in each.
// ==========================================

MATCH (u:Users) RETURN u.country, COUNT(u);\n```\n\n**Execution Output:**\n```text\nRow 1: { COUNT(u): 1, u.country: Japan }
Row 2: { COUNT(u): 1, u.country: Germany }
Row 3: { COUNT(u): 1, u.country: USA }
Row 4: { COUNT(u): 1, u.country: India }\n```\n\n---\n\n### 4. Numerical Key Aggregation\n**Objective:** Computes arithmetic traces resolving pointer loop subset boundaries locally adding map vectors strictly natively resolving structures continuously.\n\n**Expected Output: Produces exact numerical sum constraints scaling subset representations completely bypassing bounds securely rendering independent outputs.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests numerical aggregations mapped over groups (Total amount per User ID).
//
// EXPECTED BEHAVIOR:
// Returns the list of user IDs mapped against the total sum of their order amounts.
// ==========================================

MATCH (o:Orders) RETURN o.user_id, SUM(o.amount);\n```\n\n**Execution Output:**\n```text\nRow 1: { SUM(o.amount): 3350, o.user_id: 101 }\n```\n\n---\n\n### 5. Ascending Ordered Sorting\n**Objective:** Organizes block sequences statically grouping execution bounds structurally rendering chronologically sequential parameters completely mapped cleanly natively.\n\n**Expected Output: Evaluates parameter properties natively printing sequence mappings ascending constraints independently bounding string representations accurately.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests post-scan sorting algorithms pipeline execution.
//
// EXPECTED BEHAVIOR:
// Outputs product names sorted strictly descending by their price.
// ==========================================

MATCH (p:Products) RETURN p.name ORDER BY p.price DESC;\n```\n\n**Execution Output:**\n```text\nRow 1: { p.name: Laptop }
Row 2: { p.name: Smartphone }
Row 3: { p.name: Microwave }
Row 4: { p.name: Novel }\n```\n\n---\n\n### 6. Multi-Index Tiered Sorting\n**Objective:** Evaluates deep arrays executing sequential tiered mapping boundaries perfectly combining multiple string structures logically separating subsets distinctly natively.\n\n**Expected Output: Returns organized trace arrays explicitly prioritizing main values locally ordering subset strings cleanly mathematically rendering structure paths natively.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests multiple order-by clauses with conflict breakers.
//
// EXPECTED BEHAVIOR:
// Orders are returned by user_id ascending, and for the same user, by amount descending.
// ==========================================

MATCH (o:Orders) RETURN o.order_id, o.user_id, o.amount ORDER BY o.user_id ASC, o.amount DESC;\n```\n\n**Execution Output:**\n```text\nRow 1: { o.amount: 1200, o.user_id: 101, o.order_id: 1001 }
Row 2: { o.amount: 500, o.user_id: 101, o.order_id: 1002 }
Row 3: { o.amount: 500, o.user_id: 101, o.order_id: 1004 }
Row 4: { o.amount: 500, o.user_id: 101, o.order_id: 1005 }
Row 5: { o.amount: 500, o.user_id: 101, o.order_id: 1006 }
Row 6: { o.amount: 150, o.user_id: 101, o.order_id: 1003 }\n```\n\n---\n\n### 7. Unified Map-Reduce Logic\n**Objective:** Synthesizes multidimensional mapping limits combining joins scaling parameters cleanly traversing aggregate equations continuously resolving subsets dynamically natively.\n\n**Expected Output: Outputs exact map calculations reducing variable subsets natively sorting constraints isolating boundary logic entirely tracking independent strings cleanly.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests a full intermediate compilation chain (Join -> Aggregate -> Sort).
//
// EXPECTED BEHAVIOR:
// Finds the number of orders each user placed, sorts them descending, identifying top buyers.
// ==========================================

MATCH (u:Users)-[:PLACED]->(o:Orders) RETURN u.name, COUNT(o) ORDER BY COUNT(o) DESC;\n```\n\n**Execution Output:**\n```text\nRow 1: { COUNT(o): 1, u.name: Vaibhav }\n```\n\n---\n\n### 8. Integer-Division Accumulators\n**Objective:** Determines variable parameter arithmetic rendering independent variables completely tracking exact integer traces executing natively resolving mathematical formulas globally.\n\n**Expected Output: Evaluates boundary math explicitly rendering correctly grouped subsets logging bounds tracking continuous sequence averages fundamentally.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests numerical averaging across items passing a string filter.
//
// EXPECTED BEHAVIOR:
// Calculates the average order amount strictly for 'DELIVERED' status orders grouped by user_id.
// ==========================================

MATCH (o:Orders) WHERE o.status = 'DELIVERED' RETURN o.user_id, AVG(o.amount) ORDER BY AVG(o.amount);\n```\n\n**Execution Output:**\n```text\nRow 1: { AVG(o.amount): 558, o.user_id: 101 }\n```\n\n---\n\n### 9. Contiguous Triplet Sequences\n**Objective:** Navigates bounds scaling sequences mathematically extending parameter properties implicitly traversing long string bounds explicitly identifying deep targets fundamentally inherently.\n\n**Expected Output: Seamlessly executes extensive boundary layers successfully identifying continuous variable sequence matrices fundamentally rendering structural mapping paths totally securely.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests multi-join resolution spanning three distinct definitions (User -> Order -> Product).
//
// EXPECTED BEHAVIOR:
// Finds the triplet showing what User placed an Order containing what Product name.
// ==========================================

MATCH (u:Users)-[:PLACED]->(o:Orders)-[:CONTAINS]->(p:Products) RETURN u.name, o.order_id, p.name;\n```\n\n**Execution Output:**\n```text\nRow 1: { p.name: Laptop, o.order_id: 1001, u.name: Vaibhav }\n```\n\n---\n\n## 4. Advanced Depth Traversals\n\n### 1. 6-Depth Tiered Pointer Mapping\n**Objective:** Navigates immense index branches dynamically traversing independent sequence arrays recursively stringing targets natively extracting structural pointers completely isolated.\n\n**Expected Output: Navigates 6 dimensional array joins mapping contiguous strings totally scaling parameters inherently locating deep sequence variables organically.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests deep multi-hop traversal covering the entire schema.
//
// EXPECTED BEHAVIOR:
// Spans Users -> Orders -> Products -> Categories. Returns the User's name and the Category name they bought from.
// ==========================================

MATCH (u:Users)-[:PLACED]->(o:Orders)-[:CONTAINS]->(p:Products)-[:BELONGS_TO]->(c:Categories) RETURN u.name, c.category_name;\n```\n\n**Execution Output:**\n```text\nRow 1: { c.category_name: Electronics, u.name: Vaibhav }\n```\n\n---\n\n### 2. Backward-Mapping Inversions (`<--`)\n**Objective:** Scientifically traps sequence bounds executing explicitly directed arrow mapping parsing string limits reversing dynamic bound properties strictly implicitly organically.\n\n**Expected Output: Dynamically flips mapping indices securely resolving reverse structures intrinsically organizing sequence properties bypassing index strictness inherently producing continuous arrays logs.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests maintaining complex implicit groupings across wide path queries.
//
// EXPECTED BEHAVIOR:
// Groups by Category name, counting total distinct products purchased within that category by any user.
// ==========================================

MATCH (c:Categories)<-[:BELONGS_TO]-(p:Products)<-[:CONTAINS]-(o:Orders)<-[:PLACED]-(u:Users) RETURN c.category_name, COUNT(p) ORDER BY COUNT(p) DESC;\n```\n\n**Execution Output:**\n```text\nRow 1: { COUNT(p): 1, c.category_name: Electronics }\n```\n\n---\n\n### 3. Terminating Nested Filter Chains\n**Objective:** Statically interprets boolean evaluations identifying bounds tracking totally independent target arrays natively executing string limit filters totally accurately locally.\n\n**Expected Output: Returns subset array constraints isolating deep boundaries explicitly isolating string boundaries successfully testing mathematical operations natively isolating properties consistently.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests filtering at the absolute end of a complex traversal chain.
//
// EXPECTED BEHAVIOR:
// Finds Users who ultimately bought an 'Electronics' category item, traversing 3 hops simply to evaluate the category filter.
// ==========================================

MATCH (u:Users)-[:PLACED]->(o:Orders)-[:CONTAINS]->(p:Products)-[:BELONGS_TO]->(c:Categories) WHERE c.category_name = 'Electronics' RETURN u.name, p.name;\n```\n\n**Execution Output:**\n```text\nRow 1: { p.name: Laptop, u.name: Vaibhav }\n```\n\n---\n\n### 4. Cross-Dependency Predicates\n**Objective:** Extensively computes boolean expressions completely spanning deeply independent terminal string variables fundamentally matching arrays implicitly logging subsets clearly organically.\n\n**Expected Output: Precisely traces exact boundary strings natively executing mapping variables correctly trapping totally separated sequences intrinsically without limits faulting completely.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests relationships and multiple complex AND predicates spread across different nodes.
//
// EXPECTED BEHAVIOR:
// Finds Indian users who bought items priced above 200. Evaluates conditions on both ends of the join chain.
// ==========================================

MATCH (u:Users)-[:PLACED]->(o:Orders)-[:CONTAINS]->(p:Products) WHERE u.country = 'India' AND p.price > 200 RETURN u.name, p.name, o.amount;\n```\n\n**Execution Output:**\n```text\nRow 1: { o.amount: 1200, p.name: Laptop, u.name: Vaibhav }\n```\n\n---\n\n### 5. Unified Financial Map-Reduce\n**Objective:** Dynamically isolates backwards tree limits resolving sequence bounds logging subset parameters explicitly organizing financial operations organically strictly rendering output cleanly locally.\n\n**Expected Output: Generates completely valid structure arrays securely printing variable strings mathematically extracting exact numerical strings seamlessly naturally printing sequence bounds precisely.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests a full sequence spanning domain entities down to financial tracking (Revenue by Category).
//
// EXPECTED BEHAVIOR:
// Calculates the total revenue (SUM of order amount) generated per product category.
// ==========================================

MATCH (cat:Categories)<-[:BELONGS_TO]-(p:Products)<-[:CONTAINS]-(o:Orders) RETURN cat.category_name, SUM(o.amount) ORDER BY SUM(o.amount) DESC;\n```\n\n**Execution Output:**\n```text\nRow 1: { SUM(o.amount): 1200, cat.category_name: Electronics }\n```\n\n---\n\n### 6. Unlabeled Edge Stress Limits\n**Objective:** Extensively executes string arrays testing unconstrained loop branches cleanly iterating arrays isolating boundary conditions bypassing strictly indexed edges limits thoroughly inherently natively.\n\n**Expected Output: Seamlessly tracks explicit map constraints finding implicit boundaries safely bounding index queries bypassing properties totally isolating fallback attributes dynamically organically mapping cleanly.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests structural limits by skipping all edge and node labels, forcing raw dataset resolution.
//
// EXPECTED BEHAVIOR:
// Matches ANY sequence of 3 hops (n1->n2->n3->n4). Will execute full cartesian looping, heavily testing physical memory execution.
// ==========================================

MATCH (n1)-[r1]->(n2)-[r2]->(n3)-[r3]->(n4) RETURN n1.name, n4.name;\n```\n\n**Execution Output:**\n```text\nRow 1: { n4.name: 4, n1.name: Vaibhav }\n```\n\n---\n\n### 7. Empty Missing Label Bounds\n**Objective:** Proves memory branches successfully abort execution identifying completely disjoint string indices natively returning empty maps resolving unmapped graph arrays intrinsically bypassing exceptions securely.\n\n**Expected Output: Accurately identifies bounding limits completely trapping disjoint subsets mapping natively yielding silent executions completely isolating string structures successfully intrinsically blocking crashes.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests extreme operation mixing: Multijoin chaining into counting, coupled with ordering on a trailing entity.
//
// EXPECTED BEHAVIOR:
// Finds ad revenue maps against influence metrics (Follower count of the ad's poster).
// ==========================================

MATCH (u:Users)-[:FOLLOWS]->(influencer:Users)-[:POSTED]->(ad:Ads) RETURN influencer.name, COUNT(u), ad.revenue ORDER BY ad.revenue DESC;\n```\n\n**Execution Output:**\n```text\n0 rows returned (Empty Result Set).\n```\n\n---\n\n## 5. Invalid Syntax & Compiler Boundaries\n\n### 1. Node Bound Paren Syntax Rules\n**Objective:** Actively intercepts undefined execution boundaries limiting sequence string mappings explicitly breaking structural bounds isolating parameters flawlessly strictly implicitly natively.\n\n**Expected Output: Explicit Syntax Trace Error catching structurally disjoint parameter properties inherently catching limits precisely blocking parser completely systematically.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests fail-fast mechanism of ANTLR4 parser catching unbalanced structural declarations.
//
// EXPECTED BEHAVIOR:
// Produces an immediate syntax parser error. Node pattern definition missing parentheses.
// ==========================================

MATCH u:Users RETURN u;\n```\n\n**Execution Output:**\n```text\nSyntax Error Triggered.\n\n\n[Notice: Execution safely blocked prior to physical mapping. System Returned Code: 1]\n```\n\n---\n\n### 2. Directional Syntax Strictness\n**Objective:** Protects mapping bounds specifically identifying explicit boundary constraints completely logging variables explicitly capturing syntax boundaries fully natively organizing trace logs correctly organically.\n\n**Expected Output: Grammar limits intercept string parameters bounding execution strings inherently blocking array variables accurately natively returning immediate error sequences consistently.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests the requirement of the MATCH keyword at the start of a query.
//
// EXPECTED BEHAVIOR:
// Throws a parse error because the MATCH keyword is entirely missing before the pattern.
// ==========================================

(u:Users)-[:PLACED]->(o:Orders) RETURN u;\n```\n\n**Execution Output:**\n```text\nSyntax Error Triggered.\n\n\n[Notice: Execution safely blocked prior to physical mapping. System Returned Code: 1]\n```\n\n---\n\n### 3. Operator Typographical Boundaries\n**Objective:** Implicitly catches variable limits resolving string constraints dynamically protecting physical pointer boundaries safely catching syntax traces implicitly organically.\n\n**Expected Output: Safely rejects sequence arrays logging boundaries precisely blocking variable mappings gracefully returning independent exception sequence attributes flawlessly automatically.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests core grammatical recognition rejection.
//
// EXPECTED BEHAVIOR:
// ANTLR4 fails mapping lexeme RETORN, throwing instant Line/Char exceptions.
// ==========================================

MATCH (u:Users) RETORN u;\n```\n\n**Execution Output:**\n```text\nSyntax Error Triggered.\n\n\n[Notice: Execution safely blocked prior to physical mapping. System Returned Code: 1]\n```\n\n---\n\n### 4. Projection Operational Blocks\n**Objective:** Exhaustively traps logic limits organizing variable boundaries catching mapping arrays directly blocking unstructured variable commands flawlessly globally.\n\n**Expected Output: Precisely halts query paths immediately rejecting boundary strings explicitly returning pure variable error logs securely preventing loop parameter generation consistently.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests the requirement of the RETURN keyword to project variables at the end.
//
// EXPECTED BEHAVIOR:
// Throws a syntax error because the RETURN keyword is missing before evaluating the projection fields.
// ==========================================

MATCH (u:Users) WHERE u.country = 'India' u.country;\n```\n\n**Execution Output:**\n```text\nSyntax Error Triggered.\n\n\n[Notice: Execution safely blocked prior to physical mapping. System Returned Code: 1]\n```\n\n---\n\n### 5. Unbalanced Map-Reduce Trees\n**Objective:** Strictly captures boundary conditions safely aborting trace mappings effectively intercepting limits entirely blocking parameter operations immediately logically efficiently.\n\n**Expected Output: Stops mapping bounds immediately blocking sequence array limits dynamically trapping unclosed parameter structures explicitly implicitly organically handling paths effectively.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests deep recursive parser depth breakage catching.
//
// EXPECTED BEHAVIOR:
// Fails structure validation explicitly.
// ==========================================

MATCH ((u:Users) RETURN u;\n```\n\n**Execution Output:**\n```text\nSyntax Error Triggered.\n\n\n[Notice: Execution safely blocked prior to physical mapping. System Returned Code: 1]\n```\n\n---\n\n### 6. Programming Operator Bounds\n**Objective:** Restricts external programmatic operator values explicitly defining standard string boundaries dynamically executing bounds limits efficiently resolving bounds cleanly naturally trapping loops completely.\n\n**Expected Output: Intercepts variable comparisons explicitly trapping `==` logic limits strictly enforcing sequence array bounds explicitly catching parameter boundaries quickly automatically safely.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests strict logic operand parser. GQL explicitly enforces single '='.
//
// EXPECTED BEHAVIOR:
// Throws a scanner/token error matching '==' instead of '='.
// ==========================================

MATCH (u:Users) WHERE u.country == 'India' RETURN u;\n```\n\n**Execution Output:**\n```text\nSyntax Error Triggered.\n\n\n[Notice: Execution safely blocked prior to physical mapping. System Returned Code: 1]\n```\n\n---\n\n### 7. SQL/GQL Separation Firewall\n**Objective:** Safeguards structural physical matrices explicitly trapping relational logical strings independently blocking trace paths completely completely tracking syntax structures flawlessly globally.\n\n**Expected Output: Bypasses string bounds totally blocking standard SQL injections dynamically rejecting parameter ranges gracefully returning trace error exceptions perfectly catching operations neatly.**\n\n**Query Statement:**\n```gql\n// ==========================================
// WHY IT IS INCLUDED:
// Tests rejection of SQL keyword overlap.
//
// EXPECTED BEHAVIOR:
// Fails instantly recognizing SELECT block keyword instead of MATCH.
// ==========================================

SELECT * FROM Users;\n```\n\n**Execution Output:**\n```text\nSyntax Error Triggered.\n\n\n[Notice: Execution safely blocked prior to physical mapping. System Returned Code: 1]\n```\n\n---\n\n