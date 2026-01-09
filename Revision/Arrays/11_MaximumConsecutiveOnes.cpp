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
    int max=0;
    int cnt=0;
    for(int i=0;i<N;i++){
        if(v[i]==1){
            cnt++;
            if(cnt>max)
                max=cnt;
        }
        else{
            cnt=0;
        }
    }
    return max;
}
int main(){
    vector<int> v;
    int n;
    input(v,n);
    cout<<Largest(v,n);
}