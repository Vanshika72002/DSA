#include<vector>
#include<iostream>
using namespace std;
int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int cnt=0;
        while(nums.size()>0&&x!=0){
            if(nums[0]<=x&&nums[n-1]<=x){
                if(nums[0]<=nums[n-1]){
                    x-=nums[n-1];
                    cnt+=1;
                    if(x==0)
                        return cnt;
                    nums.pop_back();
                    n--;
                    cout<<nums.size();
                }
                else if(nums[0]>=nums[n-1]){
                    x-=nums[0];
                    cnt+=1;
                    if(x==0)
                        return cnt;
                    nums.erase(nums.begin());
                    n--;
                    cout<<nums.size();
                }
            }
            else if(nums[0]<=x){
                x-=nums[0];
                cnt+=1;
                if(x==0)
                    return cnt;
                nums.erase(nums.begin());
                n--;
                cout<<nums.size();
            }
            else if(nums[n-1]<=x){
                x-=nums[n-1];
                cnt+=1;
                if(x==0)
                    return cnt;
                nums.pop_back();
                n--;
                cout<<nums.size();
            }
            else{
                if(x!=0)
                    return -1;
            }
        }
        return -1;

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
    cin>>x;
    int ans=minOperations(nums,x);
    cout<<"minOperations(nums,x)"<<ans;
}