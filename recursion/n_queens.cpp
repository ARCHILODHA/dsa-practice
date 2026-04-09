bool isSafe(int row,int col,vector<string>& board,int n){
    for(int i=0;i<col;i++)
        if(board[row][i]=='Q') return false;
    return true;
}
