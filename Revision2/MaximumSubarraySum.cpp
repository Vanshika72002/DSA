#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int MaxSum(vector<int> vec){
    int N=vec.size();
    int maxsum=INT_MIN;
    //Brute force
    // for(int i=0;i<N;i++){
    //     int sum=vec[i];
    //     for(int j=i+1;j<N;j++){
    //         if(sum>maxsum)
    //             maxsum=sum;
    //         sum+=vec[j];
    //     }
    //     if(sum>maxsum)
    //         maxsum=sum;
    // }
    //Better
    int sum=0;
    for(int i=0;i<N;i++){
        sum+=vec[i];
        if(maxsum<sum)
            maxsum=sum;
        if(sum<0){
            sum=0;
        }
    }
    return maxsum;
}
int main(){
    vector<int> vec;
    int N;
    cin>>N;
    int x;
    for(int i=0;i<N;i++){
        cin>>x;
        vec.push_back(x);
    }
    int sum=MaxSum(vec);
    cout<<"maximum subarray sum is "<<sum;
}