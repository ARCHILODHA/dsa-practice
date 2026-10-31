#include <bits/stdc++.h>
using namespace std;

vector<int> findPermutation(string s) {
    vector<int> ans;
    stack<int> st;

    int n = s.size();

    for (int i = 0; i <= n; i++) {

        st.push(i + 1);

        if (i == n || s[i] == 'I') {

            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    vector<int> ans = findPermutation(s);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
