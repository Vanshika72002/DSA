#include<iostream>
using namespace std;
void fun(int i){
    cout<<"hi"<<i;
    i++;
    fun(i);
}
int main(){
    fun(1);
}