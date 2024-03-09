#include<queue>
#include<iostream>
using namespace std;


struct tree{
    int val;
    tree *left;
    tree *right;
    tree(int x){
        val= x;
        left= NULL;
        right= NULL;
    }
};

// recursive solution to finde the size of binary tree
int sizeOfBinaryTree(tree *root){
    if(root==NULL){
        return 0;
    }
    return sizeOfBinaryTree(root->left)+sizeOfBinaryTree(root->right)+1;
}

// iterative solution to find the size fo binary tree
int sizeOfBinaryTreeBreadthFirst(tree *root){
    queue<tree*> q;
    q.push(root);
    int size=0;
    while(!q.empty()){
        if(q.front()->left!=NULL)
        q.push(q.front()->left);
        if(q.front()->right!=NULL)
        q.push(q.front()->right);
        q.pop();
        size++;
    }
    return size;
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
    cout<<sizeOfBinaryTree(root)<<endl;
    cout<<sizeOfBinaryTreeBreadthFirst(root);
}