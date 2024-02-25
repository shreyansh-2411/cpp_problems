#include<iostream>
using namespace std;


class nStacks{
    public:
    int *arr;
    int size;
    int k;
    vector< pair<int,int> > index;
    nStacks(int x,int y){
        size=x;
        arr= new int[x];
        k=x/y;
        for(int i=0;i<y;i++){
            pair<int,int> temp= make_pair(i*k,0);
            index.push_back(temp);
        }
    }
    void printIndex(){
        for(int i=0;i<index.size();i++){
            cout<<index[i].first<<" "<<index[i].second<<endl;
        }
    }
    void push(int n,int x){
        if(index[n].second == k){
            cout<<"going beyond stack size"<<endl;
            return;
        }
        arr[index[n-1].first]=x;
        index[n-1].first++;
        index[n-1].second++;
    }
    void pop(int n){
        if(index[n].second == 0){
            cout<<"nothing to pop from stack"<<endl;
            return;
        }
        index[n-1].first--;
        index[n-1].second--;
    }
    int top(int n){
        return arr[(index[n-1].first)-1];
    }
    int sizeN(int n){
        return index[n-1].second;
    }
    void printStack(int n){
        for(int i=(index[n-1].first -1);i>=((n-1)*k);i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    nStacks stack1(50,5);
    stack1.push(1,1);
    stack1.push(1,2);
    stack1.push(1,3);
    stack1.push(1,4);
    stack1.push(1,5);
    stack1.push(2,11);
    stack1.push(2,12);
    stack1.push(2,13);
    stack1.push(2,14);
    stack1.push(2,15);
    stack1.push(3,21);
    stack1.push(3,22);
    stack1.push(3,23);
    stack1.push(3,24);
    stack1.push(3,25);
    stack1.pop(1);
    stack1.printStack(1);
    cout<<stack1.top(1)<<endl;
}