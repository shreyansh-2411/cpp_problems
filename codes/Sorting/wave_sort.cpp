#include<iostream>
using namespace std;


// function to swap two elements of an array
void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

// function to wave sort an array 
void waveSort(int arr[],int n){
    int i=1;
    while(i<n-1){
        if(arr[i]>arr[i-1]){
            swap(&arr[i],&arr[i-1]);
        }
        if(arr[i]>arr[i+1]){
            swap(&arr[i],&arr[i+1]);
        }
        i=i+2;
    }
}

int main(){
    int n=7;
    int arr[7]={1,3,4,7,5,6,2};
    waveSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}