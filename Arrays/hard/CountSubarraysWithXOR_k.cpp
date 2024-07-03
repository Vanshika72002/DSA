#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
int NumbOfSubarray(vector<int> v,int k){
    unordered_map<int,int> mpp;
    int prefix_XOR=0;
    int n=v.size();
    int count=0;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        prefix_XOR^=v[i];
        mpp[prefix_XOR]+=1;
        int target=prefix_XOR^k;
        if(mpp.find(target)!=mpp.end()){
            if(k==0)
                count+=mpp[target]-1;
            else    
                count+=mpp[target];
        }
    }
    return count;
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
    cin>>x;
    int len=NumbOfSubarray(nums,x);
    cout<<"\n"<<len;
    return 1;

}