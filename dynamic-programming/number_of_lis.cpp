// Problem: Number of Longest Increasing Subsequences
// Approach: Dynamic Programming
// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();

    if (n == 0)
        return 0;

    vector<int> len(n, 1);
    vector<int> cnt(n, 1);

    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (len[j] + 1 > len[i]) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                } else if (len[j] + 1 == len[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }

        maxLen = max(maxLen, len[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (len[i] == maxLen)
            ans += cnt[i];
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 3, 5, 4, 7};

    cout << "Number of LIS: "
         << findNumberOfLIS(nums) << endl;

    return 0;
}
