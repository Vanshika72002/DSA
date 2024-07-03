#include<iostream>
#include<vector>
#include<string>
using namespace std;
    void selectionSort(vector<int>&arr) {
    // Write your code here.
    int smallest,pos;
    for(int i=0;i<arr.size()-1;i++){
        smallest=arr[i];
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<smallest){
                // cout<<"for i="<<i<<"got another smallest number";
                pos=j;
                smallest=arr[j];
            }
        }
        if(arr[i]!=smallest)
        {
            arr[i]=arr[i]+smallest;
            smallest=arr[i]-smallest;
            arr[i]=arr[i]-smallest;
            arr[pos]=smallest;
        
        }
    }
}

int main(){
    vector<int> nums;
    int n;
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter";
        cin>>x;
        nums.push_back(x);
    }
    selectionSort(nums);
    cout<<"selectionSort(nums)";
    for(int i=0;i<n;i++){
        cout<<nums[i];
    }
}