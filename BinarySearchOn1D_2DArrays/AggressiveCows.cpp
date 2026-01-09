#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;
bool canWePlace(vector<int> positions,int dist,int cows){
    int N=positions.size();
    int lastCowAt=positions[0];
    int cowCount=1;
    int newDist;
    for(int j=1;j<N;j++){
        newDist=positions[j]-lastCowAt;
        if(newDist>=dist){
            //Cow can be placed at v[j]
            lastCowAt=positions[j];
            cowCount++;
            if(cowCount==cows){
                return true;
            }
        }
    }
    return false;
}
int maxofminDist(vector<int> v,int Cows){
    int N=v.size();
    int max=v[N-1];
    int min=v[0];
    int low=1;
    int high=max-min;
    while(low<=high){
        int mid=(low+high)/2;
        
        if(canWePlace(v,mid,Cows)){
            low=mid+1;
            ans=mid;
        }
        else{
            high=mid-1;
        }
    }
    return high;
    // for(int i=1;i<max-min;i++){
    //     int ansDist=-1;
    //     int j=1;
    //     int lastCowAt=v[0];
    //     int cowCount=1;
    //     int newDist;
    //     int oldDist=INT_MAX;
    //     for(;j<N;j++){
    //         newDist=v[j]-lastCowAt;
    //         if(newDist>=i){
    //             //Cow can be placed at v[j]
    //             if(newDist<oldDist){
    //                 oldDist=newDist;
    //             }
    //             lastCowAt=v[j];
    //             cowCount++;
    //             if(cowCount==Cows){
    //                 ansDist=newDist;
    //                 ans=ansDist;
    //                 break;
    //             }
    //         }
    //     }
    //     if(ansDist==-1){
    //         return ans;
    //     }
    // }
}
int main(){

    int N;      //number of stalls;
    int M;      //number of cows
    int temp;
    vector<int> stalls;
    cout<<"Number of stalls?:";
    cin>>N;
    cout<<"Number of cows?:";
    cin>>M;
    cout<<"position of stalls:\n";
    for(int i=0;i<N;i++){
        cin>>temp;  
        stalls.push_back(temp);
    }
    sort(stalls.begin(),stalls.end());
    int result=maxofminDist(stalls,M);
    cout<<"\nresult="<<result;
}