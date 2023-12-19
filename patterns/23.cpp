// 1 2 3 4
//   2 3 4 
//     3 4
//       4
#include<iostream>
using namespace std;
int main(){
    int nrows=4;
    int i=1;
    while(i<=nrows){
        int j=1;
        while(j<=nrows){
            if(j>=i){
                cout<<j<<" ";

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