#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxA = 0;

    for(int i=0;i<=heights.size();i++){
        int h = (i == heights.size() ? 0 : heights[i]);

        while(!st.empty() && h < heights[st.top()]){
            int height = heights[st.top()];
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;
            maxA = max(maxA, height * width);
        }
        st.push(i);
    }
    return maxA;
}
