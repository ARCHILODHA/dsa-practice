#include <bits/stdc++.h>
using namespace std;

// BFS traversal using an adjacency matrix.
vector<int> bfsMatrix(
    vector<vector<int>>& graph,
    int source
) {
    int V = graph.size();

    vector<int> visited(V, 0);
    vector<int> result;

    queue<int> q;

    visited[source] = 1;
    q.push(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        result.push_back(node);

        for (int neighbor = 0;
             neighbor < V;
             ++neighbor) {

            if (graph[node][neighbor] == 1 &&
                !visited[neighbor]) {

                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    vector<int> traversal =
        bfsMatrix(graph, 0);

    cout << "BFS traversal: ";

    for (int node : traversal)
        cout << node << " ";

    cout << '\n';

    return 0;
}
