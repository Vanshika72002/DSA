#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    int n=s.length();
    getline(cin,s);
    int shiftfrom;
    int shiftBy=0;
    int consecSpaces=0;
    if(s[0]==' ')
        shiftBy=1;
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            consecSpaces+=1;
        }else{
            
            if(consecSpaces>1){
                ShiftBy(consecSpaces-1);
            }
        }
    }
    cout<<s<<"-";
}