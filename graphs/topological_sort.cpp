#include <bits/stdc++.h>
using namespace std;

void topoSort(int V, vector<int> adj[]) {
    vector<int> indegree(V,0);

    for(int i=0;i<V;i++){
        for(auto it: adj[i]) indegree[it]++;
    }

    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front(); q.pop();
        cout << node << " ";

        for(auto it: adj[node]){
            if(--indegree[it]==0) q.push(it);
        }
    }
}
