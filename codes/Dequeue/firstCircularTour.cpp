#include<iostream>
using namespace std;


int firstCircularTour(int fule[],int distance[],int n){
    int current= 0;
    int previous= 0;
    int index=0;
    for(int i=0;i<n;i++){
        int temp= fule[i]-distance[i];
        current+= temp;
        if(current<0){
            index= i+1;
            previous+= current;
            current=0;
        }
    }
    current+= previous;
    if(current<0)
    return -1;
    else return index;
}

int main(){
    int fule[4]={4,8,7,4};
    int distance[4]={6,5,3,5};
    cout<<firstCircularTour(fule,distance,4);
}