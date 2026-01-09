#include<iostream>
#include<string>
#include<vector>
using namespace std;

int findSubString(string& str) {
    // code here
    int len=str.length();
    vector<int> windowcount(113,0);    //S(1)
    vector<bool> distinctCount(26,0);   //S(1)
    int distCount=0;
    int l=0,r=0;    //the extremes of window
    int windowDistCount=0;      //number of distict elements in current window from l to r
    int minlen=len;
    for(int i=0;i<len;i++){         //O(len)
            // count[str[i]-'a']++;
            if(!distinctCount[str[i]-'a']){
                distinctCount[str[i]-'a']=1;
                distCount++;
            }
    }
    cout<<"number of distinct letters:"<<distCount;
    while(r<len || distCount==windowDistCount){
        // for(int i=97;i<113;i++){
        //     cout<<"count:"<<windowcount[i]<<endl;
    // }
    cout<<"\nlooooop\n";
        if(distCount==windowDistCount){
            cout<<"r="<<r<<"l="<<l<<endl;
            minlen=min(minlen,r-l);
            windowcount[str[l]]--;
            if(windowcount[str[l]]==0)
                windowDistCount--;
            l++;
            
        }
        else{
            if(windowcount[str[r]]==0){      //a different element found
                windowDistCount++;
            }
            windowcount[str[r]]++;
            r++;
        } 
        
    }
    return minlen;     
}
int main(){
    string str="geeksforgeeks";
    cout<<findSubString(str);
}