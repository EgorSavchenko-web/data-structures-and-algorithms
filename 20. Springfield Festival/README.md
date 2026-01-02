# Springfield Festival - Minimum Effort Connections

## Problem Overview

Homer Simpson wants to visit all Duff Beer stalls at the Springfield Festival while minimizing his walking effort. The challenge involves creating connections between stalls where the cost between two stalls `a` and `b` is calculated as:

```
Cost = Distance(a,b) / (Tax(a) + Tax(b))
```

Where:

- `Distance(a,b)` is the walking distance between stalls
- `Tax(a)` and `Tax(b)` are the Burns Tax penalties of the respective stalls

## Solution Approach

The program implements Prim's algorithm to find the Minimum Spanning Forest (MSF) of the stall network. Since the graph may be disconnected, the algorithm processes each connected component separately to ensure all stalls are accessible.

### Time Complexity

- **ADD**: O(1)
- **CONNECT**: O(n) for name lookup, O(1) for edge addition
- **PRINT_MIN**: O((V+E) log V) for Prim's algorithm with binary heap
  Where V = number of stalls, E = number of connections

## Example

**Input:**

```
5
ADD Moe's_Tavern 50
ADD KwikFliart 30
ADD Duff_Stadium 80
CONNECT Moe's_Tavern KwikFliart 200
PRINT_MIN
```

**Output:**

```
Moe's_Tavern:KwikFliart
```
