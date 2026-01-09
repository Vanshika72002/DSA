#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string addStrings(string num1, string num2) {
        int len1=num1.length();
        int len2=num2.length();
        if(len2<len1){
            string temp=num1;
            num1=num2;
            num2=temp;
            int temp1=len1;
            len1=len2;
            len2=temp1;
        }

        int carry=0;
        string ans="";
        int sum=0;
        for(int i=len1-1,j=len2-1;j>=0;i--,j--){
            sum=(num1[i]-'0')+(num2[j]-'0')+carry;
            carry=sum/10;
            char digit=(sum%10)+'0';
            ans+=digit;
             
        }
        int leftDigits=len2-len1;
        for(int i=leftDigits-1;i>=0;i--){
            sum=(num2[i]-'0')+carry;
            carry=sum/10;
            char digit=(sum%10)+'0';
            ans+=digit;
        }
        if(carry==1)
            ans+=(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
}
int main(){
    string num1;
    string num2;
    cin>>num1>>num2;
    cout<<addStrings(num1,num2);
}