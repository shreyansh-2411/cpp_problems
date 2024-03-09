#include<iostream>
#include<deque>
#include<stack>
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

bool check= true;

void spiralTraversal(tree *root){
    if(root==NULL)
    return;
    deque<tree*> dq;
    dq.push_front(root);
    tree *tracker= root;
    deque<tree*> st;
    cout<<root->val<<" ";
    while(!dq.empty()){
        if(dq.front()->left!=NULL){
            dq.push_back(dq.front()->left);
            st.push_back(dq.front()->left);
        }
        if(dq.front()->right!=NULL){
            dq.push_back(dq.front()->right);
            st.push_back(dq.front()->right);
        }
        if(dq.front()==tracker){
            tracker= dq.back();
            if(check){
                while(!st.empty()){
                    cout<<st.back()->val<<" ";
                    st.pop_back();
                }
                check=false;
            }else{
                while(!st.empty()){
                    cout<<st.front()->val<<" ";
                    st.pop_front();
                }
                check=true;
            }
        }
        dq.pop_front();
    }
}

void spiralTraversalBetter(tree *root){
    stack<tree*> s1;
    stack<tree*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
        if(s1.top()->left!=NULL){
            s2.push(s1.top()->left);
        }
        if(s1.top()->right!=NULL){
            s2.push(s1.top()->right);
        }
        cout<<s1.top()->val<<" ";
        s1.pop();
    }
    while(!s2.empty()){
        if(s2.top()->right!=NULL){
            s1.push(s2.top()->right);
        }
        if(s2.top()->left!=NULL){
            s1.push(s2.top()->left);
        }
        cout<<s2.top()->val<<" ";
        s2.pop();
    }
    }
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
    spiralTraversal(root);
    cout<<endl;
    spiralTraversalBetter(root);
}