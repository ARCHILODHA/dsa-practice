// Rotting Oranges

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){

    vector<vector<int>> grid={
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int n=grid.size();
    int m=grid[0].size();

    queue<pair<int,int>> q;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j]==2)
                q.push({i,j});

    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};

    while(!q.empty()){

        auto cur=q.front();
        q.pop();

        for(int k=0;k<4;k++){

            int x=cur.first+dx[k];
            int y=cur.second+dy[k];

            if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1){

                grid[x][y]=2;
                q.push({x,y});

            }

        }

    }

    cout<<"Completed";
}
