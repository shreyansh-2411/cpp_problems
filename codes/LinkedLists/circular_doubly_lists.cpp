#include<iostream>
using namespace std;


// structure to define a node of circular doubly linked list
struct node{
    int a;
    node* next;
    node* previous;
    node(int x){
        a=x;
        next=NULL;
        previous=NULL;
    }
};

// function to insert at the head of the circular doubly linked list
node* insertHead(node* head,int x){
    node* temp= new node(x);
    if(head==NULL){
        temp->next=temp;
        temp->previous=temp;
        return temp;
    }
    // if(head->next==head){
    //     temp->next= head;
    //     temp->previous= head;
    //     head->previous= temp;
    //     head->next= temp;
    //     return temp;
    // }
    // previously written commented code was written to handle the condition
    // where head was trying to access head->previous->next as head is a single
    // element this should throw an error but as the Linked list is circular
    // head's next will be head and the above code will point to head's next
    // therefore this case does not need to be handled separately and hence commented.
    temp->next=head;
    temp->previous=head->previous;
    head->previous->next= temp;
    head->previous=temp;
    return temp;
}

int main(){
    // created a circular doubly linked list
    node* head1= new node(10);
    head1->next= new node(20);
    head1->next->previous= head1;
    head1->next->next= new node(30);
    head1->next->next->previous= head1->next;
    head1->next->next->next= head1;
    head1->previous= head1->next->next;
    // created an empty circular doubly linked list
    node* head= NULL;
    // inserted an element at the head of the circular doubly linked list
    head= insertHead(head,10);

}