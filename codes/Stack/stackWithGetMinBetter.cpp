#include<iostream>
using namespace std;


// this is a very tricky implementation for having a getMin function
// in stack , this implemenation takes O(n) time and O(1) space as heare
// we keea a min variable to store the min variable and in the actual 
// stack when we get a element smaller than the current element than we 
// store the val of curr min - new min which is a negative number and hence
// we can keep track of prev min as well . This is only possible if its given
// that all elements of stack are positive .
struct list{
    int val;
    list *next;
    list(int x){
        val=x;
        next=NULL;
    }
};
struct listStack{
    list *head;
    int min;
    listStack(){
        head=NULL;
        min= 0;
    }
    void push(int x){
        if(head==NULL){
            min= x;
        }
        list *temp;
        temp= head;
        head= new list(x);
        head->next=temp;
        if(x<min){
            head->val= x-min;
            min= x;
        }
    }
    void pop(){
        if(head->val<0){
            min= -(head->val-min);
        }
        list * temp;
        temp= head;
        head= head->next;
        delete(temp);
    }
    int top(){
        if(head->val<0){
            return min;
        }
        return head->val;
    }
    void printStack(){
        for(list* current=head; current!=NULL ; current=current->next){
            cout<<current->val<<" ";
        }
    }
};

int main(){
    listStack stack1;
    stack1.push(5);
    stack1.push(10);
    stack1.push(20);
    stack1.push(2);
    stack1.push(6);
    stack1.push(4);
    stack1.printStack();
}