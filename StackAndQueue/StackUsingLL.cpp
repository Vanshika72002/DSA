#include<iostream>
using namespace std;
class Node{
    
    public:
    int el;
    Node* next;
    Node(int el){
        this->el=el;
        this->next=nullptr;
    }
    Node(int el,Node *next){
        this->el=el;
        this->next=next;
    }
};
void displayStack(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->el<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){

    Node *sthead=nullptr;
    int el;
    int ch=1;
    int cnt=-1;
    int currSize=0;
    while(1){
        cout<<"What operation would you like to perform?\n";
        cout<<"0.Nothing\n1.Push\n2.Pop\n3.Size\n4.Top\n";
        cin>>ch; 
        switch(ch){
            case 0: return 0;
            case 1:{
                cout<<"enter element\n";
                cin>>el;
                if(!sthead)
                    sthead=new Node(el);
                else{
                    Node *newNode=new Node(el,sthead);
                    sthead=newNode;
                }
                currSize++;
                displayStack(sthead);
                break;
            } 
            case 2:{
                if(!sthead){
                    cout<<"No element to pop";
                }else{
                    cout<<sthead->el<<" popped\n";
                    currSize--;
                    Node *temp=sthead;
                    sthead=sthead->next;
                    delete temp;
                }
                displayStack(sthead);
                break;
            }
            case 3:{
                cout<<"\nsize ="<<currSize<<endl;
                break;
            }
            case 4:{
                if(sthead)
                    cout<<"\ntop= "<<sthead->el<<endl;
                else    
                    cout<<"The stack is empty\n";
                break;
            }
            default:{
                cout<<"Please enter 0/1/2/3/4";
                break;
           }     
        }
    }
    
}