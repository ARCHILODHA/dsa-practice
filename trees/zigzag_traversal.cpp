vector<vector<int>> zigzag(TreeNode* root){
    vector<vector<int>> res;
    if(!root) return res;

    queue<TreeNode*> q;
    q.push(root);
    bool left=true;

    while(!q.empty()){
        int n=q.size();
        vector<int> row(n);

        for(int i=0;i<n;i++){
            auto node=q.front(); q.pop();
            int idx = left? i : n-i-1;
            row[idx]=node->val;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        left=!left;
        res.push_back(row);
    }
    return res;
}
