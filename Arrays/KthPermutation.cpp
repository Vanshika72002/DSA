#include<iostream>
#include<vector>
#include<string>
using namespace std;
string KthPermute(int N,int k){
    if(k>N){
        return "";
    }
    int fact=1;
    string s="";
    vector<int> vec;
    for(int i=1;i<N;i++){
        vec.push_back(i);
        fact*=i;
    }
    vec.push_back(N);
    
    k=k-1;
    while(true){
        s=s+to_string(vec[k/fact]);
        vec.erase(vec.begin()+k/fact);
        if(vec.size()==0){
            return s;
        }
        k=k%fact;
        fact=fact/vec.size();
    }

}
int main(){
    int N;
    cin>>N;
    int k;
    cin>>k;
    string ans=KthPermute(N,k);
    if(ans==""){
        cout<<"sorry the permutation is not possible";
    }
    else{
        cout<<ans;
    }
    
}