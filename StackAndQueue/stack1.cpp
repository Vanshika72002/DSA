#include<iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter the size of stack";
    cin>>n;
    int arr[n];
    int el;
    int ch=1;
    int cnt=-1;
    while(ch){
        cout<<"What operation would you like to perform?\n";
        cout<<"0.Nothing\n1.Push\n2.Pop\n3.Size\n4.Top\n";
        cin>>ch; 
        switch(ch){
            case 0: break;
            case 1:{
                cout<<"enter element\n";
                cin>>el;
                arr[++cnt]=el;
                break;
            } 
            case 2:{
                if(cnt>=0)
                    cnt--;
                else   
                    cout<<"\nNothing to pop\n";
                break;
            }
            case 3:{
                cout<<"\nsize ="<<(cnt+1)<<endl;
                break;
            }
            case 4:{
                if(cnt>=0){
                    cout<<endl<<arr[cnt]<<endl;
                    break;
                }else{
                    cout<<"The stack is empty";
                    break;
                }
            }
            default:{
                cout<<"Please enter 0/1/2/3/4";
                break;
           }     
        }
        cout<<"Would you like to continue(enter 0 to exit)\n";
        cin>>ch;
    }
    
}