#include<iostream>
#include<vector>
using namespace std;
int maxOnes(vector<vector<int>> matrix,int  numrows,int numcols){
    int ans=-1;
    int maxCount=-1;
    // for(int i=0;i<numrows;i++){
    //     int count=0;
    //     for(int j=0;j<numcols;j++){
    //         if(matrix[i][j]==1){
    //             count=numcols-j;
    //             if(count>maxCount){
    //                 maxCount=count;
    //                 ans=i;
    //             }
    //             break;
    //         }
    //     }
    // }
    // return ans;
    //OPTIMAL
    for(int i=0;i<numrows;i++){
        int count=0;
        int low=0;
        int high=numcols-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[i][mid]==1){
                count=numcols-mid;  //atleast numcols-mid ones are there in the row
                if(count>maxCount){
                    maxCount=count;
                    ans=i;
                }
                high=mid-1; //to find more ones
            }else{
                low=mid+1;
            }
        }
    }
    return ans;
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
    int result=maxOnes(matrix,numRows,numCols);
    cout<<"row with maximum number of 1's is "<<result;
}