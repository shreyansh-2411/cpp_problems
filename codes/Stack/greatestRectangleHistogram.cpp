#include<iostream>
#include<stack>
using namespace std;


void prevSmaller(int arr[],int n,int result[]){
    result[0]=-1;
    stack<int> blocker;
    blocker.push(0);
    for(int i=1;i<n;i++){
        while(!blocker.empty() && arr[i]<arr[blocker.top()]){
            blocker.pop();
        }
        if(blocker.empty()){
            result[i]=-1;
            blocker.push(i);
        }else{
            result[i]=blocker.top();
            blocker.push(i);
        }
    }
}
void nextSmaller(int arr[],int n,int *result){
    result[n-1]=n;
    stack<int> blocker;
    blocker.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!blocker.empty() && arr[i]<arr[blocker.top()]){
            blocker.pop();
        }
        if(blocker.empty()){
            result[i]=-1;
            blocker.push(i);
        }else{
            result[i]=blocker.top();
            blocker.push(i);
        }
    }
}

int main(){
    int n=7;
    int arr[7]={6,2,5,4,1,5,6};
    int prev[n];
    int next[n];
    prevSmaller(arr,n,prev);
    nextSmaller(arr,n,next);
    int result =0;
    for(int i=0;i<n;i++){
        int counter= (next[i]-prev[i]-1)*arr[i];
        result= max(result,counter);
    }
    cout<<result;
    return 0;
}