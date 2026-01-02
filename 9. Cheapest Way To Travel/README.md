# Cheapest Way Travel - Pathfinder

## Problem Description

Given an `N x M` grid where each cell contains a non-negative cost, find the cheapest path from the top-left corner to the bottom-right corner. The agent can only move **right** or **down** at each step.

### Input Format

- First line: `N M` (1 ≤ N, M ≤ 10⁸ in theory, but practical memory limits apply)
- Next `N` lines: `M` integers each, representing cell costs (0 ≤ cost ≤ 10⁹)

### Output Format

- First line: Minimum total cost to reach the destination
- Second line: Space-separated costs of cells visited along the optimal path (in order from start to end)

## Solution Approach

This implementation uses **dynamic programming** to find the minimum cost path:

1. **DP State**: `best[r][c]` stores the minimum cost to reach cell `(r, c)`
2. **Transition**:
   - `best[r][c] = mat[r][c] + min(best[r-1][c], best[r][c-1])`
   - Tracks previous cell to reconstruct the path
3. **Path Reconstruction**: Backtracks from `(N-1, M-1)` to `(0, 0)` using stored parent pointers

## Complexity Analysis

- **Time**: O(N × M)
- **Space**: O(N × M) for storing the grid and DP tables
- **Note**: For very large grids (N, M up to 10⁸), this approach is not memory-efficient and would require optimization.

## Example

**Input:**

```
4 3
2 1 3
1 5 1
4 2 1
2 1 2
```

**Output:**

```
8
2 1 1 1 2 1
```
