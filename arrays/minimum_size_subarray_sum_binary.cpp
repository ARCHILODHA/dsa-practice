#include <bits/stdc++.h>
using namespace std;

// Find the minimum length subarray whose sum
// is at least target.
//
// This implementation uses a sliding window.
//
// Time: O(n)
// Space: O(1)

int minimumLength(vector<int>& nums, int target) {
    int left = 0;
    int sum = 0;
    int answer = INT_MAX;

    for (int right = 0; right < nums.size(); right++) {

        sum += nums[right];

        while (sum >= target) {
            answer = min(
                answer,
                right - left + 1
            );

            sum -= nums[left];
            left++;
        }
    }

    return answer == INT_MAX ? 0 : answer;
}

int main() {
    vector<int> nums = {
        2, 3, 1, 2, 4, 3
    };

    int target = 7;

    cout << "Minimum length: "
         << minimumLength(nums, target)
         << endl;

    return 0;
}
