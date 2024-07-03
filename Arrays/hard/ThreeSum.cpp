// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[i], arr[j], arr[k]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
set<vector<int>>  sum3(vector<int> v){
   
    set<vector<int>> stt;
    vector<int> triplet;
    int n=v.size();
     //Brute Force
    // for(int i=0;i<n;i++){
    //     if(n-i<3)
    //         break;
         
    //     for(int j=i+1;j<n;j++){
            
    //         for(int k=j+1;k<n;k++){
    //             int sum=0;
    //             if(i!=k  && j!=k && i!=j){
    //             sum=v[i]+v[j]+v[k];
    //             if(sum==0){
    //                 triplet.clear();
    //                 triplet.push_back(v[i]);
    //                 triplet.push_back(v[j]);
    //                 triplet.push_back(v[k]);
    //                 sort(triplet.begin(),triplet.end());
    //                 stt.insert(triplet);
    //             }}

    //         }
    //     }
    // }
    //BETTER
    // int i=0;
    // int j;
    // int sum;
    // set<int> st;
    // while(i<n-2){
    //     j=i+1;
    //     while(j<n){
    //         sum=v[i]+v[j];
    //         int third=-(sum);
    //         if(st.find(third)!=st.end()){
    //             triplet.clear();
    //             triplet.push_back(v[i]);
    //             triplet.push_back(v[j]);
    //             triplet.push_back(third);
    //             sort(triplet.begin(),triplet.end());
    //             stt.insert(triplet);
    //         }
    //         st.insert(v[j]);
    //         j++;
    //     }
    //     i++;
    //     st.clear();
    // }
    
    sort(v.begin(),v.end());
    for(int i=0;i<n-2;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
        int sum=v[i]+v[j]+v[k];
        if(sum<0){
            j++;
        }
        else if(sum>0){
            k--;
        }
        else{
            triplet={v[i],v[j],v[k]};
            sort(triplet.begin(),triplet.end());
            stt.insert(triplet);
            j++;
        }}
    }
    
    
    return stt;
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
    set<vector<int>> resultvec=sum3(nums);
    for(auto iter:resultvec){
        cout<<iter[0]<<" "<<iter[1]<<" "<<iter[2];
        cout<<endl;    
    }
    return 1;

}