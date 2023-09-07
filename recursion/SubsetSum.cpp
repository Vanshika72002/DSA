#include<iostream>
#include<vector>
using namespace std;
void SubsetSum(vector<int> vec,vector<int> &ans,int i,int N,int sum,vector<int> subset){
        if(i==N){
            ans.push_back(sum);
            return;
        }
        sum+=vec[i];
        subset.push_back(vec[i]);
        SubsetSum(vec,ans,i+1,N,sum,subset);
        sum-=vec[i];
        subset.pop_back();
        SubsetSum(vec,ans,i+1,N,sum,subset);
        

}
int main(){
    int N;
    int x;
    vector<int> vec;
    vector<int> v;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        vec.push_back(x);
    }
    
    vector<int> sub;
    vector<int> res;
    SubsetSum(vec,res,0,N,0,sub);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}