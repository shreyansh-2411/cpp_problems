#include<iostream>
#include<vector>
using namespace std;


void vectorAllocation(){
    // this statement will initialise an vector of size 10
    // all these 10 elements will be stored in a contigeous storage (just like any array)
    vector<int> arr(10);
    // vectors can be iterated just like arrays as they are
    // also stored in contigeous storages
    for(int i=0;i<10;i++){
        arr[i] = i+1;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // push back can be used to insert an element at the end 
    // of the vector ( it will resize the vector )
    // if i were to print arr[13] before this push back , i
    // would get an error for heap buffer overflow.
    arr.push_back(11);
    // but if i try to access 17th element after writing push_back
    // error will not be displayed instead i will get a garbage
    // value , this happens because c++ will allocate required
    // memory in the heap for a vector but if we increase the size of 
    // the vector using push_back function than compiler allocates
    // more than required memory for that vector .So, that the next
    // time more space is required than compiler will not have to
    // move the entire vector to a new memory location with available
    // contigeous memory 
    cout<<arr[18]<<endl;
    // base on the above logic if we try to access 25th positin of
    // the vector we will get heap buffer overflow error as that 
    // memory was not allocated for the vector , it is not defined
    // that how much more memory will be allocate on resizing a
    // vectory so 17th and 25th positions are just guesses.
    arr.resize(7);
    // resize function will rezise an vector , it can do both inc
    // and dec the size of an vector but on decreasing the vector 
    // it will not actually erase the value of the removed elements
    // from the arry , instead it will decrease the array size by
    // changing the end pointer to that reduced position
    // if we will try to access that position using pointer that was
    // removed by resizing the vectory we can still get the last
    // value stored in that element.
    for(int i : arr){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<arr[9]<<endl;
    // even though the size of the vector is decreased and the iterator
    // will not go to the removed elemet we can still get the last 
    // value stored in the element as complier will keep this memory
    // reserved for vector to hadle resizing of the vector if required
}

void usingVectors(){
    vector<int> arr;
    // if vector size is not defined at the time of of allocation
    // then we can use resize function to allocate memory
    arr.resize(10);
    vector<int>::iterator a=arr.begin();
    // using these iterators we can traverse through vectors
    for(a;a!=arr.end();a++)
        cout<<*a;
}

void iteratorsInVectors(){
    vector<int>::iterator a;
    // iterators are like object of a vecor that can access memebers of
    // that vector and are generally used to iterate throug vectors
    // they are designed for this specific purpose and are like pointers
    // but they can not be directly printed like pointers as they are not exactly pointers 
    // as they have a pre defined logic behind them that iterates over
    // the vector and that logic is abstracted in the form of iterators such
    // that it solves the general purpose of iterating over an vector.
    // for pointers the logic for iteration is defined by us as they point to 
    // an element of array and we increment the address stored in the pointer
    // to move to the next contigeous element of the arry but for iterators
    // this logic is pre defined in some other form.
    // to make iterators simple to understand , you can think of them as a tool
    // created in c++ for moving through an vectory without using pointer and 
    // without understanding the working of pointers as they solves the general
    // purpose of going throug an vector . (easy coding practice like OOPS).
    vector<int> arr(10,0);
    // to simplify iterator defination we use auto keyword.
    auto it = arr.begin();
    *it = 10;
    cout<< *it <<endl;
    // this is a shorthand code to print the entire vector using for loop
    for(auto test:arr){
        cout<<test<<" ";
    }
    cout<<endl;
    // pop_back() function removes the last element of the vecotr and decreases the size
    arr.pop_back();
    for(auto test:arr)
        cout<<test<<" ";
    cout<<endl;
    vector<int> arr1(3,20);
    // swap function swaps the values of two vectors(even if they are of diff sizes)
    swap(arr,arr1);
    for(auto test:arr)
        cout<<test<<" ";
    cout<<endl;
    for(auto test:arr1)
        cout<<test<<" ";
    cout<<endl;
    // swap function can only be used with vectors of same data type (otherwise error)
}

void functionsInVectors(){
    vector<int> arr(10);
    // size function can be used to get the current size of the vector
    cout<<arr.size()<<endl;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(10);
    // sort function can be used to sort the array in nlog(n) time 
    sort(arr.begin(),arr.end());
    for(auto test:arr)
        cout<<test<<" ";
    cout<<endl;
    // max_size() function returnes the max possible size of the vector
    cout<<arr.max_size()<<endl;
    // capacity() function returnes the current capacity of the vector , i.e.
    // the amout of storage vector has in reserve for resize
    cout<<arr.capacity()<<endl;
    // empty() function tells if the vector is empty or not
    cout<<arr.empty()<<endl;
    // reserve(n) function reserves n memory in the capacity of the vector
    arr.reserve(500);
    cout<<arr.capacity()<<endl;
}

int main(){
    usingVectors();
    vectorAllocation();
    iteratorsInVectors();
    functionsInVectors();
    return 0;
}