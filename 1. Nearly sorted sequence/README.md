# Nearly Sorted Sequence

This Java program implements a sorting algorithm. The program reads an array of integers, sorts them in ascending order, and outputs the sorted sequence.

## Problem Description

You are given a sequence of numbers that is **nearly sorted**. The goal is to sort it efficiently. The input consists of:

- An integer `N` (0 ≤ N ≤ 10⁶), the number of elements.
- `N` integers `a₁, a₂, ..., aₙ` (-10⁹ ≤ aᵢ ≤ 10⁹).

The output must be the sorted sequence of numbers, separated by whitespace.

### Examples

**Example 1**

```
Input:
10
1 3 2 5 4 6 7 9 8 10

Output:
1 2 3 4 5 6 7 8 9 10
```

**Example 2**

```
Input:
10
5 4 6 3 5 5 7 7 11 12

Output:
3 4 5 5 5 6 7 7 11 12
```

## Implementation Details

The program uses an **optimized Bubble Sort** algorithm with the following features:

- **In-place sorting**: The input array is sorted in place, without creating a new array.
- **Early termination**: The algorithm stops early if no swaps are made in a pass, indicating the array is already sorted.
- **Reduced pass count**: After each pass, the largest unsorted element is placed in its correct position, reducing the range of subsequent passes.

### Time and Space Complexity

- **Time Complexity**: O(N²) in the worst case, but closer to O(N) for nearly sorted sequences.
- **Space Complexity**: O(1) auxiliary space.

### Input Format

1. Enter the number of elements `N` (press Enter).
2. Enter the `N` integers separated by spaces (press Enter).
