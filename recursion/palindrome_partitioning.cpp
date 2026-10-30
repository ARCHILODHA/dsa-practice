#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right])
            return false;

        left++;
        right--;
    }

    return true;
}

void solve(int index, string& s, vector<string>& current,
           vector<vector<string>>& ans) {

    if (index == s.size()) {
        ans.push_back(current);
        return;
    }

    for (int i = index; i < s.size(); i++) {

        if (isPalindrome(s, index, i)) {

            current.push_back(s.substr(index, i - index + 1));

            solve(i + 1, s, current, ans);

            current.pop_back();
        }
    }
}

int main() {
    string s;
    cin >> s;

    vector<string> current;
    vector<vector<string>> ans;

    solve(0, s, current, ans);

    for (auto& partition : ans) {
        for (string part : partition)
            cout << part << " ";

        cout << endl;
    }

    return 0;
}
