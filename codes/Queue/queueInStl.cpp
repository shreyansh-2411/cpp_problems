#include<iostream>
#include<queue>
using namespace std;


// this is the stl implementation of Queue in cpp
// we have Push , Pop , size , front and back functions
// with stl queue.
int main(){
    queue<int> q;
    q.push(20);
    q.push(30);
    q.push(14);
    q.push(37);
    q.push(27);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.front()<<endl;
}