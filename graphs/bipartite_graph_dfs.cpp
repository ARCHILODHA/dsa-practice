#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int col,
         vector<vector<int>>& graph,
         vector<int>& color) {

    color[node] = col;

    for(int nbr : graph[node]) {
        if(color[nbr] == -1) {
            if(!dfs(nbr, 1-col, graph, color))
                return false;
        }
        else if(color[nbr] == col)
            return false;
    }
    return true;
}
