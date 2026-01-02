# Spell Checker - Problem Solution

## Problem Description

Given two collections of words, find all the distinct words from the first collection that are NOT present in the second collection.

### Input Format

- First line: integer `n` (1 ≤ n ≤ 10⁵) - number of words in the first text
- Second line: `n` words separated by spaces
- Third line: integer `m` (1 ≤ m ≤ 10⁵) - number of words in the second text
- Fourth line: `m` words separated by spaces

**Constraints:** Each word contains only lowercase English letters and has at most 30 characters.

### Output Format

- First line: integer `k` - number of unique words from the first text that are missing from the second text
- Next `k` lines: the missing words, one per line, in the order they first appear in the first text

## Solution Approach

The program implements a straightforward comparison algorithm:

1. **Reading Input**: Reads both collections of words from standard input
2. **Processing**: Compares each word from the first collection against all words in the second collection
3. **Uniqueness Check**: Ensures only distinct words are output by checking against already found results
4. **Order Preservation**: Maintains the original order from the first collection

### Algorithm Complexity

- **Time Complexity**: O(n × m) in worst case (nested loops for comparison)
- **Space Complexity**: O(n + m) for storing the word collections

## Example

**Input:**

```
10
1 will make him a stack he can not overflow
10
1 will make him an offer he can not refuse
```

**Output:**

```
3
a
stack
overflow
```
