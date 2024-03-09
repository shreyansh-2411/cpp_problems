#include<iostream>
#include<set>
using namespace std;


// i have implemented this stack uisng multiset but there is a better way
// to do this implementation , In stacks we can push and pop from top and
// random access is not allowed , Using this concept we can implement another
// stack which will keep the min element at the top when we are pushing elements.
struct element{
    int val;
    element* next;
    element(int x){
        val=x;
        next=NULL;
    }
};
// implementation of the structure which gives the minimum
// element in the stack in O(1) time .
class listStack{
    public:
    element *head;
    multiset<int> minElement;
    listStack(){
        head=NULL;
    }
    void push(int x){
        minElement.insert(x);
        element* temp= head;
        head= new element(x);
        head->next= temp;
    }
    void pop(){
        minElement.erase(minElement.find(head->val));
        element* temp= head;
        head= head->next;
        delete(temp);
    }
    int getMin(){
        return *(minElement.begin());
    }
};

int main(){
    listStack stack1;
    stack1.push(10);
    stack1.push(10);
    stack1.push(20);
    stack1.push(5);
    stack1.push(30);
    stack1.push(5);
    cout<<stack1.getMin()<<endl;
    stack1.pop();
    cout<<stack1.getMin()<<endl;
}