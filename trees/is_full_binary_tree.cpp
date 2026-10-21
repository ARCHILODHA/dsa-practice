
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

// filename: print_ancestors.cpp
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

// filename: distance_between_nodes.cpp
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

// filename: burn_tree.cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int burnTree(Node* root, int target, int& timer) {
    if (!root) return -1;

    if (root->data == target) return 0;

    int left = burnTree(root->left, target, timer);
    int right = burnTree(root->right, target, timer);

    if (left != -1) {
        timer = max(timer, left + 1);
        return left + 1;
    }

    if (right != -1) {
        timer = max(timer, right + 1);
        return right + 1;
    }

    return -1;
}

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

// filename: construct_tree_post_in.cpp
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

// filename: bst_floor.cpp
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

// filename: bst_ceil.cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findCeil(Node* root, int key) {
    int ceilValue = -1;

    while (root) {
        if (root->data == key)
            return root->data;

        if (root->data > key) {
            ceilValue = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return ceilValue;
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

    int result = findCeil(root, key);

    if (result == -1)
        cout << "Ceil does not exist";
    else
        cout << "Ceil: " << result;

    return 0;
}

// filename: bst_lca.cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* lowestCommonAncestor(Node* root, int a, int b) {
    while (root) {
        if (a < root->data && b < root->data) {
            root = root->left;
        } else if (a > root->data && b > root->data) {
            root = root->right;
        } else {
            return root;
        }
    }

    return nullptr;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    Node* lca = lowestCommonAncestor(root, 5, 15);

    if (lca)
        cout << "LCA: " << lca->data;
    else
        cout << "LCA not found";

    return 0;
}

// filename: delete_bst_node.cpp
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

// filename: bst_predecessor_successor.cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void findPredecessorSuccessor(Node* root, int key,
                              Node*& predecessor,
                              Node*& successor) {
    predecessor = nullptr;
    successor = nullptr;

    Node* current = root;

    while (current) {
        if (current->data == key) {
            if (current->left) {
                Node* temp = current->left;

                while (temp->right)
                    temp = temp->right;

                predecessor = temp;
            }

            if (current->right) {
                Node* temp = current->right;

                while (temp->left)
                    temp = temp->left;

                successor = temp;
            }

            return;
        }

        if (key < current->data) {
            successor = current;
            current = current->left;
        } else {
            predecessor = current;
            current = current->right;
        }
    }

    if (current == nullptr) {
        // For a missing key, predecessor and successor
        // retain their nearest smaller and larger candidates.
    }
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    Node* predecessor = nullptr;
    Node* successor = nullptr;

    findPredecessorSuccessor(root, 20, predecessor, successor);

    cout << "Predecessor: ";
    if (predecessor) cout << predecessor->data;
    else cout << "None";

    cout << "\nSuccessor: ";
    if (successor) cout << successor->data;
    else cout << "None";

    return 0;
}
