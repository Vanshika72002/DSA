#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> &arr,int i){
    int N=arr.size();
    if(i>=N/2){
        return;
    }
    arr[i]+=arr[N-i-1];
    arr[N-i-1]=arr[i]-arr[N-i-1];
    arr[i]=arr[i]-arr[N-1-i];
    reverseArray(arr,i+1);
}
void output(vector<int> v){
    int N=v.size();
    cout<<"N="<<N<<endl;
    for(int i=0;i<N;i++){
        cout<<v[i]<<" ";
    }
}
int main(){
    int N;
    vector<int> arr{11,2,3,4,5};
    reverseArray(arr,0);
    output(arr);
}