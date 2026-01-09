
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
void zeroesAtEnd(vector<int> &v,int n){
    //BRUTE FORCE
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(v[i]!=0){
            temp.push_back(v[i]);
        }
    }
    int nonzeroes=temp.size();
    for(int i=0;i<nonzeroes;i++){
        v[i]=temp[i];
    }
    int zeroes=n-nonzeroes;
    for(int i=nonzeroes;i<n;i++){
        v[i]=0;
    }
    //BETTER
    // int j=0;
    // while(v[j]!=0){
    //     j++;
    // }
    // for(int i=j+1;i<n;i++){
    //     if(v[i]!=0){
    //         v[j]=v[i];
    //         v[i]=0;
    //         j++;
    //     }
    // }
}
int main(){
    vector<int> v;
    vector<int> ans;
    int n;
    input(v,n);
    zeroesAtEnd(v,n);
    output(v,n);
}
 