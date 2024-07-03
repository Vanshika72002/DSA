//optimal
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int Majority(vector<int> v){
        
        int n=v.size();
        int el=v[0];
        int cnt=1;
        for(int i=1;i<v.size();i++){
            if(cnt!=0){
                if(v[i]==el){
                cnt++;
                }
                else    
                    cnt--;
            }
            else{
                el=v[i];
                cnt++;
            }
        }
        int check=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==el){
                check++;
            }
        }
        if(check==n/2+1){
            return el;
        }
        return -1;
        
}
int main(){
    vector<int> inp;
    int result;

    int n;
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        inp.push_back(x);
    }
    result=Majority(inp);
    cout<<endl<<endl;
    
    if(result!=-1){
        cout<<result;
    }
    else{
        cout<<"there is no majoriy element";
    }

}