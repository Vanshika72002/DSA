#include<iostream>
#include<cstring>
#include<string>
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string original){
    string reversedString=original;
    reverse(reversedString.begin(),reversedString.end());
    if(reversedString==original){
        cout<<"matched";
        return true;
        }
    return false;
}

int main(){
    //way1 to initialize strings
    char str[]={'e','d','c','b','\0'};
    //way2 to initialize strings
    char str2[]="hello";
    cout<<str2[0]<<endl<<str2[5]<<endl<<str2[6]<<endl;

    //input and output
    //input way1
    char inputstr[67];
    // cin>>inputstr;
    // cout<<inputstr<<endl;
    //input way2
    char inputstr2[8];
    // cin.getline(inputstr2,8,'4');
    // inputstr2[0]='8';
    // cout<<inputstr2<<endl;

    //Reverse a string
    // cout<<"Enter the string to be reversed : ";
    // string strReverse;
    // getline(cin,strReverse);
    // for(int i=0;i<strReverse.length()/2;i++){
    //     int j=strReverse.length()-1-i;
    //     char temp=strReverse[i];
    //     strReverse[i]=strReverse[j];
    //     strReverse[j]=temp;
    // }
    // cout<<"Reversed string is "<<strReverse;

    //check if string is a palindrome
    string original;
    getline(cin,original);
    cout<<endl<<isPalindrome(original);
    
}