#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
int appears_once(vector<int>& arr, int n){
        //BRUTE FORCE METHOD
        // for(int i=0;i<n;i++){
        //     int flag=0;
        //     for(int j=0;j<n;j++){
                
        //         if(i!=j && arr[i]==arr[j]){
        //             flag=1;
        //             break;
        //         }
        //     }
        //     if(flag==0){
        //         return arr[i];
        //     }

        // }
        // return 900190;

        //BETTER
        //Hashing using array
        // int largest=arr[0];
        
        // for(int i=1;i<n;i++){
        //     if(largest<arr[i]){
        //         largest=arr[i];
        //     }
        // }
        // vector<int> hasharray(largest+1,0);
        // for(int i=0;i<n;i++){
        //     hasharray[arr[i]]+=1;
        // }
        // for(int i=0;i<hasharray.size();i++){
        //     if(hasharray[i]==1){
        //         return i;
        //     }
        // }
        // BETTER #2
        // Hashing using map
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]+=1;
        }
        for(auto iter:mpp){
            if(iter.second==1){
                return iter.first;
            }
        }
        //OPTIMAL
        // int result=0;
        // for(int i=0;i<n;i++){
        //     result^=arr[i];
        // }
        // return result;
        return 4567;
        
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
    int result=appears_once(nums,n);
    cout<<"result="<<result;
}