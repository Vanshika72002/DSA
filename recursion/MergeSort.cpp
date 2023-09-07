#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int> &v,int  l,int mid,int r){
    vector<int> merged;
    cout<<"inside funcyion";
    int left=l;
    int right=mid+1;
    while(left<=mid||right<=r){
        if(v[left]<v[mid+1]){
            merged.push_back(v[left]);
            left++;
        }
        else{
            merged.push_back(v[right]);
            right++;
        }
    }
    while(left<=mid){
        merged.push_back(v[left]);
        left++;
    }
    while(right<=r){
        merged.push_back(v[right]);
        right++;
    }
    //modifying the original array
    for(int i=l;i<=r;i++){
        v[i]=merged[i-l];
    }
}
void MergeSort(vector<int> &v,int N,int l,int r){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    MergeSort(v,N,l,mid);
    MergeSort(v,N,mid+1,r);
    Merge(v,l,mid,r);
};
int main(){
    vector<int> vec;
    int N;
    int X;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>X;
        vec.push_back(X);
    }
    MergeSort(vec,N,0,N-1);
    for(int i=0;i<N;i++){
        cout<<vec[i];
    }
}