#include<iostream>
#include<string>
using namespace std;
void Nto1(int i,int N){
    
    if(i>N)
        return;
    
    Nto1(i+1,N);   
    cout<<i;
}
int main(){
    Nto1(1,5);
}