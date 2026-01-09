
#include<iostream>
#include<vector>
#include<set>
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
void output(vector<int> v,int n){
    cout<<"Array is:";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void Union(vector<int> v1,vector<int> v2,vector<int> &merged){
    //APProach 1
    int size1=v1.size();
    int size2=v2.size();
  
    //2.Set
    // set<int> stt;
    // for(int i=0;i<size1;i++){
    //     stt.insert(v1[i]);
    // }
    // for(int i=0;i<size2;i++){
    //     stt.insert(v2[i]);
    // }
    // // // 3.insert set elements back in merged
    // for(auto iter:stt){
    //     merged.push_back(iter);
    // }
    // Approach 2:Map
    map<int,int> mpp;
    for(int i=0;i<size1;i++){
        mpp[v1[i]]++;
    }
    for(int j=0;j<size2;j++){
        mpp[v2[j]]++;
    }
    for(auto iter:mpp){
        cout<<iter.first<<"->"<<iter.second<<endl;
    }
    for(auto iter:mpp){
        merged.push_back(iter.first);
    }

    //Approach 3---> 2Pointer approach
    // int i=0;int j=0; 
    // while(i<size1 && j<size2){
    //     if(v1[i]<v2[j]){
    //         merged.push_back(v1[i]);
    //         i++;
    //     }else if(v1[i]>v2[j]){
    //         merged.push_back(v2[j]);
    //         j++;
    //     }else{
    //         merged.push_back(v1[i]);
    //         i++;
    //         j++;

    //     }
    // }
    // while(i<size1){
    //     merged.push_back(v1[i]);
    //     i++;
    // }
    // while(j<size2){
    //     merged.push_back(v2[j]);
    //     j++;
    // }

}
int main(){
    vector<int> v1;
    vector<int> v2;
    int size1;
    int size2;
    input(v1,size1);
    input(v2,size2);
    vector<int> UnionArray;  

    Union(v1,v2,UnionArray);
    output(UnionArray,UnionArray.size());
}
 