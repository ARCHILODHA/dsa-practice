#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;

    TreeNode(int x){
        val=x;
        left=right=NULL;
    }
};

TreeNode* build(vector<int>& pre,int ps,int pe,
                vector<int>& in,int is,int ie,
                map<int,int>& mp){

    if(ps>pe || is>ie) return NULL;

    TreeNode* root=new TreeNode(pre[ps]);

    int idx=mp[root->val];
    int leftCount=idx-is;

    root->left=build(pre,ps+1,ps+leftCount,
                     in,is,idx-1,mp);

    root->right=build(pre,ps+leftCount+1,pe,
                      in,idx+1,ie,mp);

    return root;
}

TreeNode* buildTree(vector<int>& preorder,
                    vector<int>& inorder){

    map<int,int> mp;

    for(int i=0;i<inorder.size();i++)
        mp[inorder[i]]=i;

    return build(preorder,0,preorder.size()-1,
                 inorder,0,inorder.size()-1,mp);
}
