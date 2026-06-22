#include <bits/stdc++.h>
using namespace std;

bool redundantBrackets(string s) {
    stack<char> st;

    for(char ch : s) {
        if(ch == ')') {
            bool op = false;

            while(!st.empty() && st.top()!='(') {
                char top = st.top();
                if(top=='+' || top=='-' ||
                   top=='*' || top=='/')
                    op = true;
                st.pop();
            }

            st.pop();

            if(!op) return true;
        }
        else {
            st.push(ch);
        }
    }
    return false;
}
