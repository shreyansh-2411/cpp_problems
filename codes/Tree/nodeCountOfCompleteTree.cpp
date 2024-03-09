#include <iostream>
#include <math.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

int countNodes(TreeNode* root) {
        int lh=0;
        int rh=0;
        TreeNode *curr= root;
        while(curr!=NULL){
            lh++;
            curr=curr->left;
        }
        curr= root;
        while(curr!=NULL){
            rh++;
            curr=curr->right;
        }
        if(lh==rh){
            return (pow(2,lh)-1);
        }else{
            return (1+countNodes(root->left)+countNodes(root->right));
        }
    }

int main()
{
    TreeNode *root= new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(2);
    root->left->left= new TreeNode(30);
    root->left->right= new TreeNode(20);
    cout<<countNodes(root);
}