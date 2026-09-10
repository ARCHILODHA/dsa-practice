#include <bits/stdc++.h>
using namespace std;

// Find the length of the longest subarray with sum K.
// Works with positive, zero, and negative numbers.

int longestSubarraySumK(vector<int>& arr, int k) {
    unordered_map<long long, int> firstIndex;
    long long prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (prefixSum == k) {
            maxLength = i + 1;
        }

        if (firstIndex.count(prefixSum - k)) {
            maxLength = max(maxLength,
                            i - firstIndex[prefixSum - k]);
        }

        if (!firstIndex.count(prefixSum)) {
            firstIndex[prefixSum] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;

    cout << "Longest subarray length: "
         << longestSubarraySumK(arr, k) << endl;

    return 0;
}
