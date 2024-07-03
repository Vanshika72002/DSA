#include<iostream>
#include<vector>
using namespace std;
void RearrangeBySign(vector<int> &arr,int n,int *ans){
    //BRUTE FORCE
    int i=0;
    int j=0;
    int k=0;
    vector<int> positives;
    vector<int> negatives;
    while(i<n){  
        if(arr[i]>=0){
            positives.push_back(arr[i]);
            j++;
        }       
        else{
            negatives.push_back(arr[i]);
            k++;
        } 
        i++;
    }
    j=0;
    k=0;
    i=0;
    while(j<positives.size()&&k<negatives.size()){
        arr[i]=positives[j];
        i++;
        j++;
        arr[i]=negatives[k];
        i++;
        k++;
    }
    if(j<positives.size()){
        while(j<positives.size()){
            arr[i]=positives[j];
            i++;
            j++;
        }
    }
    else if(k<positives.size()){
        while(k<negatives.size()){
            arr[i]=negatives[k];
            i++;
            k++;
        }
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
    RearrangeBySign(nums,n,ans);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 1;

}