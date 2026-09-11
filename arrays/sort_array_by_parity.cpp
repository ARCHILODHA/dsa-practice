#include <bits/stdc++.h>
using namespace std;

// Move all even numbers before odd numbers.
// Relative order is not important.

vector<int> sortArrayByParity(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        while (left < right && nums[left] % 2 == 0) {
            left++;
        }

        while (left < right && nums[right] % 2 != 0) {
            right--;
        }

        if (left < right) {
            swap(nums[left], nums[right]);
        }
    }

    return nums;
}

int main() {
    vector<int> nums = {3, 1, 2, 4};

    sortArrayByParity(nums);

    cout << "Array after sorting by parity: ";

    for (int x : nums) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
