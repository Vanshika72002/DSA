#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<int> sum2(vector<int> v,int target){
    vector<int> resultvec; 
    //BRUTE FORCE

    // for(int i=0;i<v.size();i++){
    //     int index1=i;
    //     int el1=v[i];
    //     for(int j=i;j<v.size();j++){
    //         if(el1+v[j]==target){
    //             resultvec.push_back(index1);
    //             resultvec.push_back(j);
    //             break;
    //         }
    //     }
    // }
    //BETTER
    // unordered_map<int,int> mpp;

    // for(int i=0;i<v.size();i++){
    //     int left=target-v[i];
    //     if(mpp.find(left)!=mpp.end()){
    //         resultvec.push_back(i);
    //         resultvec.push_back(mpp[left]);
    //         break;
    //     }
    //     mpp[v[i]]=i;
    // }
    // return resultvec;
    //OPTIMAL in case of only checking if pair with the target sum exists or not
    int left=0;
    int right=v.size()-1;
    sort(v.begin(),v.end());
    while(left<right){
        if(v[left]+v[right]==target){
            resultvec.push_back(left);
            resultvec.push_back(right);
            cout<<"YES";
            break;
        }
        else if(v[left]+v[right]>target){
            right--;
        }
        else{
            left++;
        }
    }
    return resultvec;
}
int main(){
    vector<int> nums;
    
    int n;
    int x;
    cin>>n;
    int ans[n];
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    cin>>x;
    vector<int> resultvec=sum2(nums,x);
    if(resultvec.size()!=0){
        cout<<resultvec[0]<<" "<<resultvec[1];
    }
    return 1;

}