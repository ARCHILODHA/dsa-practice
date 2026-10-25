// Problem: Minimum Coins to Make an Amount
// Approach: Unbounded Dynamic Programming
// Time Complexity: O(amount * number of coins)
// Space Complexity: O(amount)

#include <bits/stdc++.h>
using namespace std;

int minimumCoins(vector<int>& coins, int amount) {
    const int INF = amount + 1;

    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INF) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Minimum Coins Required: "
         << minimumCoins(coins, amount) << endl;

    return 0;
}
