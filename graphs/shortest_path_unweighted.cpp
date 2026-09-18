#include <bits/stdc++.h>
using namespace std;

// Find shortest distance from source in an unweighted graph.
vector<int> shortestPath(
    int V,
    vector<vector<int>>& adj,
    int source
) {
    vector<int> dist(V, -1);
    queue<int> q;

    dist[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3},
        {3, 4},
        {4, 5}
    };

    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist = shortestPath(V, adj, 0);

    for (int i = 0; i < V; ++i) {
        cout << "Distance from 0 to "
             << i << " = " << dist[i] << '\n';
    }

    return 0;
}
