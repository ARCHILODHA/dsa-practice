#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int x){ data=x; left=right=NULL; }
};

class Solution{
    bool isLeaf(Node* root){
        return !root->left && !root->right;
    }

    void addLeft(Node* root, vector<int>& res){
        Node* cur=root->left;
        while(cur){
            if(!isLeaf(cur)) res.push_back(cur->data);
            if(cur->left) cur=cur->left;
            else cur=cur->right;
        }
    }

    void addLeaves(Node* root, vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }

        if(root->left) addLeaves(root->left,res);
        if(root->right) addLeaves(root->right,res);
    }

    void addRight(Node* root, vector<int>& res){
        Node* cur=root->right;
        vector<int> temp;

        while(cur){
            if(!isLeaf(cur)) temp.push_back(cur->data);
            if(cur->right) cur=cur->right;
            else cur=cur->left;
        }

        reverse(temp.begin(),temp.end());
        for(int x:temp) res.push_back(x);
    }

public:
    vector<int> boundary(Node *root){
        vector<int> res;
        if(!root) return res;

        if(!isLeaf(root)) res.push_back(root->data);

        addLeft(root,res);
        addLeaves(root,res);
        addRight(root,res);

        return res;
    }
};
