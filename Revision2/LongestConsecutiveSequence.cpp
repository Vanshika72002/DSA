#include<iostream>
#include<vector>
#include<algorithm>
0 3 7 2 5 8 4 6 0 1
using namespace std;
int LongestConsecutiveSequence(vector<int> vec){
    int N=vec.size();
    if(!N)
        return N;
    int len=1;
    int maxLen=1;
    for(int i=0;i<N;i++){
        int el=vec[i];
        len=1;
        for(int j=0;j<N;j++){
            if(vec[j]==el+1){
                j=-1;
                len++;
                maxLen=max(maxLen,len);
                el++;
            }
        }
    }
    return maxLen;
}
int main(){
    int N;
    vector<int> vec;
    cin>>N;
    int x;
    for(int i=0;i<N;i++){
        cin>>x;
        vec.push_back(x);
    }
    int len=LongestConsecutiveSequence(vec);
    cout<<"Longest consecutive sequence is of length "<<len;
}
