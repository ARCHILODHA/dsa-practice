TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root || root==p || root==q) return root;

    auto left = lca(root->left,p,q);
    auto right = lca(root->right,p,q);

    if(left && right) return root;
    return left?left:right;
}
