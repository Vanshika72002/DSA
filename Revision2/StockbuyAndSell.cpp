#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
bool decreasingOrder(vector<int> vec){
    int N=vec.size();
    int i=0;
    while(i<N){
        if(vec[i]>vec[i+1])
            i++;
        else    
            return false;
    }
    return true;
}