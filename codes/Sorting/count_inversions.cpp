#include<iostream>
using namespace std;


// code to merge the two sorted arrays
long long merge(int arr[],int start,int mid,int end){
    int ans=0;
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
            ans+= n1-i;
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
    return ans;
}

// code to find the count of inversions in an array , inversions
// are pairs of elements in an array where a[i]>a[j] and i<j
long long countInversions(int arr[],int start,int end){
    int ans=0;
    if(start<end){
        int mid = (start+end)/2;
        ans +=countInversions(arr,start,mid);
        ans +=countInversions(arr,mid+1,end);
        ans +=merge(arr,start,mid,end);
    }
    return ans;
}

int main(){
    int n=8;
    int arr[8]={3,5,6,9,1,2,7,8};
    cout<<countInversions(arr,0,n-1);
}