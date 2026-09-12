#include <bits/stdc++.h>
using namespace std;

// Find whether there exists a pair with absolute difference k.

bool hasPairWithDifference(vector<int>& nums, int k) {
    unordered_set<int> seen;

    for (int x : nums) {
        if (seen.count(x - k) || seen.count(x + k)) {
            return true;
        }

        seen.insert(x);
    }

    return false;
}

int main() {
    vector<int> nums = {5, 20, 3, 2, 50, 80};
    int k = 78;

    if (hasPairWithDifference(nums, k)) {
        cout << "Pair exists" << endl;
    } else {
        cout << "Pair does not exist" << endl;
    }

    return 0;
}
