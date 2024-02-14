#include<iostream>
#include<vector>
using namespace std;


// function to count sort the array
void countSort(int arr[],int n,int N){
    vector<int> a(N,0);
    for(int i=0;i<n;i++){
        a[arr[i]]++;
    }
    for(int i=1;i<N;i++){
        a[i]+=a[i-1];
    }
    int ar[n];
    for(int i=n-1;i>=0;i--){
        a[arr[i]]--;
        ar[a[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=ar[i];
    }
}

int main(){
    int n=9;
    int arr[9]={1,3,2,3,4,1,6,4,3};
    countSort(arr,n,7);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}