#include <bits/stdc++.h>
using namespace std;

// Maximum subarray sum when the array is treated as circular.

int maxSubarraySumCircular(vector<int>& nums) {
    int total = nums[0];

    int maxEnding = nums[0];
    int maxSum = nums[0];

    int minEnding = nums[0];
    int minSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        total += nums[i];

        maxEnding = max(nums[i], maxEnding + nums[i]);
        maxSum = max(maxSum, maxEnding);

        minEnding = min(nums[i], minEnding + nums[i]);
        minSum = min(minSum, minEnding);
    }

    // If all numbers are negative, circular calculation
    // would incorrectly return 0.
    if (maxSum < 0) {
        return maxSum;
    }

    return max(maxSum, total - minSum);
}

int main() {
    vector<int> nums = {5, -3, 5};

    cout << "Maximum circular sum: "
         << maxSubarraySumCircular(nums) << endl;

    return 0;
}
