#include<iostream>
using namespace std;
long long int sqrtt(int n){
    // long long int root=1;
    // int i=1;
    // while(i<=n/2){
    //     if(i*i<=n)
    //         root=i;
    //     else
    //         break;
    //     i++;
    // }
    // return root;
    int low=1;
    int high=n;
    int mid;    
    while(low<=high){
        mid=(low+high)/2;
        int x=(mid)*(mid);
        if(x>n){
            high=mid-1;
        }
        else{
            if((mid+1)*(mid+1)>n)
                return mid;
            else    
                low=mid+1;
        }

    }
    return -1;

}
int main(){

    int x;
    cin>>x;
    int result=sqrtt(x);
    cout<<result;
}