#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
int MajorityElement(vector<int> vec){
    int N=vec.size();
    // int count;
    // for(int i=0;i<=N/2;i++){
    //     count=1;
    //     for(int j=i+1;j<N;j++){
    //         if(vec[i]==vec[j]){
    //             count+=1;
    //             if(count>N/2)
    //                 return vec[i];
    //         }
    //     }
    //     //Didnt write below condition before submitting code on leetcode
    //     if(count>N/2)
    //         return vec[i];
    // }
    // return -1;
    //better
    // unordered_map<int,int> mpp;
    // cout<<mpp[2];
    // for(int i=0;i<N;i++){
    //     mpp[vec[i]]+=1;
    // }
    // for(auto iter:mpp){
    //     if(iter.second>N/2)
    //         return iter.first;
    // }
    //  return -1;
    //OPTIMAL
    int el=vec[0];
    int count=1;
    for(int i=0;i<N;i++){
        if(el==vec[i])
            count++;
        else
            count--;
        if(count==0){
            count=1;
            el=vec[i];
        }
    }
    //verify if the el is the majority element if question states that the array may or may not contain majority element
    // count=0;
    // for(int i=0;i<N;i++){
    //     if(vec[i]==el)
    //         count++;
    //     if(count>N/2){
    //         return vec[i];
    //     }
    // }

    return el;
}
int main(){
    vector<int> vec;
    int N;
    cin>>N;
    int x;
    for(int i=0;i<N;i++){
        cin>>x;
        vec.push_back(x);
    }
    int result=MajorityElement(vec);
    cout<<result;
}