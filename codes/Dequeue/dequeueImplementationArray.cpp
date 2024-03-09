#include<iostream>
using namespace std;


// dequeue implementation using arrays , for insert front
// and remove end we can write better code , we can simply update
// front to (front-1+cap)%cap this will make sure it will loop.
class arrayDequeue{
    public:
    int *arr;
    int front;
    int end;
    int size;
    int cap;
    arrayDequeue(int x){
        arr= new int[x];
        front= x/2;
        end= x/2;
        size= 0;
        cap= x;
    }
    void insertFront(int x){
        if(size==0){
            arr[front]= x;
            size++;
            return;
        }
        if(size==cap){
            cout<<"dequeue is full"<<endl;
            return;
        }
        --front;
        if(front<0){
            front= cap-1;
        }
        arr[front]= x;
        size++;
    }
    void insertEnd(int x){
        if(size==0){
            arr[end]= x;
            size++;
            return;
        }
        if(size==cap){
            cout<<"dequeue is full"<<endl;
            return;
        }
        end= (end+1)%cap;
        arr[end]= x;
        size++;
    }
    void removeFront(){
        if(size==0){
            cout<<"dequeue is empty"<<endl;
            return;
        }
        front= (front+1)%cap;
        size--;
    }
    void removeBack(){
        if(size==0){
            cout<<"dequeue is empty"<<endl;
            return;
        }
        end--;
        size--;
        if(end<0)
        end= cap-1;
    }
    int getFront(){
        return arr[front];
    }
    int getEnd(){
        return arr[end];
    }
    void printDequeue(){
        for(int i=0;i<cap;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
};

int main(){
    arrayDequeue dequeue1(10);
    dequeue1.insertFront(10);
    dequeue1.insertFront(20);
    dequeue1.insertEnd(30);
    dequeue1.insertEnd(40);
    dequeue1.insertFront(50);
    dequeue1.insertFront(50);
    dequeue1.insertFront(60);
    dequeue1.insertFront(70);
    dequeue1.insertFront(80);
    dequeue1.removeFront();
    dequeue1.insertFront(100);
    dequeue1.insertFront(110);
    dequeue1.insertFront(30);
    dequeue1.printDequeue();
}