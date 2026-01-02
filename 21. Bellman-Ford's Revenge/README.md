# Bellman-Ford's Revenge Solution

## Problem Description

Given a directed weighted graph represented as an adjacency matrix, determine whether it contains a **negative weight cycle**. If such a cycle exists, output the cycle's vertices.

### Input Format

- First line: `N` (1 ≤ N ≤ 100) – number of vertices
- Next `N` lines: `N` integers each, forming an adjacency matrix
  - `w_ij` is the weight of edge from vertex `i` to vertex `j` (0-based indices in matrix)
  - `|w_ij| < 1000`
  - `0` means no edge between vertices `i` and `j`

### Output Format

1. `YES` if a negative cycle exists, otherwise `NO`
2. If `YES`: the number of vertices in the cycle (excluding the repeated start vertex)
3. If `YES`: the vertices of the cycle in order (starting vertex repeated only at the end implicitly)

## Algorithm

The solution implements the **Bellman-Ford algorithm** with cycle reconstruction:

1. **Graph Representation**: Store all edges from the adjacency matrix
2. **Distance Initialization**: Initialize all distances to 0 (treating all vertices as potential sources)
3. **Relaxation**: Perform N full relaxations over all edges
4. **Cycle Detection**: After N relaxations, perform one more relaxation. If any distance can still be improved, a negative cycle exists
5. **Cycle Reconstruction**: Trace back through parent pointers to find and output the cycle

## Example

### Input

```
2
0 -1
-1 0
```

### Output

```
YES
2
1 2
```

## Complexity

- **Time**: O(N³) where N ≤ 100 (N relaxations × N² edges)
- **Space**: O(N²) for edge storage
