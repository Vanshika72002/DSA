#include<iostream>
#include<vector>
using namespace std;
int PeakElement(vector<int> nums){
    int n=nums.size();
   

    if(n==1 || nums[0]>nums[1]){
        return nums[0];
    }
    else if(nums[n-1]>nums[n-2])   
        return nums[n-1];
    int low=1,high=n-2,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
            return nums[mid];
        else if(nums[mid]>nums[mid-1])
            low=mid+1;
        else    
            high=mid-1;
    }
    return -1;

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
    int el=PeakElement(nums);
    cout<<el;
}
