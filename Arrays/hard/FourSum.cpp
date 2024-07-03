// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[i], arr[j], arr[k]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
set<vector<int>>  sum4(vector<int> v,int target){
   
    set<vector<int>> quadruplets;
    int n=v.size();
    //Brute Force
    // for(int i=0;i<n-3;i++){
    //     for(int j=i+1;j<n-2;j++){
    //         for(int k=j+1;k<n-1;k++){
    //             for(int l=k+1;l<n;l++){
    //                 int sum=v[i]+v[j]+v[k]+v[l];
    //                 if(sum==target){
    //                     vector<int> onelist={v[i],v[j],v[k],v[l]};
    //                     sort(onelist.begin(),onelist.end());
    //                     quadruplets.insert(onelist);
    //                 }
    //             }
    //         }
    //     }
    // }   

    //-----------BETTER------------
    // set<int> st;
    // for(int i=0;i<n-3;i++){
    //     for(int j=i+1;j<n-2;j++){
    //         st.clear();
    //         for(int k=j+1;k<n;k++){
    //             long long sum=v[i]+v[j]+v[k];
    //             int fourthElement=target-sum;
    //             if(st.find(fourthElement)!=st.end()){
    //                 vector<int> quadruplet={v[i],v[j],v[k],fourthElement};
    //                 sort(quadruplet.begin(),quadruplet.end());
    //                 quadruplets.insert(quadruplet);
    //             }
    //             st.insert(v[k]);


    //         }
            
    //     }
    // }
    // return quadruplets;
    //----------OPTIMAL---------------
    sort(v.begin(),v.end());

    for(int i=0;i<n-3;i++){
        int j=i+1;
        while(j<n-2){
            cout<<"in outer loop";
            int k=j+1;
            int l=n-1;
            while(k<l){
                cout<<"in loop\n";
                int sum=v[i]+v[j]+v[k]+v[l];
                if(sum>target){
                    l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    vector<int> quadruplet={v[i],v[j],v[k],v[l]};
                    quadruplets.insert(quadruplet);
                    k++;
                    l--;
                    while(k<l && v[k]==v[k-1]) k++;
                    while(k<l && v[l]==v[l+1]) l--;

                }
            }
            j++;
        }
    }
    // vector<vector<int>> result(quadruplets.begin(),quadruplets.end());
    return quadruplets;
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
    cin>>x;
    set<vector<int>> resultvec=sum4(nums,x);
    for(auto iter:resultvec){
        cout<<iter[0]<<" "<<iter[1]<<" "<<iter[2]<<" "<<iter[3];
        cout<<endl;    
    }
    return 1;

}