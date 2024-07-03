#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
bool LinearSearch(vector<int> vec,int element){
    int flag=0;
    for(int i=0;i<vec.size();i++){
        if(element==vec[i]){
            flag=1;
            break;
        }
    }
    if(flag==1)
        return true;
    return false;
}
int Consecutive(vector<int> &arr,int n){
    //BRUTE FORCE
    // int max_count=1;
    // int count;
    // for(int i=0;i<n;i++){
    //     int last_smallest=arr[i];
    //     count=1;
    //     for(int j=0;j<n;j++){
    //         if(arr[j]==last_smallest+1){
    //             last_smallest=arr[j];
    //             j=-1;       
    //             count++;
    //             max_count=max(max_count,count);
    //             cout<<"count="<<count<<endl;
    //             cout<<"max count="<<max_count<<endl;
    //         }
    //     }
    // }
    // return max_count;
    //BETTER
    // int max_count=0;
    // int count=0;
    // 👉⚠ sort(arr.begin(),arr.end());
    //     for(int i=0;i<n-1;i++){
    //         if(arr[i+1]==arr[i]+1){
    //             count+=1;
    //             max_count=max(max_count,count);
    //             i++;
    //         }
    //         else{
    //             count=0;
    //             i++;
    //         }
    //     }
    // return max_count;
    //OPTIMAL👇❌
    // unordered_set<int> set;
    // for(int i=0;i<n;i++){
    //     set.insert(arr[i]);
    // }
    // int target;
    // for(auto iter:set){
    //     if(set.find(iter-1)==set.end()){
    //         if(set.find(iter+1)!=set.end()){
    //             target=iter+1;

    //         }
    //     }
    // }

    //Brute Force Striver's way to write the code:
    int maxcount=1;
    for(int i=0;i<n;i++){
        int count=1;
        int x=arr[i];
        while(LinearSearch(arr,x+1)){
            count++;
            maxcount=max(maxcount,count);        
            x=x+1;  

        }
    } 
    return maxcount;   
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