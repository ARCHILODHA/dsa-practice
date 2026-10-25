// Problem: Longest Common Substring
// Approach: Dynamic Programming
// Time Complexity: O(n * m)
// Space Complexity: O(m)

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> curr(m + 1, 0);

        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = 1 + prev[j - 1];
                ans = max(ans, curr[j]);
            }
        }

        prev = curr;
    }

    return ans;
}

int main() {
    string s1 = "abcjklp";
    string s2 = "acjkp";

    cout << "Longest Common Substring Length: "
         << longestCommonSubstring(s1, s2) << endl;

    return 0;
}
