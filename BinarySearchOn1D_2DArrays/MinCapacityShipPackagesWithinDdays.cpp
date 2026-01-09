#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
vector<long long int> maxElAndSum(vector<int> v){
    int max=INT_MIN;
    int sum=0;
    int N=v.size();
    for(int i=0;i<N;i++){
        sum+=v[i];
        if(max<v[i])
            max=v[i];
    }
    return vector<long long int> {max,sum};
}
int Days(vector<int> v,int capacity){
    int N=v.size();
    int days=0;
    for(int j=0;j<N;){
        int loaded=0;
        while(loaded<=capacity){
            loaded+=v[j];
            if(loaded<=capacity)
                j++; 
        }
        days++;
    }
    return days;

}
int MinCapacity(vector<int> v,int max_days){
    vector<long long int> SumAndMaxEl=maxElAndSum(v);
    int N=v.size();
    long long int max=SumAndMaxEl[0];
    long long int sum=SumAndMaxEl[1];
    int flag=0;
    //BRUTE FORCE
    // for(int i=max;i<=sum;i++){
    //     int days=Days(v,i);   //number of days required if capacity of ship is i
    //     // cout<<"number of days="<<days<<"if capacity of ship is "<<i;
    //     if(days<=max_days)
    //         return i;
    // }
    int low=max;
    int high=sum;
    int mid;
    int ans;
    while(low<=high){
        mid=(low+high)/2;
        if(Days(v,mid)>max_days)    
            low=mid+1;      //need to increase the capacity of ship
        else{
            high=mid-1;
            ans=mid;
        }
    }
    return ans;
}
int main(){
    vector<int> v;
    int el;
    int Size;
    cin>>Size;
    for(int i=0;i<Size;i++){
        cin>>el;
        v.push_back(el);
    }
    int days;
    cin>>days;
    int capacity=MinCapacity(v,days);
    cout<<capacity;
}