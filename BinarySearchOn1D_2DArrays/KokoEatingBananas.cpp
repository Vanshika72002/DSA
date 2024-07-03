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
int Ceil(int x,int y){
    if(x%y!=0)
        return (x/y + 1);
    else
        return (x/y);
}
int BananasInOneHour(vector<int> v,int h){
    int maxx=maxElement(v); 
    int N=v.size();
    for(int i=1;i<=maxx;i++){
        cout<<"for i="<<i<<"\n";
        int hoursRequired=0;
        for(int j=0;j<N;j++){
            hoursRequired+=Ceil(v[j],i);
            cout<<"HoursRequired="<<hoursRequired<<" ";
            if(hoursRequired>h)
            {
                cout<<"hoursRequired exceeded h...breaking out\n";
                break;
            }
        }
        if(hoursRequired<=h)
            return i;
    }
    return -1;
}
int BananasInOneHour_BS(vector<int> v, int h){

    int maxx=maxElement(v);
    int N=v.size();
    int low=1;
    int high=maxx;
    int mid;
    int ans=INT_MAX;
    while(low<=high){
        mid=(low+high)/2;
        int hoursRequired=0;
        for(int j=0;j<N;j++){
            hoursRequired+=Ceil(v[j],mid);
            cout<<"HoursRequired="<<hoursRequired<<" ";
        }
        if(hoursRequired>h){
            low=mid+1;
        }
        else{
            high=mid-1;
            if(ans>mid){
                cout<<"if satisfied for mid= "<<mid<<"\n";
                ans=mid;}
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
    int h;
    cin>>h;
    int result=BananasInOneHour_BS(arr,h);
    cout<<result;
}