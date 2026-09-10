#include <bits/stdc++.h>
using namespace std;

// Find the maximum difference between consecutive
// elements after sorting.

int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }

    sort(nums.begin(), nums.end());

    int maxGap = 0;

    for (int i = 1; i < nums.size(); i++) {
        maxGap = max(maxGap, nums[i] - nums[i - 1]);
    }

    return maxGap;
}

int main() {
    vector<int> nums = {3, 6, 9, 1};

    cout << "Maximum gap: "
         << maximumGap(nums) << endl;

    return 0;
}
