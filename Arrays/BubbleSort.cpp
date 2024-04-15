#include<iostream>
#include<vector>

using namespace std;
void bubbleSort(vector<int>& arr, int n) 
{
    while(n!=0)
    {
        int swap=0;
        for(int i =0;i<n-1;i++){
            
            if(arr[i+1]<arr[i]){
                swap=1;
                arr[i+1]=arr[i+1]+arr[i];
                arr[i]=arr[i+1]-arr[i];
                arr[i+1]=arr[i+1]-arr[i];
            }
            
        }
        if(swap==0){
                break;
            }
        n--;
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
    bubbleSort(nums,n);
    cout<<"selectionSort(nums)";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}