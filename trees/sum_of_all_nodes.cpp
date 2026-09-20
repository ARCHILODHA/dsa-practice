#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumNodes(TreeNode* root) {
    if (root == nullptr)
        return 0;

    return root->val +
           sumNodes(root->left) +
           sumNodes(root->right);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->right->right = new TreeNode(20);

    cout << "Sum of nodes: " << sumNodes(root);

    return 0;
}
