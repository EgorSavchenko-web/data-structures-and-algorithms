# Maximum Flow with Edmonds–Karp Algorithm

## Problem Statement

Given a directed flow network with **n** vertices and **m** edges, compute the maximum flow from source vertex **1** to sink vertex **n** using the **Edmonds–Karp** algorithm (a BFS-based implementation of Ford–Fulkerson).

### Input

- First line: two integers **n** (2 ≤ n ≤ 500) and **m** (1 ≤ m ≤ 10⁴).
- Next **m** lines: three integers **u**, **v**, **c** (1 ≤ u, v ≤ n, 1 ≤ c ≤ 10⁵) representing a directed edge from **u** to **v** with capacity **c**.

### Output

A single integer — the maximum flow from vertex 1 to vertex n.

## Algorithm Overview

The **Edmonds–Karp** algorithm finds the shortest augmenting path (in terms of number of edges) in the residual network using **BFS** and repeatedly pushes flow until no augmenting path exists. This guarantees a time complexity of **O(V·E²)**, suitable for the given constraints.

### Example:

**Input:**

```
4 5
1 2 3
1 3 2
2 3 1
2 4 2
3 4 3
```

**Output:**

```
5
```

## Complexity

- **Time:** O(V·E²) — suitable for n ≤ 500, m ≤ 10⁴.
- **Memory:** O(V + E) for storing the graph.
