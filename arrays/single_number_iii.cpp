#include <bits/stdc++.h>
using namespace std;

// Every element appears twice except two elements.
// Find those two unique elements.
//
// Uses XOR and the rightmost set bit.
//
// Time: O(n)
// Space: O(1), excluding the result.

vector<int> singleNumber(vector<int>& nums) {
    int xorAll = 0;

    for (int x : nums) {
        xorAll ^= x;
    }

    // Isolate the rightmost set bit.
    int bit = xorAll & -xorAll;

    int first = 0;
    int second = 0;

    for (int x : nums) {
        if (x & bit) {
            first ^= x;
        } else {
            second ^= x;
        }
    }

    return {first, second};
}

int main() {
    vector<int> nums = {
        1, 2, 1, 3, 2, 5
    };

    vector<int> result = singleNumber(nums);

    cout << "Unique elements: "
         << result[0] << " "
         << result[1] << endl;

    return 0;
}
