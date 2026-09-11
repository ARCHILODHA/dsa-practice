#include <bits/stdc++.h>
using namespace std;

// Find the minimum number of swaps required to group
// all 1s together in a binary array.

int minSwaps(vector<int>& nums) {
    int totalOnes = 0;

    for (int x : nums) {
        totalOnes += x;
    }

    if (totalOnes <= 1) {
        return 0;
    }

    int currentOnes = 0;

    // Count ones in the first window.
    for (int i = 0; i < totalOnes; i++) {
        currentOnes += nums[i];
    }

    int maxOnes = currentOnes;

    // Sliding window of size totalOnes.
    for (int right = totalOnes; right < nums.size(); right++) {
        currentOnes += nums[right];
        currentOnes -= nums[right - totalOnes];

        maxOnes = max(maxOnes, currentOnes);
    }

    return totalOnes - maxOnes;
}

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};

    cout << "Minimum swaps: "
         << minSwaps(nums) << endl;

    return 0;
}
