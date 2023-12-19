#include<iostream>
using namespace std;
int main(){
    int i=1;
    int nrows=4;
    int count=1;
    while(i<=nrows){
        int j=1;
        while(j<=i){
            cout<<count<<" ";
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
}