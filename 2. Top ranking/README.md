# Top Ranking - Scoreboard Implementation

## Problem Description

This Java program solves the "Top ranking" problem, which requires building a highscore leadership table from an unsorted list of players with their scores in a video game. The implementation follows specific constraints and produces the top K players sorted by descending score.

## Problem Constraints

- **Input**:

  - First line: `N K` where:
    - `N` = number of entries (0 ≤ N ≤ 10⁴)
    - `K` = maximum size of leadership table (1 ≤ K ≤ 100)
  - Next N lines: `<PLAYER> <SCORE>` where:
    - `<PLAYER>`: single word containing alphanumeric characters (a-z, A-Z, 0-9) and underscores
    - `<SCORE>`: non-negative integer up to 2⁵⁰

- **Output**:
  - Exactly K lines (or fewer if N < K)
  - Each line: `<PLAYER> <SCORE>`
  - Sorted in descending order by score

## Implementation Details

### Key Components

1. **Main Algorithm** (`fetchTopPlayers` method):

   - Takes a list of string records and a limit K
   - Parses each record into player name and score
   - Sorts entries by score in descending order
   - Returns top K entries as formatted strings

2. **Data Structure** (`ScoreEntry` inner class):

   - Stores player name and score as instance variables
   - Used for sorting and ranking operations

3. **Main Method**:
   - Reads input from standard input
   - Processes N and K values
   - Collects player records
   - Invokes the main algorithm
   - Outputs results

### Algorithm Complexity

- **Time Complexity**: O(N log N) due to sorting operation
- **Space Complexity**: O(N) for storing all entries
- The implementation is efficient within the given constraints (N ≤ 10⁴, K ≤ 100)

### Example

Input:

```
6 3
buffer1 123
Ctrl_square 224
Next_Saprero 789
TUB_Index_Thing 678
Ittblatz 456
Lucifern 567
```

Output:

```
Next_Saprero 789
TUB_Index_Thing 678
Lucifern 567
```

## Edge Cases Handled

- Empty input (N = 0)
- N < K (returns fewer than K lines)
- Duplicate scores (stable sorting by occurrence order in case of ties, though not specified in problem)
- Large N values up to 10,000
