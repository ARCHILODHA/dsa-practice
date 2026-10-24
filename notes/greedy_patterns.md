# Greedy Algorithm Patterns

## 1. Introduction
A greedy algorithm makes the locally optimal choice at each step.

A greedy approach works only when these choices can lead to a globally optimal solution.

## 2. Important Patterns
- Interval scheduling
- Activity selection
- Sorting by end time
- Minimum number of platforms
- Fractional knapsack
- Jump game
- Minimum number of coins for suitable denominations
- Huffman coding

## 3. Activity Selection
The standard strategy is to select activities in increasing order of finishing time.

1. Sort activities by finishing time.
2. Select the first activity.
3. Select the next activity whose start time is at least the previous selected activity's finish time.
4. Repeat until all activities are processed.

Time Complexity: O(N log N) due to sorting.

## 4. Jump Game
For each position, track the farthest index reachable so far.

If the current index exceeds the farthest reachable index, the destination cannot be reached.

## 5. How to Identify Greedy Problems
Ask these questions:
- Can I make a choice that never needs to be reconsidered?
- Can the problem be solved by repeatedly selecting the best available option?
- Is there a proof that this choice preserves an optimal solution?

Do not assume that choosing the locally largest or smallest value always works.

## 6. Greedy vs Dynamic Programming
Greedy:
- Makes a locally optimal choice.
- Often uses less memory.
- Requires a correctness argument.

Dynamic Programming:
- Evaluates and combines subproblem results.
- Can handle choices that require comparing multiple alternatives.
- Often stores intermediate states.

## 7. Practice Problems
1. Assign Cookies
2. Jump Game
3. Jump Game II
4. Non-overlapping Intervals
5. N Meetings in One Room
6. Minimum Number of Platforms
7. Gas Station

## 8. Common Mistakes
- Applying greedy without proving correctness
- Sorting by the wrong property
- Ignoring edge cases
- Assuming every optimization problem is greedy

## 9. Key Takeaway
A greedy solution needs both an efficient strategy and a reason that its choices produce an optimal result.
