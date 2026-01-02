# AVL Tree Implementation

## Overview

This C++ program implements a self-balancing AVL tree data structure that supports basic dictionary operations while maintaining balance through tree rotations. The implementation follows standard AVL tree properties where the height difference between left and right subtrees of any node is at most 1.

## Features

### Supported Operations

1. **ADD k v** - Insert a key-value pair into the tree

   - If the key already exists: outputs `"KEY ALREADY EXISTS"`
   - Performs necessary rotations to maintain AVL balance

2. **LOOKUP k** - Search for a key in the tree

   - If found: outputs the associated value
   - If not found: outputs `"KEY NOT FOUND"`

3. **DELETE k** - Remove a key from the tree

   - If key exists: removes the node and rebalances
   - If not found: outputs `"KEY NOT FOUND"`
   - Maintains AVL properties after deletion

4. **PRINT_ROTATIONS** - Outputs the total number of rotations performed since tree creation

### AVL Balancing

The implementation handles all four rotation cases:

- **Left-Left Case**: Single right rotation
- **Right-Right Case**: Single left rotation
- **Left-Right Case**: Left rotation on left child, then right rotation
- **Right-Left Case**: Right rotation on right child, then left rotation

## Input Format

The first line contains an integer `N` (1 ≤ N ≤ 10⁵) - the number of queries.

Each of the next `N` lines contains a query in one of the following formats:

- `ADD k v` where -100 ≤ k, v ≤ 100
- `LOOKUP k` where -100 ≤ k ≤ 100
- `DELETE k` where -100 ≤ k ≤ 100
- `PRINT_ROTATIONS`

## Output Format

For each query that requires output, print the result on a new line:

- `ADD`: Only outputs if key exists ("KEY ALREADY EXISTS")
- `LOOKUP`: Outputs value or "KEY NOT FOUND"
- `DELETE`: Only outputs if key not found ("KEY NOT FOUND")
- `PRINT_ROTATIONS`: Outputs the total rotation count

## Example

**Input:**

```
10
ADD 7 5
ADD 3 2
ADD 10 100
ADD 2 3
ADD 6 0
ADD 4 4
ADD 8 7
DELETE 7
PRINT_ROTATIONS
LOOKUP 8
```

**Output:**

```
4
7
```

### Time Complexities

- **ADD**: O(log n) average and worst-case
- **LOOKUP**: O(log n) average and worst-case
- **DELETE**: O(log n) average and worst-case
- **PRINT_ROTATIONS**: O(1)

### Space Complexity

- O(n) where n is the number of nodes in the tree
