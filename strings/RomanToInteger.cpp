#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int romanToInt(string s) {
        unordered_map<char,int> mpp={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int len=s.length();
        int i=len-2;
        int ans=0;
        ans+=mpp[s[len-1]];
        while(i>=0){
            while(i>=0&&mpp[s[i+1]]<=mpp[s[i]]){
                cout<<"condition 1"<<endl;
                cout<<mpp[s[i+1]]<<"<="<<s[i]<<endl;
                ans+=mpp[s[i]];
                i--;
            }
            if(i>=0 && (mpp[s[i]]<mpp[s[i+1]])){
                cout<<"condition 2";
                cout<<mpp[s[i+1]]<<"<="<<s[i]<<endl;
                ans-=mpp[s[i]];
                i--;
            }
        }   
        return ans;    
   }
int main(){
    string s;
    cin>>s;
    cout<<romanToInt(s);
}