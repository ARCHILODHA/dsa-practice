#include <bits/stdc++.h>
using namespace std;

// For every element, find the next greater element
// to its right.
//
// Uses a monotonic stack.
//
// Time: O(n)
// Space: O(n)

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();

    vector<int> result(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }

        st.push(nums[i]);
    }

    return result;
}

int main() {
    vector<int> nums = {
        4, 5, 2, 25
    };

    vector<int> result = nextGreaterElements(nums);

    cout << "Next greater elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
