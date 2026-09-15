#include <bits/stdc++.h>
using namespace std;

// Find the maximum sum rectangle in a 2D matrix.
//
// Uses Kadane's Algorithm by compressing columns.
//
// Time: O(rows^2 * cols)
// Space: O(cols)

int kadane(vector<int>& arr) {
    int current = arr[0];
    int best = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        current = max(arr[i], current + arr[i]);
        best = max(best, current);
    }

    return best;
}

int maximumSumRectangle(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int answer = INT_MIN;

    for (int top = 0; top < rows; top++) {

        vector<int> temp(cols, 0);

        for (int bottom = top; bottom < rows; bottom++) {

            for (int col = 0; col < cols; col++) {
                temp[col] += matrix[bottom][col];
            }

            answer = max(answer, kadane(temp));
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> matrix = {
        {1,  2, -1, -4, -20},
        {-8, -3, 4,  2,  1},
        {3,   8, 10, 1,  3},
        {-4, -1, 1,  7, -6}
    };

    cout << "Maximum rectangle sum: "
         << maximumSumRectangle(matrix)
         << endl;

    return 0;
}
