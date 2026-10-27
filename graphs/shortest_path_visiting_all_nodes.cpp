#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        if (n <= 1) {
            return 0;
        }

        int targetMask = (1 << n) - 1;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(
            n, vector<bool>(1 << n, false)
        );

        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            q.push({i, mask});
            visited[i][mask] = true;
        }

        int distance = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [node, mask] = q.front();
                q.pop();

                if (mask == targetMask) {
                    return distance;
                }

                for (int neighbor : graph[node]) {
                    int newMask = mask | (1 << neighbor);

                    if (!visited[neighbor][newMask]) {
                        visited[neighbor][newMask] = true;
                        q.push({neighbor, newMask});
                    }
                }
            }

            distance++;
        }

        return -1;
    }
};
