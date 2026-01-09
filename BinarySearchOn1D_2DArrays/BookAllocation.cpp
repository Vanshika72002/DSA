#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;
int sum(vector<int> v,int N){
    int i=0;
    int Sum=0;
    for(;i<N;i++){
        Sum+=v[i];
    }
    return Sum;
}
bool canAllocateBooks(vector<int> pages, int max,int M,int N ){
    cout<<"inside checker function";
    int sum=0;
    int studentsAssignedBooks=1;
    for(int i=0;i<N;i++){
        if(sum+pages[i]>max){
            studentsAssignedBooks++;
            sum=pages[i];
        }
        else{
            sum+=pages[i];
        }
    }
    if(studentsAssignedBooks>M)
        return false;

    return true;
}
int minOfMaxPages(vector<int> pages,int M){
    int N=pages.size();
    if(M>N)
        return -1;
    if(M==N)
        return pages[N-1];
    if(M==1)
        return sum(pages,N);
    int low=pages[0];
    int high=sum(pages,N);
    int mid;
    int ans;
    while(low<=high){
        mid=(low+high)/2;
        cout<<"mid="<<mid<<"\n";

        if(canAllocateBooks(pages,mid,M,N)){
            cout<<"possible it is";
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){

    int N;      //number of books;
    int M;      //number of students
    int temp;
    vector<int> pages;  //assuming the array to be a sorted array
    cout<<"Number of books?:";
    cin>>N;
    cout<<"Number of students?:";
    cin>>M;
    cout<<"number of pages in books:\n";
    for(int i=0;i<N;i++){
        cin>>temp;  
        pages.push_back(temp);
    }
    sort(pages.begin(),pages.end());
    int result=minOfMaxPages(pages,M);
    cout<<"\nresult="<<result;
}