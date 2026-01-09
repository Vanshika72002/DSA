
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Sort(vector<int> &v){
    int N=v.size();
    // Brute Force
    // sort(v.begin(),v.end());
    //Better
    // int count[3]={0,0,0};
    // int i=0;
    // while(i<N){
    //     count[v[i]]++;
    //     i++;
    // }
    // i=0;
    // while(count[0]>0){
    //     v[i]=0;
    //     i++;
    //     count[0]--;
    // }
    // while(count[1]>0){
    //     v[i]=1;
    //     i++;
    //     count[1]--;
    // }
    // while(count[2]>0){
    //     v[i]=2;
    //     i++;
    //     count[2]--;
    // }
    //Optimal
    int low=0,mid=0,high=N-1;
    while(mid<=high){
        if(v[mid]==0){
            v[mid]+=v[low];
            v[low]=v[mid]-v[low];
            v[mid]=v[mid]-v[low];
            mid++;
            low++;
        }else if(v[mid]==1){
            mid++;
        }else{
            v[mid]+=v[high];
            v[high]=v[mid]-v[high];
            v[mid]=v[mid]-v[high];
            high--;
        }
    }

}
int main(){
    vector<int>v;
    int N;
    cin>>N;
    int x;
    for(int i=0;i<N;i++){
        cin>>x;
        v.push_back(x);
    }
    Sort(v);
    for(int i=0;i<N;i++){
        cout<<v[i]<<" ";
    }
}