#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors,
                         vector<vector<int>>& edges) {
        int n = colors.size();

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<array<int, 26>> dp(n);
        for (auto& row : dp) {
            row.fill(0);
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int processed = 0;
        int answer = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            processed++;

            int color = colors[node] - 'a';
            dp[node][color]++;

            answer = max(answer, dp[node][color]);

            for (int neighbor : adj[node]) {
                for (int c = 0; c < 26; c++) {
                    dp[neighbor][c] = max(
                        dp[neighbor][c], dp[node][c]
                    );
                }

                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (processed != n) {
            return -1;
        }

        return answer;
    }
};
