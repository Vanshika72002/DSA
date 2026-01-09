
// #include "Input_Output.h"
#include<iostream>
#include<vector>
#include<set>
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
void removeDuplicates(vector<int> &v,int &n){
   set<int> stt;
   for(int i=0;i<n;i++){
        stt.insert(v[i]);
   }
   int i=0;
   for(auto iter:stt){
        v[i]=iter;
        i++;
   } 
   
//    better
//    int j=1;
//    int lastAddedElement=v[0];
//    for(int i=1;i<n;i++){
//         if(v[i]!=lastAddedElement){
//             v[j]=v[i];
//             lastAddedElement=v[i];
//             j++;
//         }
//    }n=j;
}
int main(){
    vector<int> v;
    int n;
    input(v,n);
    removeDuplicates(v,n);
    output(v,n);
}
