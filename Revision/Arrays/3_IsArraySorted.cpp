#include<iostream>
#include<vector>
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
bool isSorted(vector<int> v,int N){
    // BrueFroce
    // for(int i=0;i<N-1;i++){
    //     for(int j=i+1;j<N;j++){
    //         if(v[j]<v[i])
    //             return false;       
    //     }
    // }
    // return true;

    //Better
    for(int i=0;i<N-1;i++){
        if(v[i]>v[i+1])
            return false;
    }
    return true;
}
int main(){
    vector<int> v;
    int n;
    input(v,n);
    cout<<isSorted(v,n);
}