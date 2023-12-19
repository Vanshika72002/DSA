//  D
//  C D
//  B C D 
//  A B C D 
#include<iostream>
using namespace std;
int main(){
    int nrows=4;
    int i=1;
    while(i<=nrows){
        int j=1;
        while(j<=i){
            char ch;
            ch='A'+nrows-i+j-1;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
         
    }
}