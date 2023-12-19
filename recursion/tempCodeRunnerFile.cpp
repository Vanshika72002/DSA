#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<string>> ans;
vector<string> vec;
int len=0;
bool isPalindrome(string str){
    int N=str.length();
    for(int i=0,j=N-1;i<N/2,j>=N/2;i++,j--){
        if(str[i]!=str[j]){
            return false;
        }
    }
    return true;
}
void PalindromePartition(string s,int ind){