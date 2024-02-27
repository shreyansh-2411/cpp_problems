#include<iostream>
using namespace std;


// this is the queue implementation using array , This is harder than
// stack as we are adding element to one end and removing form other
// and if we fill the entire array than we will be removing the elements
// from start and to add elements at end we will have to loop array form 
// start again and i have written code to do so but this is not the
// best implementation as we can use % operator to rap around the array
// as if we go beyond the array size we can use % operator with size and
// get the value without the size.
class arrayQueue{
    public:
    int *arr;
    int start;
    int end;
    int size;
    int cap;
    arrayQueue(int x){
        arr= new int[x];
        start= 0;
        end= 0;
        size= 0;
        cap= x;
    }
    void enqueue(int x){
        if(size==cap){
            cout<<"queue is full"<<endl;
            return;
        }
        if(end==cap){
            end= 0;
        }
        end++;
        arr[end-1]=x;
        size++;
    }
    void dequeue(){
        if(size==0){
            cout<<"queue is empty"<<endl;
            return;
        }
        if(start==cap-1){
            start= 0;
        }
        start++;
        size--;
    }
    int getFirst(){
        return arr[start];
    }
    int getLast(){
        return arr[end-1];
    }
    int getSize(){
        return size;
    }
    void printQueue(){
        for(int i=0;i<cap;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    arrayQueue queue1(5);
    queue1.enqueue(10);
    queue1.enqueue(30);
    queue1.enqueue(20);
    queue1.enqueue(30);
    queue1.enqueue(35);
    queue1.dequeue();
    queue1.enqueue(20);
    queue1.dequeue();
    cout<<queue1.getFirst()<<endl;
    cout<<queue1.getLast()<<endl;
    cout<<queue1.getSize()<<endl;
    queue1.enqueue(56);
    queue1.printQueue();
}