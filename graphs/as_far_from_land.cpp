#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        if (q.empty() || q.size() == n * n) {
            return -1;
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int distance = -1;

        while (!q.empty()) {
            int size = q.size();
            distance++;

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr < 0 || nr >= n ||
                        nc < 0 || nc >= n ||
                        grid[nr][nc] != 0) {
                        continue;
                    }

                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return distance;
    }
};
