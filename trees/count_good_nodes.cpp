class Solution {
public:

    int dfs(TreeNode* root, int mx){

        if(root == nullptr)
            return 0;

        int ans = 0;

        if(root->val >= mx){
            ans = 1;
            mx = root->val;
        }

        ans += dfs(root->left, mx);
        ans += dfs(root->right, mx);

        return ans;
    }

    int goodNodes(TreeNode* root) {

        return dfs(root, root->val);
    }
};
