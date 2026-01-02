# Frequency Analysis

A C++ solution for finding the k-th most frequent word in a given text, with tie-breaking based on the first occurrence of words.

## Problem Statement

Given:

- `n`: total number of words (1 ≤ n ≤ 10³)
- `k`: the rank of the word to find (1 ≤ k ≤ n)
- A text consisting of `n` lowercase English words (each ≤ 30 characters)

### Example

**Input:**

```
6
2
to be or not to be
```

**Output:**

```
be
```

## Solution Approach

The program:

1. Reads `n`, `k`, and the text.
2. Tokenizes the text into words.
3. Counts word frequencies while preserving the order of first occurrence.
4. Repeatedly selects the word with the highest frequency (with earliest first occurrence in case of ties).
5. Outputs the k-th selected word.

## Complexity

- **Time:** O(n²) in the worst case due to linear searches in the frequency table. Acceptable for n ≤ 1000.
- **Space:** O(n) for storing words and frequencies.
