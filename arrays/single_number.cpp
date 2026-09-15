#include <bits/stdc++.h>
using namespace std;

// Every element appears twice except one element.
// Find the element that appears only once.
//
// Key idea:
// a ^ a = 0
// a ^ 0 = a
//
// Time: O(n)
// Space: O(1)

int singleNumber(vector<int>& nums) {
    int answer = 0;

    for (int x : nums) {
        answer ^= x;
    }

    return answer;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    cout << "Single number: "
         << singleNumber(nums) << endl;

    return 0;
}
