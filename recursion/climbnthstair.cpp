#include<iostream>
using namespace std;
int cnt=0;
void waystoclimb(int i,int N){
    if(i==N){
        cnt++;
        return;
    }
    else if(i>N){
        return;
    }
    waystoclimb(i+1,N);
    waystoclimb(i+2,N);
}
int main(){
    cout<<"Enter N ";
    int N;
    cin>>N;
    waystoclimb(0,N);//waystoclimb(ith stair,goal stair,number of ways)
    cout<<"The number of ways to climb the "<<N<<"th stair are "<<cnt;
}