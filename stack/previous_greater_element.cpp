#include <bits/stdc++.h>
using namespace std;

vector<int> previousGreater(vector<int>& arr) {
    stack<int> st;
    vector<int> ans;

    for(int x : arr) {
        while(!st.empty() && st.top() <= x)
            st.pop();

        ans.push_back(st.empty() ? -1 : st.top());
        st.push(x);
    }
    return ans;
}
