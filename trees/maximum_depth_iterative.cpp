#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;

    queue<TreeNode*> q;
    q.push(root);

    int depth = 0;

    while (!q.empty()) {
        int size = q.size();
        depth++;

        while (size--) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
    }

    return depth;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    cout << "Maximum depth: " << maxDepth(root);

    return 0;
}
