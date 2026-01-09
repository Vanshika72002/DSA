
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
int Search(vector<int> v, int n,int k){
    for(int i=0;i<n;i++){
        if(v[i]==k)
            return i;
    }
    return -1;
}
int main(){
    vector<int> v;
    int n;
    int k;
    input(v,n);
    cin>>k;
    int index=Search(v,n,k);
    if(index!=-1)
        cout<<"element found at:"<<index;
    else
        cout<<"Element not present in array";
}
 