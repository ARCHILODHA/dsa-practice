// Detect Cycle in Directed Graph using DFS

#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path){
    vis[node]=1;
    path[node]=1;

    for(int it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,path))
                return true;
        }
        else if(path[it])
            return true;
    }

    path[node]=0;
    return false;
}

int main(){
    int V=4;
    vector<vector<int>> adj(V);

    adj[0]={1};
    adj[1]={2};
    adj[2]={3};
    adj[3]={1};

    vector<int> vis(V,0),path(V,0);

    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,path)){
                cout<<"Cycle Found";
                return 0;
            }
        }
    }

    cout<<"No Cycle";
}
