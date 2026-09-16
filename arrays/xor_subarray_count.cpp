#include <bits/stdc++.h>
using namespace std;

// Count the number of subarrays having XOR equal to k.
//
// Prefix XOR property:
// prefixXor[i] ^ prefixXor[j] = k
//
// Therefore:
// prefixXor[j] = prefixXor[i] ^ k
//
// Time: O(n)
// Space: O(n)

int countSubarraysWithXor(vector<int>& nums, int k) {
    unordered_map<int, int> frequency;

    frequency[0] = 1;

    int prefixXor = 0;
    int count = 0;

    for (int x : nums) {
        prefixXor ^= x;

        int required = prefixXor ^ k;

        if (frequency.count(required)) {
            count += frequency[required];
        }

        frequency[prefixXor]++;
    }

    return count;
}

int main() {
    vector<int> nums = {
        4, 2, 2, 6, 4
    };

    int k = 6;

    cout << "Number of subarrays: "
         << countSubarraysWithXor(nums, k)
         << endl;

    return 0;
}
