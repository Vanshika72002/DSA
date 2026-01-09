#include<iostream>
using namespace std;
int Sum(int sum,int N){
    // if(N<1)
    //     return sum;
    // sum+=N;
    // sum=Sum(sum,N-1);
    // OR
    if(N==0)
        return 0;
    sum=Sum(sum,N-1);
    sum+=N;
    //OR
    // sum=N+Sum(sum,N-1);
    return sum;
}
int main(){
    int sum=Sum(0,5);
    cout<<"sum="<<sum;
}