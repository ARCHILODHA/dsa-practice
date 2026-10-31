#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    stack<int> st;

    int result = 0;
    int number = 0;
    int sign = 1;

    for (int i = 0; i < s.size(); i++) {

        char ch = s[i];

        if (isdigit(ch)) {
            number = number * 10 + (ch - '0');
        }

        else if (ch == '+') {
            result += sign * number;
            number = 0;
            sign = 1;
        }

        else if (ch == '-') {
            result += sign * number;
            number = 0;
            sign = -1;
        }

        else if (ch == '(') {
            st.push(result);
            st.push(sign);

            result = 0;
            sign = 1;
        }

        else if (ch == ')') {
            result += sign * number;
            number = 0;

            result *= st.top();
            st.pop();

            result += st.top();
            st.pop();
        }
    }

    result += sign * number;

    return result;
}

int main() {
    string s;
    getline(cin, s);

    cout << calculate(s);

    return 0;
}
