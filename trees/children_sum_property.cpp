#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){ data=x; left=right=NULL; }
};

bool isSumProperty(Node *root){
    if(!root || (!root->left && !root->right))
        return true;

    int sum=0;
    if(root->left) sum+=root->left->data;
    if(root->right) sum+=root->right->data;

    return (root->data==sum) &&
           isSumProperty(root->left) &&
           isSumProperty(root->right);
}
