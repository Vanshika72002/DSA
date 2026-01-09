
// #include "Input_Output.h"
#include<iostream>
#include<vector>
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
void output(vector<int> v,int n){
    cout<<"Array is:";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void rotate(vector<int> &v,int &n,vector<int> &ans){
    int firstEl=v[0];
    for(int i=0;i<n-1;i++){
        v[i]=v[i+1];
    }
    v[n-1]=firstEl;

    // vector<int> new;
    // output(v,n);
    // for(int i=1;i<n;i++){
    //     ans[i-1]=v[i];
    // }
    // ans.push_back(firstEl);
    // cout<<"Rotated arra is";
    // output(ans,n);
}

int main(){
    vector<int> v;
    vector<int> ans;
    int n;
    input(v,n);
    int k;
   
    rotate(v,n,ans);
    output(v,n);
}
