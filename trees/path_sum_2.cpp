class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int sum){

        if(root == nullptr)
            return;

        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr && sum == root->val)
            ans.push_back(path);

        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        dfs(root, targetSum);

        return ans;
    }
};
