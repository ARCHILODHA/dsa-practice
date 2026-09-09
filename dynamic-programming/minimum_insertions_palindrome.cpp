#include <bits/stdc++.h>
using namespace std;

// Minimum Insertions to Make a String Palindrome
// Answer = n - LPS
// Time: O(n^2)
// Space: O(n)

int main() {
    string s;
    cin >> s;

    int n = s.size();

    if (n <= 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> dp(n, 1);

    for (int i = n - 2; i >= 0; i--) {
        int previous = 0;

        for (int j = i + 1; j < n; j++) {
            int temp = dp[j];

            if (s[i] == s[j])
                dp[j] = previous + 2;
            else
                dp[j] = max(dp[j], dp[j - 1]);

            previous = temp;
        }
    }

    int longestPalindromicSubsequence = dp[n - 1];

    cout << "Minimum insertions: "
         << n - longestPalindromicSubsequence << endl;

    return 0;
}
