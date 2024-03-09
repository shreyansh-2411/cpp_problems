#include<stack>
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

tree *result;

bool leastCommonAncestor(tree *root,int a,int b){
    if(root==NULL){
        return false;
    }
    bool current= (root->val==a || root->val==b);
    bool left=leastCommonAncestor(root->left,a,b);
    bool right=leastCommonAncestor(root->right,a,b);
    if((left && right) || (left && current) || (right && current)){
        result= root;
        return false;
    }
    if(root->val==a || root->val==b)
    return true;
    if(left || right)
    return true;
    return false;
}

int main(){
    tree *root= new tree(1);
    root->left= new tree(2);
    root->right= new tree(3);
    root->left->left= new tree(4);
    root->left->right= new tree(5);
    root->right->left= new tree(6);
    root->right->right= new tree(7);
    root->left->left->left= new tree(8);
    root->left->left->right= new tree(9);
    root->right->left->left= new tree(10);
    leastCommonAncestor(root,8,2);
    cout<<result->val;
}