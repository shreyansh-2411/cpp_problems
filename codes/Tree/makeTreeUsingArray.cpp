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

int preOrder=0;

// function to make binary tree using array of inorder tree and pre order tree
tree* treeUisngArrays(int in[],int pre[],int is,int ie){
    if(is>ie)
    return NULL; 
    tree *root= new tree(pre[preOrder++]);
    int i;
    for(i=is;i<=ie;i++){
        if(in[i]==root->val){
            break;
        }
    }
    root->left= treeUisngArrays(in,pre,is,i-1);
    root->right= treeUisngArrays(in,pre,i+1,ie);
    return root;
}

// function to get size of tree (this is just to test the tree ).
int sizeOfBinaryTree(tree *root){
    if(root==NULL){
        return 0;
    }
    return sizeOfBinaryTree(root->left)+sizeOfBinaryTree(root->right)+1;
}

int main(){
    int in[5]={20,10,40,30,50};
    int pre[5]={10,20,30,40,50};
    tree *root= treeUisngArrays(in,pre,0,4);
    cout<<sizeOfBinaryTree(root);
}