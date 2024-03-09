#include<iostream>
#include<stack>
using namespace std;


void stockSpan(int arr[],int n){
    int span[n];
    stack<int> blocker;
    cout<<1<<" ";
    span[0]=1;
    for(int i=1;i<n;i++){
        int counter=1;
        if(arr[i]<arr[i-1]){
            blocker.push(i-1);
        }else{
            counter+=span[i-1];
            while(!blocker.empty()){
                if(arr[i]>arr[blocker.top()]){
                    counter+=span[blocker.top()];
                    blocker.pop();
                }
                else break;
            }
        }
        span[i]=counter;
        cout<<counter<<" ";
    }
}

int main(){
    int arr[6]={30,20,25,28,27,29};
    stockSpan(arr,6);
}