//OPTIMAL SOLUTION
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void maxsubarray(vector<int> arr,int n,int k){
        int maxlen=0;
        int sum=arr[0];
        int len=0;
        int i=0;
        int j=0;
       while(j<n){
            while(i<=j&&sum>k){
                sum-=arr[i];
                i++;
            }
            if(sum==k){ 
                // cout<<"len="<<j<<"-"<<i<<"+1\n";
                len=j-i+1;
                maxlen=max(maxlen,len);
            }
            
            j++;
            sum+=arr[j];
        }
        cout<<"length="<<maxlen;
            // if(sum==k){
            //     if(count>maxcount){
            //         maxcount=count;
            //     }
            // }
            // else if(sum>k){
            //     count--;
            //     sum-=arr[i];
            //     i++;
            // }
            // sum+=arr[j];
            // count++;
            // j++;
        
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