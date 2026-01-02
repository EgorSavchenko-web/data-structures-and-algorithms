# Augmenting Path Finder

## Problem Description

This program solves the **Augmenting Path** problem in flow networks. Given a directed flow network with vertices `1..n` and edges with capacities and current flows, the task is to find an **augmenting path** from the source vertex `1` to the sink vertex `n` in the **residual network** using **Breadth-First Search (BFS)**.

An augmenting path is a simple path (no repeated vertices) in the residual network where every edge has a positive residual capacity. The residual network is constructed as follows:

- For each original edge `(u, v)` with capacity `c` and flow `f`, if `c - f > 0`, a forward edge `(u, v)` with residual capacity `c - f` exists.
- If `f > 0`, a reverse edge `(v, u)` with residual capacity `f` exists.

### Input Format

- First line: `n m` (2 ≤ n ≤ 10⁵, 1 ≤ m ≤ 10⁵)
- Next `m` lines: `u v c f` (1 ≤ u, v ≤ n, 1 ≤ c ≤ 10⁹, 0 ≤ f ≤ c)

### Output Format

- If an augmenting path exists:
  - First line: `k b` (number of vertices in path, bottleneck capacity)
  - Second line: `v₁ v₂ ... vₖ` (vertices in the path from 1 to n)
- Otherwise: `NO PATH`

## Solution Approach

The program implements BFS on the residual graph to find the shortest augmenting path from source to sink. Key steps:

1. **Build Residual Graph**: For each edge, add forward and reverse edges if their residual capacities are positive.
2. **BFS Traversal**: Starting from vertex 1, explore neighbors, tracking:
   - `previous[]`: parent of each vertex in the BFS tree
   - `min_capacity[]`: minimum residual capacity along the path from source to each vertex
3. **Path Reconstruction**: If sink `n` is reached, backtrack using `previous[]` to construct the path.
4. **Output**: Print path length, bottleneck capacity, and the vertex sequence, or "NO PATH" if unreachable.

## Example

Input:

```
4 5
1 2 10 5
1 3 10 10
2 3 5 0
2 4 10 2
3 4 10 4
```

Output:

```
3 5
1 2 4
```
