#include<iostream>
using namespace std;
//Quick sort algorithm


//function to put the last element in its correct
//position as per sorted array
int position(int arr[],int start,int end){
    int n =end-start;
    int a[n];
    int a1[n];
    for(int i=start;i<end;i++){
        a[i]=arr[i];
    }
    int k=start;
    int j=0;
    for(int i=start;i<end;i++){
        if(a[i]<arr[end]){
            arr[k]=a[i];
            k++;
        }
        else{
            a1[j]=a[i];
            j++;
        }
    }
    j=0;
    int result =k;
    arr[k]=arr[end];
    k++;
    while(k<=end){
        arr[k]=a1[j];
        j++; k++;
    }
    return result;
}

//function to quick sort an array
void quickSort(int arr[],int start,int end){
    if(start<end){
        int pos= position(arr,start,end);
        quickSort(arr,start,pos-1);
        quickSort(arr,pos+1,end);
    }
}

int main(){
    int arr[10]={5,6,3,10,7,12,23,11,55,90};
    quickSort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}