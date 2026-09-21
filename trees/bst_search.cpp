#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* searchBST(TreeNode* root, int key) {
    while (root != nullptr) {
        if (root->val == key)
            return root;

        if (key < root->val)
            root = root->left;
        else
            root = root->right;
    }

    return nullptr;
}

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    int key = 6;

    TreeNode* result = searchBST(root, key);

    if (result)
        cout << "Found: " << result->val;
    else
        cout << "Value not found";

    return 0;
}
