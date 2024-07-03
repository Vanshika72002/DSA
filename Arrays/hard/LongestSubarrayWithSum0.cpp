#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
int LongestSubarray(vector<int> v){
    int maxlen=0;
    int len=0;
    int n=v.size();
    //BRUTE FORCE
    // for(int i=0;i<n;i++){
    //     int sum=v[i];
    //     for(int j=i;j<n;j++){
    //         if(i!=j) sum+=v[j];
    //         if(sum==0){
    //             len=j-i+1;
    //             maxlen=max(maxlen,len);
    //         }
    //     }
    // }
    //OPTIMAL
    int sum=0;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        sum+=v[i];
        if(sum==0){
            maxlen=max(i+1,maxlen);
        }
        else{
            if(mpp.find(sum)!=mpp.end())
            {
                maxlen=max(i-mpp[sum],maxlen);
            }
            else
                mpp[sum]=i;
        }
    }
    return maxlen;
}
int main(){
    vector<int> nums;
    int n;
    int x;
    cin>>n;
    int ans[n];
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    int len=LongestSubarray(nums);
    cout<<"\n"<<len;
    return 1;

}