#include<iostream>
using namespace std;
void naturalNumbers(int i,int N){
    if(i>N)
        return;
    cout<<i;
    i++;
    naturalNumbers(i,N);
}
int main(){
    naturalNumbers(1,6);
}