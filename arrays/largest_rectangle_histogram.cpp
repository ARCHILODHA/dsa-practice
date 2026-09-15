#include <bits/stdc++.h>
using namespace std;

// Find the largest rectangular area in a histogram.
//
// Uses a monotonic increasing stack.
//
// Time: O(n)
// Space: O(n)

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    stack<int> st;
    int maximumArea = 0;

    for (int i = 0; i <= n; i++) {
        int currentHeight =
            (i == n) ? 0 : heights[i];

        while (!st.empty() &&
               currentHeight < heights[st.top()]) {

            int height = heights[st.top()];
            st.pop();

            int width;

            if (st.empty()) {
                width = i;
            } else {
                width = i - st.top() - 1;
            }

            maximumArea =
                max(maximumArea, height * width);
        }

        st.push(i);
    }

    return maximumArea;
}

int main() {
    vector<int> heights = {
        2, 1, 5, 6, 2, 3
    };

    cout << "Largest rectangle area: "
         << largestRectangleArea(heights)
         << endl;

    return 0;
}
