void flatten(TreeNode* root) {
    if(!root) return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* temp = root->right;
    root->right = root->left;
    root->left = NULL;

    TreeNode* curr = root;
    while(curr->right) curr = curr->right;

    curr->right = temp;
}
