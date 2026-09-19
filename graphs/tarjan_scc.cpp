#include <bits/stdc++.h>
using namespace std;

// Tarjan's algorithm finds strongly connected components.
class TarjanSCC {
    int timer = 0;

    vector<int> discovery;
    vector<int> low;
    vector<int> inStack;
    stack<int> st;

    vector<vector<int>> components;

    void dfs(int node, vector<vector<int>>& adj) {
        discovery[node] = low[node] = timer++;
        st.push(node);
        inStack[node] = 1;

        for (int neighbor : adj[node]) {
            if (discovery[neighbor] == -1) {
                dfs(neighbor, adj);
                low[node] = min(low[node], low[neighbor]);
            }
            else if (inStack[neighbor]) {
                low[node] =
                    min(low[node], discovery[neighbor]);
            }
        }

        // Node is the root of an SCC.
        if (low[node] == discovery[node]) {
            vector<int> component;

            while (true) {
                int current = st.top();
                st.pop();

                inStack[current] = 0;
                component.push_back(current);

                if (current == node)
                    break;
            }

            components.push_back(component);
        }
    }

public:
    vector<vector<int>> findSCC(
        int V,
        vector<vector<int>>& adj
    ) {
        discovery.assign(V, -1);
        low.assign(V, -1);
        inStack.assign(V, 0);

        for (int i = 0; i < V; ++i) {
            if (discovery[i] == -1)
                dfs(i, adj);
        }

        return components;
    }
};

int main() {
    int V = 5;

    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(3);

    TarjanSCC solver;

    vector<vector<int>> components =
        solver.findSCC(V, adj);

    cout << "Strongly Connected Components:\n";

    for (auto& component : components) {
        for (int node : component)
            cout << node << " ";

        cout << '\n';
    }

    return 0;
}
