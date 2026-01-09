#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
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
vector<int> sort(vector<int> &v,int N){
    //BRUTE FORCE 
    // sort(v.begin(),v.end());

    //BETTER
    int zeroes=0;
    int ones=0;
    int twos=0;
    for(int i=0;i<N;i++){
        if(v[i]==0){
            zeroes++;
        }
        else if(v[i]==1){
            ones++;
        }
        else{
            twos++;
        }
    }
    int i=0;
    while(zeroes>0){
        v[i]=0;
        zeroes--;
        i++;
    }
    while(ones>0){
        v[i]=1;
        ones--;
        i++;
    }
    while(twos>0){
        v[i]=2;
        twos--;
        i++;
    }

    //OPTIMAL
    //DNF Algorithm
}
int main(){
    vector<int> v;
    int n;
    input(v,n);
    sort(v,n);
    output(v,n);
}