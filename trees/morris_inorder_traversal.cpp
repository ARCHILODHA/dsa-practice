#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> morrisInorder(TreeNode* root) {
    vector<int> result;
    TreeNode* current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            result.push_back(current->val);
            current = current->right;
        } else {
            TreeNode* predecessor = current->left;

            while (predecessor->right != nullptr &&
                   predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = nullptr;
                result.push_back(current->val);
                current = current->right;
            }
        }
    }

    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = morrisInorder(root);

    for (int x : result)
        cout << x << " ";

    return 0;
}
