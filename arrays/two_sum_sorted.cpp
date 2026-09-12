#include <bits/stdc++.h>
using namespace std;

// Find two numbers in a sorted array whose sum equals target.
// Returns their 0-based indices.

vector<int> twoSumSorted(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
            return {left, right};
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    return {-1, -1};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSumSorted(nums, target);

    cout << "Indices: "
         << result[0] << ", " << result[1] << endl;

    return 0;
}
