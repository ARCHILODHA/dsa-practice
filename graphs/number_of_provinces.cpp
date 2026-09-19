#include <bits/stdc++.h>
using namespace std;

// Count connected components represented by an adjacency matrix.
void dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
    visited[node] = 1;

    for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
        if (graph[node][neighbor] == 1 && !visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int findProvinces(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0);
    int provinces = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            provinces++;
            dfs(i, graph, visited);
        }
    }

    return provinces;
}

int main() {
    vector<vector<int>> graph = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "Number of provinces: "
         << findProvinces(graph) << '\n';

    return 0;
}
