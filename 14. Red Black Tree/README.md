# Red-Black Tree Implementation

## Problem Description

This C++ program implements a **Red-Black Tree** data structure that supports six operations as per the competitive programming problem statement. The Red-Black Tree is a self-balancing binary search tree that maintains balance through specific coloring rules and rotations.

## Operations Supported

The implementation supports the following operations:

1. **ADD k v** – Insert a key `k` with value `v` into the tree. If the key already exists, outputs `"KEY ALREADY EXISTS"`.
2. **LOOKUP k** – Search for key `k` and print its associated value. If not found, outputs `"KEY NOT FOUND"`.
3. **DELETE k** – Remove the node with key `k` from the tree. If not found, outputs `"KEY NOT FOUND"`.
4. **PRINT_ROTATIONS** – Print the total number of rotations performed since program start.
5. **PRINT_COUNT_BLACK_KEYS** – Print the current count of black nodes in the tree.
6. **PRINT_COUNT_RED_KEYS** – Print the current count of red nodes in the tree.

## Input Format

- First line: Integer `N` (1 ≤ N ≤ 10⁵) – number of queries
- Next `N` lines: One query per line in the format `OPERATION argument(s)`
  - Keys and values are integers in range [-100, 100]
  - Operations are case-sensitive

## Output Format

- For each query that requires output, print the result on a new line
- Some operations (like successful ADD) produce no output
- The output depends on the operation type

## Example

**Input:**

```
10
ADD 5 1
ADD 3 2
ADD 2 3
ADD 4 4
ADD 7 5
ADD 6 6
ADD 8 7
DELETE 7
PRINT_ROTATIONS
PRINT_COUNT_BLACK_KEYS
```

**Output:**

```
5
3
```

## ⚙️ Complexity Analysis

- **Time Complexity**:
  - ADD: O(log n)
  - LOOKUP: O(log n)
  - DELETE: O(log n)
  - Other operations: O(1)
- **Space Complexity**: O(n) for storing n nodes
