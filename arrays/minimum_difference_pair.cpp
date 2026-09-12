#include <bits/stdc++.h>
using namespace std;

// Find the minimum absolute difference between any two elements.

int minimumDifference(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int answer = INT_MAX;

    for (int i = 1; i < nums.size(); i++) {
        answer = min(answer, nums[i] - nums[i - 1]);
    }

    return answer;
}

int main() {
    vector<int> nums = {1, 5, 3, 19, 18, 25};

    cout << "Minimum difference: "
         << minimumDifference(nums) << endl;

    return 0;
}
