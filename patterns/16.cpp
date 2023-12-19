// A
// B C
// B C D
// D E F G
#include<iostream>
using namespace std;
int main(){
    int nrows=4;
    int i=0;
    while(i<=nrows){
        int j=0;
        while(j<=i){
            char ch;
            ch='A'+i+j;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
         
    }
}