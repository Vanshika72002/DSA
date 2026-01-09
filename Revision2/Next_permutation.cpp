#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> next_permutation(vector<int> permutation){
    vector<int> nextPermutation=permutation;
    int N=permutation.size();
    int targetIndex=-1;
    for(int i = N-2;i>=0;i--){
        if(nextPermutation[i]<nextPermutation[i+1]){
            targetIndex=i;
            break;
        }
    }
    if(targetIndex==-1){
        reverse(nextPermutation.begin(),nextPermutation.end());
        return nextPermutation;
    }
    for(int i=N-1;i>targetIndex;i--){
        if(nextPermutation[i]>nextPermutation[targetIndex]){
            swap(nextPermutation[i],nextPermutation[targetIndex]);
            break;
        }
    }
    reverse(nextPermutation.begin()+targetIndex+1,nextPermutation.end());
    return nextPermutation;
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
    vector<int> nextPermutation=next_permutation(vec);
    for(int i=0;i<N;i++){
        cout<<nextPermutation[i]<<" ";
    }
}