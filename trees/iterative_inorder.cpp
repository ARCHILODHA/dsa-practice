#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> inorder(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;

    TreeNode* current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        result.push_back(current->val);
        current = current->right;
    }

    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<int> result = inorder(root);

    for (int x : result)
        cout << x << " ";

    return 0;
}
