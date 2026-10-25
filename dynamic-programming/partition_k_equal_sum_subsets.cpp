// Problem: Partition to K Equal Sum Subsets
// Approach: Backtracking with Bitmask DP
// Time Complexity: O(n * 2^n) states, with additional
//                  transition work per state.
// Space Complexity: O(2^n)

#include <bits/stdc++.h>
using namespace std;

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size();

    if (k <= 0 || k > n)
        return false;

    int total = accumulate(
        nums.begin(), nums.end(), 0
    );

    if (total % k != 0)
        return false;

    int target = total / k;

    sort(nums.rbegin(), nums.rend());

    if (nums[0] > target)
        return false;

    int totalMasks = 1 << n;

    vector<int> dp(totalMasks, -1);
    dp[0] = 0;

    for (int mask = 0; mask < totalMasks; mask++) {
        if (dp[mask] == -1)
            continue;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                continue;

            if (dp[mask] + nums[i] > target)
                continue;

            int nextMask = mask | (1 << i);

            dp[nextMask] =
                (dp[mask] + nums[i]) % target;
        }
    }

    return dp[totalMasks - 1] == 0;
}

int main() {
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;

    cout << boolalpha;
    cout << "Can Partition: "
         << canPartitionKSubsets(nums, k) << endl;

    return 0;
}
