#include<iostream>
using namespace std;
//Merge sort algorithm


//function to merge two sorted arrys in such a way that
//the new arry formed is also sorted 
void merge(int arr[],int start,int mid,int end){
    int n1=mid-start+1;
    int n2=end-mid;
    int a1[n1];
    int a2[n2];
    for(int i=0;i<n1;i++){
        a1[i]=arr[start+i];
    }
    for(int i=0;i<n2;i++){
        a2[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=start;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            arr[k]=a1[i];
            i++; k++;
        }
        else{
            arr[k]=a2[j];
            j++; k++;
        }
    }
    while(i<n1){
        arr[k]=a1[i];
        i++; k++;
    }
    while(j<n2){
        arr[k]=a2[j];
        j++; k++;
    }
}

//function to merge sort the unsorted array
void mergeSort(int arr[],int start,int end){
    if(start<end){
        int mid =(start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

int main(){
    int arr[10]={5,6,3,10,7,12,23,11,55,90};
    mergeSort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}