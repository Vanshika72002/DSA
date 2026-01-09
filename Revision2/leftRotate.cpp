#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void leftRotate_BF(vector<int> &v,int D){
	
	vector<int> temp;
	int N=v.size();
	D=D%N;
	if(D==0)
		return;
	for(int i=0;i<D;i++){
		temp.push_back(v[i]);
	}
	for(int i=D;i<N;i++){
		v[i-D]=v[i];
	}
	for(int i=N-D;i<N;i++){
		v[i]=temp[i-(N-D)];
	}
}
void leftRotate_Optimal(vector<int> &v,int D){
	int N=v.size();
	D=D%N;
	reverse(v.begin(),v.begin()+D);
	reverse(v.begin()+D,v.begin()+N);
	reverse(v.begin(),v.end());
}
int main(){
	vector<int> v;
	cout<<"Number of elements?:\n";
	int n;
	cin>>n;
	int x;
	int D;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
	}
	cin>>D;
	// leftRotate_BF(v,D);
	leftRotate_Optimal(v,D);
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}	
}