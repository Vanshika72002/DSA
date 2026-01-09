#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string Reverse(string s){
        reverse(s.begin(),s.end());
        return s;
    }
    string reverseWords(string s) {
        int n=s.length();
        cout<<"length of string= "<<n<<endl;
        string ans="";
        reverse(s.begin(),s.end());
        bool secondPtrActive=false;
        int secondPtr;
        int wordPtr1;
        for(int i=0;i<n;i++){
            if(s[i]!=' ' && !secondPtrActive){
                wordPtr1=i;
                secondPtrActive=true;
                secondPtr=i;
            }else if(s[i]!=' ' && secondPtrActive){
                secondPtr++;
            }
            if((s[i]==' ' || i==n-1)&& secondPtrActive){
                string substr=Reverse(s.substr(wordPtr1,secondPtr+1-wordPtr1));
                if(ans.length()>0){
                    cout<<"\n\nans= "<<ans;
                    ans+=' ';
                }ans+=substr;
                secondPtrActive=false;
            }
        }
        return ans;
    }
int main(){
    string s;
    getline(cin,s);
    string ans=reverseWords(s);
    cout<<"FINAL ANSWER: "<<ans<<"<-string ends";
}