#include<iostream>
using namespace std;
int main(){
    // ABC
    // DEF
    // GHI
    int i=1;
    int nrows=3;
    char ch='A';
    while(i<=nrows){
        
        int j=1;
        while(j<=nrows){
            cout<<char(ch);
            ch=ch+1;
            j++;
        }
        cout<<endl;
        i++;
    }
}