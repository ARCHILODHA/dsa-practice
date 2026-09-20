#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void postorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;

    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->val);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result;
    postorder(root, result);

    for (int x : result)
        cout << x << " ";

    return 0;
}
