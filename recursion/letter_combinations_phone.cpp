#include <bits/stdc++.h>
using namespace std;

void solve(int index, string& digits, string& current,
           vector<string>& ans, vector<string>& mapping) {

    if (index == digits.size()) {
        ans.push_back(current);
        return;
    }

    string letters = mapping[digits[index] - '0'];

    for (char ch : letters) {
        current.push_back(ch);

        solve(index + 1, digits, current, ans, mapping);

        current.pop_back();
    }
}

int main() {
    string digits;
    cin >> digits;

    if (digits.empty()) return 0;

    vector<string> mapping = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> ans;
    string current;

    solve(0, digits, current, ans, mapping);

    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}
