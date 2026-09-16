#include <bits/stdc++.h>
using namespace std;

// Partition an array into groups of at most k elements.
// Every element in a group is replaced by the group's maximum.
// Maximize the resulting sum.
//
// Dynamic Programming.
//
// Time: O(n * k)
// Space: O(n)

int maxSumAfterPartitioning(
    vector<int>& arr,
    int k
) {
    int n = arr.size();

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {

        int currentMax = 0;

        for (int length = 1;
             length <= k && i - length >= 0;
             length++) {

            currentMax =
                max(currentMax,
                    arr[i - length]);

            dp[i] = max(
                dp[i],
                dp[i - length] +
                currentMax * length
            );
        }
    }

    return dp[n];
}

int main() {
    vector<int> arr = {
        1, 15, 7, 9, 2, 5, 10
    };

    int k = 3;

    cout << "Maximum partition sum: "
         << maxSumAfterPartitioning(arr, k)
         << endl;

    return 0;
}
