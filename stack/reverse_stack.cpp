#include <bits/stdc++.h>
using namespace std;

void insertBottom(stack<int>& st, int x) {
    if(st.empty()) {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();

    insertBottom(st, x);

    st.push(top);
}

void reverseStack(stack<int>& st) {
    if(st.empty()) return;

    int top = st.top();
    st.pop();

    reverseStack(st);
    insertBottom(st, top);
}
