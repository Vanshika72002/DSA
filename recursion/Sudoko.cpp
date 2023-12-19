#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<char>> board={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
// void input(){
//     char x;
//     // cin>>N;
    
//     for(int i=0;i<N;i++){
//         string vec;
//         for(int j=0;j<N;j++){
//             cin>>x;
//             vec[j]=x;
//         }
//         board.push_back(vec);
//     }
// }
void output(){
    cout<<'{';
    for(int i=0;i<9;i++){
        cout<<"{";
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<",";
        }
        cout<<"}";
        cout<<"\n";
    }
    cout<<"}";
}
// bool isEmpty(int i,int j){
//     for(int row=i;row<9;row++){
//         for(int col=j;col<9;col++){
//             if(board[row][col]==' '){
//                 return true;
//             }
//         }
//     }
//     return false;
// }
bool isSafe(char digit,int row,int col){
    //digit is not present in row
    for(int i=0;i<9;i++){
        if(board[row][i]==digit){
            return false;
        }
        //digit is not present in col
        if(board[i][col]==digit){
            return false;
        }
        //digit is not present in the block
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==digit)
            return false;

    }
    return true;
}
bool sudokosolver(){
    //Base Case
    

    //find first empty place to fill
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char digit='1';digit<='9';digit++){
                    if(isSafe(digit,i,j)){
                        board[i][j]=digit;
                        if(sudokosolver()==true){
                            return true;       //it's ok to place the digit 
                        }
                        else {
                            board[i][j]='.';        //its not ok to place the digit.check some other digits
                        }       
                    }
                    
                }
                return false;    //no digit is safe
            }
            
        }
    }
    return true;    //board is not empty
    
}

int main(){
    
    sudokosolver();
    output();

}