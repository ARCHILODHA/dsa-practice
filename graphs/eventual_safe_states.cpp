// Eventual Safe States

#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node,vector<vector<int>>& graph,vector<int>& vis,vector<int>& path){

    vis[node]=1;
    path[node]=1;

    for(int x:graph[node]){
        if(!vis[x]){
            if(dfs(x,graph,vis,path))
                return true;
        }
        else if(path[x])
            return true;
    }

    path[node]=0;
    return false;
}

int main(){

    vector<vector<int>> graph={{1,2},{2,3},{5},{0},{5},{},{}};

    int n=graph.size();

    vector<int> vis(n,0),path(n,0);

    cout<<"Safe Nodes : ";

    for(int i=0;i<n;i++){

        if(!dfs(i,graph,vis,path))
            cout<<i<<" ";
    }

}
