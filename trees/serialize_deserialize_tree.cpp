string serialize(TreeNode* root) {
    if(!root) return "N,";
    return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
}
