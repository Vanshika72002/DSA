#include<iostream>
using namespace std;
int main(){
    // *
    // * *
    // * * * 
    // * * * *
    

    int nrows=4;
    int i=1;
    while(i<=nrows){
        int j=1;
        while(j<=i){
            cout<<"* ";
            // cout<<i<<' ';
            // 1
            // 2 2 
            // 3 3 3 
            // 4 4 4 4 
            j++;
        }
        cout<<endl;
        i++;
    }
}