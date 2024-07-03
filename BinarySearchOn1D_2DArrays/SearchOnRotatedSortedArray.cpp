#include<iostream>
#include<vector>
using namespace std;

int search(vector<int> v,int target){
    int n=v.size();
    int mid;
    int low=0;
    int high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        //eliminate one of the halves using binary search
        //check if left part is sorted
        if(v[mid]==target)
            return mid;
        if(v[mid]>=v[low]){
            if(v[low]<=target&&v[mid]>=target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else if(v[high]>=v[mid]){
            if(v[mid]<=target&&v[high]>=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
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
    int target;
    cin>>target;
    int index=search(nums,target);
    cout<<"index="<<index;
}   