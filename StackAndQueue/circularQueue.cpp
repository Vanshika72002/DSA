#include<iostream>
using namespace std;
void display(int arr[],int d,int i){
    if(d==-1){
        cout<<"queue is empty";
        return;
    }cout<<endl<<endl<<"The queue is \n";
    for(int iter=d;iter<=i;iter++){
        cout<<arr[iter]<<" ";
    }cout<<endl;
}
int main(){

    int n;
    cout<<"size of queue?\n";
    cin>>n;
    int arr[n];
    int el;
    int ch=1;
    int cnt=-1;
    int i=0;
    int d=-1;
    int currSize=0;
    while(ch){
        cout<<"What operation would you like to perform?\n";
        cout<<"0.Nothing\n1.Push\n2.Pop\n3.Size\n4.Top\n";
        cin>>ch; 
        switch(ch){
            case 0: break;
            case 1:{
                
                if(currSize==n){
                    cout<<"the queue is full\n";
                    break;
                }
                cout<<"enter ele";
                int el;
                cin>>el;
                if(d==-1)
                    d=0;
                else    
                    i=(i+1)%n;
                arr[i]=el;
                currSize++;
                display(arr,d,i);
                break;
            } 
            case 2:{
                
                if(currSize==0){
                    cout<<"No element in queue";
                    break;
                }
                cout<<"element popped:"<<arr[d];
                if(currSize==1){    //currsize=1 ==> the start is pointing at the first and the last element this means we cant move the start pointer ahead 
                    i=0;
                    d=-1;//returned to the initial configuration
                }else{
                    d=(d+1)%n;
                }
                currSize--;
                display(arr,d,i);
                break;
            }
            case 3:{
                cout<<"size="<<currSize<<endl;
            }
            case 4:{
                cout<<"top:"<<arr[d]<<endl;
            }
            default:{
                cout<<"\nPlease enter 0/1/2/3/4\n";
                break;
            }     
        }
        cout<<"Would you like to continue(enter 0 to exit)\n";
        cin>>ch;
    } 
}