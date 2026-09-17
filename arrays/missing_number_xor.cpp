#include <bits/stdc++.h>
using namespace std;

// Find the missing number from [0, n].
//
// Uses XOR instead of mathematical summation.
//
// Time: O(n)
// Space: O(1)

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int answer = n;

    for (int i = 0; i < n; i++) {
        answer ^= i;
        answer ^= nums[i];
    }

    return answer;
}

int main() {
    vector<int> nums = {3, 0, 1};

    cout << "Missing number: "
         << missingNumber(nums) << endl;

    return 0;
}
