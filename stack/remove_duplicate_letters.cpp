#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> lastIndex(256, -1);
    vector<bool> visited(256, false);

    for (int i = 0; i < s.size(); i++) {
        lastIndex[(unsigned char)s[i]] = i;
    }

    string st;

    for (int i = 0; i < s.size(); i++) {
        unsigned char ch = s[i];

        if (visited[ch]) continue;

        while (!st.empty() &&
               st.back() > s[i] &&
               lastIndex[(unsigned char)st.back()] > i) {

            visited[(unsigned char)st.back()] = false;
            st.pop_back();
        }

        st.push_back(s[i]);
        visited[ch] = true;
    }

    return st;
}

int main() {
    string s;
    cin >> s;

    cout << removeDuplicateLetters(s);

    return 0;
}
