#include <bits/stdc++.h>
using namespace std;

// Find the longest subarray containing at most k
// distinct elements.
//
// Time: O(n)
// Space: O(k)

int longestSubarray(vector<int>& nums, int k) {
    unordered_map<int, int> frequency;

    int left = 0;
    int answer = 0;

    for (int right = 0; right < nums.size(); right++) {
        frequency[nums[right]]++;

        while (frequency.size() > k) {
            frequency[nums[left]]--;

            if (frequency[nums[left]] == 0) {
                frequency.erase(nums[left]);
            }

            left++;
        }

        answer = max(answer, right - left + 1);
    }

    return answer;
}

int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    cout << "Longest subarray length: "
         << longestSubarray(nums, k) << endl;

    return 0;
}
