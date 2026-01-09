#include<iostream>
#include<vector>
#include<map>
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
int missing(vector<int> v,int size){
    // //BruteForce
    int N=size+1;
    // for(int i=1;i<=N;i++){
    //     int flag=0;
    //     for(int j=0;j<size;j++){
    //         if(v[j]==i){
    //             flag=1; //element found;
    //             break;
    //         }
    //     }
    //     if(flag==0)
    //         return i;
    // }
    //BETTER
    // int hashArr[N+1]={0};   
    // for(int i=0;i<size;i++){
    //     hashArr[v[i]]+=1;
    // }
    // for(int i=1;i<=N;i++){
    //     if(hashArr[i]==0)
    //         return i;
    // }
    //OPTIMAL 1
    // int sum1toN=(N*(N+1))/2;    
    // cout<<sum1toN;
    // int sumArray=0;
    // for(int i=0;i<size;i++){
    //     sumArray+=v[i];
    // }
    // cout<<endl<<sumArray;
    // return sum1toN-sumArray;

    //optimal2
    int xor1=0;
    int xor2=0;
    for(int i=0;i<size;i++){
        xor1^=v[i];
        xor2^=(i+1);
    }
    xor2^=N;
    return xor1^xor2;
}
int main(){
    vector<int> v;
    int n;
    input(v,n);
    cout<<missing(v,n);
}