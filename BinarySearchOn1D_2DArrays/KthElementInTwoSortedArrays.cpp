#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;
// int Kth(vector<int> v1,vector<int> v2,int pos){
//     vector<int> v3;
//     int i=0;
//     int j=0;
//     int M=v2.size();
//     int N=v1.size();
//     while(i<N && j<M){
//         if(v1[i]<v2[j])
//             v3.push_back(v1[i++]);
//         else    
//             v3.push_back(v2[j++]);
//     }
//     while(i<N){
//         v3.push_back(v1[i]);
//         i++;
//     }
//     while(j<M){
//         v3.push_back(v2[j]);
//         j++;

//     }
//     int x=0;
//     while(x<M+N)
//         cout<<v3[x++];
//     return v3[pos-1];
// }
// int Kth_better(vector<int> v1,vector<int> v2,int k){
//     int i=0;
//     int j=0;
//     int cnt=0;
//     int M=v2.size();
//     int N=v1.size();
//     while(i<N && j<M){
//         if(v1[i]<v2[j]){
//             cnt++;
//             if(cnt==k)
//                 return v1[i];
//             i++;
//         }else{    
//             cnt++;
//             if(cnt==k)
//                 return v2[j];
//             j++;
//         }
//     }
//     while(i<N){
//         cnt++;
//         if(cnt==k)
//                 return v1[i];
//         i++;
//     }
//     while(j<M){
//         cnt++;
//         if(cnt==k)
//             return v2[j];
//         j++;

//     }
//     return -1;
// }
int kth_optimal(vector<int> v1,vector<int> v2,int k){
    int N1=v1.size();
    int N2=v2.size();
    if(N1>N2)
        return kth_optimal(v2,v1,k);

    int low=max(k-N2,0);
    int high=min(k,N1);
    while(low<=high){
        // cout<<"inside loopp";
        int l1=INT_MIN;
        int l2=INT_MIN;
        int r1=INT_MAX;
        int r2=INT_MAX;
        int mid1=(low+high)/2;  //number of elements in left from array1 
        int mid2=k-mid1;  //number of elements in left from array2 
        //check if this is a valid division
        if(mid1-1>=0)
            l1=v1[mid1-1];
        if(mid2-1>=0)
            l2=v2[mid2-1];
        if(mid1<N1)
            r1=v1[mid1];
        if(mid2<N2)
            r2=v2[mid2];
        if(l1<=r2 && l2<=r1){
            //it it valid
            return max(l1,l2);
        }
        else{
            if(l1>r2)
                high=mid1-1;
            else
                low=mid1+1;
        }

    }
}
int main(){

    int N;      //number of elements in array 1;
    int M;      //number of elements in array 2
    int temp;
    vector<int> array1;
    vector<int> array2;
    cout<<"number of elements in array 1?:";
    cin>>N;
    cout<<"number of elements in array 2?:";
    cin>>M;
    cout<<"elements:\n";
    for(int i=0;i<N;i++){
        cin>>temp;  
        array1.push_back(temp);
    }
    for(int i=0;i<M;i++){
        cin>>temp;  
        array2.push_back(temp);
    }
    int k;
    cout<<"position:";
    cin>>k;

    int result= kth_optimal(array1,array2,k);
    cout<<"\nresult="<<result;
}