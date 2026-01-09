// Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and columns, respectively. The elements of each row and each column are sorted in non-decreasing order.
// But, the first element of a row is not necessarily greater than the last element of the previous row (if it exists).
// You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.
#include<iostream>
#include<vector>
using namespace std;
int Search(vector<vector<int>> mat,int numRows,int numCols,int key){
    //BruteForce
    // for(int i=0;i<numRows;i++){
    //     for(int j=0;j<numCols;j++){
    //         if(mat[i][ij]==key)
    //             return true;
    //     }
    // }
    // return false;
    // //Better
    // for(int i=0;i<numRows;i++){
    //     if(mat[i][0]>=key && mat[i][numCols-1]<=key){
    //         for(int j=0;j<numCols;j++){
    //             if(mat[i][j]==key)
    //                 return true;
    //         }
    //     }
    // }
    // return false;
    //OPTIMAL
    //starting from first row last element, on moving downwards the element increases and on moving left element decreases
    int row=0;
    int col=numCols-1;
    while(row<numRows && col>=0){
        if(mat[row][col]==key)
            return true;
        else if(mat[row][col]>key)
            col--;
        else
            row++;
    } 
    return false;
}
int main(){
    int numRows;
    int x;
    int numCols;
    vector<vector<int>> matrix;
    cin>>numRows;
    cin>>numCols;
    for(int i=0;i<numRows;i++){
        vector<int> row;
        for(int j=0;j<numCols;j++){
            cin>>x;
            row.push_back(x);
        }
        matrix.push_back(row);
        cout<<endl;
    }
    cin>>x;
    bool result=Search(matrix,numRows,numCols,x);
    cout<<"element present in the matrix : "<<result;
}