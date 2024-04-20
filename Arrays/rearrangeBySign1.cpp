#include<iostream>
#include<vector>
using namespace std;
void RearrangeBySign(vector<int> &arr,int n,int *ans){
    vector<int> positives;
    vector<int> negatives;
    int j=0;
    int k=0;
    int i=0;
    //BRUTE FORCE
    // while(i<n){  
    //     if(arr[i]>=0){
    //         positives.push_back(arr[i]);
    //         j++;
    //     }       
    //     else{
    //         negatives.push_back(arr[i]);
    //         k++;
    //     } 
    //     i++;
    // }
    // for(int i=0,pos=0;i<n/2;i++,pos++){
    //     arr[pos]=positives[i];
    //     pos++;
    //     arr[pos]=negatives[i];
    // }
    //OPTIMAL
    int pos=0;      //positive elements will be at even positions in the ans array
    int neg=1;     //negative elements will be at odd positions in the ans array
    while(i<n){
        if(arr[i]>=0){
            ans[pos]=arr[i];
            pos+=2;
        }
        else{
            ans[neg]=arr[i];
            neg+=2;
        }
        i++;
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
        cout<<ans[i]<<" ";
    }
    return 1;

}