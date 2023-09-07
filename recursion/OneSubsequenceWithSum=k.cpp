#include<iostream>
#include <string>
#include<vector>
using namespace std;
vector<vector<int>> ans;
bool Subsequence(vector<int> v,int i,int N,int target,vector<int> seq,int sum){
    if(i==N){
            if(sum==target){
            for(auto iter:seq) cout<<iter<<" ";
            cout<<endl;
            return true;   
        }
        return false;
    }
    seq.push_back(v[i]);
    sum+=v[i];
    if(Subsequence(v,i+1,N,target,seq,sum)==true) return true;
    seq.pop_back();
    sum-=v[i];
    if(Subsequence(v,i+1,N,target,seq,sum)==true) return true;
    return false;
}
int main (){
    int x;
    vector<int> Empty;
    vector<int> vec;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        vec.push_back(x);
    }
    int k;
    cin>>k;
    Subsequence(vec,0,vec.size(),k,Empty,0);
}
