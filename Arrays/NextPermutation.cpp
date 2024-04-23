#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    //Brute Force 
    //O(N!*N);
    //BETTER
    // next_permutation(nums.begin(),nums.end());
    //OPTIMAL
       int ind=-1;
       int n=nums.size();
       for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            ind=i;
            break;
        }
       }
       if(ind==-1){
        reverse(nums.begin(),nums.end());
        return ;
       } 
       for(int i=n-1;i>ind;i--){
        if(nums[i]>nums[ind]){
            swap(nums[i],nums[ind]);
            break;
        }
       }
       reverse(nums.begin()+ind+1,nums.end());
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
    nextPermutation(nums);
    cout<<"next permutation is:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}