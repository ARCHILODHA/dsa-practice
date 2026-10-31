#include <bits/stdc++.h>
using namespace std;

long long sumSubarrayRanges(vector<int>& nums) {
    int n = nums.size();

    vector<int> left(n), right(n);
    stack<int> st;

    // Contribution as minimum
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] >= nums[i])
            st.pop();

        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] > nums[i])
            st.pop();

        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    long long minSum = 0;

    for (int i = 0; i < n; i++) {
        minSum += 1LL * nums[i] * (i - left[i]) * (right[i] - i);
    }

    while (!st.empty()) st.pop();

    // Contribution as maximum
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] <= nums[i])
            st.pop();

        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] < nums[i])
            st.pop();

        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    long long maxSum = 0;

    for (int i = 0; i < n; i++) {
        maxSum += 1LL * nums[i] * (i - left[i]) * (right[i] - i);
    }

    return maxSum - minSum;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << sumSubarrayRanges(nums);

    return 0;
}
