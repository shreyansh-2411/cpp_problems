#include<iostream>
#include<vector>
using namespace std;


bool comparator(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}

void reduceArray(int arr[],int n){
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        pair<int,int> temp;
        temp.first= arr[i];
        temp.second= i;
        a.push_back(temp);
    }
    sort(a.begin(),a.end(),comparator);
    int i=0;
    for(auto it:a){
        arr[it.second]=i;
        i++;
    }
}

int main(){
    int arr[8]={10,16,7,14,5,3,12,9};
    reduceArray(arr,8);
    for(int i=0;i<8;i++)
    cout<<arr[i]<<" ";
}