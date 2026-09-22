#include <bits/stdc++.h>
using namespace std;

// Partition array into subarrays of size at most k
// to maximize the total sum.
int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int maximum = 0;

        for (int j = 1; j <= k && i - j >= 0; j++) {
            maximum = max(maximum, arr[i - j]);

            dp[i] = max(dp[i],
                        dp[i - j] + maximum * j);
        }
    }

    return dp[n];
}
