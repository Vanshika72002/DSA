#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>
using namespace std;
void maxsubarray(vector<int> arr,int n,int k){
        unordered_map<int,int> mpp;
        int len=0;
        int prefixsum=0;
        for(int i=0;i<n;i++){   
            prefixsum+=arr[i];
            mpp[prefixsum]=i;
            if(mpp[k]>=0&&mpp[k]<n){
                len=max(len,mpp[k]+1);
            }
            else if(mpp[prefixsum-k]){
                int index=mpp[prefixsum-k];
                len=max(len,i-(index));
            }

        }
        cout<<"len="<<len;
}
int main(){
    vector<int> nums;
    int n;
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter";
        cin>>x;
        nums.push_back(x);
    }
    cout<<"enter k ";
    cin>>x;
    maxsubarray(nums,n,x);
    // cout<<"result="<<result;
}