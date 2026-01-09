
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
void reverse(vector<int> &v,int start,int end){
    cout<<"reversing from "<<start<<" to "<<end;
    while(start<end){
        int el=v[start];
        v[start]=v[end];
        v[end]=el;
        start++;
        end--;
    }
    cout<<"Reversed Array is";
    output(v,v.size());
}
void rotatekTimes(vector<int> &v,int &n,int k){

    //Brute force
    // vector<int> temp;
    // for(int i=0;i<k;i++){
    //     temp.push_back(v[i]);
    // }
    // for(int i=k,j=0;i<n;i++,j++){
    //     v[j]=v[i];
    // }
    // for(int i=k,j=0;i<n;j++,i++){
    //     v[i]=temp[j];
    // }

    //BETTER-Reversal Algorithm
    reverse(v,n-k+1,n-1);
    reverse(v,0,n-k);
    reverse(v,0,n-1);

}
int main(){
    vector<int> v;
    vector<int> ans;
    int n;
    input(v,n);
    int k;
    cout<<"Rotate by how many places?:";
    cin>>k;
    rotatekTimes(v,n,k);
    output(v,n);
}
