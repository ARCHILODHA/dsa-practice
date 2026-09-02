#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int rows, cols;

void bfs(vector<vector<char>>& grid, int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});

    grid[r][c] = '0';

    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto& direction : directions) {
            int nx = x + direction[0];
            int ny = y + direction[1];

            if (nx >= 0 && nx < rows &&
                ny >= 0 && ny < cols &&
                grid[nx][ny] == '1') {

                grid[nx][ny] = '0';
                q.push({nx, ny});
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    rows = grid.size();
    cols = grid[0].size();

    int islands = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (grid[i][j] == '1') {
                islands++;
                bfs(grid, i, j);
            }
        }
    }

    return islands;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0'},
        {'1', '0', '0', '1'},
        {'0', '0', '1', '1'},
        {'0', '0', '0', '0'}
    };

    cout << "Number of islands: " << numIslands(grid) << endl;

    return 0;
}
