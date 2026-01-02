# Garbage Collector

## Problem

You are implementing a garbage collector for the language **Simplang++**. The memory is represented as a linear array of `n` slots. Each slot contains either:

- A **non‑negative integer** (a pointer) that indicates another slot’s index, or
- A **negative integer** (non‑pointer data).

Given the memory array and a set of **root pointers**, the task is to identify all **contiguous blocks of unreachable (garbage) slots** and report each block’s starting index and size.

## Input Format

- First line: two integers `n` and `r`
  - `n` (1 ≤ n ≤ 10⁵) – size of the memory array
  - `r` (0 ≤ r ≤ n) – number of root pointers
- Second line: `n` integers `a₀, a₁, …, aₙ₋₁`
  - `aᵢ ≥ 0` → slot `i` contains a pointer to slot `aᵢ`
  - `aᵢ < 0` → slot `i` contains non‑pointer data
- Third line: `r` distinct integers `b₁, b₂, …, bᵣ` (0 ≤ bᵢ < n) – the root pointers’ addresses

## Output Format

- First line: integer `m` – number of garbage memory blocks
- Then `m` lines, each containing two integers:
  - `sᵢ` – starting index of the i‑th garbage block
  - `cᵢ` – size (number of contiguous slots) of that block

Blocks must be reported in **ascending order** of their starting indices.  
If there are no garbage blocks, output a single `0`.

## Example

**Input**

```
10 2
1 -3 3 -1 2 7 -2 -1 9 -1
0 4
```

**Output**

```
1
5 5
```

## Complexity

- **Time:** O(n) – each slot is processed at most twice (once during marking, once during scanning).
- **Space:** O(n) – for the `accessible`, `pointers`, and `origins` arrays.
