#include<iostream>
using namespace std;
int main(){
    //A B C
    //B C D
    //C D E
    int i=1;
    int nrows=3;
    char ch='A';
    // while(i<=nrows){
        
    //     int j=1;
    //     while(j<=nrows){

    //         cout<<char(ch);
    //         ch=ch+1;
    //         j++;
    //     }
    //     ch='A'+i;
    //     cout<<endl;
    //     i++;
    // }
    while(i<=nrows){
        
        int j=1;
        while(j<=nrows){

            cout<<char('A'+i+j-2);
            j++;
        }
        cout<<endl;
        i++;
    }
}