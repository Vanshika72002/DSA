#include<iostream>
#include<string>
using namespace std;
void Nto1(int i ,int N){
    if(i<=0)
        return;
    cout<<i<<" ";
    i--;
    Nto1(i,N);
}
int main(){
    Nto1(5,5);//
}