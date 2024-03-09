#include<iostream>
#include<queue>
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

bool isChildSumTree(tree *root){
    if(root==NULL)
    return true;
    if(root->left==NULL && root->right==NULL)
    return true;
    int leftVal= (root->left!=NULL)?(root->left->val):0;
    int rightVal= (root->right!=NULL)?(root->right->val):0;
    if(root->val == (leftVal+rightVal)){
        return (isChildSumTree(root->left) && isChildSumTree(root->right));
    }else return false;
}

int main(){
    // tree *root= new tree(20);
    // root->left= new tree(8);
    // root->left->left= new tree(3);
    // root->left->right= new tree(5);
    // root->right= new tree(12);
    // cout<<isChildSumTree(root);
    tree *root= new tree(3);
    root->left= new tree(1);
    root->right= new tree(2);
    root->right->left= new tree(1);
    root->right->right= new tree(2);
    cout<<isChildSumTree(root);
}