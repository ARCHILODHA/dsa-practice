#include <bits/stdc++.h>
using namespace std;

// Find any peak element.
// A peak is an element greater than its neighbors.
//
// Uses binary search.
//
// Time: O(log n)
// Space: O(1)

int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {

        int mid =
            left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}

int main() {
    vector<int> nums = {
        1, 2, 1, 3, 5, 6, 4
    };

    int index = findPeakElement(nums);

    cout << "Peak index: "
         << index << endl;

    cout << "Peak value: "
         << nums[index] << endl;

    return 0;
}
