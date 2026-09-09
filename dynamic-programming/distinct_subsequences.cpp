#include <bits/stdc++.h>
using namespace std;

// Distinct Subsequences
// Count how many times t appears as a subsequence of s.
// Time: O(n * m)
// Space: O(m)

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<long long> dp(m + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }

    cout << "Distinct subsequences: "
         << dp[m] << endl;

    return 0;
}
