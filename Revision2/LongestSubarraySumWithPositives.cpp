#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int LongestSubarray_BF(vector<int> v,int k){
    int sum=0;
    int maxlen=0;
    int len=0;
    int N=v.size();
    for(int i=0;i<N;i++){
        sum=0;
        for(int j=i;j<N;j++){
            sum+=v[j];
            if(sum==k){
                cout<<"sum=="<<k<<"for i= "<<i<<"and j= "<<j;
                len=j-i+1;
                maxlen=max(maxlen,len);
            }
        }
    }
    return maxlen;
}
int LongestSubarray_better(vector<int> v,int k){
    int N=v.size();
    unordered_map<int,int> mpp;
    int sum=0;
    int maxlen=0;
    int len=0;
    for(int i=0;i<N;i++){
        sum+=v[i];
        if(sum==k){
            len=i+1;
            maxlen=i+1;
        }
        if(mpp.find(sum)==mpp.end()){       //sum doesnt exist in map
            mpp[sum]=i;
            if(sum>k){
                if(mpp.find(sum-k)!=mpp.end()){
                    len=i-mpp[sum-k];
                    maxlen=max(maxlen,len);
                }
            }        
        }else{                              //sum exists in map
            if(sum>k){
                if(mpp.find(sum-k)!=mpp.end()){
                    len=i-mpp[sum-k];
                    maxlen=max(maxlen,len);
                }
            }
        }       

    }
    return maxlen;
}
int LongestSubarray_optimal(vector<int> v,int k){
    int i=0;int j=0;int sum=0;
    int N=v.size();
    int len=0;int maxlen=0;
    while(i<N){
        if(sum==k){
            len=j-i;
            maxlen=max(maxlen,len);
        }
        if(j<N){
            sum+=v[j];
            j++;
        }else{
            sum-=v[i];
            i++;
        }
        while(sum>k && i<=j){
            sum-=v[i];
            i++;
        }
    }
    return maxlen;
}
int main(){
    vector<int> v;
    int N;
    cin>>N;
    int k;
    for(int i=0;i<N;i++){
        cin>>k;
        v.push_back(k);
    }
    cin>>k;
    // int ans=LongestSubarray_BF(v,k);
    // int ans=LongestSubarray_better(v,k);
    int ans=LongestSubarray_optimal(v,k);
    
    cout<<"longest subarray is of length "<<ans;

}