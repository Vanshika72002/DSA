#include<iostream>
#include <string>
#include<vector>
using namespace std;
vector<vector<int>> ans;
void Subsequence(vector<int> v,int i,int N,int target,vector<int> seq,int sum){
    if(sum==target){
            cout<<"target acheived.\n";
            ans.push_back(seq);
            return;   
    }
    if(i==N){
        cout<<"Reached end..\n";
        return;
    }
    cout<<"Continuing...\n";
    seq.push_back(v[i]);
    sum+=v[i];
    Subsequence(v,i+1,N,target,seq,sum);
    seq.pop_back();
    sum-=v[i];
    Subsequence(v,i+1,N,target,seq,sum);

}
int main (){
    //  string str;
    // Taking string input using getline()
    // getline(cin, str);
    int x;
    vector<int> Empty;
    vector<int> vec;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x;
        vec.push_back(x);
    }
    int k;
    cin>>k;
    Subsequence(vec,0,vec.size(),k,Empty,0);
    for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                    cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
    }
}