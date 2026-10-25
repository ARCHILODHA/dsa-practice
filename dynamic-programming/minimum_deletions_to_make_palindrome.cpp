// Problem: Minimum Deletions to Make a String Palindrome
// Approach: Longest Palindromic Subsequence
// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int minimumDeletions(string s) {
    int n = s.size();

    string rev = s;
    reverse(rev.begin(), rev.end());

    vector<int> prev(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        vector<int> curr(n + 1, 0);

        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == rev[j - 1]) {
                curr[j] = 1 + prev[j - 1];
            } else {
                curr[j] = max(
                    prev[j], curr[j - 1]
                );
            }
        }

        prev = curr;
    }

    int longestPalindromicSubsequence = prev[n];

    return n - longestPalindromicSubsequence;
}

int main() {
    string s = "aebcbda";

    cout << "Minimum Deletions: "
         << minimumDeletions(s) << endl;

    return 0;
}
