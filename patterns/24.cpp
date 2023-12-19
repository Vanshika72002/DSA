//      1
//    2 3
//  4 5 6 
//7 8 9 10
#include<iostream>
using namespace std;
int main(){
    int nrows=4;
    int i=1;
    int count=1;
    while(i<=nrows){
        int j=1;
        while(j<=nrows){
            if(j>nrows-i){
                cout<<count<<" ";
                count+=1;
            }
            else{
                cout<<"  ";
            }
            j++;
        }
        cout<<endl;
        i++;
    }
}