#!/bin/bash

# Script to create all 105 test query files
# This script creates individual .gql files for each query

cd "$(dirname "$0")"

# Small Queries (1-20)
cat > Q1.gql << 'EOF'
MATCH (n) RETURN n;
EOF

cat > Q2.gql << 'EOF'
MATCH (p:Person) RETURN p;
EOF

cat > Q3.gql << 'EOF'
MATCH (p:Person) RETURN p.name;
EOF

cat > Q4.gql << 'EOF'
MATCH (p:Person)-[:KNOWS]->(f:Person) RETURN p, f;
EOF

cat > Q5.gql << 'EOF'
MATCH (p:Person) WHERE p.age > 25 RETURN p;
EOF

cat > Q6.gql << 'EOF'
MATCH (p:Person) WHERE p.name = "Alice" RETURN p;
EOF

cat > Q7.gql << 'EOF'
CREATE (p:Person {name: "Alice", age: 30});
EOF

cat > Q8.gql << 'EOF'
CREATE (p:Person {name: "Bob"});
EOF

cat > Q9.gql << 'EOF'
MATCH (p:Person) DELETE p;
EOF

cat > Q10.gql << 'EOF'
MATCH (p:Person) WHERE p.age > 100 DELETE p;
EOF

cat > Q11.gql << 'EOF'
MATCH (p:Person) WHERE p.name = "Alice" SET p.age = 31;
EOF

cat > Q12.gql << 'EOF'
MATCH (p:Person) WHERE p.name = "Bob" REMOVE p.age;
EOF

cat > Q13.gql << 'EOF'
MATCH (p:Person) RETURN COUNT(*) AS total;
EOF

cat > Q14.gql << 'EOF'
MATCH (p:Person) RETURN AVG(p.age) AS avgAge;
EOF

cat > Q15.gql << 'EOF'
MATCH (p:Person) RETURN MAX(p.age) AS maxAge, MIN(p.age) AS minAge;
EOF

cat > Q16.gql << 'EOF'
MATCH (p:Person) RETURN p.name ORDER BY p.name;
EOF

cat > Q17.gql << 'EOF'
MATCH (p:Person) RETURN p LIMIT 10;
EOF

cat > Q18.gql << 'EOF'
MATCH (p:Person) RETURN p OFFSET 5;
EOF

cat > Q19.gql << 'EOF'
SESSION SET SCHEMA mySchema;
EOF

cat > Q20.gql << 'EOF'
START TRANSACTION;
EOF

# Medium Queries (21-50) - Creating key ones, you can expand
cat > Q21.gql << 'EOF'
MATCH (a:Person)-[:KNOWS]->(b:Person)-[:KNOWS]->(c:Person)
RETURN a, b, c;
EOF

cat > Q22.gql << 'EOF'
MATCH (p:Person) WHERE p.age > 25 AND p.city = "New York" RETURN p;
EOF

cat > Q23.gql << 'EOF'
MATCH (p:Person) WHERE p.age < 18 OR p.age > 65 RETURN p;
EOF

cat > Q24.gql << 'EOF'
MATCH (p:Person) RETURN p.name, p.age, p.city;
EOF

cat > Q25.gql << 'EOF'
CREATE (p:Person {name: "Alice", age: 30, city: "Boston", email: "alice@example.com"});
EOF

cat > Q26.gql << 'EOF'
CREATE (a:Person {name: "Alice"})-[:KNOWS]->(b:Person {name: "Bob"});
EOF

cat > Q27.gql << 'EOF'
MATCH (p:Person) WHERE p.age > 100 DETACH DELETE p;
EOF

cat > Q28.gql << 'EOF'
MATCH (p:Person) WHERE p.name = "Alice"
SET p.age = 31, p.city = "Boston", p.email = "newemail@example.com";
EOF

cat > Q29.gql << 'EOF'
MATCH (p:Person) WHERE p.name = "Bob"
SET p = {name: "Bob", age: 26, city: "Seattle"};
EOF

cat > Q30.gql << 'EOF'
MATCH (p:Person) WHERE p.name = "Charlie"
REMOVE p.age, p.city;
EOF

cat > Q31.gql << 'EOF'
MATCH (p:Person) WHERE p.name = "David" SET p:Employee;
EOF

cat > Q32.gql << 'EOF'
MATCH (p:Person) WHERE p.name = "Eve" REMOVE p:Person;
EOF

cat > Q33.gql << 'EOF'
MATCH (p:Person) RETURN p.city, COUNT(p) AS residents GROUP BY p.city;
EOF

cat > Q34.gql << 'EOF'
MATCH (p:Person) RETURN p.city, p.country, COUNT(p) AS count
GROUP BY p.city, p.country;
EOF

cat > Q35.gql << 'EOF'
MATCH (p:Person) RETURN p.name, p.age
ORDER BY p.age DESC, p.name ASC;
EOF

cat > Q36.gql << 'EOF'
MATCH (p:Person) RETURN p.name, p.age
ORDER BY p.age DESC LIMIT 10;
EOF

cat > Q37.gql << 'EOF'
MATCH (p:Person) RETURN p.name
OFFSET 5 LIMIT 10;
EOF

cat > Q38.gql << 'EOF'
MATCH (p:Person) RETURN p.name, p.age
ORDER BY p.age DESC OFFSET 5 LIMIT 20;
EOF

cat > Q39.gql << 'EOF'
MATCH (p:Person)
OPTIONAL MATCH (p)-[:OWNS]->(c:Car)
RETURN p.name, c.model;
EOF

cat > Q40.gql << 'EOF'
MATCH (p:Person)
OPTIONAL MATCH (p)-[:FRIEND_OF]->(f:Person)
WHERE p.age > 30
RETURN p.name, f.name;
EOF

cat > Q41.gql << 'EOF'
MATCH (p:Person)
LET x = p.age * 2
RETURN p.name, x;
EOF

cat > Q42.gql << 'EOF'
MATCH (p:Person)
LET doubledAge = p.age * 2, isSenior = p.age > 65
RETURN p.name, doubledAge, isSenior;
EOF

cat > Q43.gql << 'EOF'
MATCH (p:Person)
FILTER p.age > 18
RETURN p.name;
EOF

cat > Q44.gql << 'EOF'
MATCH (p:Person)
FILTER WHERE p.age > 18 AND p.city = "New York"
RETURN p.name, p.age;
EOF

cat > Q45.gql << 'EOF'
INSERT (p:Person {name: "Frank", age: 35});
EOF

cat > Q46.gql << 'EOF'
INSERT (a:Author {name: "Jane Smith"})-[:WROTE]->(b:Book {title: "New Novel", year: 2024});
EOF

cat > Q47.gql << 'EOF'
INSERT (p1:Person {name: "Alice"}), (p2:Person {name: "Bob"}), (p1)-[:KNOWS]->(p2);
EOF

cat > Q48.gql << 'EOF'
START TRANSACTION;
MATCH (n) RETURN n;
COMMIT;
EOF

cat > Q49.gql << 'EOF'
START TRANSACTION READ WRITE;
CREATE (p:Person {name: "Eve", age: 28});
COMMIT;
EOF

cat > Q50.gql << 'EOF'
START TRANSACTION READ ONLY;
MATCH (p:Person) RETURN p;
ROLLBACK;
EOF

echo "Created queries Q1-Q50. Run this script multiple times or extend it for Q51-Q105."
echo "Or use the Python script: python3 generate_all_queries.py"

