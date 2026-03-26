#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, src});

    while(!pq.empty()){
        auto [d, node] = pq.top(); pq.pop();

        for(auto [adjNode, wt] : adj[node]){
            if(d + wt < dist[adjNode]){
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
