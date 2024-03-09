#include<iostream>
using namespace std;


struct binaryTree{
    int val;
    binaryTree *left;
    binaryTree *right;
    binaryTree(int x){
        val= x;
        left= NULL;
        right= NULL;
    }
};

void printNodesAtKDistance(binaryTree *root,int k){
    if(root==NULL){
        return;
    }
    if(k!=0){
        printNodesAtKDistance(root->left,k-1);
        printNodesAtKDistance(root->right,k-1);
    }else{
        cout<<root->val<<" ";
    }
}

int main(){
    binaryTree *root= new binaryTree(10);
    root->left= new binaryTree(20);
    root->left->left= new binaryTree(30);
    root->left->right= new binaryTree(40);
    root->right= new binaryTree(50);
    root->right->right= new binaryTree(60);
    printNodesAtKDistance(root,2 );
}