int prim(int n, vector<vector<pair<int,int>>>& adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<int> vis(n,0);

    pq.push({0,0});
    int cost = 0;

    while(!pq.empty()){
        auto [wt,node] = pq.top(); pq.pop();

        if(vis[node]) continue;
        vis[node]=1;
        cost += wt;

        for(auto &it : adj[node]){
            if(!vis[it.first]){
                pq.push({it.second, it.first});
            }
        }
    }
    return cost;
}
