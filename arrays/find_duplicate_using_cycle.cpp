#include <bits/stdc++.h>
using namespace std;

// Find the duplicate number using Floyd's Cycle Detection.
//
// Numbers are in the range [1, n].
// There is exactly one duplicate.
//
// Time: O(n)
// Space: O(1)

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // Find intersection point.
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Find entrance of the cycle.
    slow = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};

    cout << "Duplicate number: "
         << findDuplicate(nums) << endl;

    return 0;
}
