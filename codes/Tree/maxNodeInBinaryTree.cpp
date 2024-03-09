#include <iostream>
#include <queue>
using namespace std;

struct tree
{
    int val;
    tree *left;
    tree *right;
    tree(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// recurssive solution to find the max element in the binary tree 
int maxInBinaryTree(tree *root)
{
    if (root == NULL)
         return INT_MIN;
    int temp = max(root->val, maxInBinaryTree(root->left));
    return max(temp, maxInBinaryTree(root->right));
}

// iterative solution to find the max element in the binary tree
int maxInBinaryTreeIterative(tree *root)
{
    if (root == NULL)
        return -1;
    queue<tree *> q;
    q.push(root);
    int maximum = root->val;
    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            q.pop();
            continue;
        }
        q.push(q.front()->left);
        q.push(q.front()->right);
        maximum= max(maximum,q.front()->val);
        q.pop();
    }
    return maximum;
}

int main()
{
    tree *root = new tree(10);
    root->left = new tree(20);
    root->right = new tree(30);
    root->left->left = new tree(8);
    root->left->right = new tree(7);
    root->right->right = new tree(6);
    root->left->right->left = new tree(9);
    root->left->right->right = new tree(15);
    cout<< maxInBinaryTree(root)<<endl;
    cout<< maxInBinaryTreeIterative(root);
}