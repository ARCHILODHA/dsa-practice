#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1) {
            return 0;
        }

        if (m > 1 && n > 1 &&
            grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        if (m == 1 && n > 1 && grid[0][1] > 1) {
            return -1;
        }

        if (n == 1 && m > 1 && grid[1][0] > 1) {
            return -1;
        }

        vector<vector<int>> dist(
            m, vector<int>(n, INT_MAX)
        );

        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [time, r, c] = pq.top();
            pq.pop();

            if (time != dist[r][c]) {
                continue;
            }

            if (r == m - 1 && c == n - 1) {
                return time;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n) {
                    continue;
                }

                int nextTime = time + 1;

                if (nextTime < grid[nr][nc]) {
                    int difference = grid[nr][nc] - nextTime;

                    if (difference % 2 == 1) {
                        nextTime = grid[nr][nc];
                    } else {
                        nextTime = grid[nr][nc] + 1;
                    }
                }

                if (nextTime < dist[nr][nc]) {
                    dist[nr][nc] = nextTime;
                    pq.push({nextTime, nr, nc});
                }
            }
        }

        return -1;
    }
};
