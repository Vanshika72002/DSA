#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void maxsubarray(vector<int> arr,int n,int k){
        int maxcount=0;
        int index=0;
        for(int i=0;i<n;i++){
            int sum=0;
            int count=1;
            // if(sum==k){
            //     if(maxcount<count){
            //         maxcount=count;
            //         index=i;
            //     }
            //     continue;
            // }
            // else if(sum>k){
            //     continue;
            // }         
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum>k){
                    break;
                }
                else if(sum==k){
                    count++;
                    if(maxcount<count){
                        index=i;
                        maxcount=count;
                    }
                }
                else{
                    count++;
                }
            }
        }
        cout<<"maximum subarray begins from "<<index<<"and ends at "<<maxcount+index-2<<"\n";
}
int main(){
    vector<int> nums;
    int n;
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter";
        cin>>x;
        nums.push_back(x);
    }
    cout<<"enter k ";
    cin>>x;
    maxsubarray(nums,n,x);
    // cout<<"result="<<result;
}