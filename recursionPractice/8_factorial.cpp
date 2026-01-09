#include<iostream>
using namespace std;

//functional recursion:return the answer
int factorial(int N){
    if(N==0)
        return 1;
    return N*factorial(N-1);
}
//parameterized way:prints the answer
//get closer to the answer in every single step and at last print.
void print_factorial(int N,int fact){
    if(N==0){
        cout<<fact;
    }
    fact*=N;
    print_factorial(N-1,fact);
}
int main(){
    int N;
    cin>>N;
    int fact=factorial(N);
    cout<<fact<<endl;
    print_factorial(N,1);
}
