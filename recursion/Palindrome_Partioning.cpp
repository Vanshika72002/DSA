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
        
        cout<<"Inside function";
        cout<<"ind="<<ind;
        if(ind==s.length()){
            len=0;
            if(vec.size()){
                for(auto iter:vec)
                    cout<<iter<<" ";
                ans.push_back(vec);
                cout<<"{";
                for(int i=0;i<ans.size();i++){
                    cout<<"{";
                    for(int j=0;j<ans[i].size();j++){
                            cout<<ans[i][j]<<",";
                    }
                    cout<<"};";
                }
                cout<<"}";
                vec.clear();
                
            }
        } 
        for(int i=ind;i<s.length();i++){
            string substring = s.substr(ind,i-ind+1);
            if(isPalindrome(substring)){
                vec.push_back(substring);
                len+=substring.length();
                cout<<"\nlen="<<len;
                PalindromePartition(s,len);

            }
            else{
                vec.clear();
                continue;
            }
        }
}
int main(){
    PalindromePartition("a      ba",0);
    // cout<<"{";
    //   for(int i=0;i<ans.size();i++){
    //     cout<<"{";
    //     for(int j=0;j<ans[i].size();j++){
    //             cout<<ans[i][j]<<",";
    //     }
    //     cout<<"}";
    // }
    // cout<<"}";
}