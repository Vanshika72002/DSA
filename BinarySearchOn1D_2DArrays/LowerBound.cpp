#include<iostream>
#include<vector>
using namespace std;
int lowerbound(vector<int> nums,int target){
    int low=0;
    int Size=nums.size();
    int high=Size-1;
    int index;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=target){
            index=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return index;
}
int main(){
    int n;
    vector<int> nums;
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    int target;
    cin>>target;
    int index=lowerbound(nums,target);
    cout<<index;
}
