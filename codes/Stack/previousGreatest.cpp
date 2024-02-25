#include<iostream>
#include<stack>
using namespace std;


void prevGreatest(int arr[],int n){
    stack<int> greater;
    greater.push(arr[0]);
    cout<<-1<<" ";
    for(int i=1;i<n;i++){
        if(arr[i]<greater.top()){
            cout<<greater.top()<<" ";
            greater.push(arr[i]);
        }else{
            greater.pop();
            while(!greater.empty() && (arr[i]>greater.top())){
                greater.pop();
            }
            if(greater.empty()){
                greater.push(arr[i]);
                cout<<-1<<" ";
            }else{
                cout<<greater.top()<<" ";
                 greater.push(arr[i]);
            }
        }
    }
}

int main(){
    int arr[8]={15,10,18,12,4,6,2,8};
    prevGreatest(arr,8);
}