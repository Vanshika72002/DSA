#include<iostream>
#include<cstring>
#include<string>
#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int res=str.find("abc");
    str.erase(res,3);
    cout<<res;
    cout<<str;
}