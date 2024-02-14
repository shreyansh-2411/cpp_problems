#include<iostream>
#include<vector>
using namespace std;


// function to dnf sort the array
void dnfSort(int arr[],int n){
    int start =0;
    int mid =0;
    int end =n-1;
    while(mid<end){
        if(arr[mid]==0){
            arr[mid]=arr[start];
            arr[start]=0;
            mid++;
            start++;
        }
        if(arr[mid]==1){
            mid++;
        }
        if(arr[mid]==2){
            arr[mid]=arr[end];
            arr[end]=2;
            end--;
        }
    }
}

int main(){
    int n=9;
    // dnf sort can only be used to sort an array with 0,1 and 2 as elements
    int arr[9]={1,0,2,1,0,1,2,1,2};
    dnfSort(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}