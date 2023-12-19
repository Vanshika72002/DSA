#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isSafe(int row,int col,vector<string> &board,int N,vector<int> left,vector<int> lowerD,vector<int> UpperD){
        // int duprow=row;
        // int dupcol=col;
        // //checking the left side of the row
        // while(col>=0){
        //     if(board[row][col]=='Q')
        //         return false;
        //     col--;
        // }
        // col=dupcol;
        // row=duprow;
        // //checking the lower diagonal
        // while(col>=0&&row<N){
        //     if(board[row][col]=='Q')
        //         return false;
        //     col--;
        //     row++;
        // }
        // col=dupcol;
        // row=duprow;
        // while(col>=0&&row>=0){
        //     if(board[row][col]=='Q')
        //         return false;
        //     col--;
        //     row--;
        // }
        // return true;
        
        /*
        *       OPTIMIZED WAY👇
        */
        if(left[row]==0&&UpperD[N-1+col-row]==0&&lowerD[row+col]==0){
            return true;
        }
        return false;


}
void Solve(int col,vector<string> &board,vector<vector<string>> &ans,int N, vector<int> left,vector<int> lowerD,vector<int> UpperD){
        if(col==N){                     //all the columns have been filled wih queen
            ans.push_back(board);
            return;
        }
        for(int i=0;i<N;i++){
            if(isSafe(i,col,board,N,left,lowerD,UpperD)){
                board[i][col]='Q';
                left[i]=1;
                UpperD[N-1+col-i]=1;
                lowerD[i+col]=1;
                Solve(col+1,board,ans,N,left,lowerD,UpperD);
                board[i][col]='.';
                left[i]=0;
                UpperD[N-1+col-i]=0;
                lowerD[i+col]=0;
            }

        }
}
int main(){
    vector<vector<string>> ans;
    vector<string> board;
       int N;
    cin>>N;
     vector<int> left(N,0);
    vector<int> lowerD(2*N-1,0) ; 
    vector<int> UpperD(2*N-1,0);

    string s(N,'.');
    for(int i=0;i<N;i++){       //initializing the board with '.'
        board.push_back(s);
    }
    
    Solve(0,board,ans,N,left,lowerD,UpperD);
    for(int i=0;i<ans.size();i++){
        //for each board
        for(int j=0;j<N;j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<"\n--------\n";
    }

}