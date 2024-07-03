#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int maxElement(vector<int> v){
    int max=INT_MIN;
    
    for(int i=0;i<v.size();i++){
        
        if(v[i]>max)
            max=v[i];
    }
    return max;
} 
int SumAfterDivision(vector<int> v,int d){
    int sum=0;
    int N=v.size();
    if(d==maxElement(v))
        return N;
    for(int i=0;i<N;i++){
        if(d==1)
            sum+=v[i];
        else   
            sum+=ceil(double(v[i]/double(d)));
    }
    return sum;
}
int SmallestDivisor(vector<int> v,int l){
    
    int maxx=maxElement(v);
    for(int i=1;i<=maxx;i++){
        if(SumAfterDivision(v,i)<=l)
            return i;
    }
    return -1;
}
int SmallestDivisor_BS(vector<int> v, int l){

    int high=maxElement(v);
    int low=1;
    int mid;
    int ans;
    while(low<=high){
        mid=(low+high)/2;
        if(SumAfterDivision(v,mid)<=l){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;    
}
int main(){
    int n;
    cin>>n;
    int x;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    int limit;
    cin>>limit;
    int result=SmallestDivisor(arr,limit);
    cout<<result;
}