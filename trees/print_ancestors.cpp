#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool printAncestors(Node* root, int target) {
    if (!root) return false;

    if (root->data == target) return true;

    if (printAncestors(root->left, target) ||
        printAncestors(root->right, target)) {
        cout << root->data << " ";
        return true;
    }

    return false;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int target = 5;

    if (!printAncestors(root, target))
        cout << "Node not found";

    return 0;
}
