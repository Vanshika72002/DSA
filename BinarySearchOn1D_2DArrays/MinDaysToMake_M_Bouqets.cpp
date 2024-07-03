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
int DaysToMake_M_bouqets_BS(vector<int> DaysToBloom,int flowersIn_a_Bouqet,int TotalBouqets){
    unsigned int TotalFlowersRequired=flowersIn_a_Bouqet*TotalBouqets;
    cout<<TotalFlowersRequired;
    int flowersAvailable=DaysToBloom.size();
    if(flowersAvailable<TotalFlowersRequired){
        cout<<"less flowers are available";
        return -1;
    }
    int maxx=minmaxInVector(DaysToBloom)[1];
    int minn=minmaxInVector(DaysToBloom)[0];
    int low=minn;
    int high=maxx;
    int mid;
    int ans;
    while(low<=high){
        cout<<"inside while loop low="<<low<<"high="<<high<<endl;
        mid=(low+high)/2;
        cout<<"mid="<<mid;
        int bouqet=0;
        int flowers=0;
        for(int j=0;j<flowersAvailable;j++){
            cout<<"for j="<<j<<endl;
            if(DaysToBloom[j]<=mid){
                flowers++;
                cout<<"inside outer if..bouqetsMade = "<<bouqet<<" flowersBloomed="<<flowers;
                cout<<"flowersIn_a_Bouqet="<<flowersIn_a_Bouqet;
                if(flowers==flowersIn_a_Bouqet){
                    bouqet++;
                    cout<<"inside inner if ..bouqetsMade = "<<bouqet<<" flowersBloomed="<<flowers;
                    flowers=0;
                    
                }
            }
            else    
                flowers=0;
        }
        if(bouqet>=TotalBouqets){
            ans=mid;
            high=mid-1;
            cout<<"changed high to "<<high;
            cout<<"low="<<low;
        }         
        else if(bouqet<TotalBouqets){
            cout<<"modifying low to"<<mid+1;
            low=mid+1;
        }
    }
    return ans; 

}
int DaysToMake_M_bouqets(vector<int> DaysToBloom,int flowersIn_a_Bouqet,int TotalBouqets){
    int TotalFlowersRequired=flowersIn_a_Bouqet*TotalBouqets;
    int flowersAvailable=DaysToBloom.size();
    if(flowersAvailable<TotalFlowersRequired){
        cout<<"less flowers are available";
        return -1;
    }
    int maxx=minmaxInVector(DaysToBloom)[1];
    int minn=minmaxInVector(DaysToBloom)[0];
    for(int i=minn;i<=maxx;i++){
        cout<<"min days to bloom ="<<i<<endl;
        int bouqetsMade=0;
        int flowersBloomed=0;
        for(int j=0;j<flowersAvailable;j++){
            cout<<"for j="<<j<<endl;
            if(DaysToBloom[j]<=i){
                flowersBloomed++;
                cout<<"inside outer if..bouqetsMade = "<<bouqetsMade<<" flowersBloomed="<<flowersBloomed;
                cout<<"flowersIn_a_Bouqet="<<flowersIn_a_Bouqet;
                if(flowersBloomed==flowersIn_a_Bouqet){
                    bouqetsMade++;
                    cout<<"inside inner if ..bouqetsMade = "<<bouqetsMade<<" flowersBloomed="<<flowersBloomed;
                    flowersBloomed=0;
                    if(bouqetsMade==TotalBouqets)
                        return i;
                }
            }
                else    
                    flowersBloomed=0;
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
    int Days=DaysToMake_M_bouqets_BS(v,k,m);
    cout<<"Days Required= "<<Days;
}