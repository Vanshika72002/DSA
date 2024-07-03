#include<iostream>
#include<cmath>
using namespace std;

long long int nth_root_binary_search(int n,int p){
    if(n==1)
        return 1;
    int low=1;
    int high=n;
    int mid;
    int root=-1;
    while(low<=high){
        mid=(low+high)/2;
        int power=func(mid,p,n);
        cout<<"pow="<<power<<endl;
        if(power==1){
            return mid;
        }
        else if(power==0) {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int func(int mid,int p,int n)
{
    long long ans=1;
    for(int i=1;i<=p;i++){
        ans*=mid;
        if(ans==n)
            return 1;
        if(ans>n)
            return 2;
    }
        return 0;
}
long long int nth_root(int n,int p){
    if(n==1)
	    return 1;
    int root=-1;
    int i=1;
    while(i<=n){
        if(pow(i,p)==n){
            // cout<<"pow("<<i<<","<<p<<")="<<pow(i,p)<<endl;
            return i;
        }
        else if(pow(i,p)>n)
            break;
        i++;
    }
    return root;
}  
    

int main(){

    int x;
    cin>>x;
    int p;
    cin>>p;
    int result=nth_root_binary_search(x,p);
    cout<<result;
}