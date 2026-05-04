map<int, vector<int>> mp;

void dfs(TreeNode* root, int hd) {
    if(!root) return;

    mp[hd].push_back(root->val);
    dfs(root->left, hd - 1);
    dfs(root->right, hd + 1);
}
