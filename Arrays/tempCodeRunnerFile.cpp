int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int cnt=0;
        while(nums.size()>0||x!=0){
            cout<<"inside looooooooooooop";
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