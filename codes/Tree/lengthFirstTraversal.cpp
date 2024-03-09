#include<iostream>
using namespace std;


// structure to define a binary tree internal implementation
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

void inorderTraversal(binaryTree *root){
    if(root==NULL)
    return; 
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(binaryTree *root){
    if(root!=NULL){
        cout<<root->val<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(binaryTree *root){
    if(root!=NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->val<<" ";
    }
}

int main(){
    binaryTree *root= new binaryTree(10);
    root->left= new binaryTree(20);
    root->right= new binaryTree(30);
    root->right->left= new binaryTree(40);
    root->right->right= new binaryTree(50);
    inorderTraversal(root);
    cout<<endl;
    preorderTraversal(root);
    cout<<endl;
    postorderTraversal(root);
}