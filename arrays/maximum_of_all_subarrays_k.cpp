#include <bits/stdc++.h>
using namespace std;

// Find the maximum element in every window of size k.
//
// Uses a deque to maintain indices of useful elements.
//
// Time: O(n)
// Space: O(k)

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {

        // Remove indices outside the current window.
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements because they can never
        // become the maximum while nums[i] is in the window.
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {
        1, 3, -1, -3, 5, 3, 6, 7
    };

    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Window maximums: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
