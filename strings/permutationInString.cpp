#include<iostream>
using namespace std;
#include<string>
bool isEqual(int arr1[],int arr2[]){
        // int n=sizeof(arr1);
        // cout<<endl<<n<<endl;
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string permutStr, string s) {
     
        int reqdFreq[26]={0};
        int n=permutStr.length();
        int N=s.length();
        int ind;
        int windInd;
        for(int i=0;i<n;i++){
            reqdFreq[permutStr[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            cout<<(char)('a'+i)<<" : "<<reqdFreq[i]<<" , ";
        }
        for(int i=0;i<=N-n;i++){
            cout<<"iteration "<<i+1<<" ";
            windInd=i;
            int windFreq[26]={0};
            ind=0;
            while(ind<n){
                windFreq[s[windInd]-'a']++;
                windInd++;
                ind++;
            }
            if(isEqual(reqdFreq,windFreq)){
                return true;
            }
        }
        return false;
    }
int main(){
    cout<<checkInclusion("hello","ooolleoooleh");
}