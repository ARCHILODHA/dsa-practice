#include <bits/stdc++.h>
using namespace std;

// Find the maximum subarray sum that does not exceed k.
//
// Uses prefix sums and an ordered set.
//
// Time: O(n log n)
// Space: O(n)

int maxSubarraySumNoMoreThanK(
    vector<int>& nums,
    int k
) {
    set<int> prefixSums;

    prefixSums.insert(0);

    int prefix = 0;
    int answer = INT_MIN;

    for (int x : nums) {

        prefix += x;

        // We need:
// prefix - previousPrefix <= k
// previousPrefix >= prefix - k

        auto it =
            prefixSums.lower_bound(prefix - k);

        if (it != prefixSums.end()) {
            answer =
                max(answer, prefix - *it);
        }

        prefixSums.insert(prefix);
    }

    return answer;
}

int main() {
    vector<int> nums = {
        2, 2, -1, 3
    };

    int k = 4;

    cout << "Maximum sum <= k: "
         << maxSubarraySumNoMoreThanK(nums, k)
         << endl;

    return 0;
}
