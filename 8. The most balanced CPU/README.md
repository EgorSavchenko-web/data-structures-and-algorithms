# CPU Finder

## Overview

This C++ program solves the "Most Balanced CPU" problem by finding the CPU model whose benchmark score is exactly in the middle when all scores are ranked in ascending order (the median). The solution implements a modified version of the Quicksort algorithm to efficiently identify the median CPU.

## Problem Statement

A hardware review website needs to identify the most balanced CPU - the one with exactly as many CPUs performing better as there are performing worse. Given N CPU models with unique benchmark scores, the program must output the model name of the CPU with the median score.

### Input Format

- First line: An odd integer N (0 < N < 10^6) - number of CPU models
- Next N lines: Each contains a score K (0 ≤ K ≤ 10^6) followed by the CPU model name
- CPU model names consist of English letters, numbers, and "-" character
- All benchmark scores are guaranteed to be unique

### Output Format

- Single line: The model name of the CPU with the median score

### Example

**Input:**

```
5
3229 Ryzen5960X
5686 Core17
7298 Ryzen5960X
2589 Pentium56408
6899 Core19
```

**Output:**

```
Core17
```

## Algorithm

The program implements the following approach:

1. **Data Structure**: Uses a `Learner` struct to store each CPU's score and model name together
2. **Sorting**: Implements Quicksort to sort the CPU models by their benchmark scores in ascending order
3. **Median Selection**: After sorting, selects the CPU at index `N/2` (zero-based indexing) which represents the median

## Complexity Analysis

- **Time Complexity**: O(N log N) average case, O(N²) worst case (though unlikely with random data)
- **Space Complexity**: O(N) for storing the CPU data, O(log N) for recursion stack
