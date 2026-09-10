#include <bits/stdc++.h>
using namespace std;

// Rotate an n x n matrix by 90 degrees clockwise.
// Approach: transpose + reverse every row.

void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse every row.
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrix(matrix);

    for (auto& row : matrix) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
