#include<iostream>
using namespace std;
int main(){
    // ABC
    // ABC
    // ABC
    int i=1;
    int nrows=3;
    while(i<=nrows){
        
        int j=1;
        while(j<=nrows){
            cout<<char('A'+j-1);
            j++;
        }
        cout<<endl;
        i++;
    }
}