#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isFullBinaryTree(Node* root) {
    if (!root) return true;

    if (!root->left && !root->right) return true;

    if (root->left && root->right)
        return isFullBinaryTree(root->left) &&
               isFullBinaryTree(root->right);

    return false;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << (isFullBinaryTree(root) ? "Full Binary Tree" :
                                      "Not a Full Binary Tree");
    return 0;
}
