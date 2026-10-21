#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(vector<int>& inorder, vector<int>& postorder,
                int inStart, int inEnd, int& postIndex,
                unordered_map<int, int>& position) {
    if (inStart > inEnd) return nullptr;

    int value = postorder[postIndex--];
    Node* root = new Node(value);

    int mid = position[value];

    root->right = buildTree(inorder, postorder, mid + 1, inEnd,
                            postIndex, position);

    root->left = buildTree(inorder, postorder, inStart, mid - 1,
                           postIndex, position);

    return root;
}

void preorder(Node* root) {
    if (!root) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> postorder = {4, 5, 2, 6, 3, 1};

    unordered_map<int, int> position;

    for (int i = 0; i < (int)inorder.size(); i++)
        position[inorder[i]] = i;

    int postIndex = (int)postorder.size() - 1;

    Node* root = buildTree(inorder, postorder, 0,
                           (int)inorder.size() - 1,
                           postIndex, position);

    cout << "Preorder traversal: ";
    preorder(root);

    return 0;
}
