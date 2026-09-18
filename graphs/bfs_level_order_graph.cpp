#include <bits/stdc++.h>
using namespace std;

// Print vertices grouped according to BFS levels.
void printLevels(
    int V,
    vector<vector<int>>& adj,
    int source
) {
    vector<int> visited(V, 0);
    queue<int> q;

    visited[source] = 1;
    q.push(source);

    int level = 0;

    while (!q.empty()) {
        int nodesInLevel = q.size();

        cout << "Level "
             << level
             << ": ";

        while (nodesInLevel--) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }

        cout << '\n';
        level++;
    }
}

int main() {
    int V = 7;
    vector<vector<int>> adj(V);

    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4},
        {2, 5},
        {2, 6}
    };

    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printLevels(V, adj, 0);

    return 0;
}
