#include<iostream>
using namespace std;


void dynamicInteger(){
    // new keyword is used to declare dynamic memory
    // it tells compiler to allocate memory in heap and
    // an pointer is returned that points to allocate memo
    int* a = new int;
    *a = 10;
    cout<<*a;
    cout<<endl;
    // we have to manually deallocate this memory as the
    // scope of this memory is infinite and will never be 
    // deleted if not done manually ( memory leak )
    delete a;
}

void dynamicArray(){
    // for using new keyword we need a pointer to store the
    // location of the variabel and after new keyword we
    // need to define the data type that we want to allocate
    // in this case it is array
    int* arr= new int[5];
    for(int i=0;i<5;i++){
        arr[i]=i+1;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // array is delete in the same way as a single variabel
    // delete function will delete all the allocate memo on its own
    delete[] arr;
}

void dynamic2DArray(){
    // for making a 2D array we have to dynamically allocate an
    // array of pointers where each pointer will have an array 
    // this gives us a 2D array
    int** arr= new int*[5];
    // here we have use two (*)s as we want a pointer to further
    // dereference to another pointer
    for(int i=0;i<5;i++){
        arr[i]= new int[5];
        for(int j=0;j<5;j++){
            arr[i][j]=i+1;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // deallocaing memory is same for 2D array as well
    delete[] arr;
}

int main(){
    dynamicInteger();
    dynamicArray();
    dynamic2DArray();
    return 0;
}