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
int upperbound(vector<int> nums,int target){
    int low=0;
    int Size=nums.size();
    int high=Size-1;
    int index;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>target){
            index=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return index;
}
vector<int> firstAndLastOccurence(vector<int> v,int target){
    int n=v.size();
    //BruteForce
    //O(N)
    // int first=-1;
    // int last=-1;
    // for(int i=0;i<n;i++){
    //     if(v[i]==target){
    //         if(first==-1){
    //             first=i;
    //         }
    //         last=i;
    //     }
    // }
    // vector<int> result{first,last};
    // return result;
    //optimal
    //O(2*logN)
    // int lb=lowerbound(v,target);
    // int ub=upperbound(v,target);
    // if(lb==n || v[lb]!=target){
    //     vector<int> v{-1,-1};
    //     return v;
    // }
    // else if(v[ub-1]==target){
    //     vector<int> v{lb,ub-1};
    //     return v;
    // }
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
    vector<int> indexes=firstAndLastOccurence(nums,target);
    cout<<indexes[0]<<" "<<indexes[1];
}
