// A
// B C
// D E F
// G H I J
#include<iostream>
using namespace std;
int main(){
    int nrows=4;
    char ch='A';
    int i=1;
    while(i<=nrows){
        int j=1;
        while(j<=i){
            cout<<ch<<" ";
            ch=ch+1;
            j++;
        }
        cout<<endl;
        i++;
         
    }
}