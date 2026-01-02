# Sort By Frequency

## Problem Statement

Given `N` integers, sort the numbers in **ascending order based on their frequency** in the input.  
If two numbers have the same frequency, they should be ordered by their **ascending value**.  
Additionally, each number must be printed together with its **original index** (0‑based) in the input.  
If the same number appears multiple times, its occurrences are ordered by their original indices.

### Input Format

- First line: integer `N` (1 ≤ N ≤ 10⁷), the number of integers.
- Second line: `N` integers `M_i` (0 ≤ M_i ≤ 1000).

### Output Format

Print the sorted numbers, each on a new line, as a pair:  
`<value> <original_index>`

### Example

**Input**

```
10
20 1 6 20 6 17 20 14 17 1
```

**Output**

```
14 7
1 1
1 9
6 2
6 4
17 5
17 8
20 0
20 3
20 6
```

## Solution Explanation

The program implements a **custom merge sort** to sort the numbers according to the following criteria (in order of priority):

1. **Frequency (ascending)** – numbers that appear less often come first.
2. **Value (ascending)** – if frequencies are equal, smaller numbers come first.
3. **Original index (ascending)** – if both frequency and value are equal, earlier occurrences come first.

### Steps:

1. Read `N` and the sequence of integers.
2. Count the frequency of each number (values are between 0 and 1000, so an array of size 1001 is sufficient).
3. Create a vector of `DataUnit` structures, each storing:
   - `num` – the integer value.
   - `idx` – its original index.
   - `cnt` – its frequency in the input.
4. Sort the vector using a **merge sort** algorithm that implements the multi‑key comparison.
5. Output each element as `num idx`.

### Complexity

- **Time complexity:** O(N log N) due to the merge sort.
- **Space complexity:** O(N) for storing the array of `DataUnit` elements.
