#include<iostream>
#include<vector>
using namespace std;
int SmallestMissing(vector<int>& arr,int k){
    int cnt=0,i=1,j=0;
        while(cnt<k){
            if(arr[j]==i){
                j++;
                i++;
            }
            else{
                cnt++;
                if(cnt==k)
                    return i;
                i++;
            }
        }
        
    return i;
}
int main(){
    
    vector<int> v;
    int el;
    int Size;
    cin>>Size;
    for(int i=0;i<Size;i++){
        cin>>el;
        v.push_back(el);
    }
    int k;
    cin>>k;
    int result=SmallestMissing(v,k);
    cout<<result;
}