// Problem: Wildcard Matching
// '?' matches one character.
// '*' matches any sequence of characters.
// Time Complexity: O(n * m)
// Space Complexity: O(m)

#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    vector<bool> dp(m + 1, false);
    dp[0] = true;

    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
            dp[j] = dp[j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        vector<bool> curr(m + 1, false);

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '?' ||
                p[j - 1] == s[i - 1]) {
                curr[j] = dp[j - 1];
            } else if (p[j - 1] == '*') {
                curr[j] = curr[j - 1] || dp[j];
            }
        }

        dp = curr;
    }

    return dp[m];
}

int main() {
    string s = "adceb";
    string p = "*a*b";

    cout << boolalpha;
    cout << "Pattern Matches: "
         << isMatch(s, p) << endl;

    return 0;
}
