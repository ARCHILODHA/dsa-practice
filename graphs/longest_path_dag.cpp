#include <bits/stdc++.h>
using namespace std;

// Find longest path distances from a source in a DAG.
void topoDFS(
    int node,
    vector<vector<pair<int, int>>>& adj,
    vector<int>& visited,
    stack<int>& st
) {
    visited[node] = 1;

    for (auto [neighbor, weight] : adj[node]) {
        if (!visited[neighbor])
            topoDFS(neighbor, adj, visited, st);
    }

    st.push(node);
}

vector<int> longestPath(
    int V,
    vector<vector<pair<int, int>>>& adj,
    int source
) {
    vector<int> visited(V, 0);
    stack<int> st;

    for (int i = 0; i < V; ++i) {
        if (!visited[i])
            topoDFS(i, adj, visited, st);
    }

    const int NEG_INF = -1e9;
    vector<int> dist(V, NEG_INF);
    dist[source] = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] == NEG_INF)
            continue;

        for (auto [neighbor, weight] : adj[node]) {
            dist[neighbor] =
                max(dist[neighbor],
                    dist[node] + weight);
        }
    }

    return dist;
}

int main() {
    int V = 6;

    vector<vector<pair<int, int>>> adj(V);

    adj[0].push_back({1, 5});
    adj[0].push_back({2, 3});
    adj[1].push_back({3, 6});
    adj[2].push_back({3, 4});
    adj[2].push_back({4, 2});
    adj[3].push_back({5, 1});
    adj[4].push_back({5, 3});

    vector<int> dist = longestPath(V, adj, 0);

    cout << "Longest path distances:\n";

    for (int i = 0; i < V; ++i) {
        if (dist[i] == -1e9)
            cout << i << " -> unreachable\n";
        else
            cout << i << " -> " << dist[i] << '\n';
    }

    return 0;
}
