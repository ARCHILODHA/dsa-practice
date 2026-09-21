#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void findPaths(TreeNode* root,
               vector<int>& path,
               vector<vector<int>>& result) {
    if (root == nullptr)
        return;

    path.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr) {
        result.push_back(path);
    } else {
        findPaths(root->left, path, result);
        findPaths(root->right, path, result);
    }

    path.pop_back();
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> result;
    vector<int> path;

    findPaths(root, path, result);

    for (auto& p : result) {
        for (int x : p)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
