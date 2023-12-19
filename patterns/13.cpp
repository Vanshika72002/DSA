// A
// B B 
// C C C 
#include<iostream>
using namespace std;
int main(){
    int nrows=10;
    int i=0;
    while(i<nrows){
        int j=0;
        while(j<=i){
            char ch='A'+i;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}   