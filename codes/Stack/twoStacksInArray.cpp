#include<iostream>
using namespace std;


// internal defination of two stacks created in a single array 
// this is a self made implementation but the actual implementation
// for this will be to start one stack form start of the array and 
// stack from end of the array .The problem with current implementation
// is that the size of first and second stack is fixed if one stack
// is greater than other than some space will always be wasted.
class stackArr{
    public:
    int *arr;
    int first;
    int second;
    int sizeFirst;
    int sizeSecond;
    stackArr(int x){
        arr= new int[x];
        first=-2;
        second=-1;
        sizeFirst=0;
        sizeSecond=0;
    }
    void push1(int x){
        first=first+2;
        arr[first]=x;
        sizeFirst++;
    }
    int pop1(){
        first=first-2;
        sizeFirst--;
        return arr[first+2];
    }
    int firstSize(){
        return sizeFirst;
    }
    int top1(){
        return arr[first];
    }
    void push2(int x){
        second=second+2;
        arr[second]=x;
        sizeSecond++;
    }
    int pop2(){
        second= second-2;
        sizeSecond--;
        return arr[second+2];
    }
    int secondSize(){
        return sizeSecond;
    }
    int top2(){
        return arr[second];
    }
    void printStack1(){
        for(int i=first;i>=0;i=i-2){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void printStack2(){
        for(int i=second;i>=0;i=i-2){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    stackArr stack1(20);
    stack1.push1(10);
    stack1.push2(15);
    stack1.push1(20);
    stack1.push2(25);
    stack1.push1(30);
    stack1.push2(35);
    stack1.push1(40);
    stack1.push2(45);
    stack1.pop1();
    stack1.pop2();
    stack1.printStack1();
    stack1.printStack2();
    cout<<stack1.firstSize()<<endl;
    cout<<stack1.secondSize()<<endl;
    cout<<stack1.top1()<<endl;
    cout<<stack1.top2()<<endl;
}