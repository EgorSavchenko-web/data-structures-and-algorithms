# Connected Components using Disjoint Set Union (DSU)

## Problem Description

Given an undirected graph with **N** vertices (numbered from 1 to N) and **M** edges, the task is to determine the number of connected components in the graph using the **Disjoint Set Union (DSU)** data structure.

### Input Format

- The first line contains two integers **N** and **M** (1 ≤ N, M ≤ 10⁵) — the number of vertices and edges, respectively.
- The next M lines each contain two integers **u** and **v** (1 ≤ u, v ≤ N) — representing an undirected edge between vertex u and vertex v.

### Output Format

- Print a single integer — the number of connected components in the graph.

### Example

**Input:**

```
8 7
1 2
2 3
3 4
4 5
6 7
7 8
1 5
```

**Output:**

```
2
```

## Solution Overview

The solution implements the **Disjoint Set Union (Union-Find)** data structure with two optimizations:

- **Path Compression** in the `find` operation
- **Union by Size** in the `unite` operation

### Complexity

- **Time Complexity:** O(M·α(N)), where α(N) is the inverse Ackermann function (effectively constant).
- **Space Complexity:** O(N) for storing parent and size arrays.
