#include <bits/stdc++.h>
using namespace std;

// Find the maximum sum of a subarray
// containing exactly k elements.
//
// Fixed-size sliding window.
//
// Time: O(n)
// Space: O(1)

int maximumSum(vector<int>& nums, int k) {
    if (k > nums.size()) {
        return 0;
    }

    int windowSum = 0;

    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    int answer = windowSum;

    for (int i = k; i < nums.size(); i++) {
        windowSum += nums[i];
        windowSum -= nums[i - k];

        answer = max(answer, windowSum);
    }

    return answer;
}

int main() {
    vector<int> nums = {
        2, 1, 5, 1, 3, 2
    };

    int k = 3;

    cout << "Maximum sum: "
         << maximumSum(nums, k)
         << endl;

    return 0;
}
