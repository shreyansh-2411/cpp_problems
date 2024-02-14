#include<iostream>
using namespace std;


// comparator function used to define the sorting method 
// to be applied on the vector of pairs.
bool comparator(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}

// function to count the number of inversions in the array
// i created this method thinking that this would have less time 
// complexity than the original code but turns out this might have
// greater time complexity.
int countInversions(int arr[],int n){
    int ans =0;
    vector< pair<int,int> > a(n);
    for(int i=0;i<n;i++){
        a[i].first =arr[i];
        a[i].second = i;
    }
    sort(a.begin(),a.end(),comparator);
    for(int i=1;i<n;i++){
        int j=i-1;
        while(j>=0){
            if(a[i].second<a[j].second)
            ans++;
            j--;
        }
    }
    return ans;
}

int main(){
    int n=8;
    int arr[8]={3,5,6,9,1,2,7,8};
    cout<<countInversions(arr,n);
}