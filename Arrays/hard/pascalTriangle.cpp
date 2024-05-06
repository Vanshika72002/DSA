//VARIATION I -
//Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
#include<iostream>
#include<vector>
using namespace std;
void Print_vec(vector<int> vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}
int var1(int row,int col){
    int iter=1;
    int result=1;
    while(iter<=col){
        result*=row;
        result/=iter;
        iter++;
        row--;
    }
    return result;
}
vector<int> var2(int row){
    //Brute force
    // for(int i=1;i<=row;i++){
    //     cout<<var1(row-1,i-1)<<" ";
    // }
    //Optimal
    vector<int> resultvec;
    int result=1;
    resultvec.push_back(result);
    for(int i=2;i<=row;i++){
        result*=(row+1-i);
        result/=(i-1);
        resultvec.push_back(result);
    }
    return resultvec;
}
vector<vector<int>> var3(int num){
    vector<vector<int>> result;
    //BRUTE FORCE
    // for(int i=1;i<=num;i++){
    //     vector<int> vec;
    //     for(int j=1;j<=i;j++){
    //         vec.push_back(var1(i-1,j-1));
    //     }
    //     result.push_back(vec);
    // }
    //BETTER
    for(int i=1;i<=num;i++){
        result.push_back(var2(i));
    }

    return result;
}
int main(){
    int row;
    int col;
    int n;// number of rows
    cout<<"Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal's triangle.\nVariation 2: Given the row number n. Print the n-th row of Pascal's triangle.\nVariation 3: Given the number of rows n. Print the first n rows of Pascal's triangle.\nChoose one of the above variations(1/2/3)";
    int choice;
    int x;
    cin>>choice;
    switch(choice){
        case 1: cin>>row;
                cin>>col;
                x=var1(row-1,col-1);
                cout<<x;
                break;
        case 2: {cin>>row;
                vector<int> var2result;
                var2result=var2(row);
                
                for(int i=0;i<var2result.size();i++){
                    cout<<var2result[i]<<" ";
                }}
                break;
        case 3: {cin>>n;
                vector<vector<int>> result=var3(n);
                for(int i=0;i<result.size();i++){
                    for(int j=0;j<result[i].size();j++){
                        cout<<result[i][j]<<" ";
                    }
                    cout<<endl;
                }
                break;}

        default: cout<<"choose correct option";   
    }

}