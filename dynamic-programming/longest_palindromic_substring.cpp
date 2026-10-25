// Problem: Longest Palindromic Substring
// Approach: Dynamic Programming
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();

    if (n == 0)
        return "";

    vector<vector<bool>> dp(
        n, vector<bool>(n, false)
    );

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (s[i] == s[j]) {
                if (len == 2 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;

                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s = "babad";

    cout << "Longest Palindromic Substring: "
         << longestPalindrome(s) << endl;

    return 0;
}
