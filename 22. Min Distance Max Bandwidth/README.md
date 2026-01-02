# Min Distance Max Bandwidth - Shortest Path with Maximum Bandwidth

## Problem Description

Given an undirected graph where each edge has both a **distance** and a **bandwidth**, the goal is to find the shortest path (by total distance) between two vertices. If there are multiple shortest paths, select the one with the **maximum minimum bandwidth** along the path—that is, the path where the smallest bandwidth edge is as large as possible.

## Input Format

- First line: `n m`  
  Number of vertices `n` (1 ≤ n ≤ 10⁵) and edges `m` (1 ≤ m ≤ 10⁵).
- Next `m` lines: `u v d b`  
  Edge from vertex `u` to vertex `v` (0 ≤ u, v ≤ n), with distance `d` (1 ≤ d ≤ 10⁹) and bandwidth `b` (1 ≤ b ≤ 10⁹).
- Last line: `s t`  
  Source vertex `s` and target vertex `t`.

## Output Format

Print two space-separated integers:

1. The **total distance** of the shortest path from `s` to `t`.
2. The **maximum possible minimum bandwidth** along that shortest path.

If no path exists, output `-1 -1`.

## Solution Approach

The solution uses a **modified Dijkstra's algorithm** with two optimization criteria:

1. **Minimize total distance**.
2. Among paths with equal distance, **maximize the minimum bandwidth**.

### Example

**Input:**

```
5 6
0 1 2 5
0 2 2 3
1 3 2 4
2 3 2 6
3 4 1 2
2 4 6 10
0 4
```

**Output:**

```
5 2
```

## Complexity

- **Time:** O((n + m) log n) due to heap operations.
- **Space:** O(n + m) for graph and auxiliary arrays.
