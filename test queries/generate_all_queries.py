#!/usr/bin/env python3
"""
Script to generate all 105 test query files from the TEST_REPORT.md
Extracts queries from the markdown report and creates individual .gql files
"""

import re
import os

def extract_queries_from_report(report_file):
    """Extract all queries from the TEST_REPORT.md file"""
    queries = {}
    
    with open(report_file, 'r') as f:
        content = f.read()
    
    # Pattern to match query blocks: ### Q##: Title followed by ```gql ... ```
    pattern = r'### (Q\d+):.*?\n```gql\n(.*?)\n```'
    
    matches = re.findall(pattern, content, re.DOTALL)
    
    for query_num, query_text in matches:
        # Clean up the query text
        query_text = query_text.strip()
        queries[query_num] = query_text
    
    return queries

def generate_query_files(queries, output_dir='.'):
    """Generate individual .gql files for each query"""
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    
    generated = 0
    for query_num, query_text in sorted(queries.items()):
        filename = os.path.join(output_dir, f"{query_num}.gql")
        with open(filename, 'w') as f:
            f.write(query_text)
            f.write('\n')
        generated += 1
        print(f"Generated {filename}")
    
    return generated

if __name__ == "__main__":
    report_file = "TEST_REPORT.md"
    
    if not os.path.exists(report_file):
        print(f"Error: {report_file} not found!")
        print("Please run this script from the 'test queries' directory")
        exit(1)
    
    print("Extracting queries from TEST_REPORT.md...")
    queries = extract_queries_from_report(report_file)
    
    print(f"\nFound {len(queries)} queries")
    print("Generating individual .gql files...")
    
    generated = generate_query_files(queries)
    
    print(f"\n✓ Successfully generated {generated} query files!")
    print("\nYou can now run: ./run_all_tests.sh")

