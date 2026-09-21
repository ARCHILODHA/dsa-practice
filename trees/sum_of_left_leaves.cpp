#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumLeftLeaves(TreeNode* root) {
    if (root == nullptr)
        return 0;

    int sum = 0;

    if (root->left != nullptr &&
        root->left->left == nullptr &&
        root->left->right == nullptr) {
        sum += root->left->val;
    }

    sum += sumLeftLeaves(root->left);
    sum += sumLeftLeaves(root->right);

    return sum;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Sum of left leaves: "
         << sumLeftLeaves(root);

    return 0;
}
