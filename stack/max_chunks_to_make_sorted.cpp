#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    stack<int> st;

    for (int num : arr) {

        int maxValue = num;

        while (!st.empty() && st.top() > num) {
            maxValue = max(maxValue, st.top());
            st.pop();
        }

        st.push(maxValue);
    }

    return st.size();
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxChunksToSorted(arr);

    return 0;
}
