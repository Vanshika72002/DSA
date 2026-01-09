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
int LongestLength(vector<int> v,int N,int k){
    //BRUTE FORCE - Generating all subarrays and checking sum of each
    // int maxlen=0;
    // int sum;
    // for(int i=0;i<N;i++){
    //     sum=0;
    //     for(int j=i;j<N;j++){
    //         sum+=v[j];
    //         if(sum==k)
    //             if(j-i+1>maxlen)
    //                 maxlen=j-i+1;
    //         else if(sum>k)
    //             break;
    //     }

    // }
    // return maxlen;
    //BETTER - using map
    // unordered_map <int,int> mpp;
    // mpp[0]=-1;
    // int prefix_sum=0;
    // int maxlen=-1;
    // for(int i=0;i<N;i++){
    //     prefix_sum+=v[i];
    //     if(mpp.find(prefix_sum-k)!=mpp.end()){
    //         int index=mpp[prefix_sum-k];
    //         maxlen=max(maxlen,i-index);
    //     }
    //     if(mpp.find(prefix_sum)==mpp.end()){
    //         mpp[prefix_sum]=i;
    //     }
    // }
    // return maxlen;
    //OPTIMAL
        //move 
        // sum<k   
        //     move    
        //         sum<k 
        //             move 
        //                 sum>k   
        //                     trim from left
        int left=0;
        int right=0;
        int sum=0;
        int len;
        int maxlen=0;
        while(right<=N){
            cout<<"inside loop";
            while(left<=right&&sum>k){
                sum-=v[left];
                left++;
            }
            if(right<N){
                sum+=v[right];
            right++;}
            if(sum==k){
                len=right-left;
                maxlen=max(len,maxlen);
            }
        }   
}
int main(){
    vector<int> v;
    int n;
    input(v,n);
    int k;
    cin>>k;
    cout<<LongestLength(v,n,k);
}