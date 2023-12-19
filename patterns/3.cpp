#include<iostream>
using namespace std;
int main(){
    //pattern to be printed
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4
    // 1 2 3 4
    int nrows=4;
    int i=1;
    while(i<=nrows){
        int j=1;
        while(j<=nrows){
            cout<<j<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
    

}