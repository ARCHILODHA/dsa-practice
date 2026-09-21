#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string serialize(TreeNode* root,
                 unordered_map<string, int>& freq,
                 vector<TreeNode*>& result) {
    if (root == nullptr)
        return "#";

    string current = to_string(root->val) + "," +
                     serialize(root->left, freq, result) + "," +
                     serialize(root->right, freq, result);

    freq[current]++;

    if (freq[current] == 2)
        result.push_back(root);

    return current;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int> freq;
    vector<TreeNode*> result;

    serialize(root, freq, result);

    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(4);

    vector<TreeNode*> result = findDuplicateSubtrees(root);

    cout << "Duplicate subtree roots: ";

    for (TreeNode* node : result)
        cout << node->val << " ";

    return 0;
}
