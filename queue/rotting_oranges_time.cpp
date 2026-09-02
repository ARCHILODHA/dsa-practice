#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (grid[i][j] == 2)
                q.push({i, j});

            else if (grid[i][j] == 1)
                fresh++;
        }
    }

    int minutes = 0;

    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    while (!q.empty() && fresh > 0) {
        int size = q.size();

        while (size--) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = 2;
                    fresh--;

                    q.push({nr, nc});
                }
            }
        }

        minutes++;
    }

    return fresh == 0 ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << "Minutes required: "
         << orangesRotting(grid) << endl;

    return 0;
}
