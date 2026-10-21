#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }

    return root;
}

void inorder(Node* root) {
    if (!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    root = deleteNode(root, 30);

    cout << "Inorder after deletion: ";
    inorder(root);

    return 0;
}
