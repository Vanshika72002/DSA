#include<iostream>
using namespace std;
void display(int arr[],int d,int i){
    cout<<endl<<endl<<"The queue is \n";
    for(int iter=d;iter<i;iter++){
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
    while(ch){
        cout<<"What operation would you like to perform?\n";
        cout<<"0.Nothing\n1.Push\n2.Pop\n3.Size\n4.Top\n";
        cin>>ch; 
        switch(ch){
            case 0: break;
            case 1:{
                if(i==n)
                    cout<<"no space in queue "<<(d)<<" elements deleted";
                else{  
                     cout<<"enter element\n";
                    cin>>el;  
                    arr[i++]=el;
                    if(d==-1)
                        d=0;
                }                
                display(arr,d,i);
                break;
            } 
            case 2:{
                
                if(d==-1 || d==i)
                    cout<<"queue is empty";
                else    
                    d++;
                display(arr,d,i);
                break;
            }
            case 3:{
                if(d==-1)
                    cout<<"size=0";
                else
                    cout<<"\nsize ="<<(i-d)<<endl;
            }
            case 4:{
                if(d==-1)
                    cout<<"\nno element pushed in queue\n";
                else if(d==n)
                    cout<<"all elements deleted\n";
                else    
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