#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(
            n, vector<bool>(n, false)
        );

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= n || c < 0 || c >= n ||
                grid[r][c] == 0 || visited[r][c]) {
                return;
            }

            visited[r][c] = true;
            q.push({r, c});

            for (int i = 0; i < 4; i++) {
                dfs(r + dr[i], c + dc[i]);
            }
        };

        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    found = true;
                }
            }
        }

        int distance = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr < 0 || nr >= n ||
                        nc < 0 || nc >= n ||
                        visited[nr][nc]) {
                        continue;
                    }

                    if (grid[nr][nc] == 1) {
                        return distance;
                    }

                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }

            distance++;
        }

        return -1;
    }
};
