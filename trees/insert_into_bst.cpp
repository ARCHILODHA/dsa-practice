#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int key) {
    if (root == nullptr)
        return new TreeNode(key);

    if (key < root->val)
        root->left = insertIntoBST(root->left, key);
    else
        root->right = insertIntoBST(root->right, key);

    return root;
}

void inorder(TreeNode* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 12);

    cout << "BST after insertion: ";
    inorder(root);

    return 0;
}
