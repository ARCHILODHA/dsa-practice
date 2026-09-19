#include <bits/stdc++.h>
using namespace std;

// Find the minimum time required for all oranges to become rotten.
int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 2)
                q.push({r, c});
            else if (grid[r][c] == 1)
                fresh++;
        }
    }

    int minutes = 0;
    int directions[4][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    while (!q.empty() && fresh > 0) {
        int size = q.size();

        while (size--) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& direction : directions) {
                int nr = r + direction[0];
                int nc = c + direction[1];

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

    cout << "Minimum time: "
         << orangesRotting(grid) << " minutes\n";

    return 0;
}
