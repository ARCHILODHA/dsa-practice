#include <bits/stdc++.h>
using namespace std;

// Shortest path when every edge has weight 0 or 1.
vector<int> zeroOneBFS(
    int V,
    vector<vector<pair<int, int>>>& adj,
    int source
) {
    const int INF = 1e9;

    vector<int> dist(V, INF);
    deque<int> dq;

    dist[source] = 0;
    dq.push_front(source);

    while (!dq.empty()) {
        int node = dq.front();
        dq.pop_front();

        for (auto [neighbor, weight] : adj[node]) {
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] =
                    dist[node] + weight;

                if (weight == 0)
                    dq.push_front(neighbor);
                else
                    dq.push_back(neighbor);
            }
        }
    }

    return dist;
}

int main() {
    int V = 5;

    vector<vector<pair<int, int>>> adj(V);

    auto addEdge = [&](int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    };

    addEdge(0, 1, 0);
    addEdge(0, 2, 1);
    addEdge(1, 2, 1);
    addEdge(1, 3, 0);
    addEdge(2, 4, 0);
    addEdge(3, 4, 1);

    vector<int> dist = zeroOneBFS(V, adj, 0);

    for (int i = 0; i < V; ++i)
        cout << "Distance to " << i
             << " = " << dist[i] << '\n';

    return 0;
}
