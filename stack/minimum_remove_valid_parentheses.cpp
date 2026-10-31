#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s) {
    stack<int> st;
    vector<bool> remove(s.size(), false);

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '(') {
            st.push(i);
        }
        else if (s[i] == ')') {

            if (st.empty()) {
                remove[i] = true;
            }
            else {
                st.pop();
            }
        }
    }

    while (!st.empty()) {
        remove[st.top()] = true;
        st.pop();
    }

    string ans;

    for (int i = 0; i < s.size(); i++) {
        if (!remove[i]) {
            ans.push_back(s[i]);
        }
    }

    return ans;
}

int main() {
    string s;
    getline(cin, s);

    cout << minRemoveToMakeValid(s);

    return 0;
}
