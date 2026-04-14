void solve(int i, int j, vector<vector<int>>& m, string path, vector<string>& res) {
    int n = m.size();
    if(i==n-1 && j==n-1) {
        res.push_back(path);
        return;
    }

    if(i+1<n && m[i+1][j]==1) solve(i+1,j,m,path+'D',res);
    if(j+1<n && m[i][j+1]==1) solve(i,j+1,m,path+'R',res);
}
