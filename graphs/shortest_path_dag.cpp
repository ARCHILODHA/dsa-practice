#include <bits/stdc++.h>
using namespace std;

void topoSort(int node,
              vector<pair<int,int>> adj[],
              vector<int>& vis,
              stack<int>& st) {

    vis[node] = 1;

    for(auto it : adj[node])
        if(!vis[it.first])
            topoSort(it.first, adj, vis, st);

    st.push(node);
}
