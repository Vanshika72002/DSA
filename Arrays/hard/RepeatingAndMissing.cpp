
#include<iostream>
#include<bitset>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
vector<int> RepeatingAndMissing(vector<int> v){
    long long n=v.size();
    //Brute Force
    int count=0;
    long long missingElement;
    long long repeatingElement;
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<n;j++){
    //         if(i==v[j]){
    //             count++;
    //         }
    //     }
    //     if(count==0)
    //         missingElement=i;
    //     else if(count==2)
    //         repeatingElement=i;
    //     count=0;
    // }
    // unordered_map<int,int> mpp(n,0);
    //hash array
    // int hash[n+1]={0};
    // for(int i=0;i<n;i++){
    //     hash[v[i]]++;
    // }
    // for(int i=1;i<=n;i++){
    //     if(hash[i]==2)
    //         repeatingElement=i;
    //     else if(hash[i]==0)
    //         missingElement=i;
    // }
    //self
    // int sumofNnaturals=(n*(n+1))/2;
    // int sum=0;
    // for(int i=0;i<n;i++){
    //     sum+=v[i];
    // }
    // cout<<sum<<" "<<sumofNnaturals;
    // //searching for repeating element
    // int hash[n+1]={0};
    // for(int i=0;i<n;i++){
    //     hash[v[i]]++;
    // }
    // for(int i=1;i<=n;i++){
    //     if(hash[i]==2)
    //         repeatingElement=i;
    // }
    // missingElement=sumofNnaturals-sum+repeatingElement;
    //OPTIMAL 1
    // 👇 not working
    // long long sumNaturals=(n*(n+1))/2;
    // long long sumNaturalsSquare=(n*(n+1)*((2*n)+1))/6;
    // long long sumarray=0;
    // long long sumarraysquares=0;
    // for(int i=0;i<n;i++){
    //     sumarray+=v[i];
    //     sumarraysquares+=(v[i]*v[i]);
    // }
    // long long sumsquare_Difference=sumarraysquares-sumNaturalsSquare;
    // long long difference=sumarray-sumNaturals;
    // long long sum=sumsquare_Difference/difference;
    // missingElement=(sum+difference)/2;
    // repeatingElement=sum-missingElement;
    // return {(int)missingElement,(int)repeatingElement};
    //
    // long long n = v.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    //👇striver's code :- not working
    // Calculate S and S2:
    // long long S = 0, S2 = 0;
    // for (int i = 0; i < n; i++) {
    //     S += v[i];
    //     S2 += (long long)v[i] * (long long)v[i];
    // }

    // //S-Sn = X-Y:
    // long long val1 = S - SN;

    // // S2-S2n = X^2-Y^2:
    // long long val2 = S2 - S2N;

    // //Find X+Y = (X^2-Y^2)/(X-Y):
    // val2 = val2 / val1;

    // //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // // Here, X-Y = val1 and X+Y = val2:
    // long long x = (val1 + val2) / 2;
    // long long y = x - val1;

    // return {(int)x, (int)y};

    //OPTIMAL 2
    int Xor=0;
    for(int i=0;i<n;i++){
        Xor^=v[i];
        Xor^=(i+1);
    }
    string x= bitset<8>(Xor).to_string();
    int len=x.size();   //length of the binary converted value of xor
    int differentiatingBit=-1;
    for(int i=len-1;i>=0;i--){
        cout<<"x["<<i<<"]="<<x[i]<<endl;
        // ❌👇not entering into this 
        if(x[i]==1){
            cout<<"condition true i="<<i;
            differentiatingBit=i;
            break;
        }
    }
    cout<<"diff bit="<<differentiatingBit<<"  ";
    vector<int> zeroclub;
    vector<int> oneclub;
    int zeroclubxor=0;
    int oneclubxor=0;
    for(int i=0;i<n;i++){
        if(bitset<8>(v[i]).to_string()[differentiatingBit]==1){
            oneclubxor^=v[i];
            oneclub.push_back(v[i]);
        }    
        else{
            zeroclub.push_back(v[i]);
            zeroclubxor^=v[i];
        }
        if(bitset<8>(i+1).to_string()[differentiatingBit]==1){
            oneclubxor^=(i+1);
            oneclub.push_back(i+1);
        }
        else{    
            zeroclubxor^=(i+1);
            zeroclub.push_back(i+1);
        }
    }
    // int count=0;
    for(int i=0;i<n;i++){
        if(v[i]==zeroclubxor){
            count++;  
        }
    }
    int repeating;
    int missing;
    if(count==0){
        missing=zeroclubxor;
        repeating=oneclubxor;
    }
    else{
         missing=oneclubxor;
        repeating=zeroclubxor;
    }
    return {repeating,missing};
}
int main(){
    vector<int> nums;
    int n;
    int x;
    cin>>n;
    int ans[n];
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    vector<int> resultvec=RepeatingAndMissing(nums);
    cout<<resultvec[0]<<" "<<resultvec[1]<<endl;
    return 1;
}