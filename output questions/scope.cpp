#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<a<<endl;
    a=12;
    cout<<a<<endl;
    if(true){
        cout<<a<<endl;
        int a=9;
        cout<<a<<endl;
        int b=10;
    }
    cout<<a<<endl;
    // cout<<b;            ///Error::b was not declared in the scope

}
