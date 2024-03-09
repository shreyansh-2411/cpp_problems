#include<iostream>
#include<queue>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val=x;
        left= NULL;
        right= NULL;
    }
};

void serialiseBinaryTree(TreeNode *root,vector<int> &arr){
    if(root==NULL){
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->val);
    serialiseBinaryTree(root->left,arr);
    serialiseBinaryTree(root->right,arr);
}

int counter =0;
TreeNode *deserialiseBinaryTree(vector<int> &arr){
    if(counter== arr.size())
    return NULL;
    if(arr[counter]==-1)
    return NULL;
    TreeNode *root= new TreeNode(arr[counter]);
    counter++;
    root->left= deserialiseBinaryTree(arr);
    counter++;
    root->right= deserialiseBinaryTree(arr);
    return root;
}

int main(){
    vector<int> arr;
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
    serialiseBinaryTree(root,arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    TreeNode *root1= deserialiseBinaryTree(arr);
    vector<int> a;
    serialiseBinaryTree(root1,a);
    cout<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}