# Job Scheduling - Maximum Profit Problem

## Problem Description

You are given a list of `N` jobs where each job `i` starts at time `s_i`, finishes at time `f_i`, and yields a profit `p_i`. The goal is to find a subset of non-overlapping jobs that maximizes the total profit.

Two jobs `i` and `j` are considered overlapping if they satisfy `f_i < s_j` (jobs must be completely non-overlapping).

## Solution Approach

This C++ solution implements a dynamic programming approach to solve the weighted job scheduling problem:

1. **Sorting**: Jobs are sorted by their finish time in ascending order.
2. **Dynamic Programming**: A DP array `dp[i]` stores the maximum profit achievable considering the first `i+1` jobs.
3. **State Transition**: For each job `i`, we either:
   - Exclude it: `dp[i] = dp[i-1]`
   - Include it: `dp[i] = profit[i] + dp[prev]` where `prev` is the last non-overlapping job

### Time Complexity

- **O(n log n)** for sorting (using quicksort)
- **O(n²)** for DP computation (due to linear search for previous non-overlapping job)
- Overall: **O(n²)** in worst case

### Space Complexity

- **O(n)** for storing jobs and DP array

### Input Format

```
N
s1 s2 ... sN
f1 f2 ... fN
p1 p2 ... pN
```

### Example

**Input:**

```
5
1 4 6 3 7
4 6 7 5 8
3 5 4 2 10
```

**Output:**

```
22
```
