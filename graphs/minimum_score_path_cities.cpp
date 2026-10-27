#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int weight = road[2];

            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        int answer = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto [neighbor, weight] : adj[node]) {
                answer = min(answer, weight);

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return answer;
    }
};
