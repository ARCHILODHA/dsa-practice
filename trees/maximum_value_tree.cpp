#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maximumValue(TreeNode* root) {
    if (root == nullptr)
        return INT_MIN;

    int leftMax = maximumValue(root->left);
    int rightMax = maximumValue(root->right);

    return max(root->val, max(leftMax, rightMax));
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(25);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(30);

    cout << "Maximum value: " << maximumValue(root);

    return 0;
}
