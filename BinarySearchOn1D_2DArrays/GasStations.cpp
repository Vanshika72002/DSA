#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
using namespace std;
//BruteForce Approach👇
// void minOfMax(vector<int> positions,int newGasStations){
//     int ExistingStations=positions.size();
//     vector<int> sections(ExistingStations-1,0);
//     for(int i=1;i<=newGasStations;i++){
//         long double max=INT_MIN;
//         long double sectionLength;
//         long double placeAtSection;
//         for(int j=0;j<ExistingStations-1;j++){
//             if(sections[j]>0){
//                 long double diff=positions[i+1]-positions[i];
//                 sectionLength=(diff)/(long double)(sections[j]+1); 
//             }
//             else{
//                 sectionLength=positions[j+1]-positions[j];   
//             }
//             if(sectionLength>max){
//                 max=sectionLength;
//                 placeAtSection=j;
//             }
//         }
//         sections[placeAtSection]++;
//     }
//     for(int i=0;i<ExistingStations-1;i++){
//         cout<<"Gas stations at section "<<i+1<<":"<<sections[i]<<endl;
//     }
//     long double max=INT_MIN;
//     for(int i=0;i<ExistingStations-1;i++){
//         long double diff=positions[i+1]-positions[i];
//         long double sectionLength=(diff)/(long double)(sections[i]+1);
//         if(max<sectionLength)
//             max=sectionLength;
//     }
//     cout<<"the maximum of the minimized section length is"<<max;
// }
//Better USING PRIORITY QUEUE
void minOfMax(vector<int> positions,int newGasStations){
    priority_queue<pair<long double,int>> pq;
    int ExistingStations=positions.size();
    vector<int> howmany(ExistingStations-1,0);
    vector<int> secLength;
    // for(int i=0;i<ExistingStations-1;i++){
    //     secLength[i]=positions[i+1]-positions[i];
    //     pair<long double,int> p;
    //     p.first=secLength[i];
    //     p.second=i;
    //     pq.push(p);
    // }replaced by:

    for(int i=0;i<ExistingStations-1;i++){
        pq.push({positions[i+1]-positions[i],i});
    }

    // for(int i=1;i<=newGasStations;i++){
    //     cout<<"inside loop";
    //     long double max=INT_MIN;
    //     long double sectionLength;
    //     // long double placeAtSection;
    //     long double placeAtSection=pq.top().second;
    //     pq.pop();
    //     howmany[placeAtSection]++;
    //     int newSecLength=secLength[placeAtSection]/(howmany[placeAtSection]+1);
    //     pair<long double,int> p;
    //     p.first=newSecLength;
    //     p.second=placeAtSection;
    //     pq.push(p);
    // }
     for(int i=1;i<=newGasStations;i++){
        cout<<"inside loop";
        long double placeAtSection=pq.top().second;
        pq.pop();
        howmany[placeAtSection]++;
        long double initial_diff=positions[placeAtSection+1]-positions[placeAtSection];
        long double newSecLength=initial_diff/(long double)(howmany[placeAtSection]+1);
        
        pq.push({newSecLength,placeAtSection});
    }
    for(int i=0;i<ExistingStations-1;i++){
        cout<<"Gas stations at section "<<i+1<<":"<<howmany[i]<<endl;
    }
    // for(int i=0;i<ExistingStations-1;i++){
    //     long double diff=positions[i+1]-positions[i];
    //     long double sectionLength=(diff)/(long double)(howmany[i]+1);
    //     if(max<sectionLength)
    //         max=sectionLength;
    // }
    long double max=pq.top().first;
    cout<<"the maximum of the minimized section length is"<<max;
}
int main(){

    int N;      //number of existing gasStation;
    int k;      //number of gasStations to be placed
    int temp;
    vector<int> positions;
    cout<<"number of existing gas stations";
    cin>>N;
    cout<<"Number of new gas stations";
    cin>>k;
    cout<<"gas stations position\n";
    for(int i=0;i<N;i++){
        cin>>temp;  
        positions.push_back(temp);
    }
    sort(positions.begin(),positions.end());
    minOfMax(positions,k);
    // cout<<"\nresult="<<result;
}