#include <bits/stdc++.h>
using namespace std;

// Find the length of the smallest subarray whose sum
// is at least target.
//
// Assumes all numbers are positive.
//
// Time: O(n)
// Space: O(1)

int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    long long sum = 0;
    int answer = INT_MAX;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        while (sum >= target) {
            answer = min(answer, right - left + 1);

            sum -= nums[left];
            left++;
        }
    }

    return answer == INT_MAX ? 0 : answer;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << "Minimum subarray length: "
         << minSubArrayLen(target, nums) << endl;

    return 0;
}
