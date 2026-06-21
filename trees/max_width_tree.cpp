#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
};

int widthOfBinaryTree(TreeNode* root){
    if(!root) return 0;

    long long ans=0;
    queue<pair<TreeNode*,long long>> q;
    q.push({root,0});

    while(!q.empty()){
        int size=q.size();
        long long mini=q.front().second;
        long long first,last;

        for(int i=0;i<size;i++){
            auto it=q.front();
            q.pop();

            long long cur=it.second-mini;

            if(i==0) first=cur;
            if(i==size-1) last=cur;

            if(it.first->left)
                q.push({it.first->left,2*cur+1});

            if(it.first->right)
                q.push({it.first->right,2*cur+2});
        }

        ans=max(ans,last-first+1);
    }

    return ans;
}
