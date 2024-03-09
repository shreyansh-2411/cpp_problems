#include<iostream>
using namespace std;


struct tree{
    int val;
    tree *left;
    tree *right;
    tree(int x){
        val=x;
        left= NULL;
        right= NULL;
    }
};

tree *previous=NULL;

tree* treeToDll(tree *root){
    if(root==NULL)
    return root;
    tree *head= treeToDll(root->left);
    if(previous!=NULL){
        previous->right= root;
        root->left= previous;
    }else{
        head= root;
    }
    previous= root;
    treeToDll(root->right);
    return head;
}

int main(){
    tree *root= new tree(10);
    root->left= new tree(20);
    root->right= new tree(30);
    root->left->left= new tree(8);
    root->left->right= new tree(7);
    root->right->right= new tree(6);
    root->left->right->left= new tree(9);
    root->left->right->right= new tree(15);
    tree *head= treeToDll(root);
    tree *curr= head;
    while(curr->right!=NULL){
        cout<<curr->val<<" ";
        curr=curr->right;
    }
}