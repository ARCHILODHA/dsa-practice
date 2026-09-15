#include <bits/stdc++.h>
using namespace std;

// Find the sum of the minimum element of every subarray.
//
// Uses monotonic stacks to determine how many subarrays
// use each element as their minimum.
//
// Time: O(n)
// Space: O(n)

long long sumSubarrayMins(vector<int>& arr) {
    const long long MOD = 1000000007;

    int n = arr.size();

    vector<int> left(n);
    vector<int> right(n);

    stack<int> st;

    // Previous smaller element.
    for (int i = 0; i < n; i++) {
        while (!st.empty() &&
               arr[st.top()] > arr[i]) {
            st.pop();
        }

        left[i] = st.empty()
                    ? i + 1
                    : i - st.top();

        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

    // Next smaller or equal element.
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() &&
               arr[st.top()] >= arr[i]) {
            st.pop();
        }

        right[i] = st.empty()
                     ? n - i
                     : st.top() - i;

        st.push(i);
    }

    long long answer = 0;

    for (int i = 0; i < n; i++) {
        long long contribution =
            1LL * arr[i] * left[i] * right[i];

        answer = (answer + contribution) % MOD;
    }

    return answer;
}

int main() {
    vector<int> arr = {
        3, 1, 2, 4
    };

    cout << "Sum of subarray minimums: "
         << sumSubarrayMins(arr)
         << endl;

    return 0;
}
