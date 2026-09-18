#include <bits/stdc++.h>
using namespace std;

// Reconstruct one shortest path between source and target.
vector<int> getPath(
    int V,
    vector<vector<int>>& adj,
    int source,
    int target
) {
    vector<int> parent(V, -1);
    vector<int> visited(V, 0);
    queue<int> q;

    visited[source] = 1;
    q.push(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    if (!visited[target])
        return {};

    vector<int> path;

    for (int node = target; node != -1; node = parent[node])
        path.push_back(node);

    reverse(path.begin(), path.end());

    return path;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {0, 3},
        {3, 4},
        {4, 5},
        {2, 5}
    };

    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> path = getPath(V, adj, 0, 5);

    if (path.empty()) {
        cout << "No path\n";
    } else {
        cout << "Shortest path: ";

        for (int node : path)
            cout << node << " ";

        cout << '\n';
    }

    return 0;
}
