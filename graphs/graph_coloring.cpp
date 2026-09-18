#include <bits/stdc++.h>
using namespace std;

// Greedy graph coloring.
vector<int> colorGraph(
    int V,
    vector<vector<int>>& adj
) {
    vector<int> color(V, -1);

    color[0] = 0;

    for (int node = 1; node < V; ++node) {
        set<int> used;

        for (int neighbor : adj[node]) {
            if (color[neighbor] != -1)
                used.insert(color[neighbor]);
        }

        int c = 0;

        while (used.count(c))
            c++;

        color[node] = c;
    }

    return color;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {2, 4}
    };

    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> colors = colorGraph(V, adj);

    for (int i = 0; i < V; ++i) {
        cout << "Vertex "
             << i
             << " -> color "
             << colors[i] << '\n';
    }

    return 0;
}
