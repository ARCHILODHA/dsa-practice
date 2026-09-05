#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;

    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' ||
           c == '*' || c == '/' || c == '^';
}

string infixToPrefix(string expression) {
    // Reverse the expression.
    reverse(expression.begin(), expression.end());

    // Swap brackets.
    for (char& c : expression) {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    stack<char> st;
    string postfix;

    for (char c : expression) {

        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {

            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else if (isOperator(c)) {

            while (!st.empty() &&
                   st.top() != '(' &&
                   precedence(st.top()) > precedence(c)) {

                postfix += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    // Reverse postfix to obtain prefix.
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string expression = "(A-B/C)*(A/K-L)";

    cout << "Infix: " << expression << endl;

    cout << "Prefix: "
         << infixToPrefix(expression) << endl;

    return 0;
}
