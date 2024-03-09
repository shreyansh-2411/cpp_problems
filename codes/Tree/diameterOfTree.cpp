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

int maxDiameter= 0;

int diameterOfTree(tree *root){
    if(root==NULL)
    return 0;
    maxDiameter= max(maxDiameter,(diameterOfTree(root->left)+diameterOfTree(root->right)+1));
    return (max(diameterOfTree(root->left),diameterOfTree(root->right))+1);
}

int main(){  
    tree *root= new tree(10);
    root->left= new tree(20);
    root->left->left= new tree(30);
    root->left->right= new tree(80);
    root->left->left->left= new tree(40);
    root->left->left->left->left= new tree(60);
    root->left->left->right= new tree(50);
    root->left->right->right= new tree(90);
    root->left->right->right->right= new tree(18);
    root->right= new tree(60);
    diameterOfTree(root);
    cout<<maxDiameter<<endl;
}