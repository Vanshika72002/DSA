#include<iostream>
#include<vector>
using namespace std;
void leaders(vector<int> arr,int n){
    vector<int> ans;
    // BRUTE FORCE;
    // for(int i=0;i<n-1;i++){
    //     bool leader=true;
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i]<arr[j]){
    //             leader=false;     //element on right is greater
    //             break;
    //         }
    //     }
    //     if(leader){
    //         ans.push_back(arr[i]);
    //     }    
    // }
    // ans.push_back(arr[n-1]);
    // for(int i=0;i<ans.size();i++){
    //         cout<<ans[i]<<" ";
        // }
    //OPTIMAL
    int max=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>max){
            ans.push_back(arr[i]);
            max=arr[i];
        }
    }
    for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
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
    leaders(nums,n);
    
    return 1;

}