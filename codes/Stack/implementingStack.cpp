#include<iostream>
using namespace std;


// this is a custom implemented stack using arrays , Generally we will be
// using stacks implemented in stl by default but this is to understand the 
// internal implementation of stacks using arrays .
class arrayStack{
    public:
    int *start;
    int *current;
    int size;
    // constructor to initialise this user defined stack
    arrayStack(int x){
        start= new int[x];
        current= start;
        size=0;
    }
    // function to add element to the top of the stack
    void push(int x){
        *current= x;
        current++;
        size++;
    }
    // fucntion to remove element from the top of the stack
    void pop(){
        --current;
        size--;
    }
    // fucntion to return the top element of the stack
    int top(){
        return *(current-1);
    }
    // fucntion to check if the stack is empty or not
    bool empty(){
        if(current==start)
        return true;
        return false;
    }
    // function to get size of the stack
    int stackSize(){
        return size;
    }
    // function to print the entire stack in reverse order
    void print(){
        for(int i=(size-1);i>=0;i--){
            cout<<start[i]<<" ";
        }
        cout<<endl;
    }
};

// structure of a single linked list
struct list{
    int val;
    list *next;
    list(int x){
        val= x;
        next= NULL;
    }
};

// custom stack using linked list as internal implementation
class listStack{
    public:
    list *current;
    int size;
    // constructor
    listStack(){
        current= NULL;
        size= 0;
    }
    // function to insert an value at the top of the stack
    void push(int x){
        list* temp= new list(x);
        temp->next= current;
        current= temp;
        size++;
    }
    // function to delete an value from top of the stack
    void pop(){
        list* temp= current->next;
        delete(current);
        current= temp;
        size--;
    }
    // function to print the entire stack
    void printStack(){
        for(list *temp=current;temp!=NULL;temp=temp->next){
            cout<<temp->val<<" ";
        }
        cout<<endl;
    }
    // function to get the size of the stack
    int stackSize(){
        return size;
    }
    // function to get the top element of the stack
    int topElement(){
        return current->val;
    }
    // function to check if the stack is empty or not
    bool stackEmpty(){
        return !size;
    }
};

int main(){
    arrayStack stack1(10);
    stack1.push(10);
    stack1.push(20);
    stack1.push(20);
    stack1.push(30);
    stack1.push(14);
    stack1.pop();
    cout<<stack1.stackSize()<<endl;
    cout<<stack1.empty()<<endl;
    cout<<stack1.top()<<endl;
    stack1.print();
    listStack stack2;
    stack2.push(20);
    stack2.push(10);
    stack2.push(22);
    stack2.push(11);
    stack2.pop();
    stack2.printStack();
    cout<<stack2.stackSize()<<endl;
    cout<<stack2.topElement()<<endl;
    cout<<stack2.stackEmpty()<<endl;
}