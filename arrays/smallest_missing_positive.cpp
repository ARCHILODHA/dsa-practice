#include <bits/stdc++.h>
using namespace std;

// Find the smallest missing positive integer.
// Time: O(n)
// Space: O(1)

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    // Place every number x at index x - 1.
    for (int i = 0; i < n; i++) {
        while (nums[i] >= 1 &&
               nums[i] <= n &&
               nums[nums[i] - 1] != nums[i]) {

            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // Find the first incorrect position.
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    vector<int> nums = {3, 4, -1, 1};

    cout << "Smallest missing positive: "
         << firstMissingPositive(nums) << endl;

    return 0;
}
