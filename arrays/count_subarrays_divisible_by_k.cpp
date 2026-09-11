#include <bits/stdc++.h>
using namespace std;

// Count subarrays whose sum is divisible by k.
// Uses prefix sum remainders.

int subarraysDivByK(vector<int>& nums, int k) {
    vector<int> remainderCount(k, 0);

    remainderCount[0] = 1;

    int prefixSum = 0;
    int answer = 0;

    for (int x : nums) {
        prefixSum += x;

        int rem = prefixSum % k;

        if (rem < 0) {
            rem += k;
        }

        answer += remainderCount[rem];
        remainderCount[rem]++;
    }

    return answer;
}

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    cout << "Subarrays divisible by "
         << k << ": "
         << subarraysDivByK(nums, k) << endl;

    return 0;
}
