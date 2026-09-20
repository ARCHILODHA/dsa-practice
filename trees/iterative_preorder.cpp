#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorder(TreeNode* root) {
    vector<int> result;

    if (root == nullptr)
        return result;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        result.push_back(node->val);

        if (node->right)
            st.push(node->right);

        if (node->left)
            st.push(node->left);
    }

    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<int> result = preorder(root);

    for (int x : result)
        cout << x << " ";

    return 0;
}
