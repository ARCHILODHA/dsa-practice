vector<int> findOrder(int n, vector<vector<int>>& pre) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for(auto &p : pre) {
        adj[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }

    vector<int> order;

    while(!q.empty()){
        int node = q.front(); q.pop();
        order.push_back(node);

        for(auto &nbr : adj[node]){
            if(--indegree[nbr]==0)
                q.push(nbr);
        }
    }

    return order.size()==n ? order : vector<int>();
}
