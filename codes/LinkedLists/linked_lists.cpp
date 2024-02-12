#include<iostream>
using namespace std;


// stucture created which wich represent the data type of our node 
// in the linked list
struct node{
    int a;
    node* next;
    node(int x){
        a=x;
        next=NULL;
    }
};

// function to traverse through linked list
void nodeTraversal(node* head){
    node* temp= head;
    while(temp != NULL){
        cout<<temp->a<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

// recursive function to traverse through linked list
void nodeRecursiveTraversal(node* head){
    cout<<head->a<<" ";
    if(head->next== NULL)
    return;
    nodeRecursiveTraversal(head->next);
}

// fucntion to insert at the start of linked list
node* insertAtStart(node* head,int x){
    node* temp = new node(x);
    temp->next=head;
    return temp;
}

// function to insert at the end of the linked list
void insertAtEndOfNonEmpty(node* head,int x){
    while(head->next!=NULL){
        head=head->next;
    }
    head->next= new node(x);
}

// function to insert at the end of the linked list if linked list is empty
node* insertAtEndOfEmpty(node* head,int x){
    head= new node(x);
    return head;
}

// function to insert at the end of linked list for empty and non empty
node* insertAtEnd(node* head, int x){
    if(head==NULL){
        head = new node(x);
        return head;
    }
    node* temp = head;
    while(head->next!=NULL){
        head=head->next;
    }
    head->next= new node(x);
    return temp;
}

// function to delete the head node of a linked list
node* deleteFirstNode(node* head){
    if(head==NULL)
    return NULL;
    node* temp= head->next;
    delete(head);
    return temp;
}

// delete element from end of the linked list
node* deleteLastNode(node* head){
    if(head==NULL)
    return NULL;
    if(head->next==NULL){
        delete(head);
        return NULL;
    }
    node* temp= head;
    while(head->next->next!=NULL){
        head= head->next;
    }
    delete(head->next);
    head->next=NULL;
    return temp;
}

// insert at x position of the linked list
node* insertAtX(node* head, int x,int val){
    int i=2;
    if(x<1){
        cout<<"incorrect position to be inserted at"<<endl;
        return head;
    }
    if(x==1){
        node* temp= new node(val);
        temp->next= head;
        return temp;
    }
    node* curr= head;
    while(i!=x && head->next!=NULL){
        head=head->next;
        i++;
    }
    if(head->next==NULL){
        cout<<"incorrect position to be inserted at"<<endl;
        return curr;
    }
    node* temp= head->next;
    head->next= new node(val);
    head->next->next= temp;
    return curr;
}

// search in linked list
int searchList(node* head,int key){
    int i=1;
    if(head==NULL)
    return -1;
    do{
        if(head->a==key){
            return i;
        }
        i++;
        head=head->next;
    }while(head!=NULL);
    return -1;
}

// search in linked list using recursion
int searchListR(node* head,int key,int counter=1){
    if(head==NULL)
    return -1;
    if(head->a==key)
    return counter;
    return searchListR(head->next,key,++counter);
}

int main(){
    // don't confuse structure with actual node as it is just a user defined
    // data type and its the blue print of the actual node , when we create
    // a object of this structure than a node is created 
    node* head= new node(10);
    node* first= new node(20);
    node* second= new node(20);
    head->next=first;
    first->next=second;
    // simpler implementation of this linked list
    node* head1= new node(10);
    head1->next= new node(20);
    head1->next->next= new node(30);
    nodeTraversal(head);
    nodeRecursiveTraversal(head1);
    cout<<endl;
    // adding element to the start of the linked list
    head1= insertAtStart(head1,5);
    nodeTraversal(head1);
    // adding element to the end of the linked list
    insertAtEndOfNonEmpty(head1,40);
    nodeTraversal(head1);
    // adding element to the end of an empty linked list
    node* emptyHead = NULL;
    // emptyHead= insertAtEndOfEmpty(emptyHead,20);
    // nodeTraversal(emptyHead);
    head1 = insertAtEnd(head1,50);
    nodeTraversal(head1);
    emptyHead = insertAtEnd(emptyHead,10);
    nodeTraversal(emptyHead);
    // deleting first element of the linked list
    head1= deleteFirstNode(head1);
    nodeTraversal(head1);
    // deleting last element of the linked list
    head1= deleteLastNode(head1);
    nodeTraversal(head1);
    // inserting at the x position of the linked list
    head1= insertAtX(head1,0,1);
    nodeTraversal(head1);
    cout<<searchList(head1,30)<<endl;
    cout<<searchListR(head1,30)<<endl;
    return 0;
}