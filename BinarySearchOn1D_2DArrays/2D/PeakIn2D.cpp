#include<iostream>
#include<vector>
using namespace std;
int maxElementRow(vector<vector<int>>& mat,int m,int n,int col){
    int max_ind=0;
    for(int i=0;i<n;i++){
        if(mat[i][col]>mat[max_ind][col]){
            max_ind=i;
        }
    }
    return max_ind;
}
vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int numRows=mat.size();
        int numCols=mat[0].size();
        //brute Force
        // for(int i=0;i<numRows;i++){
        //     for(int j=0;j<numCols;j++){
        //         cout<<"for "<<mat[i][j];
        //         if((i>=1 && mat[i][j]>mat[i-1][j] )||i<1){
        //                 cout<<"greater than above element";
        //             }
        //             else{
        //                 continue;
        //             }
        //         if((j>=1 && mat[i][j]>mat[i][j-1]) || j<1){
        //                 cout<<"greater than the left element";
        //             }
        //             else{
        //                 continue;
        //             }
        //         if((i<numRows-1 && mat[i][j]>mat[i+1][j] )||i>=numRows-1){
        //                 cout<<"greater than the below element";
        //             }
        //             else{
        //                 continue;
        //             }
        //         if((j<numCols-1 && mat[i][j]>mat[i][j+1]) || j>=numCols-1){
        //                 cout<<"greater than the right element"<<mat[i][j+1];
        //                 return {i,j};
        //             }
        //             else{
        //                 continue;
        //             }
        //     }
                    
        // }
        int low=0;
        int high=numCols-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            //find maximum in mid col of matrix
            int row=maxElementRow(mat,numCols,numRows,mid);
            int left=mid-1>=0 ? mat[row][mid-1] : -1;
            int right=mid+1 < numCols ? mat[row][mid+1] : -1;
            if(mat[row][mid]>left&&mat[row][mid]>right)
                return {row,mid};
            if(left>mat[row][mid])
                high=mid-1;
            else
                low=mid+1;
        }
        return {-1,-1};
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
    cout<<"matrix  is\n";
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int> result=findPeakGrid(matrix);
    cout<<"Peak ELement position :("<<result[0]<<","<<result[1]<<")";
}