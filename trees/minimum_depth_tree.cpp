#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;

    queue<TreeNode*> q;
    q.push(root);

    int depth = 1;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left == nullptr && node->right == nullptr)
                return depth;

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        depth++;
    }

    return depth;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    cout << "Minimum depth: " << minDepth(root);

    return 0;
}
