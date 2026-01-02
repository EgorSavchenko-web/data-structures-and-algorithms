# Distance From Origin

A C++ solution for sorting points on a unit disk by their distance from the origin (0, 0).

## Problem Statement

Given `N` points \((x_i, y_i)\) uniformly distributed on the unit disk, sort the points in **ascending order** based on their Euclidean distance from the origin \((0, 0)\).

### Input Format

- First line: integer \( N \) ( \( 1 \leq N \leq 10^6 \) ) — number of points.
- Next \( N \) lines: each contains two floating‑point numbers \( x_i \) and \( y_i \) ( \( -1 \leq x_i, y_i \leq 1 \) ), representing a point \( P_i \).

### Output Format

- Print the sorted points in the same format as input: `x_i y_i` on separate lines.
- Each coordinate must be printed with **exactly 4 digits after the decimal point**.
- Points must appear in **ascending order of distance** from the origin.

## Solution

The program reads all points, sorts them by distance using a **merge sort** algorithm (custom implementation), and outputs the sorted points with the required precision.

### Key Features

- **O(N log N)** time complexity — efficient for up to \(10^6\) points.
- **Stable sorting** — merge sort preserves the original order of points with equal distance.
- **Precise output** — coordinates are printed with exactly 4 decimal digits using `printf("%.4f")`.
- **Memory efficient** — uses `vector` for storage and temporary arrays only during merging.

### Example

**Input:**

```
5
0.5000 0.5000
-0.2000 0.0000
0.0000 0.5000
0.3000 0.7000
-0.3000 0.3000
```

**Output:**

```
-0.2000 0.0000
-0.3000 0.3000
0.0000 0.5000
0.5000 0.5000
0.3000 0.7000
```
