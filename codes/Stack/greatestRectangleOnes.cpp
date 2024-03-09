#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int greatestRectangleInBinaryMatrix(vector<vector<int>> arr,int r,int c){
    int result=0;
    int current;
    for(int i=0;i<r;i++){
        stack<int> s;
        for(int j=0;j<c;j++){
            if(i!=0 && arr[i][j]!=0){
                arr[i][j]+= arr[i-1][j];
            }
            while(!s.empty() && arr[i][s.top()]>=arr[i][j]){
                int temp= s.top();
                s.pop();
                current= arr[i][temp]* (s.empty()?j:(j-s.top()-1));
                result= max(result,current);
            }
            s.push(j);
        }
        while(!s.empty()){
            int temp= s.top();
            s.pop();
            current = arr[i][temp]* (s.empty()?c:(c-s.top()-1));
            result= max(result,current);
        }
    }
    return result;
}

int main(){
    vector<vector<int>> arr={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
    cout<<greatestRectangleInBinaryMatrix(arr,4,4);
}