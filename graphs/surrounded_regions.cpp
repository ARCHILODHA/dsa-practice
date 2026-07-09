// Surrounded Regions

#include<iostream>
#include<vector>
using namespace std;

void dfs(int i,int j,vector<vector<char>>& board){

    if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!='O')
        return;

    board[i][j]='S';

    dfs(i+1,j,board);
    dfs(i-1,j,board);
    dfs(i,j+1,board);
    dfs(i,j-1,board);

}

int main(){

    vector<vector<char>> board={
        {'X','X','X'},
        {'X','O','X'},
        {'X','X','X'}
    };

    dfs(1,1,board);

    cout<<"Done";

}
