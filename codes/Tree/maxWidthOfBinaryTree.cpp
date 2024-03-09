#include<iostream>
#include<queue>
using namespace std;


struct tree{
    int val;
    tree *right;
    tree *left;
    tree(int x){
        val=x;
        left= NULL;
        right= NULL;
    }
};

int maxWidth(tree *root){
    if(root==NULL)
    return 0;
    queue<tree*> q;
    q.push(root);
    tree *tracker=root;
    int currSize=0;
    int maxSize=0;
    while(!q.empty()){
        if(q.front()->left!=NULL){
            q.push(q.front()->left);
            currSize++;
        }
        if(q.front()->right!=NULL){
            q.push(q.front()->right);
            currSize++;
        }
        if(q.front()==tracker){
            maxSize=max(maxSize,currSize);
            currSize=0;
            tracker=q.back();
        }
        q.pop();
    }
    return maxSize;
}

int main(){
    tree *root = new tree(10);
    root->left = new tree(20);
    root->right = new tree(30);
    root->left->left = new tree(8);
    root->left->right = new tree(7);
    root->right->right = new tree(6);
    root->right->left= new tree(8);
    cout<<maxWidth(root);
}