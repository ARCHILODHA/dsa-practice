#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findFloor(Node* root, int key) {
    int floorValue = -1;

    while (root) {
        if (root->data == key)
            return root->data;

        if (root->data < key) {
            floorValue = root->data;
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return floorValue;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int key = 9;
    int result = findFloor(root, key);

    if (result == -1)
        cout << "Floor does not exist";
    else
        cout << "Floor: " << result;

    return 0;
}
