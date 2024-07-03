#include<iostream>
#include<vector>
using namespace std;

int Merge(vector<int> &v,int low,int mid,int high){
    int count=0;
    vector<int> temp;
    int i=low;
    int j;
    for( j=mid+1;(i<=mid&&j<=high);){
        if(v[i]>v[j]){
            count=count+mid-i+1;
            temp.push_back(v[j]);
            j++;
        }
        else{
            temp.push_back(v[i]);
            i++;
        }
    }
    while(i<=mid){
        temp.push_back(v[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(v[j]);
        j++;
    }
    
    for(int i=low;i<=high;i++){
        v[i]=temp[i-low];
    }
    return count;
}
int MergeSort(vector<int> &vec1,int low,int high){
    int cnt=0;
    if(low>=high)
        return cnt;
    int mid=(low+high)/2;
    cnt += MergeSort(vec1,low,mid);
    cnt += MergeSort(vec1,mid+1,high);
    cnt += Merge(vec1,low,mid,high);
    return cnt;
}
int countInversion(vector<int> v){
    int count=0;
    // int n=v.size();
    // for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(v[j]<v[i]){
    //             cout<<"inversion at "<<i<<"and"<<j;
    //             count++;
    //         }
    //     }
    // }
    // return count;
    //OPTIMAL using merge sort
    
    int n=v.size();
    count+=MergeSort(v,0,n-1);
    return count;
    
}
int main(){
    vector<int> vec;
    int n;
    cin>>n;
    int count;

    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        vec.push_back(x);
    }
    count=countInversion(vec);
    cout<<"Count===="<<count;
}