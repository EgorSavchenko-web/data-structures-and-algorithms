# Alien Alphabet Order Solver

## Problem Description

This C++ program solves the "Anonymous Alphabet" problem, which involves determining the correct character order of an unknown alien alphabet given a lexicographically sorted dictionary of words.

Given a list of words sorted according to the rules of an unknown alphabet, the program deduces a valid character ordering that would produce this lexicographic ordering. If multiple valid orderings exist, any one is acceptable. If no valid ordering exists (due to contradictory constraints), the program outputs "Doh."

## Input Format

- First line: Integer `N` (1 ≤ N ≤ 100) - number of words
- Next `N` lines: Words consisting of lowercase English letters ('a'-'z'), each with length between 1 and 100 characters

## Output Format

- A string representing any valid alphabet order according to the given dictionary
- "Doh" if no valid alphabet order exists

## Algorithm Approach

The program uses **topological sorting** on a directed graph to determine the character ordering:

1. **Edge Creation**: Compare consecutive words to find the first differing character. This creates a directed edge from the character in the earlier word to the character in the later word, establishing a "comes before" relationship.

2. **Cycle Detection**: The presence of cycles in the graph indicates contradictions (e.g., a < b < c < a), which makes the ordering impossible.

3. **Special Case Handling**: If a word appears as a prefix of the next word, it's valid. However, if a longer word comes before its own prefix, this violates lexicographic ordering (e.g., "abc" before "ab").

4. **Topological Sort**: Using Kahn's algorithm, the program processes characters with zero incoming edges first, building the final ordering.

## Example

**Input:**

```
5
map
mng
mo
z
zx
```

**Output:**

```
xpmmoz
```

## Time and Space Complexity

- **Time Complexity**: O(N × L + V + E) where N is number of words, L is maximum word length, V is number of vertices (26 letters), and E is number of edges
- **Space Complexity**: O(V²) for the adjacency matrix (constant since V=26)
