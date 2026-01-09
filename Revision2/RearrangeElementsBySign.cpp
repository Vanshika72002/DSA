#include<iostream>
#include<vector>
using namespace std;
void RearrangeBySign(vector<int> &v){
    int N=v.size();
    vector<int> positives;
    vector<int> negatives;
    for(int i=0;i<N;i++){
        if(v[i]>0)
            positives.push_back(v[i]);
        else
            negatives.push_back(v[i]);
    }
    int pos=0,neg=1;
    for(int i=0;i<N/2;i++){
        v[pos]=positives[i];
        v[neg]=negatives[i];
        pos+=2;
        neg+=2;
    }
    
}
vector<int> RearrangeBySign_optimal(vector<int> v){
    int N=v.size();
    vector<int> newVec(N,0);
    int pos=0;
    int neg=1;
    for(int i=0;i<N;i++){
        if(v[i]>0){
            newVec[pos]=v[i];
            pos+=2;
        }else{
            newVec[neg]=v[i];
            neg+=2;
        }
    }
    return newVec;
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
    // RearrangeBySign(vec);
    vec=RearrangeBySign_optimal(vec);
    for(int i=0;i<N;i++){
        cout<<vec[i]<<" ";
    }
}