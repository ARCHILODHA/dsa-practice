#include <bits/stdc++.h>
using namespace std;

// Find the longest contiguous subarray containing
// equal numbers of 0s and 1s.
//
// Convert 0 -> -1 and 1 -> +1.
// A repeated prefix sum means the section between
// those indices has sum 0.

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> firstIndex;

    firstIndex[0] = -1;

    int prefixSum = 0;
    int answer = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            prefixSum--;
        } else {
            prefixSum++;
        }

        if (firstIndex.count(prefixSum)) {
            answer = max(answer, i - firstIndex[prefixSum]);
        } else {
            firstIndex[prefixSum] = i;
        }
    }

    return answer;
}

int main() {
    vector<int> nums = {0, 1, 0, 0, 1, 1, 0};

    cout << "Maximum length: "
         << findMaxLength(nums) << endl;

    return 0;
}
