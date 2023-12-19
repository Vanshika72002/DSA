#include<iostream>
using namespace std;
int main(){
    // 1
    // 2 1
    // 3 2 1
    // 4 3 2 1
    int i=1;
    int nrows=4;
    int count=1;
    while(i<=nrows){
        int j=1;
        int val=i;
        while(j<=i){
            cout<<i-j+1;    //cout<<val<<" ";val--
            j++;
        }
        cout<<endl;
        i++;
    }
}