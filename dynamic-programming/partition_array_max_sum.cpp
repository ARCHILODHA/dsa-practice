#include <bits/stdc++.h>
using namespace std;

// Partition Array for Maximum Sum
// Each partition can have at most k elements.
// Time: O(n * k)
// Space: O(n)

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int &x : arr)
        cin >> x;

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int maximum = 0;

        for (int len = 1; len <= k && i - len >= 0; len++) {
            maximum = max(maximum, arr[i - len]);

            dp[i] = max(
                dp[i],
                dp[i - len] + maximum * len
            );
        }
    }

    cout << "Maximum sum: " << dp[n] << endl;

    return 0;
}
