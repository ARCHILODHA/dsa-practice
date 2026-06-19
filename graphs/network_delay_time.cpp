#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times,
                     int n, int k) {

    vector<pair<int,int>> adj[n+1];

    for(auto &t : times)
        adj[t[0]].push_back({t[1], t[2]});

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> dist(n+1, INT_MAX);

    dist[k] = 0;
    pq.push({0, k});

    while(!pq.empty()) {
        auto [d,node] = pq.top();
        pq.pop();

        for(auto [nbr,w] : adj[node]) {
            if(dist[nbr] > d + w) {
                dist[nbr] = d + w;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    return *max_element(dist.begin()+1, dist.end());
}
