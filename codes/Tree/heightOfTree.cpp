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

int heightOfTree(binaryTree *root){
    if(root==NULL){
        return 0;
    }
    return max(heightOfTree(root->left),heightOfTree(root->right))+1;
}

int main(){
    binaryTree *root= new binaryTree(30);
    root->left= new binaryTree(40);
    root->left->left= new binaryTree(50);
    root->left->left->left= new binaryTree(60);
    root->right= new binaryTree(20);
    cout<<heightOfTree(root);
}