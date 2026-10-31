#include <bits/stdc++.h>
using namespace std;

vector<int> previousSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans = previousSmaller(arr);

    for (int x : ans) cout << x << " ";

    return 0;
}
