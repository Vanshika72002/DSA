#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;
// double Median(vector<int> v1,vector<int> v2){
//     int i=0;
//     int j=0;
//     int N=v1.size();
//     int M=v2.size();
//     vector<int> NewVec;
//     while(i<N && j<M){
//         cout<<"inside loop";
//         if(v1[i]<v2[j]){
//             NewVec.push_back(v1[i]);
//             i++;
//         }
//         else if(v1[i]>v2[j]){
//             NewVec.push_back(v2[j]);
//             j++;
//         }
//         else{
//             NewVec.push_back(v1[i]);
//             NewVec.push_back(v2[j]);
//             i++;
//             j++;
//         }
//     }
//     while(i<N){
//         NewVec.push_back(v1[i]);
//         i++;
//     }
//     while(j<M){
//         NewVec.push_back(v2[j]);
//         j++;
//     }
//     int TotalElements=M+N;
//     int median;
//     if(TotalElements%2==0){
//         int ind1=TotalElements/2;
//         int ind2=(TotalElements/2)-1;
//         return (double)(NewVec[ind1]+NewVec[ind2])/2;
//     }
//     else{
//         return NewVec[TotalElements/2];
//     }
// }
//BEtter - optimizing the space complexity
// double Median_Better(vector<int> v1,vector<int> v2){
//     int i=0;
//     int j=0;
//     int N=v1.size();
//     int M=v2.size();
//     int cnt=0;
//     int el1,el2;
//     while(i<N && j<M){
//         cout<<"inside loop";
//         if(v1[i]<v2[j]){
            
//             cnt++;
//             if(cnt==(M+N)/2+1){
//                 el2=v1[i];
//                 break;
//             }
//             else if(cnt==(M+N)/2){
//                 el1=v1[i];
//             }
//             i++;
//         }
//         else if(v1[i]>v2[j]){

//             cnt++;
//             if(cnt==(M+N)/2+1){
//                 el2=v2[j];
//                 break;
//             }
//             else if(cnt==(M+N)/2){
//                 el1=v2[j];
//             }
//             j++;
//         }
//         else{
//             cnt++;
//             if(cnt==(M+N)/2+1){
//                 el2=v2[j];
//                 break;
//             }
//             else if(cnt==(M+N)/2){
//                 el1=v2[j];
//             }
//             j++;
//             cnt++;
//             if(cnt==(M+N)/2+1){
//                 el2=v1[i];
//                 break;
//             }
//             else if(cnt==(M+N)/2){
//                 el1=v1[i];
//             }
//             i++;

//         }
//     }
//     while(i<N){
//         cnt++;
//         if(cnt==(M+N)/2+1){
//                 el2=v1[i];
//                 break;
//         }
//         else if(cnt==(M+N)/2){
//             el1=v1[i];
//             break;
//         }
//         i++;
//     }
//     while(j<M){
//         cnt++;
//         if(cnt==(M+N)/2+1){
//                 el2=v2[j];
//                 break;
//         }
//         else if(cnt==(M+N)/2){
//             el1=v2[j];
//         }
//         j++;
//     }
//     int TotalElements=M+N;
//     int median;
//     cout<<"el1="<<el1<<"el2="<<el2;
//     if(TotalElements%2==0){
        
//         return (double)(el1+el2)/2;
//     }
//     else{
//         return el2;
//     }
// }
double median_optimal(vector<int> v1,vector<int> v2){
    int N=v1.size();
    int M=v2.size();
    if(N>M)
        return median_optimal(v2,v1);
    int low=0;
    int high=N;
    int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
    int mid1,mid2;
    int numOfElementsOnLeft=(M+N+1)/2;
    int TotalElements=M+N;
    while(low<=high){
        mid1=(low+high)/2;  //number of elements on left from array1
        mid2=numOfElementsOnLeft-mid1;  //number of elements on left from array 2
        if(mid1-1>=0)
            l1=v1[mid1-1];
        if(mid2-1>=0)
            l2=v2[mid2-1];
        if(mid1<N)
            r1=v1[mid1];
        if(mid2<M)
            r2=v2[mid2];
        if(l1>r2)
            high=mid1-1;
        else if(l2>r1)
            low=mid1+1;
        else    
            break;
    }
    double median;
    if(TotalElements%2==0)

        median=(double)(max(l1,l2)+min(r1,r2))/2.0;
    
    else

        median=max(l1,l2);
    cout<<"media="<<median;
        return median;
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
    cout<<"elements in array 1:\n";
    for(int i=0;i<N;i++){
        cin>>temp;  
        array1.push_back(temp);
    }
    cout<<"elements in array 2:\n";
    for(int i=0;i<M;i++){
        cin>>temp;  
        array2.push_back(temp);
    }
    double median=median_optimal(array1,array2);
    cout<<"\nresult="<<median;
}