/*

    Each Element to be used only once✅
    No duplicate combination


    
*/


#include<iostream>
#include<vector>
using namespace std;
void CombinationSum(vector<int> v,int target,int ind,int sum,int N,vector<int> seq){
    if(sum==target){
        for(int i=0;i<seq.size();i++){
            cout<<seq[i]<<" ";
        }
        cout<<endl;
        return;
    }
    // ||target-sum<v[ind]
    if(ind==N||target-sum<v[ind]){
        return;
    }
    //pick
    sum+=v[ind];
    seq.push_back(v[ind]);
    CombinationSum(v,target,ind+1,sum,N,seq);
    
    //Not pick
    sum-=v[ind];
    seq.pop_back();
    CombinationSum(v,target,ind+1,sum,N,seq);
}
int main(){
    int N;
    int x;
    int k;
    vector<int> vec;
    vector<int> v;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        vec.push_back(x);
    }
    cin>>k;
    CombinationSum(vec,k,0,0,N,v);

}