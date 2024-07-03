#include<iostream>
#include<vector>
using namespace std;
int mini(vector<int> v){
    int low=0;
    int n=v.size();
    int high=n-1;
    int m=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(v[low]<=v[mid]&&v[mid]<=v[high]){
            m=min(m,v[low]);
            break;
        }
        else if(v[low]<=v[mid]){
            m=min(v[low],m);
            low=mid+1;
        }
        else if(v[mid]<=v[high]){
            m=min(v[mid],m);
            high=mid-1;
        }
    }
    return m;
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
    int m=mini(nums);
    cout<<"minimum="<<m;
}