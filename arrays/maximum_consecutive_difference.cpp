#include <bits/stdc++.h>
using namespace std;

// Find the maximum absolute difference between
// adjacent elements after arranging the array optimally.
//
// Uses sorting and considers neighboring differences.

int maximumAdjacentDifference(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }

    sort(nums.begin(), nums.end());

    int answer = 0;

    for (int i = 1; i < nums.size(); i++) {
        answer = max(answer, nums[i] - nums[i - 1]);
    }

    return answer;
}

int main() {
    vector<int> nums = {3, 6, 9, 1};

    cout << "Maximum difference: "
         << maximumAdjacentDifference(nums) << endl;

    return 0;
}
