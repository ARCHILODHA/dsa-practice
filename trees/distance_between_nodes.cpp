#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* lowestCommonAncestor(Node* root, int a, int b) {
    if (!root) return nullptr;

    if (root->data == a || root->data == b)
        return root;

    Node* left = lowestCommonAncestor(root->left, a, b);
    Node* right = lowestCommonAncestor(root->right, a, b);

    if (left && right) return root;

    return left ? left : right;
}

int distanceFrom(Node* root, int target, int distance) {
    if (!root) return -1;

    if (root->data == target) return distance;

    int left = distanceFrom(root->left, target, distance + 1);
    if (left != -1) return left;

    return distanceFrom(root->right, target, distance + 1);
}

int distanceBetweenNodes(Node* root, int a, int b) {
    Node* lca = lowestCommonAncestor(root, a, b);

    if (!lca) return -1;

    int d1 = distanceFrom(lca, a, 0);
    int d2 = distanceFrom(lca, b, 0);

    if (d1 == -1 || d2 == -1) return -1;

    return d1 + d2;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << distanceBetweenNodes(root, 4, 6);
    return 0;
}
