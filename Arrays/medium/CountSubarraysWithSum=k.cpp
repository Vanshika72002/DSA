#include<iostream>
#include<vector>
using namespace std;
int countsubarray(vector<int> arr,int n,int k){
        int count =0;    
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum=arr[i];
            if(sum==k){
                count++;
            }
            for(int j=i+1;j<n;j++){
                sum=sum+arr[j];
                if(sum==k){
                    count++;
                }     
            }
        }
        return count;
        // unordered_map<int,int> mpp;
        // int prefixsum=0;
        // int remainingsum=prefixsum-k;
        // mpp[0]=1;
        // for(int i=0;i<n;i++){
        //     prefixsum+=arr[i];
        //     remainingsum=prefixsum-k;
        //     if(mpp.find(remainingsum)!=mpp.end()){
        //         count+=mpp[remainingsum];
        //     }
        //     mpp[prefixsum]+=1;
        // }
        // return count;
}
int main(){
    vector<int> nums;
    
    int n;
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    cin>>x;
    x=countsubarray(nums,n,x);
    cout<<"count="<<x;
    return 1;

}