#include <bits/stdc++.h>
using namespace std;

// Find the maximum possible sum of an increasing subsequence.

int maxSumIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp = nums;

    int answer = nums[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }

        answer = max(answer, dp[i]);
    }

    return answer;
}

int main() {
    vector<int> nums = {1, 101, 2, 3, 100, 4, 5};

    cout << "Maximum sum: "
         << maxSumIncreasingSubsequence(nums) << endl;

    return 0;
}
