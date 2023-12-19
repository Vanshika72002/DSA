//       1
//     1 2 1
//   1 2 3 2 1 
// 1 2 3 4 3 2 1

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    int i=1;
    while(i<=n){
        int start=1;
        int j=1;
        while(j<=(2*n-1)){
            if(j>=n-i+1&&j<n){
                cout<<start<<" ";
                start++;
            }
            else if(j==n){
                cout<<start<<" ";
                start--;
            }
            else if(j>n&&j<=n+i-1){
                
                cout<<start<<" ";
                start--;
            }
            else{
                cout<<" ";
            }
            j++;
        }
        cout<<endl;
        i++;
    }
}