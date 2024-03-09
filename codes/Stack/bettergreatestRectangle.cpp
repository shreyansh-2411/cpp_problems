#include<iostream>
#include<stack>
using namespace std;

// to solve this question we will be iterating through the array and
// pushing every elemnt to a stack which is greater than the current
// top element of the stack , with this we will have a stack where element 
// next to the top will be previous smaller element of the top.
int greatestRectangle(int arr[],int n){
    stack<int> s;
    int result=0;
    int current;
    for(int i=0;i<n;i++){
        // And when we will enter this while loop we will be removing
        // the elements of the stack which are smaller than the current 
        // element as our new smaller element is the current element and 
        // while doing this we can treat the current element as the next
        // smaller element which will help us calculate the are of the
        // rectangle whith stacks top elemnt as the height of the rect.
        while(s.empty()==false && arr[s.top()]>=arr[i]){
            int temp= s.top();
            s.pop();
            current= arr[temp]* (s.empty()?i:(i-s.top()-1));
            result= max(result,current);
        }
        s.push(i);
    }
    while(s.empty()==false){
        int temp=s.top();
        s.pop();
        current= arr[temp]* (s.empty()?n:(n-s.top()-1));
        result= max(result,current);
    }
    return result;
}

// as we have understood previously to find the area of largest rectangle
// we have to check the area of rectangle with every elemnt being height 
// of that rectangle and to achieve that we find the previous and next smaller
// element of that elemnt as that is the point till which we will be able to 
// form an rectangle whith that element being the height of the rectangle
// in this logic we just take advantage of the fact that if the prev elemnt is
// smaller than the current elemnt than we don't have to look any furthure back
// as that element will create a blocker for rectangel beyond that point.
// this logic is a bit hard to understand , Recomend watching video again.
int main(){
    int n=7;
    int arr[7]={6,2,5,4,1,5,6};
    cout<<greatestRectangle(arr,n);
}