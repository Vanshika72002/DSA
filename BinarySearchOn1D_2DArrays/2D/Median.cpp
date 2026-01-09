#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// int median(vector<vector<int>> mat,int rows,int cols){
//     if(rows==1){
//         return mat[0][(cols)/2];
//     }else{
//         return mat[(rows)/2][0];
//     }
//     vector<int> v;  //1D array to store 2D array elements
//     for(int i=0;i<rows;i++){
//         for(int j=0;j<cols;j++){
//             v.push_back(mat[i][j]);
//         }
//     }
//     sort(v.begin(),v.end());
//     int midIndex=(rows*cols)/2;
//     return v[midIndex];
// }
int upperBound(vector<int> nums,int target){
    int low=0;
    int Size=nums.size();
    int high=Size-1;
    int index=Size;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>target){
            index=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return index;
}
int func(vector<vector<int>> mat,int rows,int cols,int el){
    int nums=0;
    for(int i=0;i<rows;i++){
        cout<<"number of elements <= "<<el<<"in row "<<i<<"= "<<upperBound(mat[i],el);
        nums+=upperBound(mat[i],el);
    }
    return nums;
}
int median(vector<vector<int>> mat,int rows,int cols){
    int high=mat[0][0];
    int low=mat[0][cols-1];
    for(int i=0;i<rows;i++){
        if(high<mat[i][0])
            high=mat[i][0];
    }
    for(int i=0;i<rows;i++){
        if(low>mat[i][cols-1])
            low=mat[i][cols-1];
    }
    while(low<=high){
        int mid=(low+high)/2;
        int sizeBy2=(cols*rows)/2;
        if(func(mat,rows,cols,mid)>sizeBy2){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
    
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
    int result=median(matrix,numRows,numCols);
    cout<<"Median is "<<result;
}