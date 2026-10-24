
# Dynamic Programming Patterns

## 1. Introduction
Dynamic Programming (DP) solves problems by breaking them into overlapping subproblems and storing their results.

It is useful when a problem has:
- Overlapping subproblems
- Optimal substructure

## 2. Two Main Approaches

### Memoization
Top-down recursion with caching.

### Tabulation
Bottom-up computation using a table.

## 3. Fibonacci Example
### Memoization
```cpp
int fib(int n, vector<int>& dp) {
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

Tabulation
int fib(int n) {
    if (n <= 1)
        return n;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

Both approaches run in O(N) time.

4. Common DP Patterns
One-dimensional DP
Climbing stairs
House robber
Grid-based DP
0/1 knapsack
Unbounded knapsack
Longest Common Subsequence
Longest Increasing Subsequence
Subset sum
Partition problems
DP on trees
DP on strings
5. How to Solve a DP Problem
Define the state.
Identify the transition.
Establish base cases.
Determine the order of computation.
Calculate the answer.
Optimize space if possible.
6. Example: Climbing Stairs

You can climb either one or two steps at a time.

The recurrence is:

dp[i] = dp[i - 1] + dp[i - 2]

Base cases:

dp[1] = 1
dp[2] = 2

Time Complexity: O(N)

Space Complexity: O(N), reducible to O(1).

7. Practice Problems
Climbing Stairs
House Robber
Coin Change
Unique Paths
Longest Common Subsequence
Longest Increasing Subsequence
Partition Equal Subset Sum
Edit Distance
8. Common Mistakes
Defining the state incorrectly
Missing base cases
Using incorrect transitions
Mixing up index and value
Returning the wrong DP state
Optimizing space before the recurrence is correct
9. Key Takeaway

First understand the recurrence and state definition. Then implement memoization, convert it to tabulation, and optimize space when appropriate.
