#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& M, int n) {
    stack<int> st;

    for(int i=0;i<n;i++)
        st.push(i);

    while(st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        if(M[a][b])
            st.push(b);
        else
            st.push(a);
    }

    int cand = st.top();

    for(int i=0;i<n;i++) {
        if(i!=cand && (M[cand][i] || !M[i][cand]))
            return -1;
    }

    return cand;
}
