#include<iostream>
using namespace std;


struct tree{
    int val;
    tree *left;
    tree *right;
    tree(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

int isHeightBalanced(tree *root){
    if(root==NULL)
    return 0;
    int leftHeight= isHeightBalanced(root->left);
    int rightHeight= isHeightBalanced(root->right);
    if(leftHeight==-1 || rightHeight==-1)
    return -1; 
    if(max(leftHeight,rightHeight)-min(leftHeight,rightHeight)<=1){
        return max(leftHeight,rightHeight)+1;
    }
    return -1;
}

int main(){
    tree *root= new tree(10);
    root->left= new tree(20);
    root->right= new tree(30);
    root->right->left= new tree(10);
    root->left->left= new tree(30);
    root->left->right= new tree(10);
    root->left->right->left= new tree(20);
    root->left->right->right= new tree(30);
    // tree *root= new tree(10);
    // root->left= new tree(20);
    // root->right= new tree(30);
    // root->right->right= new tree(10);
    // root->right->right->left= new tree(20);
    // root->left->left= new tree(30);
    // root->left->right= new tree(10);
    if(isHeightBalanced(root) != -1){
        cout<<"Tree is balance (height)"<<endl;
    }
    else cout<<"Tree is not balance (height)"<<endl;
}