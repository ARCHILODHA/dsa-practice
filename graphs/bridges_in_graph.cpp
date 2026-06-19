#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> bridges;

    void dfs(int node, int parent, vector<int> adj[],
             vector<int>& disc, vector<int>& low, int& timer) {

        disc[node] = low[node] = timer++;

        for(int nbr : adj[node]) {
            if(nbr == parent) continue;

            if(disc[nbr] == -1) {
                dfs(nbr, node, adj, disc, low, timer);

                low[node] = min(low[node], low[nbr]);

                if(low[nbr] > disc[node])
                    bridges.push_back({node, nbr});
            }
            else {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }
};
