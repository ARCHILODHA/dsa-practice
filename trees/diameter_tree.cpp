#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int diameter = 0;

int height(TreeNode* root){
    if(!root) return 0;

    int left = height(root->left);
    int right = height(root->right);

    diameter = max(diameter, left + right);

    return 1 + max(left, right);
}
