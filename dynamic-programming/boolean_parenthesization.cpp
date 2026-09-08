#include <bits/stdc++.h>
using namespace std;

// Boolean Parenthesization
// Count ways to parenthesize expression so that it evaluates to true.
// Time: O(n^3)
// Space: O(n^2)

long long solve(
    const string& symbols,
    const string& operators,
    int i,
    int j,
    bool wantTrue,
    vector<vector<vector<long long>>>& dp
) {
    if (i > j)
        return 0;

    if (i == j) {
        if (wantTrue)
            return symbols[i] == 'T';

        return symbols[i] == 'F';
    }

    int index = wantTrue ? 1 : 0;

    if (dp[i][j][index] != -1)
        return dp[i][j][index];

    long long ways = 0;

    for (int k = i; k < j; k++) {
        long long leftTrue =
            solve(symbols, operators, i, k, true, dp);

        long long leftFalse =
            solve(symbols, operators, i, k, false, dp);

        long long rightTrue =
            solve(symbols, operators, k + 1, j, true, dp);

        long long rightFalse =
            solve(symbols, operators, k + 1, j, false, dp);

        char op = operators[k];

        if (op == '&') {
            if (wantTrue)
                ways += leftTrue * rightTrue;
            else
                ways += leftTrue * rightFalse
                      + leftFalse * rightTrue
                      + leftFalse * rightFalse;
        }
        else if (op == '|') {
            if (wantTrue)
                ways += leftTrue * rightTrue
                      + leftTrue * rightFalse
                      + leftFalse * rightTrue;
            else
                ways += leftFalse * rightFalse;
        }
        else if (op == '^') {
            if (wantTrue)
                ways += leftTrue * rightFalse
                      + leftFalse * rightTrue;
            else
                ways += leftTrue * rightTrue
                      + leftFalse * rightFalse;
        }
    }

    return dp[i][j][index] = ways;
}

int main() {
    string symbols, operators;

    cin >> symbols;
    cin >> operators;

    int n = symbols.size();

    vector<vector<vector<long long>>> dp(
        n,
        vector<vector<long long>>(
            n,
            vector<long long>(2, -1)
        )
    );

    cout << "Ways to evaluate to true: "
         << solve(symbols, operators, 0, n - 1, true, dp)
         << endl;

    return 0;
}
