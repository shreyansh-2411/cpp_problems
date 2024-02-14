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

// function to insert an element in a sorted linked list
node* insertSorted(node* head,int x){
    if(head==NULL){
        head= new node(x);
        return head;
    }
    if(head->a > x){
        node* temp= new node(x);
        temp->next= head;
        return temp;
    }
    node* curr= head;
    while(head->next!=NULL && head->next->a < x){
        head=head->next;
    }
    node* temp= head->next;
    head->next= new node(x);
    head->next->next= temp;
    return curr;
}

// function to print the middle element of a linked list
void printMiddle(node* head){
    if(head==NULL)
    return;
    node* curr=head;
    int counter=1;
    while(curr->next!=NULL){
        curr= curr->next;
        counter++;
    }
    counter=counter/2;
    while(counter>0){
        head=head->next;
        counter--;
    }
    cout<<head->a<<endl;
}

// function to print the middle element of a linked list
void printMiddleBetter(node* head){
    if(head==NULL)
    return;
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;
    }
    cout<<slow->a<<endl;
}

// function to print the nth element from end of the linked list
void printFromEnd(node* head,int n){
    if(head==NULL)
    return;
    node* first= head;
    node* second= head;
    while(second->next!=NULL){
        if(n==1){
            first= first->next;
        }else{
            n--;
        }
        second= second->next;
    }
    if(n==1)
    cout<<first->a<<endl;
}

// function to reverse a linked list
// this code can be written in a much more better way by making a
// temp linked list NULL and traversing our actual linked list . 
// while traversing the link list we have to add each element to the
// head of NULL and delete head from our actual linked list.
node* reverseList(node* head){
    if(head==NULL)
    return NULL;
    if(head->next==NULL)
    return head;
    node* first= head;
    head= head->next;
    node* second= head->next;
    first->next= NULL;
    do{
        head->next= first;
        first= head;
        head= second;
        second= second->next;
    }while(second!= NULL);
    head->next= first;
    return head;
}

// Recursive function to reverse a linked list
node* reverseListRecurssion(node* head,node* temp){
    if(head==NULL)
    return temp;
    temp= insertAtStart(temp,head->a);
    head= deleteFirstNode(head);
    return reverseListRecurssion(head,temp);
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
    // searching in a linked list
    cout<<searchList(head1,30)<<endl;
    cout<<searchListR(head1,30)<<endl;
    // insert inside a sorted linked list
    cout<<"new linked list after this point "<<endl;
    node* head2= NULL;
    head2= insertAtStart(head2,10);
    head2= insertSorted(head2,15);
    head2= insertSorted(head2,20);
    head2= insertSorted(head2,30);
    head2= insertSorted(head2,40);
    head2= insertSorted(head2,50);
    head2= insertSorted(head2,60);
    nodeTraversal(head2);
    // print the middle element of the linked list
    printMiddle(head2);
    // better method to print the middle element of the linked list
    printMiddleBetter(head2);
    // print the nth element from end of the linked list
    printFromEnd(head2,7);
    // reverse a linked list
    head2= reverseList(head2);
    nodeTraversal(head2);
    // reverse a linked list using recurssion
    head2= reverseListRecurssion(head2,NULL);
    nodeTraversal(head2);
    return 0;
}