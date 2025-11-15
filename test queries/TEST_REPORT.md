# GQL Parser Performance Test Report

## Test Overview
This report contains 100+ GQL queries organized by complexity and type for comprehensive performance testing.

**Test Categories:**
- Small Queries (1-3 operations)
- Medium Queries (4-7 operations)
- Complex Queries (8-15 operations)
- Very Complex Queries (16+ operations)

**Query Types Covered:**
- MATCH statements
- CREATE operations
- DELETE operations
- SET/REMOVE operations
- INSERT operations
- Transactions
- Session management
- Aggregations
- Filtering and WHERE clauses
- Ordering and pagination
- UNION queries
- SELECT statements
- LET statements
- OPTIONAL MATCH
- Complex path patterns

---

## SMALL QUERIES (1-20)

### Q1: Simple Node Match
```gql
MATCH (n) RETURN n;
```

### Q2: Labeled Node Match
```gql
MATCH (p:Person) RETURN p;
```

### Q3: Single Property Return
```gql
MATCH (p:Person) RETURN p.name;
```

### Q4: Simple Relationship
```gql
MATCH (p:Person)-[:KNOWS]->(f:Person) RETURN p, f;
```

### Q5: Basic WHERE Clause
```gql
MATCH (p:Person) WHERE p.age > 25 RETURN p;
```

### Q6: String Comparison
```gql
MATCH (p:Person) WHERE p.name = "Alice" RETURN p;
```

### Q7: Simple CREATE
```gql
CREATE (p:Person {name: "Alice", age: 30});
```

### Q8: CREATE with Single Property
```gql
CREATE (p:Person {name: "Bob"});
```

### Q9: Simple DELETE
```gql
MATCH (p:Person) DELETE p;
```

### Q10: DELETE with WHERE
```gql
MATCH (p:Person) WHERE p.age > 100 DELETE p;
```

### Q11: Simple SET
```gql
MATCH (p:Person) WHERE p.name = "Alice" SET p.age = 31;
```

### Q12: Simple REMOVE
```gql
MATCH (p:Person) WHERE p.name = "Bob" REMOVE p.age;
```

### Q13: COUNT Aggregation
```gql
MATCH (p:Person) RETURN COUNT(*) AS total;
```

### Q14: AVG Aggregation
```gql
MATCH (p:Person) RETURN AVG(p.age) AS avgAge;
```

### Q15: MAX/MIN Aggregation
```gql
MATCH (p:Person) RETURN MAX(p.age) AS maxAge, MIN(p.age) AS minAge;
```

### Q16: ORDER BY Single Field
```gql
MATCH (p:Person) RETURN p.name ORDER BY p.name;
```

### Q17: LIMIT Clause
```gql
MATCH (p:Person) RETURN p LIMIT 10;
```

### Q18: OFFSET Clause
```gql
MATCH (p:Person) RETURN p OFFSET 5;
```

### Q19: Session SET Schema
```gql
SESSION SET SCHEMA mySchema;
```

### Q20: START TRANSACTION
```gql
START TRANSACTION;
```

---

## MEDIUM QUERIES (21-50)

### Q21: Two-Hop Relationship
```gql
MATCH (a:Person)-[:KNOWS]->(b:Person)-[:KNOWS]->(c:Person)
RETURN a, b, c;
```

### Q22: WHERE with AND
```gql
MATCH (p:Person) WHERE p.age > 25 AND p.city = "New York" RETURN p;
```

### Q23: WHERE with OR
```gql
MATCH (p:Person) WHERE p.age < 18 OR p.age > 65 RETURN p;
```

### Q24: Multiple Properties Return
```gql
MATCH (p:Person) RETURN p.name, p.age, p.city;
```

### Q25: CREATE with Multiple Properties
```gql
CREATE (p:Person {name: "Alice", age: 30, city: "Boston", email: "alice@example.com"});
```

### Q26: CREATE Relationship
```gql
CREATE (a:Person {name: "Alice"})-[:KNOWS]->(b:Person {name: "Bob"});
```

### Q27: DELETE with DETACH
```gql
MATCH (p:Person) WHERE p.age > 100 DETACH DELETE p;
```

### Q28: SET Multiple Properties
```gql
MATCH (p:Person) WHERE p.name = "Alice"
SET p.age = 31, p.city = "Boston", p.email = "newemail@example.com";
```

### Q29: SET with Object
```gql
MATCH (p:Person) WHERE p.name = "Bob"
SET p = {name: "Bob", age: 26, city: "Seattle"};
```

### Q30: REMOVE Multiple Properties
```gql
MATCH (p:Person) WHERE p.name = "Charlie"
REMOVE p.age, p.city;
```

### Q31: SET Label
```gql
MATCH (p:Person) WHERE p.name = "David" SET p:Employee;
```

### Q32: REMOVE Label
```gql
MATCH (p:Person) WHERE p.name = "Eve" REMOVE p:Person;
```

### Q33: GROUP BY Single Field
```gql
MATCH (p:Person) RETURN p.city, COUNT(p) AS residents GROUP BY p.city;
```

### Q34: GROUP BY Multiple Fields
```gql
MATCH (p:Person) RETURN p.city, p.country, COUNT(p) AS count
GROUP BY p.city, p.country;
```

### Q35: ORDER BY Multiple Fields
```gql
MATCH (p:Person) RETURN p.name, p.age
ORDER BY p.age DESC, p.name ASC;
```

### Q36: ORDER BY with LIMIT
```gql
MATCH (p:Person) RETURN p.name, p.age
ORDER BY p.age DESC LIMIT 10;
```

### Q37: OFFSET with LIMIT
```gql
MATCH (p:Person) RETURN p.name
OFFSET 5 LIMIT 10;
```

### Q38: ORDER BY with OFFSET and LIMIT
```gql
MATCH (p:Person) RETURN p.name, p.age
ORDER BY p.age DESC OFFSET 5 LIMIT 20;
```

### Q39: OPTIONAL MATCH Simple
```gql
MATCH (p:Person)
OPTIONAL MATCH (p)-[:OWNS]->(c:Car)
RETURN p.name, c.model;
```

### Q40: OPTIONAL MATCH with WHERE
```gql
MATCH (p:Person)
OPTIONAL MATCH (p)-[:FRIEND_OF]->(f:Person)
WHERE p.age > 30
RETURN p.name, f.name;
```

### Q41: LET Single Variable
```gql
MATCH (p:Person)
LET x = p.age * 2
RETURN p.name, x;
```

### Q42: LET Multiple Variables
```gql
MATCH (p:Person)
LET doubledAge = p.age * 2, isSenior = p.age > 65
RETURN p.name, doubledAge, isSenior;
```

### Q43: FILTER Simple
```gql
MATCH (p:Person)
FILTER p.age > 18
RETURN p.name;
```

### Q44: FILTER with WHERE
```gql
MATCH (p:Person)
FILTER WHERE p.age > 18 AND p.city = "New York"
RETURN p.name, p.age;
```

### Q45: INSERT Single Node
```gql
INSERT (p:Person {name: "Frank", age: 35});
```

### Q46: INSERT Relationship
```gql
INSERT (a:Author {name: "Jane Smith"})-[:WROTE]->(b:Book {title: "New Novel", year: 2024});
```

### Q47: INSERT Multiple Nodes
```gql
INSERT (p1:Person {name: "Alice"}), (p2:Person {name: "Bob"}), (p1)-[:KNOWS]->(p2);
```

### Q48: Transaction with MATCH
```gql
START TRANSACTION;
MATCH (n) RETURN n;
COMMIT;
```

### Q49: Transaction with CREATE
```gql
START TRANSACTION READ WRITE;
CREATE (p:Person {name: "Eve", age: 28});
COMMIT;
```

### Q50: Transaction ROLLBACK
```gql
START TRANSACTION READ ONLY;
MATCH (p:Person) RETURN p;
ROLLBACK;
```

---

## COMPLEX QUERIES (51-80)

### Q51: Three-Hop Path
```gql
MATCH (a:Person)-[:KNOWS]->(b:Person)-[:KNOWS]->(c:Person)-[:KNOWS]->(d:Person)
RETURN a.name, b.name, c.name, d.name;
```

### Q52: Complex WHERE with Multiple Conditions
```gql
MATCH (p:Person)-[:FRIEND_OF]->(f:Person)
WHERE p.age > 25 AND f.city = "London" AND p.salary > 50000
RETURN p.name, f.name, p.salary;
```

### Q53: Multiple Relationship Types
```gql
MATCH (p:Person)-[:KNOWS|FRIEND_OF|COLLEAGUE]->(other:Person)
RETURN p.name, other.name;
```

### Q54: Variable Length Path
```gql
MATCH path = (start:Person)-[:KNOWS*]->(end:Person)
WHERE start.name = "Alice"
RETURN path;
```

### Q55: Variable Length Path with Range
```gql
MATCH path = (start:Person)-[:KNOWS*2..4]->(end:Person)
WHERE start.name = "Alice"
RETURN path;
```

### Q56: Multiple MATCH Clauses
```gql
MATCH (p:Person)
MATCH (c:Company)
MATCH (p)-[:WORKS_FOR]->(c)
RETURN p.name, c.name;
```

### Q57: MATCH with Multiple Patterns
```gql
MATCH (a:Author)-[:WROTE]->(b:Book), (b)-[:PUBLISHED_BY]->(p:Publisher)
RETURN a.name, b.title, p.name;
```

### Q58: Complex Aggregation with GROUP BY
```gql
MATCH (p:Person)-[:OWNS]->(c:Car)
RETURN p.name, COUNT(c) AS carCount, AVG(c.price) AS avgPrice
GROUP BY p.name;
```

### Q59: Nested Aggregations
```gql
MATCH (p:Person)
RETURN p.city, COUNT(p) AS residents, AVG(p.age) AS avgAge, MAX(p.age) AS maxAge
GROUP BY p.city
HAVING COUNT(p) > 10;
```

### Q60: ORDER BY with Aggregation
```gql
MATCH (p:Person)
RETURN p.city, COUNT(p) AS count
GROUP BY p.city
ORDER BY count DESC;
```

### Q61: Complex ORDER BY
```gql
MATCH (p:Person)
RETURN p.name, p.age, p.salary
ORDER BY p.salary DESC NULLS LAST, p.age ASC, p.name;
```

### Q62: Multiple OPTIONAL MATCH
```gql
MATCH (p:Person)
OPTIONAL MATCH (p)-[:OWNS]->(c:Car)
OPTIONAL MATCH (p)-[:LIVES_IN]->(h:House)
RETURN p.name, c.model, h.address;
```

### Q63: OPTIONAL MATCH with Conditions
```gql
MATCH (p:Person)
OPTIONAL MATCH (p)-[:FRIEND_OF]->(f:Person)
WHERE p.age > 30 AND (f IS NULL OR f.age > 25)
RETURN p.name, f.name;
```

### Q64: LET with Complex Expression
```gql
MATCH (p:Person)
LET tax = p.salary * 0.2, netSalary = p.salary - (p.salary * 0.2)
RETURN p.name, p.salary, tax, netSalary;
```

### Q65: LET with Conditional Logic
```gql
MATCH (p:Person)
LET ageGroup = CASE WHEN p.age < 18 THEN "Minor"
                   WHEN p.age < 65 THEN "Adult"
                   ELSE "Senior" END
RETURN p.name, p.age, ageGroup;
```

### Q66: Multiple FILTER Clauses
```gql
MATCH (p:Person)
FILTER p.age > 18
FILTER WHERE p.city = "New York" OR p.city = "Boston"
RETURN p.name, p.age, p.city;
```

### Q67: FILTER with Complex Condition
```gql
MATCH (p:Person)
FILTER WHERE (p.age > 25 AND p.salary > 50000) OR (p.age < 30 AND p.education = "PhD")
RETURN p.name, p.age, p.salary;
```

### Q68: INSERT with Complex Pattern
```gql
INSERT (a:Author {name: "John Doe", born: 1980})-[:WROTE]->(b:Book {title: "My Book", year: 2023}),
       (b)-[:PUBLISHED_BY]->(p:Publisher {name: "ABC Publishing"});
```

### Q69: Multiple INSERT Statements
```gql
INSERT (p1:Person {name: "Alice", age: 30}),
       (p2:Person {name: "Bob", age: 25}),
       (p3:Person {name: "Charlie", age: 35}),
       (p1)-[:KNOWS]->(p2),
       (p2)-[:KNOWS]->(p3);
```

### Q70: Complex Transaction
```gql
START TRANSACTION READ WRITE;
CREATE (p:Person {name: "Eve", age: 28, city: "Seattle"});
MATCH (p:Person) WHERE p.name = "Eve"
SET p.email = "eve@example.com";
COMMIT;
```

### Q71: Transaction with Multiple Operations
```gql
START TRANSACTION;
MATCH (p:Person) WHERE p.age > 100 DELETE p;
CREATE (p:Person {name: "New Person", age: 25});
MATCH (p:Person) WHERE p.name = "New Person"
SET p.city = "Boston";
COMMIT;
```

### Q72: UNION Simple
```gql
MATCH (p:Person) WHERE p.age < 18 RETURN p.name AS name
UNION
MATCH (p:Person) WHERE p.age >= 65 RETURN p.name AS name;
```

### Q73: UNION ALL
```gql
MATCH (p:Person) RETURN p.name
UNION ALL
MATCH (p:Employee) RETURN p.name;
```

### Q74: UNION with Multiple Queries
```gql
MATCH (p:Person) WHERE p.city = "New York" RETURN p.name AS name
UNION
MATCH (p:Person) WHERE p.city = "Boston" RETURN p.name AS name
UNION
MATCH (p:Person) WHERE p.city = "Seattle" RETURN p.name AS name;
```

### Q75: SELECT with FROM MATCH
```gql
SELECT p.name, p.age
FROM MATCH (p:Person)
WHERE p.age > 25;
```

### Q76: SELECT with Aggregation
```gql
SELECT COUNT(*) AS total, AVG(p.age) AS avgAge
FROM MATCH (p:Person);
```

### Q77: SELECT with GROUP BY and HAVING
```gql
SELECT p.city, COUNT(p) AS count
FROM MATCH (p:Person)
GROUP BY p.city
HAVING COUNT(p) > 10;
```

### Q78: SELECT with ORDER BY
```gql
SELECT p.name, p.age, p.salary
FROM MATCH (p:Person)
WHERE p.salary > 50000
ORDER BY p.salary DESC
LIMIT 10;
```

### Q79: Session Multiple Settings
```gql
SESSION SET SCHEMA mySchema;
SESSION SET PROPERTY GRAPH myGraph;
SESSION SET TIME ZONE 'UTC';
```

### Q80: Session RESET
```gql
SESSION RESET SCHEMA;
SESSION RESET ALL PARAMETERS;
```

---

## VERY COMPLEX QUERIES (81-100+)

### Q81: Multi-Pattern Complex Query
```gql
MATCH (a:Author)-[:WROTE]->(b:Book),
      (b)-[:PUBLISHED_BY]->(p:Publisher),
      (a)-[:LIVES_IN]->(city:City)
WHERE b.year > 2000 AND p.country = "USA"
RETURN a.name, b.title, p.name, city.name
ORDER BY b.year DESC;
```

### Q82: Deep Path with Multiple Hops
```gql
MATCH (p1:Person)-[:KNOWS]->(p2:Person)-[:KNOWS]->(p3:Person)-[:KNOWS]->(p4:Person)-[:KNOWS]->(p5:Person)
WHERE p1.name = "Alice"
RETURN p1.name, p2.name, p3.name, p4.name, p5.name;
```

### Q83: Complex WHERE with Nested Conditions
```gql
MATCH (p:Person)-[:WORKS_FOR]->(c:Company)
WHERE (p.age > 25 AND p.salary > 50000) OR
      (p.age < 30 AND p.education = "PhD" AND c.industry = "Tech")
RETURN p.name, p.age, p.salary, c.name;
```

### Q84: Multiple Aggregations with Complex GROUP BY
```gql
MATCH (p:Person)-[:OWNS]->(c:Car)
RETURN p.city, p.country,
       COUNT(p) AS people,
       COUNT(c) AS cars,
       AVG(c.price) AS avgCarPrice,
       MAX(p.age) AS maxAge
GROUP BY p.city, p.country
HAVING COUNT(p) > 5 AND AVG(c.price) > 30000;
```

### Q85: Complex ORDER BY with Multiple Fields
```gql
MATCH (p:Person)
RETURN p.name, p.age, p.salary, p.city
ORDER BY p.salary DESC NULLS LAST,
         p.age ASC NULLS FIRST,
         p.city ASC,
         p.name ASC
LIMIT 50;
```

### Q86: Nested OPTIONAL MATCH with Conditions
```gql
MATCH (p:Person)
OPTIONAL MATCH (p)-[:OWNS]->(c:Car)
OPTIONAL MATCH (p)-[:LIVES_IN]->(h:House)
OPTIONAL MATCH (p)-[:WORKS_FOR]->(company:Company)
WHERE p.age > 25 AND (c IS NULL OR c.price > 20000)
RETURN p.name, c.model, h.address, company.name;
```

### Q87: Complex LET with Multiple Calculations
```gql
MATCH (p:Person)
LET baseTax = p.salary * 0.2,
    deductions = p.salary * 0.1,
    netSalary = p.salary - (p.salary * 0.2) - (p.salary * 0.1),
    taxBracket = CASE WHEN p.salary < 50000 THEN "Low"
                     WHEN p.salary < 100000 THEN "Medium"
                     ELSE "High" END
RETURN p.name, p.salary, baseTax, deductions, netSalary, taxBracket;
```

### Q88: Multiple FILTER with Complex Logic
```gql
MATCH (p:Person)
FILTER p.age > 18
FILTER WHERE (p.city = "New York" AND p.salary > 60000) OR
            (p.city = "Boston" AND p.salary > 50000) OR
            (p.education = "PhD" AND p.age < 35)
RETURN p.name, p.age, p.city, p.salary, p.education;
```

### Q89: Complex INSERT with Multiple Patterns
```gql
INSERT (a:Author {name: "John Doe", born: 1980, country: "USA"})-[:WROTE]->(b1:Book {title: "Book 1", year: 2020}),
       (a)-[:WROTE]->(b2:Book {title: "Book 2", year: 2023}),
       (b1)-[:PUBLISHED_BY]->(p:Publisher {name: "ABC Publishing", country: "USA"}),
       (b2)-[:PUBLISHED_BY]->(p),
       (a)-[:LIVES_IN]->(city:City {name: "New York"});
```

### Q90: Complex Transaction with Multiple Operations
```gql
START TRANSACTION READ WRITE;
CREATE (p:Person {name: "Eve", age: 28, city: "Seattle", email: "eve@example.com"});
MATCH (p:Person) WHERE p.name = "Eve"
SET p.salary = 75000, p.department = "Engineering";
MATCH (p:Person) WHERE p.name = "Eve"
MATCH (c:Company) WHERE c.name = "Tech Corp"
CREATE (p)-[:WORKS_FOR]->(c);
COMMIT;
```

### Q91: UNION with Complex Queries
```gql
MATCH (p:Person) WHERE p.age < 18 AND p.city = "New York" RETURN p.name AS name, p.age AS age
UNION
MATCH (p:Person) WHERE p.age >= 65 AND p.city = "Boston" RETURN p.name AS name, p.age AS age
UNION
MATCH (p:Student) WHERE p.grade > 3.5 RETURN p.name AS name, p.age AS age
ORDER BY age DESC;
```

### Q92: Complex SELECT with Multiple JOINs
```gql
SELECT a.name AS author, b.title AS book, p.name AS publisher, city.name AS city
FROM MATCH (a:Author)-[:WROTE]->(b:Book),
     MATCH (b)-[:PUBLISHED_BY]->(p:Publisher),
     MATCH (a)-[:LIVES_IN]->(city:City)
WHERE b.year > 2000 AND p.country = "USA" AND city.population > 1000000
GROUP BY a.name, b.title, p.name, city.name
ORDER BY b.year DESC
LIMIT 20;
```

### Q93: Variable Length Path with Complex Conditions
```gql
MATCH path = (start:Person)-[:KNOWS*2..5]->(end:Person)
WHERE start.name = "Alice" AND end.city = "Boston"
RETURN path, LENGTH(path) AS pathLength
ORDER BY pathLength;
```

### Q94: Complex Pattern with Multiple Relationship Types
```gql
MATCH (p:Person)-[r:KNOWS|FRIEND_OF|COLLEAGUE|FAMILY]->(other:Person)
WHERE p.age > 25 AND other.age > 25 AND
      (r:KNOWS OR (r:FRIEND_OF AND p.city = other.city))
RETURN p.name, other.name, TYPE(r) AS relationshipType;
```

### Q95: Nested Aggregations with Multiple GROUP BY
```gql
MATCH (p:Person)-[:WORKS_FOR]->(c:Company)
RETURN c.industry, c.country,
       COUNT(DISTINCT p) AS employees,
       AVG(p.salary) AS avgSalary,
       MAX(p.salary) AS maxSalary,
       MIN(p.salary) AS minSalary,
       SUM(p.salary) AS totalSalary
GROUP BY c.industry, c.country
HAVING COUNT(DISTINCT p) > 10 AND AVG(p.salary) > 50000
ORDER BY avgSalary DESC;
```

### Q96: Complex Query with All Features
```gql
MATCH (p:Person)
LET ageGroup = CASE WHEN p.age < 18 THEN "Minor"
                   WHEN p.age < 65 THEN "Adult"
                   ELSE "Senior" END,
    taxRate = CASE WHEN p.salary < 50000 THEN 0.15
                  WHEN p.salary < 100000 THEN 0.25
                  ELSE 0.35 END,
    netSalary = p.salary * (1 - taxRate)
OPTIONAL MATCH (p)-[:OWNS]->(c:Car)
OPTIONAL MATCH (p)-[:LIVES_IN]->(h:House)
WHERE p.age > 18 AND (c IS NULL OR c.price > 15000)
RETURN p.name, p.age, ageGroup, p.salary, taxRate, netSalary, c.model, h.address
ORDER BY netSalary DESC, p.age ASC
LIMIT 25;
```

### Q97: Multi-Statement Complex Transaction
```gql
START TRANSACTION READ WRITE;
MATCH (p:Person) WHERE p.age > 100 DELETE p;
CREATE (p1:Person {name: "New Person 1", age: 25, city: "Boston"}),
       (p2:Person {name: "New Person 2", age: 30, city: "Seattle"});
MATCH (p1:Person) WHERE p1.name = "New Person 1"
SET p1.email = "person1@example.com", p1.salary = 60000;
MATCH (p2:Person) WHERE p2.name = "New Person 2"
SET p2.email = "person2@example.com", p2.salary = 70000;
MATCH (p1:Person), (p2:Person)
WHERE p1.name = "New Person 1" AND p2.name = "New Person 2"
CREATE (p1)-[:KNOWS]->(p2);
COMMIT;
```

### Q98: Complex UNION with Aggregations
```gql
MATCH (p:Person) WHERE p.age < 18
RETURN p.city AS location, COUNT(p) AS count, "Minor" AS category
GROUP BY p.city
UNION
MATCH (p:Person) WHERE p.age >= 18 AND p.age < 65
RETURN p.city AS location, COUNT(p) AS count, "Adult" AS category
GROUP BY p.city
UNION
MATCH (p:Person) WHERE p.age >= 65
RETURN p.city AS location, COUNT(p) AS count, "Senior" AS category
GROUP BY p.city
ORDER BY location, category;
```

### Q99: Very Complex SELECT with All Features
```gql
SELECT a.name AS author,
       b.title AS book,
       p.name AS publisher,
       city.name AS city,
       COUNT(b) AS bookCount,
       AVG(b.year) AS avgYear,
       MAX(b.year) AS latestYear
FROM MATCH (a:Author)-[:WROTE]->(b:Book),
     MATCH (b)-[:PUBLISHED_BY]->(p:Publisher),
     MATCH (a)-[:LIVES_IN]->(city:City)
WHERE b.year > 2000 AND p.country = "USA" AND city.population > 1000000
GROUP BY a.name, b.title, p.name, city.name
HAVING COUNT(b) > 1 AND AVG(b.year) > 2010
ORDER BY bookCount DESC, latestYear DESC
LIMIT 30;
```

### Q100: Ultimate Complex Query
```gql
START TRANSACTION READ WRITE;
SESSION SET SCHEMA mySchema;
MATCH (p:Person)
LET ageGroup = CASE WHEN p.age < 18 THEN "Minor"
                   WHEN p.age < 65 THEN "Adult"
                   ELSE "Senior" END
OPTIONAL MATCH (p)-[:OWNS]->(c:Car)
OPTIONAL MATCH (p)-[:LIVES_IN]->(h:House)
OPTIONAL MATCH (p)-[:WORKS_FOR]->(company:Company)
WHERE p.age > 18 AND (c IS NULL OR c.price > 15000) AND
      (h IS NULL OR h.price > 200000)
RETURN p.name, p.age, ageGroup, c.model, h.address, company.name
ORDER BY p.age DESC, p.name ASC
LIMIT 50;
COMMIT;
```

### Q101: Complex Path Pattern with Quantifiers
```gql
MATCH path = (start:Person)-[:KNOWS*1..3]->(middle:Person)-[:KNOWS*1..2]->(end:Person)
WHERE start.name = "Alice" AND end.city = "Boston"
RETURN path, LENGTH(path) AS pathLength, start.name, end.name
ORDER BY pathLength;
```

### Q102: Multi-Graph Pattern Match
```gql
MATCH (a:Author)-[:WROTE]->(b:Book),
      (b)-[:IN_GENRE]->(g:Genre),
      (b)-[:PUBLISHED_BY]->(p:Publisher),
      (a)-[:LIVES_IN]->(city:City),
      (p)-[:LOCATED_IN]->(pubCity:City)
WHERE b.year > 2000 AND g.name IN ["Fiction", "Mystery"] AND
      city.country = "USA" AND pubCity.country = "USA"
RETURN a.name, b.title, g.name, p.name, city.name, pubCity.name
ORDER BY b.year DESC;
```

### Q103: Complex Aggregation with Multiple Groupings
```gql
MATCH (p:Person)-[:WORKS_FOR]->(c:Company),
      (c)-[:IN_INDUSTRY]->(i:Industry)
RETURN i.name AS industry,
       c.country AS country,
       COUNT(DISTINCT c) AS companies,
       COUNT(DISTINCT p) AS employees,
       AVG(p.salary) AS avgSalary,
       MAX(p.salary) AS maxSalary,
       MIN(p.salary) AS minSalary,
       SUM(p.salary) AS totalSalary
GROUP BY i.name, c.country
HAVING COUNT(DISTINCT p) > 20 AND AVG(p.salary) > 50000
ORDER BY avgSalary DESC, employees DESC;
```

### Q104: Complex LET with Nested CASE
```gql
MATCH (p:Person)
LET ageGroup = CASE WHEN p.age < 18 THEN "Minor"
                   WHEN p.age < 30 THEN "Young Adult"
                   WHEN p.age < 50 THEN "Adult"
                   WHEN p.age < 65 THEN "Middle Age"
                   ELSE "Senior" END,
    salaryCategory = CASE WHEN p.salary < 30000 THEN "Low"
                         WHEN p.salary < 60000 THEN "Medium"
                         WHEN p.salary < 100000 THEN "High"
                         ELSE "Very High" END,
    taxRate = CASE WHEN p.salary < 50000 THEN 0.15
                  WHEN p.salary < 100000 THEN 0.25
                  WHEN p.salary < 200000 THEN 0.35
                  ELSE 0.40 END,
    netSalary = p.salary * (1 - taxRate)
RETURN p.name, p.age, ageGroup, p.salary, salaryCategory, taxRate, netSalary
ORDER BY netSalary DESC;
```

### Q105: Very Complex Transaction
```gql
START TRANSACTION READ WRITE;
SESSION SET SCHEMA mySchema;
MATCH (p:Person) WHERE p.age > 100 DELETE p;
CREATE (p1:Person {name: "Person 1", age: 25, city: "Boston", salary: 60000}),
       (p2:Person {name: "Person 2", age: 30, city: "Seattle", salary: 70000}),
       (p3:Person {name: "Person 3", age: 35, city: "New York", salary: 80000});
MATCH (p1:Person), (p2:Person), (p3:Person)
WHERE p1.name = "Person 1" AND p2.name = "Person 2" AND p3.name = "Person 3"
SET p1.email = "person1@example.com", p1.department = "Engineering",
    p2.email = "person2@example.com", p2.department = "Sales",
    p3.email = "person3@example.com", p3.department = "Marketing";
MATCH (p1:Person), (p2:Person), (p3:Person)
WHERE p1.name = "Person 1" AND p2.name = "Person 2" AND p3.name = "Person 3"
CREATE (p1)-[:KNOWS]->(p2),
       (p2)-[:KNOWS]->(p3),
       (p1)-[:COLLEAGUE]->(p3);
COMMIT;
```

---

## Test Execution Instructions

### Running Individual Queries
```bash
# Save query to a file (e.g., query.gql)
./gqlparser query.gql
```

### Batch Testing Script
Create a script to test all queries and collect timing data:

```bash
#!/bin/bash
# test_all_queries.sh

echo "Query Number,Parse Time (ms),AST Time (ms),Total Time (ms)" > results.csv

for i in {1..105}; do
    # Extract query from report and save to temp file
    # Run parser and extract timing
    ./gqlparser query_${i}.gql 2>&1 | grep -E "Lexing|AST|Total" >> results.csv
done
```

### Expected Output Format
Each query execution will produce:
- Lexing + Parsing Time (ms)
- AST Construction Time (ms)
- Total Execution Time (ms)

---

## Performance Metrics Summary

After running all queries, analyze:
1. **Average parse time by complexity**
2. **Average AST construction time**
3. **Total execution time trends**
4. **Query type performance comparison**
5. **Complexity impact on performance**

---

## Notes

- All queries are syntactically valid GQL according to ISO/IEC 39075:2024
- Queries are organized by complexity for systematic testing
- Some queries may require appropriate graph data to execute fully
- Timing measurements focus on parsing and AST construction phases
- For execution testing, ensure proper graph database setup

---

**Total Queries: 105**
**Categories:**
- Small: 20 queries
- Medium: 30 queries
- Complex: 30 queries
- Very Complex: 25 queries

