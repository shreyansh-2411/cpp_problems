#include<iostream>
using namespace std;


struct node{
    int a;
    node* next;
    node(int x){
        a= x;
        next= NULL;
    }
};

// function to insert at the start of a linked list
node* insertAtStart(node* head,int x){
    node* temp = new node(x);
    temp->next=head;
    return temp;
}

// function to traverse through linked list
void nodeTraversal(node* head){
    node* temp= head;
    while(temp != NULL){
        cout<<temp->a<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

// function to insert at the end of a single linked list
node* insertAtEnd(node* head,int x){
    if(head==NULL){
        node* temp= new node(x);
        temp->next= NULL;
        return temp;
    }
    node* curr= head;
    while(curr->next!=NULL){
        curr= curr->next;
    }
    curr->next= new node(x);
    return curr->next;
}

// function to remove duplicates form a sorted singly linked list
void removeDuplicates(node* head){
    if(head==NULL || head->next==NULL)
    return;
    node* curr= head;
    head= head->next;
    while(head!=NULL){
        if(head->a==curr->a){
            node* temp= head;
            head=head->next;
            delete(temp);
            curr->next= head;
        }else{
            curr= head;
            head=head->next;
        }
    }
}

// function to reverse a linked list in groups of k elements
node* reverseListInGroup(node* head,int k){
    node* prev= NULL;
    if(head==NULL)
    return head;
    if(head->next==NULL){
        head->next= prev;
        return head;
    }
    int i=0;
    node* curr= head;
    while(i!=k && head!=NULL){
        node* next= head->next;
        head->next= prev;
        prev= head;
        head= next;
        i++;
    }
    curr->next= reverseListInGroup(head,k);
    return prev;
}

// function to reverse a linked list in groups of k elements without recurssion
node* reverseList(node* head,int k){
    node* curr= head;
    int j=0;
    node* previousTail= head;
    while(curr!=NULL && curr->next!=NULL){
        node* prev= NULL;
        node* next= NULL;
        node* currentTail= curr;
        for(int i=0;i<k && curr!=NULL;i++){
            next= curr->next;
            curr->next= prev;
            prev= curr;
            curr= next;
        }
        if(j==0){
            head= prev;
            j++;
            continue;
        }
        previousTail->next= prev;
        previousTail= currentTail;
    }
    return head;
}

// function to check if a linked list is looped or not
// there is one another way of doing this code but this method
// is better , we can change the structure of the node and
// add a check which will tell us if we have already visited
// a node or not to check the loop .
bool isLooped(node* head){
    node* first= head;
    node* second= head->next;
    bool check=1;
    if(head==NULL)
    return false;
    while(second!=NULL && second->next!=NULL && first!=second){
        if(check){
            second= second->next->next;
            check= !check;
        }else{
            first= first->next;
            check= !check;
        }
    }
    if(first==second)
    return true;
    else return false;
}

// function to remove a loop from linked list
void removeLoop(node* head){
    node* first= head;
    node* second= head;
    if(head==NULL)
    return;
    while(second!=NULL && second->next!=NULL){
            second= second->next->next;
            first= first->next;
            if(first==second)
            break;
    }
    if(first!=second)
    return;
    first= head;
    while(first->next!=second->next){
        first= first->next;
        second= second->next;
    }
    second->next= NULL;
}

// function to delete a node from linked list with just its pointer
void deleteNodeWihtPointer(node* pointer){
    node* temp= pointer->next;
    pointer->a= temp->a;
    pointer->next= temp->next;
    delete(temp);
}

// function to segregate odd and even nodes of a linked list 
node* segregateOddEven(node* head){
    node* odd=NULL;
    node* even=NULL;
    node* evenTail=NULL;
    bool checkEven=1;
    bool checkOdd=1;
    while(head!=NULL){
        if(head->a%2==0){
            if(checkEven){
                even= insertAtEnd(even,head->a);
                evenTail= even;
                checkEven=0;
            }else{
                evenTail= insertAtEnd(even,head->a);
            }
            node* temp= head;
            head= head->next;
            delete(temp);
        }else{
            if(checkOdd){
                odd= insertAtEnd(odd,head->a);
                checkOdd=0;
            }else{
                insertAtEnd(odd,head->a);
            }
            node* temp= head;
            head= head->next;
            delete(temp);
        }
    }
    evenTail->next=odd;
    return even;
}

int main(){
    node* head= NULL;
    head= insertAtStart(head,10);
    insertAtEnd(head,20);
    insertAtEnd(head,20);
    insertAtEnd(head,30);
    insertAtEnd(head,30);
    insertAtEnd(head,30);
    insertAtEnd(head,40);
    insertAtEnd(head,40);
    // removing duplicates form the linked list
    removeDuplicates(head);
    nodeTraversal(head);
    // reversing a linked list in group
    insertAtEnd(head,50);
    insertAtEnd(head,40);
    insertAtEnd(head,70);
    insertAtEnd(head,90);
    nodeTraversal(head);
    head= reverseListInGroup(head,3);
    nodeTraversal(head);
    // reversing a linked list in group
    head= reverseList(head,3);
    nodeTraversal(head);
    // creating a looped linked list
    node* head1= NULL;
    head1= insertAtStart(head1,1);
    insertAtEnd(head1,2);
    insertAtEnd(head1,3);
    insertAtEnd(head1,4);
    insertAtEnd(head1,5);
    insertAtEnd(head1,6);
    head1->next->next->next->next->next->next= head1->next->next;
    // check if the linked list is looped or not
    if(isLooped(head))
    cout<<"Linked list is looped"<<endl;
    else cout<<"Linked list is not looped"<<endl;
    if(isLooped(head1))
    cout<<"Linked list is looped"<<endl;
    else cout<<"Linked list is not looped"<<endl;
    // removing loop from a looped lined list
    removeLoop(head1);
    nodeTraversal(head1);
    // deleting a node from a linked list with just its pointer
    deleteNodeWihtPointer(head1->next->next);
    nodeTraversal(head1);
    // segregating odds and evens in a linked list
    head1= segregateOddEven(head1);
    nodeTraversal(head1);
}