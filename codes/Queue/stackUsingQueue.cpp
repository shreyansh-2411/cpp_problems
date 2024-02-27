#include<iostream>
#include<queue>
using namespace std;


// function to reverse a linked list ( we are pssing
// queue as call by value )
void reverseQueue(queue<int> &q){
    if(q.empty()){
        return ;
    }
    int temp= q.front();
    q.pop();
    reverseQueue(q);
    q.push(temp);
}

// implementation of stack using queue where pop
// operation will take some time .
class stack{
    public:
    queue<int> q1,q2;
    void popStack(){
        while(q1.size()!=1){
            int temp= q1.front();
            q1.pop();
            q2.push(temp);
        }
        while(!q2.empty()){
            int temp= q2.front();
            q2.pop();
            q1.push(temp);
        }
        q1.pop();
    }
    void pushStack(int x){
        q1.push(x);
    }
    int top(){
        return q1.back();
    }
    int size(){
        return q1.size();
    }
    void printStack(){
        while(!q1.empty()){
            cout<<q1.front()<<" ";
            q1.pop();
        }
        cout<<endl;
    }
};

// implementation of stackin using queue here 
// we are using recursiion to make a stack ( recurssion
// is done in the reverse queue function ).
class stackRecursion{
    public:
    queue<int> q1;
    void popStack(){
        reverseQueue(q1);
        q1.pop();
        reverseQueue(q1);
    }
    void pushStack(int x){
        q1.push(x);
    }
    int top(){
        return q1.back();
    }
    int size(){
        return q1.size();
    }
    void printStack(){
        while(!q1.empty()){
            cout<<q1.front()<<" ";
            q1.pop();
        }
        cout<<endl;
    }
};

int main(){
    stack stack1;
    stack1.pushStack(10);
    stack1.pushStack(20);
    stack1.pushStack(30);
    stack1.pushStack(40);
    stack1.pushStack(50);
    stack1.popStack();
    stack1.pushStack(30);
    stack1.pushStack(20);
    stack1.popStack();
    stack1.printStack();
    stackRecursion stack2;
    stack2.pushStack(10);
    stack2.pushStack(20);
    stack2.pushStack(30);
    stack2.pushStack(40);
    stack2.pushStack(50);
    stack2.popStack();
    stack2.pushStack(30);
    stack2.pushStack(20);
    stack2.popStack();
    stack2.printStack();
}