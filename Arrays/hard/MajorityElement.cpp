#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<int> Majority(vector<int> v){
    //BRUTE FORCE
    //*******At max there can be 2 elements in the final result***********//
    //******instead of checking using find() we can check the first element because there can be only 2 elements//
    int n=v.size();
    // vector<int> result;
    // for(int i=0;i<v.size();i++){
    //     cout<<"inside outer loop";
    //     int count=1;
    //     // if(find(result.begin(),result.end(),v[i])==result.end())
    //     if(result.size()==2){
    //         cout<<"size=2";
    //         break;
    //     }
    //     if(result.size()==0||result[0]!=v[i]){
    //         for(int j=i+1;j<v.size();j++){
    //             cout<<"inside inner loop";
    //             if(v[j]==v[i]){
    //                 count++;
    //             }
    //         }
    //     }
    //     if(count>n/3){
    //         result.push_back(v[i]);
    //         cout<<"pushing "<<v[i]<<" to result";
    //     }
        
    // }
    // return result;
    //BETTER
    // int n=v.size();
        vector<int> vec;
        // unordered_map<int,int> count;
        // for(int i=0;i<v.size();i++){
        //     // cout<<"loop";
        //     count[v[i]]+=1;
        //     for(auto iter:count){
        //         cout<<iter.first<<"->"<<iter.second;
        //     }
        //     if(vec.size()==0||vec[0]!=v[i]&&count[v[i]]==n/3+1){
        //         // cout<<"conditiion tredfbn";
        //         if(count[v[i]]==n/3+1){
        //             // cout<<v[i]<<"----->"<<count[v[i]];
        //             vec.push_back(v[i]);
                
        //         }if(vec.size()==2){
        //             // cout<<"true";
        //             break;
        //         }
        //     }
        // }
        // return vec;

       
        //OPTIMAL
        int el1=INT_MIN;
        int el2=INT_MIN;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(cnt1==0&&v[i]!=el2){
                el1=v[i];
                cnt1++;
            }
            else if(cnt2==0&&v[i]!=el1){
                el2=v[i];
                cnt2++;
            }
            else if(v[i]==el1){
                cnt1++;
            }
            else if(v[i]==el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(v[i]==el1){
                cnt1++;
            }
            else if(v[i]==el2){
                cnt2++;
            }
        }
        if(cnt1>=(int)(n/3)+1){
            vec.push_back(el1);
        }
        if(cnt2>=(int)(n/3)+1){
            vec.push_back(el2);
        }
        return vec;
}
int main(){
    vector<int> inp;
    vector<int> result;

    int n;
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        inp.push_back(x);
    }
    result=Majority(inp);
    cout<<endl<<endl;
    if(result.size()!=0){
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    }
    else{
        cout<<"there is no majoriy element";
    }

}
