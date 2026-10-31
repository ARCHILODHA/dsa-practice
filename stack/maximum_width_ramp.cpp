#include <bits/stdc++.h>
using namespace std;

int maxWidthRamp(vector<int>& nums) {
    int n = nums.size();

    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (st.empty() || nums[i] < nums[st.top()]) {
            st.push(i);
        }
    }

    int ans = 0;

    for (int j = n - 1; j >= 0; j--) {
        while (!st.empty() && nums[st.top()] <= nums[j]) {
            ans = max(ans, j - st.top());
            st.pop();
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << maxWidthRamp(nums);

    return 0;
}
