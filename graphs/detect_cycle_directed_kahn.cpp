// Detect Cycle using Kahn's Algorithm

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int V=4;

    vector<vector<int>> adj(V);

    adj[0]={1};
    adj[1]={2};
    adj[2]={3};
    adj[3]={1};

    vector<int> indegree(V,0);

    for(int i=0;i<V;i++)
        for(int x:adj[i])
            indegree[x]++;

    queue<int> q;

    for(int i=0;i<V;i++)
        if(indegree[i]==0)
            q.push(i);

    int count=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;

        for(int x:adj[node]){
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }
    }

    if(count==V)
        cout<<"No Cycle";
    else
        cout<<"Cycle Exists";
}
