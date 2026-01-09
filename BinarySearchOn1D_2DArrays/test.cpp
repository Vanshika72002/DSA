#include<iostream>
using namespace std;
int fun(int n){
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=i;j>0;j--)
            cout<<"Statement running";
    return cnt;
    
}
int main(){
    fun(7);
}