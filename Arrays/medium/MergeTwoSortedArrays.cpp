#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<math.h>
void Merge(vector<int> &first,vector<int> &second){
        int size1=first.size();
        int size2=second.size();
        int len=size1+size2;
        // int minsize=min(size1,size2);
        // int count=0;
        // //optimal 1
        // int maxonleft=first[size1-1];
        // int maxindex=size1-1;
        // int minindex=0;
        // int minonright=second[0];
        // while(count<minsize){
        //     if(first[maxindex]>second[minindex]){
        //         swap(first[maxindex],second[minindex]);
        //     }
        //     else{
        //         break;
        //     } 
        //     maxindex--;
        //     minindex++;
        //     count++;
        // }
        // sort(first.begin(),first.end());
        // sort(second.begin(),second.end());
        
        //OPTIMAL2 
        //Gap method
        
        int gap=(len/2)+(len%2);
        int gap1count=0;
        while(1){
            // if(gap1count==1)
            //     break;
            // if(gap==1)
            //     gap1count++;
            int left=0;
            int right=left+gap;
            while(right<len){
                if(right<size1&&left<size1){
                    if(first[left]>first[right])
                    {
                        swap(first[left],first[right]);
                    }
                }
                else if(right>=size1 && left < size1){
                    if(second[right-size1]<first[left]){
                        swap(second[right-size1],first[left]);
                    }
                }
                //both on right array
                else if(left>=size1){
                    if(second[right-size1]<first[left-size1]){
                        swap(second[right-size1],first[left-size1]);
                    }
                }
                left++;
                right++;
            }
            if(gap==1)
                break;
            gap=(gap/2)+(gap%2);
        }
        
        
        for(int i=0;i<size2;i++){
            cout<<second[i]<<" ";
        }
        cout<<endl;
        for(int i=size1,j=0;j<size2;i++,j++){
            
            first[i]=second[j];
        }
        cout<<endl;
        for(int i=0;i<len;i++){
            cout<<first[i]<<" ";
        }


}
int main(){
    vector<int> nums1;
    vector<int> nums2;
    int n;
    int x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        nums1.push_back(x);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        nums2.push_back(x);
    }
    Merge(nums1,nums2);
    return 1;

}