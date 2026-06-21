#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){ data=x; left=right=NULL; }
};

bool isSameTree(Node* p, Node* q){
    if(!p && !q) return true;
    if(!p || !q) return false;

    return p->data==q->data &&
           isSameTree(p->left,q->left) &&
           isSameTree(p->right,q->right);
}
