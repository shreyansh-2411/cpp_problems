#include<iostream>
using namespace std;


// internal implementation of k stacks in an array
class nStack{
    public:
    // here we are using two additional arrays next and top where 
    // top will store the index of top elemnt of each stack and next
    // array will map the next element index of stack in array , it
    // also servers another purpose fo finding the next free element
    int *arr,*next,*top;
    int nextFree,cap,n;
    nStack(int x,int y){
        n=x;
        cap=y;
        arr= new int[cap];
        top= new int[n];
        next= new int[cap];
        for(int i=0;i<n;i++){
            top[i]=-1;
        }
        for(int i=0;i<cap-1;i++){
            next[i]=i+1;
        }
        next[cap-1]=-1;
        nextFree= 0;
    }
    void push(int val,int index){
        index--;
        int temp = next[nextFree];
        next[nextFree]= top[index];
        top[index]= nextFree;
        arr[top[index]]= val;
        nextFree= temp;
    }
    void pop(int index){
        index--;
        int temp= top[index];
        top[index]= next[top[index]];
        next[temp]= nextFree;
        nextFree= temp;
    }
    int topElement(int index){
        index--;
        return arr[top[index]];
    }
    int size(int index){
        index--;
        int counter=0;
        for(int i=top[index];next[i]!=-1;i=next[i]){
            counter++;
        }
        return counter;
    }
    void printStack(int index){
        index--;
        int i;
        for(i=top[index];next[i]!=-1;i=next[i]){
            cout<<arr[i]<<" ";
        }
        cout<<arr[i];
        cout<<endl;
        // for(int i=0;i<cap;i++){
        //     cout<<arr[i]<<" "<<next[i]<<endl;
        // }
        // for(int i=0;i<n;i++){
        //     cout<<top[i]<<" ";
        // }
        // cout<<endl;
    }
};

int main(){
    nStack stack1(3,10);
    stack1.push(10,1);
    stack1.push(20,1);
    stack1.push(30,1);
    stack1.push(40,1);
    stack1.push(24,2);
    stack1.push(25,2);
    stack1.push(25,1);
    stack1.pop(1);
    stack1.printStack(1);
}