#include<iostream>
#include<queue>
using namespace std;


// function to get the n numbers with given set in sorted order
// here we use queue to get all the number , Look at the output
// of this code to understand the problem statement better.
void nNumbersWithGivenSet(int arr[],int n,int l){
    queue<int> q;
    int counter= 0;
    for(int i=0;i<n;i++){
        q.push(arr[i]);
        cout<<q.back()<<" ";
        counter++;
        if(counter==l){
            break;
        }
    }
    // there is another way of doing this question , we can use 
    // string insted of arry , that we appending number at the end
    // will be easy , rest all will be same.
    int i=0;
    while(counter!=l){
        int temp= q.front()*10 + arr[i];
        q.push(temp);
        cout<<q.back()<<" ";
        counter++;
        i++;
        if(i==n){
            i=0;
            q.pop();
        }
    }
}

int main(){
    int arr[4]={2,3,4,5};
    nNumbersWithGivenSet(arr,4,40);
}