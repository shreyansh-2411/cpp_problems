#include<iostream>
#include<stack>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val= x;
        right= NULL;
        left= NULL;
    }
};

void inorderTraversalWithoutRecursion(TreeNode *root){
    stack<TreeNode*> s;
    while(root!=NULL || !s.empty()){
        while(root!=NULL){
        s.push(root);
        root=root->left;
        }
        root= s.top();
        cout<<root->val<<" ";
        s.pop();
        root= root->right;
    }
}

int main(){
    TreeNode *root= new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(3);
    root->left->left= new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->right->left= new TreeNode(6);
    root->right->right= new TreeNode(7);
    root->left->left->left= new TreeNode(8);
    root->left->left->right= new TreeNode(9);
    root->right->left->left= new TreeNode(10);
    inorderTraversalWithoutRecursion(root);
}