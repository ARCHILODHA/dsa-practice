#include <bits/stdc++.h>
using namespace std;

// Unbounded Knapsack
// Each item can be selected multiple times.
// Time: O(n * capacity)
// Space: O(capacity)

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<int> weight(n), value(n);

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    for (int i = 0; i < n; i++)
        cin >> value[i];

    vector<int> dp(capacity + 1, 0);

    for (int w = 0; w <= capacity; w++) {
        for (int i = 0; i < n; i++) {
            if (weight[i] <= w) {
                dp[w] = max(dp[w], value[i] + dp[w - weight[i]]);
            }
        }
    }

    cout << "Maximum value: " << dp[capacity] << endl;

    return 0;
}
