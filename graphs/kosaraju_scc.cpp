void dfs1(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj) {
    vis[node] = 1;
    for(auto it : adj[node])
        if(!vis[it]) dfs1(it, vis, st, adj);
    st.push(node);
}

void dfs2(int node, vector<int>& vis, vector<vector<int>>& rev) {
    vis[node] = 1;
    for(auto it : rev[node])
        if(!vis[it]) dfs2(it, vis, rev);
}
