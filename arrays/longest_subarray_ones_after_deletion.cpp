#include <bits/stdc++.h>
using namespace std;

// Find the longest subarray containing only 1s
// after deleting exactly one element.

int longestSubarray(vector<int>& nums) {
    int left = 0;
    int zeros = 0;
    int answer = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) {
            zeros++;
        }

        while (zeros > 1) {
            if (nums[left] == 0) {
                zeros--;
            }
            left++;
        }

        // One element must be deleted.
        answer = max(answer, right - left);
    }

    return answer;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << "Longest subarray: "
         << longestSubarray(nums) << endl;

    return 0;
}
