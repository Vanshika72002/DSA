#include<iostream>
#include<string>
using namespace std;
int main(){
        int len=s.length();
        int startFrom=0;
        int endAt;
        string words[10];
        
        for(int i=0;i<len;i++){
            if(isdigit(s[i])){
                endAt=i-1;
                words[s[i]-'0'-1]=s.substr(startFrom,endAt-startFrom+1);
                startFrom=i+2;
            }
        }
        string finalString=words[0];
        int i=1;
        while(words[i]!="\0"){
            finalString+=(" "+words[i]);
            i++;
        }
        return finalString;
}