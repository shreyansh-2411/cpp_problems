#include<iostream>
using namespace std;


struct linkedList{
    int val;
    linkedList *next;
    linkedList(int val){
        this->val= val;
        next= NULL;
    }
};

// Linked list implementation of Queue , this is very streight
// foreword , just go through the code.
class listQueue{
    public:
    linkedList *front;
    linkedList *rear;
    int size;
    listQueue(){
        front= NULL;
        rear= NULL;
        size= 0;
    }
    void enqueue(int x){
        if(size==0){
            front= new linkedList(x);
            rear= front;
            size++;
            return;
        }
        rear->next= new linkedList(x);
        rear= rear->next;
        size++;
    }
    void dequeue(){
        if(size==0){
            cout<<"queue is empty"<<endl;
            return;
        }
        linkedList * temp;
        temp= front;
        front= front->next;
        // this condition is required as if we dequeue the only
        // element form queue than Rear needs to be assigned NULL.
        if(front==NULL)
        rear= NULL;
        delete(temp);
        size--;
    }
    bool isEmpty(){
        return (size==0);
    }
    int getFront(){
        return front->val;
    }
    int getRear(){
        return rear->val;
    }
    int getSize(){
        return size;
    }
    void printQueue(){
        for(linkedList *curr=front;curr!=NULL;curr=curr->next){
            cout<<curr->val<<" ";
        }
        cout<<endl;
    }
};

int main(){
    listQueue queue1;
    queue1.enqueue(10);
    queue1.enqueue(30);
    queue1.enqueue(20);
    queue1.enqueue(30);
    queue1.enqueue(35);
    queue1.dequeue();
    queue1.enqueue(20);
    queue1.dequeue();
    queue1.enqueue(56);
    cout<<queue1.getFront()<<endl;
    cout<<queue1.getRear()<<endl;
    cout<<queue1.getSize()<<endl;
    queue1.printQueue();
}