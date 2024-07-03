#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void print_Spiral(vector<vector<int>> v){
    int numrow=v.size();
    int numcol=v[0].size();
    int count=0;
    int left=0,right=numcol-1;
    int top=0,bottom=numrow-1;
   
    while(left<=right&&bottom>=top){
    
        // cout<<"top row:\n";
        for(int j=left;j<=right;j++){
            cout<<v[top][j]<<" ";
            count++;
        }
        top++;
    
        // cout<<"right column:\n";

        for(int i=top;i<=bottom;i++){
            cout<<v[i][right]<<" ";
            count++;

        }
        right--;
    
    if(bottom>=top){
        // cout<<"bottom row:\n";

        for(int j=right;j>=left;j--){
            cout<<v[bottom][j]<<" ";
            count++;
            
        }
        bottom--;
    }
    // cout<<"top="<<top<<"bottom="<<bottom;
    if(right>=left){
        // cout<<"left column:\n";

        for(int i=bottom;i>=top;i--){
            cout<<v[i][left]<<" ";
            count++;

        }
        left++;
    }}

}
int main(){
    int m;
    int n;
    vector<vector<int>> v;
    cin>>m;
    cin>>n;
    int x;
    vector<int> row;
    for(int i=0;i<m;i++){
        for(int i=0;i<n;i++){
            cin>>x;
            row.push_back(x);
        }
        v.push_back(row);
        row.clear();
    }
    print_Spiral(v);
    
}
