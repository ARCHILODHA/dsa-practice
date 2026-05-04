int maxPath = INT_MIN;

int solve(TreeNode* root) {
    if(!root) return 0;

    int left = max(0, solve(root->left));
    int right = max(0, solve(root->right));

    maxPath = max(maxPath, left + right + root->val);

    return root->val + max(left, right);
}
