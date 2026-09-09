#include <bits/stdc++.h>
using namespace std;

// Matrix Chain Multiplication
// Time: O(n^3)
// Space: O(n^2)

int main() {
    int n;
    cin >> n;

    vector<int> dimensions(n);

    for (int &x : dimensions)
        cin >> x;

    // n dimensions represent n-1 matrices
    vector<vector<long long>> dp(
        n,
        vector<long long>(n, 0)
    );

    for (int length = 2; length < n; length++) {
        for (int i = 1; i + length - 1 < n; i++) {
            int j = i + length - 1;

            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long cost =
                    dp[i][k] +
                    dp[k + 1][j] +
                    1LL * dimensions[i - 1] *
                    dimensions[k] *
                    dimensions[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << "Minimum multiplication cost: "
         << dp[1][n - 1] << endl;

    return 0;
}
