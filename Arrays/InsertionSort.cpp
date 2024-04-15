#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int>& arr, int n) 
{
    // int i=0; 
    int sorted_till=0;
    // int k;//element to be placed at its correct position
    while(sorted_till!=n-1){
        int pos=sorted_till+1; //position of the element to be placed at correct position
        // k=arr[sorted_till+1];
        while(pos!=0 && arr[pos]<arr[pos-1]){
            //swap arr[pos] with arr[pos-1]
            arr[pos]=arr[pos-1]+arr[pos];
            arr[pos-1]=arr[pos]-arr[pos-1];
            arr[pos]=arr[pos]-arr[pos-1];
            pos--;
        }
        sorted_till++;
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
    insertionSort(nums,n);
    cout<<"InsertionSort(nums)";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}