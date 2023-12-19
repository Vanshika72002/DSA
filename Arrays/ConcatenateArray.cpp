#include<iostream>
#include<vector>
using namespace std;
vector<int> getConcatenation(vector<int>& nums,int n,vector<int> &resultant) {
    
    int i=0;
    for(auto iter:nums){
        resultant.insert(resultant.begin()+i,iter);
        int z=i+nums.size();
        cout<<"resultant.begin()+i+nums.size()";
        cout<<z;
        resultant.insert(resultant.begin()+i+nums.size(),iter);
        i++;
    }
    return resultant; 
}
int main(){
    vector<int> nums;
    vector<int> resultant;
    int n;
    cin>>n;
        int x;

    for(int i=0;i<n;i++){
          cin>>x;
          nums.push_back(x);  
    }
    getConcatenation(nums,nums.size(),resultant);
    for(auto iter:resultant){
        cout<<iter <<" ";
    }


}