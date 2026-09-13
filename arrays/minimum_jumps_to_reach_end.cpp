#include <bits/stdc++.h>
using namespace std;

// Find the minimum number of jumps required to reach
// the last index.
//
// Each element represents the maximum jump length.
//
// Time: O(n)
// Space: O(1)

int jump(vector<int>& nums) {
    if (nums.size() <= 1) {
        return 0;
    }

    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);

        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }

    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << "Minimum jumps: "
         << jump(nums) << endl;

    return 0;
}
