#include<iostream>
#include<vector>

using namespace std;
vector<int> minmaxInVector(vector<int> v){
    int max=INT_MIN;
    int min=INT_MAX;
    for(int i=0;i<v.size();i++){
        if(max<v[i])    max=v[i];
        if(min>v[i])    min=v[i];
    }
    return vector<int>{min,max};
}
int DaysToMake_M_bouqets(vector<int> v,int k,int m){
    int TotalFlowersRequired=k*m;
    int N=v.size();
    if(N<TotalFlowersRequired){
        cout<<"less flowers are available";
        return -1;
    }
    int maxx=minmaxInVector(v)[1];
    int minn=minmaxInVector(v)[0];
    for(int low=minn;low<=maxx;low++){
        cout<<"min days to bloom ="<<low<<endl;
        int bouqets=0;
        int flowers=0;
        for(int i=0;i<N;i++){
            cout<<"for i="<<i<<endl;
            cout<<"v[i]= "<<v[i];
            cout<<"low="<<low<<endl;
            if(v[i]<=low){
                flowers++;
                cout<<"inside outer if..bouqets = "<<bouqets<<" flowers="<<flowers;
                cout<<"k="<<k;
                if(flowers==k){
                    bouqets++;
                    cout<<"inside inner if ..bouqets = "<<bouqets<<" flowers="<<flowers;
                    flowers=0;
                    if(bouqets==m)
                        return i;
                }
            }
            else    
                flowers=0;
        }
    }
    return -1;

}
int main(){
    vector<int> v;
    int N;
    int k;
    int m;
    cin>>N;
    int x;
    for(int i=0;i<N;i++){
        cin>>x;
        v.push_back(x);
    }
    cout<<"Enter number of flowers in each bouqet\n";
    cin>>k;
    cout<<"Enter number of bouqets\n";
    cin>>m;
    int Days=DaysToMake_M_bouqets(v,k,m);
    cout<<"Days Required= "<<Days;
}