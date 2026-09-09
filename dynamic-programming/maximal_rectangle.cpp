#include <bits/stdc++.h>
using namespace std;

// Maximal Rectangle of 1s in a Binary Matrix
// Time: O(rows * cols)
// Space: O(cols)

int largestRectangle(vector<int>& heights) {
    stack<int> st;
    int maximum = 0;

    for (int i = 0; i <= (int)heights.size(); i++) {
        int current =
            (i == heights.size()) ? 0 : heights[i];

        while (!st.empty() && current < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();

            int width = st.empty()
                      ? i
                      : i - st.top() - 1;

            maximum = max(
                maximum,
                height * width
            );
        }

        st.push(i);
    }

    return maximum;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<int> heights(cols, 0);
    int answer = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            cin >> value;

            if (value == 1)
                heights[j]++;
            else
                heights[j] = 0;
        }

        answer = max(
            answer,
            largestRectangle(heights)
        );
    }

    cout << "Maximum rectangle area: "
         << answer << endl;

    return 0;
}
