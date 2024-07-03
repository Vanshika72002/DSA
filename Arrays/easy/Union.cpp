#include<vector>
#include<iostream>
using namespace std;
#include<set>
vector<int> result;
vector<int> intersect;
vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    // vector<int> result;
    std::set<int> st;
    for(int i=0;i<a.size();i++){
        st.insert(a[i]);
    }
    for(int i=0;i<b.size();i++){
        st.insert(b[i]);
    }
    cout<<endl;
    // auto iter=st.begin();
    for(auto iter:st){
        result.push_back(iter);
    }
    return result;
}
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	/******************BRUTE**FORCE*********************/
	

	// unordered_map<int,bool> visited1;
	unordered_map<int,bool> visited2;
	for(int i=0;i<m;i++){
		visited2[i]=false;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!visited2[j]&&arr1[i]==arr2[j]){
				intersect.push_back(arr1[i]);
				// visited1[i]=true;
				visited2[j]=true;
                i++;
			}
		}
	}
	return intersect;
}

int main(){
    // 1 4 5
// 3 4 5
vector<int> a;
    vector<int> b;
    int x;
    int n,m;
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        b.push_back(x);
    }
    
    sortedArray(a,b);
    for(auto iter:result){
        cout<<iter <<" ";
    }
    cout<<endl<<endl;
    findArrayIntersection(a,n,b,m);
    for(auto iter:intersect){
        cout<<iter <<" ";
    }
    cout<<endl<<endl;
    
}