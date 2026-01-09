#include<iostream>
#include<string>
using namespace std;
void _1toN(int i,int N){
    //keep on decrementing keep on decrementing until value becomes 0 to get the starting point
    //as soon as the value becomes zero, return and start printing value of i in previous calls
    if(i<1)
        return;
    
    _1toN(i-1,N);   
    cout<<i;
}
int main(){
    _1toN(5,5);
}