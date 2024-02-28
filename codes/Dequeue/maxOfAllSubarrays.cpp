#include <iostream>
#include <deque>
#include<vector>
using namespace std;


// function to get the max of all the sub arrays of size l 
// in an give array . Here we optimise the code by adding new items
// in such a way that if new item is greater than the current items
// than we will pop all the smaller existing items form the back 
// this is based on the fact that the new element will always be the
// part of sub array than prev elements are a part of
void maxOfSubArray(vector<int> arr, int l)
{
    deque<int> dq;
    vector<int> vec;
    dq.push_front(0);
    for(int i=1;i<l;i++){
        while(!dq.empty() && arr[dq.back()]<arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    vec.push_back(dq.front());
    for(int i=l;i<arr.size();i++){
        // we use this while loop to remove elements which shoudl 
        // not be the part of the sub array.
        while(!dq.empty() && dq.front()<=i-l)
        dq.pop_front();
        while(!dq.empty() && arr[dq.back()]<arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        vec.push_back(dq.front());
    }
    for(int i=0;i<vec.size();i++)
    cout<<arr[vec[i]]<<" ";
}

int main()
{
    vector<int> arr;
    arr.push_back(20);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(15);
    arr.push_back(6);
    arr.push_back(30);
    maxOfSubArray(arr, 3);
}