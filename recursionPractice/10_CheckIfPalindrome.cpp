#include<iostream>
#include<string>
using namespace std;

bool isPlaindrome(string s,int i){
    int N=s.length();
    if(i>=N/2){
        return true;
    }
    if(s[i]==s[N-i-1]){
        return isPlaindrome(s,i+1);
    }else{
        return false;
    }
    
}

int main(){
    
    string s;
    cin>>s;
    if(isPlaindrome(s,0)){
        cout<<"String is palindrome";
    }else{
        cout<<"string is not palindrome";
    }   

}