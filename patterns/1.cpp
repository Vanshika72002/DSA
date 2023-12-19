#include<iostream>
using namespace std;
int main(){
    //to print the pattern
    //     * * * * 
    //     * * * *
    //     * * * *
    //     * * * *
    //number of rows = no of columns
    int nrows=4;
    for(int i=0;i<nrows;i++){
        for(int j=0;j<nrows;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
}