# D-ary Max-Heap Construction

## Problem Description

Given an integer \( d \) (the arity of the heap) and a list of \( N \) integers, construct **any** valid **d-ary max-heap** using these integers and output its array representation.

In a **d-ary max-heap**:

- Every parent node has at most \( d \) children.
- The value of each parent node is **greater than or equal to** the values of its children.
- The array representation follows a **level-order traversal**, where the children of the node at index \( i \) are at indices:
  \[
  d \cdot i + 1,\ d \cdot i + 2,\ \ldots,\ d \cdot i + d
  \]

### Input

- First line: two integers \( N \) and \( d \) (\( 2 \leq d \leq 10,\ 1 \leq N \leq 10^5 \)).
- Second line: \( N \) integers \( a_1, a_2, \ldots, a_N \) (\( -10^3 \leq a_i \leq 10^3 \)).

### Output

Print the array representation of any valid **d-ary max-heap** as space-separated integers.

## Solution Approach

A simple and efficient way to produce a valid **d-ary max-heap** is to:

1. Sort all input integers in **non-increasing order** (descending order).
2. Output the sorted array.

**Why this works:**  
In the level-order array representation, a parent at index \( i \) always appears **before** its children (which are at indices \( d \cdot i + 1, \dots, d \cdot i + d \)).  
If the array is sorted in descending order, then every parent value is automatically **greater than or equal to** all its children's values, satisfying the max-heap property for any \( d \).

Thus, any descending-order sorted array is a valid **d-ary max-heap** representation.

### Complexity

- **Time complexity:** \( O(N \log N) \) due to merge sort.
- **Space complexity:** \( O(N) \) for the merge sort recursion and temporary vectors.
