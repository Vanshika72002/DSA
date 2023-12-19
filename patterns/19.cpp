// * * * * 
// * * * 
// * * 
// * 
#include<iostream>
using namespace std;
int main(){
    int nrows=4;
    int i=1;
    while(i<=nrows){
        int j=1;
        while(j<=nrows-i+1){
            cout<<"* ";
            j++;
        }
        i++;
        cout<<endl;
    }
}