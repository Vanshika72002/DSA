#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
void Rotate(vector<vector<int>> &v){
    //BRUTE FORCE
        //copy the matrix to another matrix 
     int numrow=v.size();
     int numcol=v[0].size();
    // vector<vector<int>> Copy;    
    // int x;
    // vector<int> row;
    // for(int i=0;i<numrow;i++){
    //     Copy.push_back(v[i]);
    // }
    // for(int i=0;i<numrow;i++){
    //     for(int j=0;j<numcol;j++){
    //         v[i][j]=Copy[numrow-1-j][i];
    //     }
    // }
    //OPTIMAL
    //Transpose
    for(int i=0;i<numrow-1;i++){
        for(int j=i+1;j<numcol;j++){
            swap(v[i][j],v[j][i]);
        }
    }
    cout<<"Transposed matrix:";
    for(int i=0;i<numrow;i++){
        for(int j=0;j<numcol;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    //reverse each row
    for(int i=0;i<numrow;i++){
        reverse(v[i].begin(),v[i].end());
    }
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
    Rotate(v);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
