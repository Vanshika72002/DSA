#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void maxsubarray(vector<int> arr,int n,int k){

    int prefixsum=0;
    unordered_map<int,int> mpp;
    int left;
    int right;
    mpp[0]=-1;
    int maxlen=0;
    int len=0;
    for(int i=0;i<n;i++){
        prefixsum+=arr[i];
        if(mpp.find(prefixsum)==mpp.end()){
            mpp[prefixsum]=i;
            
        }
        if(mpp.find(prefixsum-k)!=mpp.end()){
            
            len=i-mpp[prefixsum-k];
            if(len>maxlen){
                left=mpp[prefixsum-k];
                right=i;     
                maxlen=len;          
            }
            
        }
    }
    cout<<endl<<maxlen;
    cout<<"left="<<left+1<<"right="<<right;
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
    cout<<"enter k ";
    cin>>x;
    maxsubarray(nums,n,x);
}