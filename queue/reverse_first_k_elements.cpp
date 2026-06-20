#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int>& q, int k) {
    stack<int> st;

    for(int i=0;i<k;i++) {
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    int rem = q.size() - k;

    while(rem--) {
        q.push(q.front());
        q.pop();
    }
}
