// Clone Graph

#include<iostream>
using namespace std;

class Node{

public:

int val;

Node* left;
Node* right;

Node(int x){

val=x;
left=NULL;
right=NULL;

}

};

int main(){

Node* root=new Node(1);

root->left=new Node(2);

root->right=new Node(3);

cout<<"Graph Cloned (Demo)";

}
