#include <bits/stdc++.h>
using namespace std;

// Count triplets whose sum is smaller than target.

int countTriplets(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < target) {
                // Every element from left+1 to right
                // can form a valid triplet.
                count += right - left;
                left++;
            } else {
                right--;
            }
        }
    }

    return count;
}

int main() {
    vector<int> nums = {-2, 0, 1, 3};
    int target = 2;

    cout << "Number of valid triplets: "
         << countTriplets(nums, target) << endl;

    return 0;
}
