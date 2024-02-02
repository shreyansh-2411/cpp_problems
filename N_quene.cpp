#include <iostream>
using namespace std;
//we have to place n quenes in nxn board such
//that none of the quenes can kill each other


//function to check if the postion is safe for placing quene
int isSafe(int** arr,int col[],int x,int y,int n){
    if(col[y]==1)
        return false;
    int r=x;
    int c=y;
    while(r>=0 && c>=0){
        if(arr[r][c]==1)
            return false;
        r--;
        c--;
    }
    r=x;
    c=y;
    while(r>=0 && c<n){
        if(arr[r][c]==1)
            return false;
        r--;
        c++;
    }
    return true;
}
//recursive function to place quenes in a nxn board
bool quene(int** sol,int col[],int n,int row){
    if(row>=n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(isSafe(sol,col,row,i,n)){
            col[i]=1;
        sol[row][i]=1;
        if(quene(sol,col,n,row+1)){
            return true;
        }
        col[i]=0;
        sol[row][i]=0;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    //we are using a 2D arry of dynamic size
    //that is how we pass a 2D array in a function 
    int** sol=new int*[n];
    for(int i=0;i<n;i++){
        sol[i]= new int[n];
        for(int j=0;j<n;j++)
            sol[i][j]=0;
    }
    int col[n];
    for(int i=0;i<n;i++){
        col[i]=0;
    }
    if(quene(sol,col,n,0)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<sol[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}