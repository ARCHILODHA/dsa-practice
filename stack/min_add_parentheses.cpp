#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
    int open = 0;
    int additions = 0;

    for (char ch : s) {

        if (ch == '(') {
            open++;
        }
        else if (ch == ')') {

            if (open > 0) {
                open--;
            }
            else {
                additions++;
            }
        }
    }

    return additions + open;
}

int main() {
    string s;
    cin >> s;

    cout << minAddToMakeValid(s);

    return 0;
}
