#include<iostream>
#include<queue>
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

// in bredth first traversal we use queue data structure
// if we remove the new line variable form this function , 
// this function will still work , this is added to print
// the tree in new line after covering every linear iteration.
void bredthFirstTraversal(tree *root){
    tree *nextLine;
    queue<tree *> q ;
    q.push(root);
    nextLine= root;
    while(!q.empty()){
        if(q.front()==NULL){
            q.pop();
            continue;
        }
        cout<<q.front()->val<<" ";
        q.push(q.front()->left);
        q.push(q.front()->right);
        // this new linke code works on the fact that when we have reached the end of previous
        // linke than we have entered the entire next line into the queue .So, end of the queue
        // will be the end of current line .
        if(q.front()==nextLine){
            cout<<endl;
            nextLine= q.back();
        }
        q.pop();
    }
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
    bredthFirstTraversal(root);
}