#include<iostream>
#include<vector>
using namespace std;
int Consecutive(vector<int> &arr,int n){
    //BRUTE FORCE
    int max_count=0;
    int count=0;
    sort(arr,arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            if(arr[i+1]==arr[i]+1){
                count+=1;
                max_count=max(max_count,count);
                i++;
            }
            else{
                count=0;
                i++;
            }
        }
    
    return max_count;
    
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
    int longest=Consecutive(nums,n);
    cout<<"longest consecutive sequence is of length "<<longest;
    return 1;

}