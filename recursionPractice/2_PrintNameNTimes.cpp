#include<iostream>
#include<string>
using namespace std;
void printName(string name ,int N){
    if(N==0)
        return;
    cout<<name<<endl;
    N--;
    printName(name,N);
}
int main(){
    printName("vanshika",5);
}