#include<iostream>
using namespace std;
#include<vector>
vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        cout<<"inside function";
        int ptr1=0;int ptr2=0;
        int size_a=a.size();
        int size_b=b.size();
        vector<int> c;
        int currEl;
        c.push_back(a[ptr1]<=b[ptr2] ? a[ptr1] : b[ptr2]);
        if(c[0]==a[ptr1])
            ptr1++;
        else
            ptr2++;
        while(ptr1<size_a && ptr2<size_b){
            cout<<"inside loop";
            if(a[ptr1]<=b[ptr2]){
                currEl=a[ptr1];
                ptr1++;
            }else{
                currEl=b[ptr2];
                ptr2++;
            }
            
            if(c.back()!=currEl)
                c.push_back(currEl);
        }
        while(ptr1<size_a){
            if(c.back()!=a[ptr1])
                c.push_back(a[ptr1]);
            ptr1++;
        }
        while(ptr2<size_b){
            if(c.back()!=b[ptr2])
                c.push_back(b[ptr2]);
            ptr2++;
        }
        return c;
    }
int main(){
    vector<int> a;
    vector<int> b;
    int n1,n2;
    cout<<"size1:";
    cin>>n1;
    cout<<"size2:";
    cin>>n2;
    int x;
    for(int i=0;i<n1;i++){
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n2;i++){
        cin>>x;
        b.push_back(x);
    }
    vector<int> Union=findUnion(a,b);
    int unionSize=Union.size();
    cout<<"Result\n";
    for(int i=0;i<unionSize;i++){
        cout<<Union[i]<<" ";
    }
}
