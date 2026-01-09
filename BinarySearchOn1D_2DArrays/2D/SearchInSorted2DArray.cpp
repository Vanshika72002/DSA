#include<iostream>
#include<vector>
using namespace std;
bool present(vector<vector<int>> matrix,int  numrows,int numcols,int el){
    
    // BruteForce
    // int bruteForceCount=0;
    // int flag=0;
    // for(int i=0;i<numrows;i++){
    //     for(int j=0;j<numcols;j++){
    //         bruteForceCount++;
    //         if(el==matrix[i][j]){  
    //             // return true;
    //             flag=1;
    //             break;
    //         }
    //         if(flag==1)
    //             break;
    //     }
    // }
    // cout<<"bruteForceCount="<<bruteForceCount;
    // // return false;
    // //Better
    // int better_count=0;
    // flag=0;
    // for(int i=0;i<numrows;i++){
    //     if(el>=matrix[i][0] && el<=matrix[i][numcols-1]){
    //         for(int j=0;j<numcols;j++){
    //             better_count++;
    //             if(matrix[i][j]==el)
    //                 flag=1;
    //         }
    //     }
    //     if(flag==1){
    //         cout<<"better count="<<better_count;
    //         return true;
    //     }
    // }
    // return false;
    //OPTIMAL
    int TotalElements=numrows*numcols;
    int low=0;
    int high=TotalElements-1;
    while(low<=high){
        int mid=(low+high)/2;
        int i=mid/numcols;
        int j=mid%numcols;
        if(matrix[i][j]==el)
            return true;
        if(matrix[i][j]<el)
            low=mid+1;
        else
            high=mid-1;

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
    bool result=present(matrix,numRows,numCols,x);
    cout<<"element present in the matrix : "<<result;
}