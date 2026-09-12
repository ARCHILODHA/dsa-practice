#include <bits/stdc++.h>
using namespace std;

// Find an element appearing more than n/2 times.
// Uses Moore's Voting Algorithm.

int majorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }

        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Verify the candidate.
    count = 0;

    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return candidate;
    }

    return -1;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority element: "
         << majorityElement(nums) << endl;

    return 0;
}
