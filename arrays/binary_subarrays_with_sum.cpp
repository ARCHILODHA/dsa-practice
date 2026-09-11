#include <bits/stdc++.h>
using namespace std;

// Count the number of subarrays whose sum equals goal.
// Works for binary arrays containing only 0 and 1.

int atMost(vector<int>& nums, int goal) {
    if (goal < 0) return 0;

    int left = 0;
    int sum = 0;
    int count = 0;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        while (sum > goal) {
            sum -= nums[left++];
        }

        count += right - left + 1;
    }

    return count;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    cout << "Number of subarrays: "
         << numSubarraysWithSum(nums, goal) << endl;

    return 0;
}
