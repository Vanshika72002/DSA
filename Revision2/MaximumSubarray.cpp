#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
vector<int> MaxSum(vector<int> vec){
    int N=vec.size();
    int maxsum=INT_MIN;
    int start=-1,end=-1;
    //Brute force
    if(N==1){
        return {vec[0],0,0};
    }
    // for(int i=0;i<N;i++){
    //     int sum=0;
    //     for(int j=i;j<N;j++){
    //         sum+=vec[j];
    //         if(sum>maxsum){
    //             maxsum=sum;
    //             start=i;
    //             end=j;
    //         }
    //     }
    // }
    //Better
    int sum=0;
    start=0;
    int probablyStart=0;  
    // cout<<sum<<"      "<<start<<"       "<<probablyStart<<"        "<<"-1"<<" "<<maxsum<<" "<<end<<endl;
    for(int i=0;i<N;i++){
        
        sum+=vec[i];
        if(maxsum<sum){
            maxsum=sum;
            start=probablyStart;
            end=i;
        }if(sum<0){
            sum=0;
            probablyStart=i+1;
        }
         cout<<sum<<"      "<<start<<"       "<<probablyStart<<"         "<<i<<"    "<<maxsum<<"       "<<end<<endl;
    }
    return {maxsum,start,end};
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
    cout<<"sum start probabalystart i maxsum end\n";
    vector<int>  sum=MaxSum(vec);
    cout<<"maximum subarray sum is "<<sum[0];
    cout<<"subarray indices:["<<sum[1]<<","<<sum[2]<<"]";
}