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
int Largest(vector<int> v,int N){
    // //BruteForce
    // sort(v.begin(),v.end());
    // return v[N-1];
    //Better
    int max=v[0];
    for(int i=1;i<N;i++){
        if(v[i]>max)
            max=v[i];
    }
    return max;
}
int main(){
    vector<int> v;
    int n;
    input(v,n);
    cout<<Largest(v,n);
}