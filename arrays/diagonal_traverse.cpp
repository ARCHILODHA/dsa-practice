#include <bits/stdc++.h>
using namespace std;

// Traverse a matrix diagonally in zig-zag order.

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    vector<int> result;

    for (int diagonal = 0;
         diagonal < rows + cols - 1;
         diagonal++) {

        vector<int> current;

        int rowStart = max(0, diagonal - cols + 1);
        int rowEnd = min(rows - 1, diagonal);

        for (int row = rowStart; row <= rowEnd; row++) {
            int col = diagonal - row;
            current.push_back(mat[row][col]);
        }

        if (diagonal % 2 == 0) {
            reverse(current.begin(), current.end());
        }

        for (int x : current) {
            result.push_back(x);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = findDiagonalOrder(mat);

    cout << "Diagonal traversal: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
