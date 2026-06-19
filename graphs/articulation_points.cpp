#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, -1), low(V), parent(V, -1);
        vector<bool> ap(V, false);
        int timer = 0;

        function<void(int)> dfs = [&](int u) {
            disc[u] = low[u] = timer++;
            int children = 0;

            for(int v : adj[u]) {
                if(disc[v] == -1) {
                    children++;
                    parent[v] = u;
                    dfs(v);

                    low[u] = min(low[u], low[v]);

                    if(parent[u] == -1 && children > 1) ap[u] = true;
                    if(parent[u] != -1 && low[v] >= disc[u]) ap[u] = true;
                }
                else if(v != parent[u])
                    low[u] = min(low[u], disc[v]);
            }
        };

        for(int i = 0; i < V; i++)
            if(disc[i] == -1) dfs(i);

        vector<int> ans;
        for(int i = 0; i < V; i++)
            if(ap[i]) ans.push_back(i);

        return ans.empty() ? vector<int>{-1} : ans;
    }
};
