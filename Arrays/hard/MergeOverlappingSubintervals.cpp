#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
vector<int> Merge(vector<int> first,vector<int> second){
    cout<<"Merging:";
        cout<<"("<<first[0]<<","<<first[1]<<"),"<<endl;
    cout<<"and:";
        cout<<"("<<second[0]<<","<<second[1]<<"),"<<endl;
    vector<int> merged;
    if(first[0]<=second[0]) merged.push_back(first[0]);
    else merged.push_back(second[0]);
    if(first[1]>second[1]) merged.push_back(first[1]);
    else merged.push_back(second[1]);
    return merged;
}
vector<vector<int>> MergeIntervals(vector<vector<int>> v){
    sort(v.begin(),v.end());
    int n=v.size();
    vector<vector<int>> result;
    for(int i=0;i<n;){
        vector<int> el=v[i];
        cout<<"new element\n";
        for(int i=0;i<el.size();i++){
            cout<<el[i]<<" ";
        }
        cout<<endl;
        int j=i+1;
        cout<<"j = "<<j<<endl;
        while(j<n && el[1]>=v[j][0]){
            cout<<"calling merge function\n";
            el=Merge(el,v[j]);

            cout<<"el changed to";
            cout<<"("<<el[0]<<","<<el[1]<<"),"<<endl;
            j++;
        }
        i=j;
        cout<<"i changed to"<<i;
        result.push_back(el);
        cout<<"------------";
        cout<<"result size="<<result.size();
        cout<<"\nResult after "<<i<<" iteration:";
        for(int i=0;i<result.size();i++){
        cout<<"("<<result[i][0]<<","<<result[i][1]<<"),"<<endl;
        cout<<"---------------";
    }
    }
    return result;
}
int main(){
    vector<vector<int>> intervals;
    int n;  //number of intervals
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> interval;
        int x;
        cin>>x;
        interval.push_back(x);
        cin>>x;
        interval.push_back(x);
        intervals.push_back(interval);
    }
    vector<vector<int>> result=MergeIntervals(intervals);
    cout<<"--------dfghjkl3456789-";
    cout<<"final result size="<<result.size()<<endl;
    for(int i=0;i<result.size();i++){
        cout<<"("<<result[i][0]<<","<<result[i][1]<<"),"<<endl;
    }
}