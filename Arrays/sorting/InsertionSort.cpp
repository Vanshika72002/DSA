#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int>& arr, int n) 
{
    int sorted_till=0;
    while(sorted_till!=n-1){
        int pos=sorted_till+1; //position of the element to be placed at correct position
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