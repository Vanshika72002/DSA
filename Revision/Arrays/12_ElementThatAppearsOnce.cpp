#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
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
int OnceInArray(vector<int> v,int N){
    //Approach 1
    // map<int,int> mpp;
    // for(int i=0;i<N;i++){
    //     mpp[v[i]]++;
    // }
    // for(auto iter: mpp){
    //     if(iter.second==1)
    //         return iter.first;
    // }
    // return -1;
    
    //Aproach2
    int Xor = 0;
    for(int i=0;i<N;i++){
        Xor ^= v[i];
    }
    return Xor;
}
int main(){
    vector<int> v;
    int n;
    input(v,n);
    cout<<OnceInArray(v,n);
}