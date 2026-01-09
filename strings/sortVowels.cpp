#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool isVowel(char ch){
    ch=tolower(ch);
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
        return true;
    }return false;
}
string sortVowels(string s) {
    int len=s.length();
    vector<int> indexes;
    vector<char> vowels;
    for(int i=0;i<len;i++){
        if(isVowel(s[i])){
            indexes.push_back(i);
            vowels.push_back(s[i]);
        }
    }
    cout<<endl<<endl;
    sort(vowels.begin(),vowels.end());
    for(int i=0;i<indexes.size();i++){
        s[indexes[i]]=vowels[i];
    }
    return s;
}
int main(){
    cout<<sortVowels("lEetcOde");
}