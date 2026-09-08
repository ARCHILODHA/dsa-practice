#include <bits/stdc++.h>
using namespace std;

// Egg Dropping Problem
// Find minimum attempts needed in worst case.
// Time: O(eggs * floors^2)
// Space: O(eggs * floors)

int main() {
    int eggs, floors;
    cin >> eggs >> floors;

    vector<vector<int>> dp(
        eggs + 1,
        vector<int>(floors + 1)
    );

    for (int i = 1; i <= eggs; i++) {
        dp[i][0] = 0;

        if (floors >= 1)
            dp[i][1] = 1;
    }

    for (int j = 1; j <= floors; j++)
        dp[1][j] = j;

    for (int e = 2; e <= eggs; e++) {
        for (int f = 2; f <= floors; f++) {
            dp[e][f] = INT_MAX;

            for (int x = 1; x <= f; x++) {
                int breaks = dp[e - 1][x - 1];
                int survives = dp[e][f - x];

                int attempts = 1 + max(breaks, survives);

                dp[e][f] = min(dp[e][f], attempts);
            }
        }
    }

    cout << "Minimum attempts: "
         << dp[eggs][floors] << endl;

    return 0;
}
