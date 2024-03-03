#include<iostream>
#include<queue>
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

int maxLevel=INT_MIN;

void printLeftViewRecurssive(tree *root,int level=0){  
    if(root==NULL){
        return;
    }
    if(level>maxLevel){  
        cout<<root->val<<" ";
        maxLevel=level;
    }
    printLeftViewRecurssive(root->left,level+1);
    printLeftViewRecurssive(root->right,level+1);
}

void printLeftView(tree *root){
    queue<tree*> q;
    q.push(root);
    while(!q.empty()){
        int k= q.size();
        for(int i=0;i<k;i++){
            if(i==0)
            cout<<q.front()->val<<" ";
            if(q.front()->left!=NULL)
            q.push(q.front()->left);
            if(q.front()->right!=NULL)
            q.push(q.front()->right);
            q.pop();
        }
    }
}

int main(){
    tree *root= new tree(10);
    root->left= new tree(20);
    root->right= new tree(30);
    root->right->left= new tree(40);
    root->right->right= new tree(50);
    printLeftView(root);
    cout<<endl;
    printLeftViewRecurssive(root);
}