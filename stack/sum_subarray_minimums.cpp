#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const long long MOD = 1000000007;

// Find the sum of minimum elements of every subarray.
long long sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();

    vector<int> left(n);
    vector<int> right(n);

    stack<int> st;

    // Previous smaller element.
    for (int i = 0; i < n; i++) {

        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();

        if (st.empty())
            left[i] = i + 1;
        else
            left[i] = i - st.top();

        st.push(i);
    }

    while (!st.empty())
        st.pop();

    // Next smaller or equal element.
    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (st.empty())
            right[i] = n - i;
        else
            right[i] = st.top() - i;

        st.push(i);
    }

    long long answer = 0;

    for (int i = 0; i < n; i++) {
        long long contribution =
            (long long)arr[i] * left[i] * right[i];

        answer = (answer + contribution) % MOD;
    }

    return answer;
}

int main() {
    vector<int> arr = {
        3, 1, 2, 4
    };

    cout << "Sum of subarray minimums: "
         << sumSubarrayMins(arr) << endl;

    return 0;
}
