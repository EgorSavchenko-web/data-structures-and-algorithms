# Sort By Frequency

## Problem Description

Given `N` integers, sort them in **ascending order based on their frequency of appearance** in the input. If two or more numbers have the same frequency, they may be printed in **any order**.

### Input

- First line: integer `N` (1 ≤ N ≤ 10⁵) — the number of integers.
- Second line: `N` integers `M_i` (0 ≤ M_i ≤ 1000), separated by spaces.

### Output

Print the sorted numbers, one per line, in increasing order of frequency.

### Example

**Input**

```
10
20 1 6 20 6 17 20 14 17 1
```

**Output**

```
14
6
17
1
20
```

## Solution Approach

The provided C++ solution follows these steps:

1. **Read Input**: Store the `N` integers in an array.
2. **Count Frequencies**: Use an array of size 1001 (since `M_i ≤ 1000`) to count occurrences of each number.
3. **Collect Non-zero Frequencies**: Store each number and its frequency in a struct array.
4. **Sort by Frequency**: Use a **bubble sort** (or any stable sort) to order the struct array by increasing frequency.
5. **Output**: Print the numbers from the sorted array, each on a new line.

### Complexity

- **Time Complexity**: O(N + K²) where K ≤ 1001 (the range of values). The dominant term is the bubble sort on the frequency array, which is acceptable since K is small.
- **Space Complexity**: O(N + K) for storing the input and frequency arrays.
