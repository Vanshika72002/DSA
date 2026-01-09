#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
void input(vector<int> &v,int &n){
    cout<<"Number of elements:";
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
}
vector<int> TwoSum(vector<int> v,int N,int k){
    //BRUTE FORCE
    // for(int i=0;i<N-1;i++){
    //     for(int j=0;j<N;j++){
    //         if(i!=j && v[i]+v[j]==k)
    //             return {i,j};
    //     }
    // }
    // return {-1,-1};

    //BETTER
    // for(int i=0;i<N-1;i++){
    //     for(int j=i+1;j<N;j++){
    //         if(v[i]+v[j]==k)
    //             return {i,j};
    //     }
    // }
    // return {-1,-1};

    //Approach 3 - map
    // unordered_map<int,int> mpp;
    // for(int i=0;i<N;i++){
    //     if(mpp.find(k-v[i])!=mpp.end())
    //         return {i,mpp[k-v[i]]};
    //     if(mpp.find(v[i])==mpp.end())
    //         mpp[v[i]]=i;
    // }
    // return {-1,-1};
    //Optimal 
    sort(v.begin(),v.end());
    int left=0;
    int right=N-1;
    while(left<right){
        if(v[left]+v[right]==k)
            return {left,right};
        else if(v[left]+v[right]>k)
            right--;
        else    
            left++;
    }
    cout<<"the index is according to sorted array";
    return {-1,-1};
}
int main(){
    vector<int> v;
    int n;
    input(v,n);
    int k;
    cin>>k;
    cout<<"{"<<TwoSum(v,n,k)[0]<<",";
    cout<<TwoSum(v,n,k)[1]<<"}";
}