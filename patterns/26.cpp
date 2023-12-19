// 1 2 3 4 5 5 4 3 2 1
// 1 2 3 4 * * 4 3 2 1 
// 1 2 3 * * * * 3 2 1
// 1 2 * * * * * * 2 1
// 1 * * * * * * * * 1
#include<iostream>
using namespace std;
int main(){
    int nrows;
    cout<<"enter number of rows ";
    cin>>nrows;
    cout<<endl;
    int i=1;
    while(i<=nrows){
        int j=1;
        int ncol=2*nrows;
        int count=0;
        while(j<=ncol){
            if(j<=nrows-i+1){
                count++;
                cout<<count;
            }
            else 
            if(j<=nrows+i-1){
                cout<<"*";
            }
            else{
                cout<<count;
                count--;

            }
            j++;
            
        }
        cout<<endl;
        i++;
    }
}
