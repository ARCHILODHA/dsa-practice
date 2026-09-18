#include <bits/stdc++.h>
using namespace std;

void dfs(
    int node,
    vector<vector<int>>& adj,
    vector<int>& visited
) {
    visited[node] = 1;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countComponents(
    int V,
    vector<vector<int>>& adj
) {
    vector<int> visited(V, 0);
    int components = 0;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }

    return components;
}

int main() {
    int V = 7;
    vector<vector<int>> adj(V);

    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {3, 4},
        {5, 6}
    };

    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Connected components = "
         << countComponents(V, adj) << '\n';

    return 0;
}
