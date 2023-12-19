#include<iostream>
using namespace std;
int main(){
    //  pattern is:-
    // 1 2 3 
    // 4 5 6
    // 7 8 9 
     int nrows=3;
    int n=1;
    int i=1;
    while(i<=nrows){
        int j=1;
        while(j<=nrows){
            cout<<n<<" ";
            j=j+1;
            n=n+1;
        }
        cout<<endl;
        i=i+1;
    }

}