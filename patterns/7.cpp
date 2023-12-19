#include<iostream>
using namespace std;
int main(){
    //1
    //2 3 
    //3 4 5
    //4 5 6 7
    int i=1;
    int nrows=4;
    int count=1;
    while(i<=nrows){
        int j=1;
        int val=i;
        while(j<=i){
            cout<<val<<" ";         ////or cout<<i+j-1;
            val++;
            j++;
        }
        cout<<endl;
        i++;
    }
}