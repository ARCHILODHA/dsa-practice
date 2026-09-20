#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minimumValue(TreeNode* root) {
    if (root == nullptr)
        return INT_MAX;

    int leftMin = minimumValue(root->left);
    int rightMin = minimumValue(root->right);

    return min(root->val, min(leftMin, rightMin));
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);

    cout << "Minimum value: " << minimumValue(root);

    return 0;
}
