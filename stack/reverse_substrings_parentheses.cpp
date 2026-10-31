#include <bits/stdc++.h>
using namespace std;

string reverseParentheses(string s) {
    int n = s.size();

    vector<int> pairIndex(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        if (s[i] == '(') {
            st.push(i);
        }
        else if (s[i] == ')') {
            int j = st.top();
            st.pop();

            pairIndex[i] = j;
            pairIndex[j] = i;
        }
    }

    string ans;
    int direction = 1;

    for (int i = 0; i < n; i += direction) {

        if (s[i] == '(' || s[i] == ')') {
            i = pairIndex[i];
            direction = -direction;
        }
        else {
            ans.push_back(s[i]);
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << reverseParentheses(s);

    return 0;
}
