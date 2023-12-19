#include<iostream>
using namespace std;
int main(){
    //to print the pattern
    //     A A A
    //     B B B
    //     C C C
    //number of rows = no of columns
    int nrows=3;
    // int ascii=65;
    for(int i=0;i<nrows;i++){
        for(int j=0;j<nrows;j++){
            // cout<<char(ascii)<<" ";
            char ch='A'+i;
            cout<<ch;
        }
        // ascii++;
        cout<<"\n";
    }
}