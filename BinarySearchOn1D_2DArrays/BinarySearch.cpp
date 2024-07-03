#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
        int Size=nums.size();
        //our search space is from low to high
        int low=0,high=Size-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target>nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;   
}
int RecursiveSearch(vector<int> v,int low,int high,int target){
    if(low>high)
    {
        return -1;
    }
    int mid=(low+high)/2;
    if(v[mid]==target){
        return mid;
    }
    else if(v[mid]<target){
        low=mid+1;
        return RecursiveSearch(v,low,high,target);
    }
    else{
        high=mid-1;
        return RecursiveSearch(v,low,high,target);
    }
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
    int index=search(nums,target);
    cout<<index;
    index=RecursiveSearch(nums,0,n-1,target);
    cout<<"recursive index="<<index;
}