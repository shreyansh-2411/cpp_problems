#include<iostream>
#include<queue>
#include<stack>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val= x;
        left= NULL;
        right= NULL;
    }
};

void preorderTraversal(TreeNode *root){
    queue<TreeNode*> q;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode *curr= s.top();
        s.pop();
        while(curr!=NULL){
            q.push(curr);
            curr= curr->left;
        }
        while(!q.empty()){
            cout<<q.front()->val<<" ";
            if(q.front()->right!=NULL)
            s.push(q.front()->right);
            q.pop();
        }
    }
}

void preorderTraversalBetter(TreeNode *root){
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode *curr= s.top();
        s.pop();
        cout<<curr->val<<" ";
        if(curr->right!=NULL)
        s.push(curr->right);
        if(curr->left!=NULL)
        s.push(curr->left);
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
    preorderTraversalBetter(root);
}