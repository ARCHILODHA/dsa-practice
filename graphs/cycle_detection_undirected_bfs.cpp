#include <bits/stdc++.h>
using namespace std;

// Detect a cycle in an undirected graph using BFS.
bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<int> visited(V, 0);

    for (int start = 0; start < V; ++start) {
        if (visited[start]) continue;

        queue<pair<int, int>> q;
        q.push({start, -1});
        visited[start] = 1;

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push({neighbor, node});
                } 
                else if (neighbor != parent) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 4);

    cout << (hasCycle(V, adj)
        ? "Cycle exists"
        : "No cycle") << '\n';

    return 0;
}
