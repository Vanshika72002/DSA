#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string TwoSum_optimal(vector<int> v,int target){
    sort(v.begin(),v.end());
    int left=0;
    int N=v.size();
    int right=N-1;
    while(left<right){
        if(v[left]+v[right]==target)
            return "YES";
        else{
            if(v[left]+v[right]>target){
                right--;
            }else{
                left++;
            }

        }
    }
    return "NO";
}
int main(){
    vector<int> v;
    int N;
    cin>>N;
    int x;
    for(int i=0;i<N;i++){
        cin>>x;
        v.push_back(x);
    }
    cin>>x;
    cout<<TwoSum_optimal(v,x);
}