
// #include "Input_Output.h"
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void input(vector<int> &v,int &n){
    cout<<"Number of elements:";
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
}
int Largest(vector<int> v,int N){
    
    int max=v[0];
    for(int i=1;i<N;i++){
        if(v[i]>max)
            max=v[i];
    }
    return max;
}
int secondLargest(vector<int> v,int N){
    //BruteForce
    // int secondLargest=INT_MIN;
    // int largest=Largest(v,N);
    // for(int i=0;i<N;i++){
    //     if(v[i]>secondLargest&&v[i]<largest)
    //         secondLargest=v[i];
    // }
    // return secondLargest;

    //Better
    int secondLargest=-1;
    int largest=-1;
    for(int i=0;i<N;i++){
        if(v[i]>secondLargest){
            if(v[i]>largest){
                
                secondLargest=largest;
                largest=v[i];
            }
            else if(v[i]<largest){
                secondLargest=v[i];
            }
        }
    } return secondLargest;

}
int main(){
    vector<int> v;
    int n;
    input(v,n);
    cout<<secondLargest(v,n);
}
