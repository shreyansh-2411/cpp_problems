#include<iostream>
using namespace std;
//Quick sort algorithm


//function to put the last element in its correct
//position as per sorted array
//this function was first thought by me you can find the better
//version of this code in the function below
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

//function to find correct position of the last element
//as per the sorted array.
int position1(int arr[],int start,int end){
    int j=start-1;
    for(int i=start;i<end;i++){
        if(arr[i]<arr[end]){
            j++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[end];
    arr[end]=arr[j+1];
    arr[j+1]=temp;
    return j+1;
}

//function to quick sort an array
void quickSort(int arr[],int start,int end){
    if(start<end){
        int pos= position1(arr,start,end);
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