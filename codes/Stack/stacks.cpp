#include<iostream>
#include<stack>
using namespace std;


int main(){
    // this is the syntax to declare a stack
    stack<int> stack1;
    // push function is used to insert data inside a stack
    // we can only insert and delete elements from one end 
    // of the stack ( because of its internal implementation)
    stack1.push(10);
    stack1.push(20);
    stack1.push(15);
    stack1.push(25);
    stack1.pop();
    cout<<stack1.empty()<<endl;
    cout<<stack1.size()<<endl;
    cout<<stack1.top()<<endl;
    
}