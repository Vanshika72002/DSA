#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;
int sum(vector<int> v,int N){
    int i=0;
    int Sum=0;
    for(;i<N;i++){
        Sum+=v[i];
    }
    return Sum;
}
bool canWeSplit(vector<int> vec,int numOfSubarrays,int maxSum){
    int N=vec.size();
    int subarraysFormed=1;
    int sum=0;
    for(int i=0;i<N;i++){
        if(vec[i]>maxSum)
            return false;
        if(sum+vec[i]>maxSum){
            subarraysFormed++;
            sum=vec[i];
        }
        else{
            sum+=vec[i];
        }
        
    }
    if(subarraysFormed<=numOfSubarrays)
        return true;
    return false;
    
}
int minOfMaxSum(vector<int> v,int numOfSubarrays){

    int N=v.size();
    int high=sum(v,N);
    int low=v[0];
    int ans;
    while(low<=high){
        int mid=(low+high)/2;
        
        if(canWeSplit(v,numOfSubarrays,mid)){
            high=mid-1;
            ans=mid;
        }
        
        else{
            low=mid+1;
        }
    }
    return ans;
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

    int N;      //number of elements;
    int M;      //number of cows
    int temp;
    vector<int> elements;
    cout<<"number of elements";
    cin>>N;
    cout<<"Number of subarrays";
    cin>>M;
    cout<<"elements :\n";
    for(int i=0;i<N;i++){
        cin>>temp;  
        elements.push_back(temp);
    }
    sort(elements.begin(),elements.end());
    int result=minOfMaxSum(elements,M);
    cout<<"\nresult="<<result;
}