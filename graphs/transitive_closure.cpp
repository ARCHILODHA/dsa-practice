#include <bits/stdc++.h>
using namespace std;

// Warshall's algorithm for transitive closure.
// reach[u][v] = 1 if v is reachable from u.
vector<vector<int>> transitiveClosure(
    vector<vector<int>> graph
) {
    int V = graph.size();

    vector<vector<int>> reach = graph;

    for (int i = 0; i < V; ++i)
        reach[i][i] = 1;

    for (int via = 0; via < V; ++via) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                reach[u][v] =
                    reach[u][v] ||
                    (reach[u][via] && reach[via][v]);
            }
        }
    }

    return reach;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    vector<vector<int>> reach =
        transitiveClosure(graph);

    cout << "Transitive Closure:\n";

    for (auto& row : reach) {
        for (int value : row)
            cout << value << " ";

        cout << '\n';
    }

    return 0;
}
