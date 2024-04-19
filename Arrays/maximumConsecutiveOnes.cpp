#include<iostream>
using namespace std;
#include<vector>
int maximumones(vector<int> &nums){
    int count=0;
    int maxcount=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count++;
            if(maxcount<count){
                maxcount=count;
            }
        }
        else if(nums[i]==0){
            count=0;
        }
    }
    return maxcount;
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
    int ans=maximumones(nums);
    cout<<"ans="<<ans;
}