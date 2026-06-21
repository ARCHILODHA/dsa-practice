#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){ data=x; left=right=NULL; }
};

bool mirror(Node* a, Node* b){
    if(!a && !b) return true;
    if(!a || !b) return false;

    return a->data==b->data &&
           mirror(a->left,b->right) &&
           mirror(a->right,b->left);
}

bool isSymmetric(Node* root){
    return mirror(root->left, root->right);
}
