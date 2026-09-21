#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

pair<int, int> solve(TreeNode* root) {
    if (root == nullptr)
        return {0, 0};

    auto left = solve(root->left);
    auto right = solve(root->right);

    if (left.first > right.first) {
        return {left.first + 1, left.second + root->val};
    }

    if (right.first > left.first) {
        return {right.first + 1, right.second + root->val};
    }

    return {
        left.first + 1,
        root->val + max(left.second, right.second)
    };
}

int longestPathSum(TreeNode* root) {
    return solve(root).second;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Longest root-to-leaf path sum: "
         << longestPathSum(root);

    return 0;
}
