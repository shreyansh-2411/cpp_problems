#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// this code will work in any online compiler
int maxHeight = INT_MIN;
// in this function i am using a pair to maintain both current height of the 
// tree and the root to track if the current node is an ancestor of start node
// or not , If its an ancestor of start node than we do the comparison to get 
// the max distance . Watch the GFG ( geek for geek ) video to get the actual 
// concept in detail ( remember this is a bit diff implementation of code with 
// same concept )
pair<int, TreeNode *> maxHeightOfTree(TreeNode *root, int start)
{
    if (root == NULL)
        return {0, NULL};
    if (root->val == start)
    {
        pair<int, TreeNode *> leftHeight = maxHeightOfTree(root->left, start);
        pair<int, TreeNode *> rightHeight = maxHeightOfTree(root->right, start);
        maxHeight = max(maxHeight, max(leftHeight.first, rightHeight.first));
        return {0, root};
    }
    pair<int, TreeNode *> leftHeight = maxHeightOfTree(root->left, start);
    pair<int, TreeNode *> rightHeight = maxHeightOfTree(root->right, start);
    if (leftHeight.second != NULL)
    {
        maxHeight = max(maxHeight, leftHeight.first + rightHeight.first + 1);
        return {leftHeight.first + 1, root};
    }
    else
    {
        if (rightHeight.second != NULL)
        {
            maxHeight = max(maxHeight, leftHeight.first + rightHeight.first + 1);
            return {rightHeight.first + 1, root};
        }
        else
        {
            return {max(rightHeight.first, leftHeight.first) + 1, NULL};
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->right->left->left = new TeeNode(10);
    pair<int, TreeNode *> result = maxHeightOfTree(root, start);
    cout << maxHeight;
}