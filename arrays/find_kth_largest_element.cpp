#include <bits/stdc++.h>
using namespace std;

// Find the kth largest element using a min heap.
//
// Time: O(n log k)
// Space: O(k)

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int x : nums) {
        minHeap.push(x);

        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}

int main() {
    vector<int> nums = {
        3, 2, 1, 5, 6, 4
    };

    int k = 2;

    cout << "Kth largest element: "
         << findKthLargest(nums, k) << endl;

    return 0;
}
