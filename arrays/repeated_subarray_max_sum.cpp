#include <bits/stdc++.h>
using namespace std;

// Find the maximum sum of a subarray with at most k
// repetitions of the same value.
//
// Demonstrates frequency counting + sliding window.

int maxSumAtMostKFrequency(vector<int>& nums, int k) {
    unordered_map<int, int> frequency;

    long long windowSum = 0;
    long long answer = 0;

    int left = 0;

    for (int right = 0; right < nums.size(); right++) {
        windowSum += nums[right];
        frequency[nums[right]]++;

        while (frequency[nums[right]] > k) {
            frequency[nums[left]]--;
            windowSum -= nums[left];
            left++;
        }

        answer = max(answer, windowSum);
    }

    return answer;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 1, 2};
    int k = 2;

    cout << "Maximum valid subarray sum: "
         << maxSumAtMostKFrequency(nums, k) << endl;

    return 0;
}
