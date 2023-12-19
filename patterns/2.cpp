#include<iostream>
using namespace std;
int main(){
    //to print the pattern
    //     1 1 1 1  
    //     2 2 2 2 
    //     3 3 3 3 
    //     4 4 4 4 
    //number of rows = no of columns
    int nrows=4;
    int i=1;
    while(i<=nrows){
        int j=1;
        while(j<=nrows){
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;

    }
}