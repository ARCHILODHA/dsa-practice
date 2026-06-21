#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

bool getPath(Node* root, vector<int>& path, int x){
    if(!root) return false;

    path.push_back(root->data);

    if(root->data==x) return true;

    if(getPath(root->left,path,x) ||
       getPath(root->right,path,x))
        return true;

    path.pop_back();
    return false;
}
