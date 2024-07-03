#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void setZeroes(vector<vector<int>> &v){
    int numrow=v.size();
    int numcol=v[0].size();
    
    
    //BETTER - MY WAY
    // unordered_set<int> setrow;
    // unordered_set<int> setcol;
    // for(int i=0;i<numrow;i++){
    //     for(int j=0;j<numcol;j++){
            
    //         if(v[i][j]==0){
    //             setrow.insert(i);
    //             setcol.insert(j);
    //         }
    //     }
    // }    
    // //setting row to zero
    // for(auto iter:setrow){
    //     for(int col=0;col<numcol;col++){
    //         v[iter][col]=0;
    //     }
    // }
    // //setting col to zero
    // for(auto iter:setcol){
    //     for(int row=0;row<numrow;row++){
    //         v[row][iter]=0;
    //     }
    // }
    //BETTER-STRIVER's WAY
    // vector<int> zerorow(numrow,0);
    // vector<int> zerocol(numcol,0);
    // for(int i=0;i<numrow;i++){
    //     for(int j=0;j<numcol;j++){
    //         if(v[i][j]==0){
    //             zerorow[i]=1;
    //             zerocol[j]=1;
    //         }
    //     }
    // }
    // for(int i=0;i<numrow;i++){
    //     for(int j=0;j<numcol;j++){
    //         if(zerorow[i]==1||zerocol[j]==1){
    //             v[i][j]=0;
    //         }
    //     }
    // }
    //OPTIMAL
    int col0=1;
    for(int i=0;i<numrow;i++){
        for(int j=0;j<numcol;j++){
            
            if(v[i][j]==0){
                v[i][0]=0;
                if(j!=0)
                    v[0][j]=0;
                
                else
                    col0=0;
                  
            }
        }
    } 
    for(int i=1;i<numrow;i++){
        for(int j=1;j<numcol;j++){
            if(v[0][j]==0 || v[i][0]==0){
                v[i][j]=0;
            }
        }
    }
    if(v[0][0]==0){   
        for(int j=1;j<numcol;j++){
            v[0][j]=0;   
        }
    }
    if(col0==0){
        
    for(int i=1;i<numrow;i++){
        
            v[i][0]=0;
        
    }
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
    setZeroes(v);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
