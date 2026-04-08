vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V,1e9);
    dist[src]=0;

    for(int i=0;i<V-1;i++){
        for(auto e:edges){
            if(dist[e[0]]+e[2] < dist[e[1]])
                dist[e[1]] = dist[e[0]] + e[2];
        }
    }
    return dist;
}
