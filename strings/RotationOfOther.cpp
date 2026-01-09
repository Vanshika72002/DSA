#include<iostream>
#include<string>
using namespace std;
bool rotateString(string s, string goal) {
        int len=s.length();
        if(goal.length()!=len)
            return false;
        int numberOfRotations=1;
        bool flag;
        while(numberOfRotations<len){
            cout<<"number of rotations= "<<numberOfRotations;
            flag=true;
            for(int i=0;i<len;i++){
                if(goal[i]!=s[(i+numberOfRotations)%len]){
                    cout<<"goal[i]= "<<goal[i]<<" ";
                    cout<<"s[(i+numberOfRotations)%len])"<<s[(i+numberOfRotations)%len]<<endl;
                    flag=false;
                    break;
                }
            }
            cout<<"flag="<<flag;
            if(flag)
                return true;
            numberOfRotations++;
        }
        return false;
    }
int main(){
    cout<<rotateString("abcde","cdeab");
    char ch=0+'a';
    cout<<ch;
}