#include <bits/stdc++.h>
using namespace std;

// Find all numbers in the range [1, n] that do not appear
// in the array.
//
// Time: O(n)
// Space: O(1) extra space, excluding the answer.

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();

    for (int x : nums) {
        int index = abs(x) - 1;

        if (nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }

    vector<int> result;

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            result.push_back(i + 1);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    vector<int> result = findDisappearedNumbers(nums);

    cout << "Missing numbers: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
