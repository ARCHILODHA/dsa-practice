#include <bits/stdc++.h>
using namespace std;

// An undirected connected graph has an Eulerian path
// when it contains either 0 or 2 vertices of odd degree.
bool hasEulerianPath(
    int V,
    vector<vector<int>>& adj
) {
    int odd = 0;

    for (int i = 0; i < V; ++i) {
        if (adj[i].size() % 2 != 0)
            odd++;
    }

    return odd == 0 || odd == 2;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},
        {0, 2}
    };

    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << (hasEulerianPath(V, adj)
        ? "Eulerian path degree condition satisfied"
        : "No Eulerian path") << '\n';

    return 0;
}
