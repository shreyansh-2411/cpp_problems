#include<iostream>
using namespace std;


// structure of a node of doubly linked list
struct node{
    int a;
    node* previous;
    node* next;
    node(int x){
        a=x;
        previous=NULL;
        next=NULL;
    }
};

// function to insert at the start of dubly linked list
node* insertAtStart(node* head, int x){
    if(head==NULL){
        node* temp = new node(x);
        return temp;
    }
    head->previous= new node(x);
    head->previous->next= head;
    return head->previous;
}

// function to traverse through doubly linked list
void nodeTraversal(node* head){
    while(head!=NULL){
        cout<<head->a<<" ";
        head= head->next;
    }
    cout<<endl;
}

// function to insert at the end of the doubly linked list
node* insertAtEnd(node* head, int x){
    node* curr= head;
    node* temp= new node(x);
    if(head==NULL)
    return temp;
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=temp;
    temp->previous=head;
    return curr;
}

// function to traverse doubly linked list in reverse this function
// is written to check if the linked list is connected in both directions
void nodeTraversalReverse(node* head){
    while(head->next!=NULL){
        head= head->next;
    }
    while(head!=NULL){
        cout<<head->a<<" ";
        head=head->previous;
    }
    cout<<endl;
}
 
// function to reverse a doubly linked list
node* reverseLinkedList(node* head){
    if(head==NULL)
    return NULL;
    if(head->next==NULL)
    return head;
    node* temp;
    while(head!=NULL){
        temp= head->previous;
        head->previous=head->next;
        head->next=temp;
        head= head->previous;
    }
    return temp->previous;
}

// function to delete the head of doubly linked list
node* deleteHead(node* head){
    if(head==NULL)
    return NULL;
    if(head->next==NULL){
        delete(head);
        return NULL;
    }
    node* temp= head->next;
    temp->previous= NULL;
    delete(head);
    return temp;
}

// function to delete the last element of the doubly linked list
// we can reduce the time complexity of this function by keeping a 
// tail pointer along with head pointer but that will make coding
// complicated as we will have to update tail pointer will every
// operation like insertion and deletion.
node* deleteLast(node* head){
    if(head==NULL)
    return NULL;
    if(head->next==NULL){
        delete(head);
        return NULL;
    }
    node* curr= head;
    while(head->next!=NULL){
        head= head->next;
    }
    head->previous->next= NULL;
    delete(head);
    return curr;
}

// traversal through circular linked list
void nodeTraversalCircular(node* head){
    if(head==NULL){
        return;
    }
    node* curr=head;
    do{
        cout<<curr->a<<" ";
        curr=curr->next;
    }while(curr!=head);
    cout<<endl;
}

// function to insert at the begining of the circular linked list
node* insertAtStartCircular(node* head, int x){
    if(head==NULL){
        head= new node(x);
        head->next= head;
        return head;
    }
    node* temp= head->next;
    head->next= new node(head->a);
    head->a= x;
    head->next->next= temp;
    return head;
}

// function to insert at the end of the circular linked list
node* insertAtEndCircular(node* head, int x){
    if(head==NULL){
        head= new node(x);
        head->next= head;
        return head;
    }
    node* temp= head->next;
    head->next= new node(head->a);
    head->next->next= temp;
    head->a= x;
    return head->next;
}

// function to delete the head of a circular linked list
node* deleteHeadCircular(node* head){
    if(head==NULL)
    return NULL;
    if(head->next==head){
        delete(head);
        return NULL;
    }
    node* temp= head->next;
    head->a= head->next->a;
    head->next= head->next->next;
    delete(temp);
    return head;
}

// function to delete the kth element from a circular linked list
node* deleteKthElement(node* head, int k){
    if(head==NULL){
        return NULL;
    }
    if(k==1 && head->next==head)
    return NULL;
    int i=1;
    node* curr= head;
    while(i!=k && curr->next!=head){
        i++;
        curr=curr->next;
    }
    if(i!=k){
        cout<<"position to be deleted does not exists"<<endl;
        return head;
    }
    curr->a= curr->next->a;
    node* temp= curr->next;
    curr->next= curr->next->next;
    if(temp==head){
        delete(temp);
        return curr;
    }
    else{
        delete(temp);
        return head;
    }
}

int main(){
    // making a doubly linked list (raw method)
    node* head= new node(10);
    head->next= new node(20);
    head->next->previous= head;
    head->next->next= new node(30);
    head->next->next->previous= head->next;
    // inserting at the start of doubly linked list
    head= insertAtStart(head,5);
    nodeTraversal(head);
    nodeTraversalReverse(head);
    // inserting at the end of the doubly linked list
    head= insertAtEnd(head,40);
    nodeTraversal(head);
    nodeTraversalReverse(head);
    // reversing a doubly linked list
    head= reverseLinkedList(head);
    nodeTraversal(head);
    nodeTraversalReverse(head);
    // deleting head of the doubly linked list
    head= deleteHead(head);
    nodeTraversal(head);
    nodeTraversalReverse(head);
    // deleting last element of the doubly linked list
    head= deleteLast(head);
    nodeTraversal(head);
    nodeTraversalReverse(head);
    cout<<"Circular linked list after this"<<endl;
    // creating a circular linked list
    node* head1= new node(10);
    head1->next= new node(20);
    head1->next->next= new node(30);
    head1->next->next->next= head1;
    // printing an entire circular linked list
    nodeTraversalCircular(head1);
    // inserting element at the head
    head1= insertAtStartCircular(head1,5);
    nodeTraversalCircular(head1);
    // inserting element at the end of the circular linked list
    head1= insertAtEndCircular(head1,40);
    nodeTraversalCircular(head1);
    // deleting head of the circular linked list
    head1= deleteHeadCircular(head1);
    nodeTraversalCircular(head1);
    // deleting kth element of the circular linked list
    head1= deleteKthElement(head1,5);
    nodeTraversalCircular(head1);
}