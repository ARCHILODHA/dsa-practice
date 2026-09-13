#include <bits/stdc++.h>
using namespace std;

// Find the minimum element in a rotated sorted array.
// Assumes all elements are distinct.
//
// Time: O(log n)
// Space: O(1)

int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << "Minimum element: "
         << findMin(nums) << endl;

    return 0;
}
