#include <bits/stdc++.h>
using namespace std;

void solve(string s, int open, int close) {
    if (open == 0 && close == 0) {
        cout << s << endl;
        return;
    }

    if (open > 0)
        solve(s + "(", open - 1, close);

    if (close > open)
        solve(s + ")", open, close - 1);
}
