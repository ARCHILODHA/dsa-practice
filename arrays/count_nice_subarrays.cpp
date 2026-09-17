#include <bits/stdc++.h>
using namespace std;

// Count subarrays containing exactly k odd numbers.
//
// Convert the problem into a prefix sum problem.
// Each odd number contributes 1.
//
// Time: O(n)
// Space: O(n)

int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> frequency;

    frequency[0] = 1;

    int oddCount = 0;
    int answer = 0;

    for (int x : nums) {

        if (x % 2 != 0) {
            oddCount++;
        }

        if (frequency.count(oddCount - k)) {
            answer += frequency[oddCount - k];
        }

        frequency[oddCount]++;
    }

    return answer;
}

int main() {
    vector<int> nums = {
        1, 1, 2, 1, 1
    };

    int k = 3;

    cout << "Number of nice subarrays: "
         << numberOfSubarrays(nums, k)
         << endl;

    return 0;
}
