#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trap(vector<int>& h) {
    stack<int> st;
    int ans = 0;

    for (int i = 0; i < h.size(); i++) {
        while (!st.empty() && h[i] > h[st.top()]) {
            int top = st.top();
            st.pop();

            if (st.empty()) break;

            int width = i - st.top() - 1;
            int height = min(h[i], h[st.top()]) - h[top];
            ans += width * height;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(h);
}
