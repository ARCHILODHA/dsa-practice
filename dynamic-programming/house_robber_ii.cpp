#include <bits/stdc++.h>
using namespace std;

// House Robber II
// Houses are arranged in a circle.
// Time: O(n)
// Space: O(1)

int robLinear(const vector<int>& nums, int start, int end) {
    int prev2 = 0;
    int prev1 = 0;

    for (int i = start; i <= end; i++) {
        int take = nums[i] + prev2;
        int skip = prev1;

        int current = max(take, skip);

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int &x : nums)
        cin >> x;

    if (n == 1) {
        cout << nums[0] << endl;
        return 0;
    }

    int excludeLast = robLinear(nums, 0, n - 2);
    int excludeFirst = robLinear(nums, 1, n - 1);

    cout << "Maximum amount: "
         << max(excludeLast, excludeFirst) << endl;

    return 0;
}
