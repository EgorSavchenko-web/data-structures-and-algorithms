# K-ary Search Implementation

## Problem Description

This C++ program implements the **k-ary search algorithm** to find target elements in a sorted array. Given a sorted array `A` of size `N` and a parameter `K`, the program answers `M` queries, each looking for a target integer `x` in the array.

### Problem Statement

For each query, determine the **0-based index** of `x` in the array using the k-ary search algorithm. If `x` does not exist in the array, return `-1`.

### Search Algorithm

The k-ary search follows these steps:

1. If the array is empty, return `-1`.
2. If the array has only one element and `A[0] = x`, return the index. Otherwise, return `-1`.
3. Otherwise, divide the current search interval into `K` equal parts by selecting `K` midpoints evenly spaced across the interval.
4. Identify two consecutive midpoints `m_i` and `m_{i+1}` such that `A[m_i] < x < A[m_{i+1}]`.
5. Recursively apply the search algorithm on the subarray `A[m_i : m_{i+1}]`.

### Input Format

- First line: Two integers `N` and `K` where:
  - `3 < N < 10⁶`
  - `2 < K < 10`
- Second line: `N` space-separated integers `A₁, A₂, ..., Aₙ` where:
  - `-10⁹ < Aᵢ < 10⁹`
  - The array is **sorted**
- Third line: An integer `M` where:
  - `1 < M < 10⁸`
- Next `M` lines: Each contains one integer `x` to search for where:
  - `-10⁹ < x < 10⁹`

### Output Format

For each query, print the **0-based index** of `x` if found, otherwise print `-1`.

### Example

**Input:**

```
8 2
1 3 4 5 7 9 11 12
3
6
9
0
```

**Output:**

```
-1
5
-1
```
