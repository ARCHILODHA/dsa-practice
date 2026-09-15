#include <bits/stdc++.h>
using namespace std;

// Split the array into k non-empty subarrays.
// Minimize the largest subarray sum.
//
// Binary Search on Answer.
//
// Time: O(n log(sum))
// Space: O(1)

bool canSplit(vector<int>& nums,
              int k,
              long long maximumAllowed) {

    int parts = 1;
    long long currentSum = 0;

    for (int x : nums) {
        if (currentSum + x <= maximumAllowed) {
            currentSum += x;
        } else {
            parts++;
            currentSum = x;

            if (parts > k) {
                return false;
            }
        }
    }

    return true;
}

long long splitArray(vector<int>& nums, int k) {
    long long low = *max_element(
        nums.begin(), nums.end()
    );

    long long high = accumulate(
        nums.begin(),
        nums.end(),
        0LL
    );

    long long answer = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canSplit(nums, k, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    vector<int> nums = {
        7, 2, 5, 10, 8
    };

    int k = 2;

    cout << "Minimum largest subarray sum: "
         << splitArray(nums, k)
         << endl;

    return 0;
}
