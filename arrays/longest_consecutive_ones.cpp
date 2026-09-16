#include <bits/stdc++.h>
using namespace std;

// Find the maximum number of consecutive 1s
// after flipping at most one 0.
//
// Time: O(n)
// Space: O(1)

int longestOnes(vector<int>& nums) {
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

        answer = max(answer, right - left + 1);
    }

    return answer;
}

int main() {
    vector<int> nums = {
        1, 0, 1, 1, 0, 1
    };

    cout << "Longest sequence: "
         << longestOnes(nums)
         << endl;

    return 0;
}
