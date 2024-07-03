#include<iostream>
using namespace std;
#include<vector>
int missingNumber(vector<int>& nums) {
    int lengthofarray=nums.size();
    cout<<"length="<<lengthofarray;
    vector<int> hasharray(lengthofarray+1, 0); 
    for(int i=0;i<lengthofarray;i++){
        hasharray[nums[i]]=1;

    }
    for(int i=0;i<=lengthofarray;i++){
        cout<<i<<"="<<hasharray[i]<<" ";
        if(hasharray[i]==0){
            return i;
        }
    }
    return 19999;
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
    int ans=missingNumber(nums);
    cout<<"ans="<<ans;
    
}

