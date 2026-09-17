#include <bits/stdc++.h>
using namespace std;

// You can modify at most 3 elements.
// Find the minimum possible difference between
// the largest and smallest elements.
//
// Sort the array and consider four possibilities.
//
// Time: O(n log n)
// Space: O(1), excluding sorting implementation.

int minDifference(vector<int>& nums) {
    int n = nums.size();

    if (n <= 4) {
        return 0;
    }

    sort(nums.begin(), nums.end());

    int answer = INT_MAX;

    // Remove 3 largest.
    answer = min(
        answer,
        nums[n - 4] - nums[0]
    );

    // Remove 2 largest and 1 smallest.
    answer = min(
        answer,
        nums[n - 3] - nums[1]
    );

    // Remove 1 largest and 2 smallest.
    answer = min(
        answer,
        nums[n - 2] - nums[2]
    );

    // Remove 3 smallest.
    answer = min(
        answer,
        nums[n - 1] - nums[3]
    );

    return answer;
}

int main() {
    vector<int> nums = {
        5, 3, 2, 4
    };

    cout << "Minimum difference: "
         << minDifference(nums)
         << endl;

    return 0;
}
