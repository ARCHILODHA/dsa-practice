#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(Node* root) {
    if (!root) return 0;

    return 1 + max(height(root->left), height(root->right));
}

int findNode(Node* root, int target) {
    if (!root) return -1;

    if (root->data == target) return 0;

    int left = findNode(root->left, target);
    if (left != -1) return left;

    return findNode(root->right, target);
}

int burnHeight(Node* root, int target, int distance, int& timer) {
    if (!root) return 0;

    if (root->data == target) {
        timer = max(timer, height(root) - 1);
        return 1;
    }

    int left = burnHeight(root->left, target, distance + 1, timer);
    int right = burnHeight(root->right, target, distance + 1, timer);

    if (left > 0) {
        timer = max(timer, distance + height(root->right));
        return left + 1;
    }

    if (right > 0) {
        timer = max(timer, distance + height(root->left));
        return right + 1;
    }

    return 0;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    int target = 2;
    int timer = 0;

    if (findNode(root, target) == -1) {
        cout << "Target not found";
    } else {
        burnHeight(root, target, 0, timer);
        cout << "Minimum time to burn tree: " << timer;
    }

    return 0;
}
