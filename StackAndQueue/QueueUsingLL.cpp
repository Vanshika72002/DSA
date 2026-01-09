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
void displayQueue(Node *head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->el<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){

    Node *start=nullptr;
    Node *end=nullptr;
    int el;
    int ch=1;
    int cnt=-1;
    int Size=0;
    while(1){
        cout<<"What operation would you like to perform?\n";
        cout<<"0.Nothing\n1.Push\n2.Pop\n3.Size\n4.Top\n";
        cin>>ch; 
        switch(ch){
            case 0: return 0;
            case 1:{
                cout<<"enter element\n";
                cin>>el;
                if(!start){
                    start=new Node(el);
                    end=start;
                }else{
                    Node *newNode=new Node(el);
                    end->next=newNode;
                    end=newNode;
                }
                Size++;
                displayQueue(start);
                break;
            } 
            case 2:{
                if(!start){
                    cout<<"No element to pop";
                }else{
                    cout<<start->el<<" popped\n";
                    Size--;
                    Node *temp=start;
                    start=start->next;
                    delete temp;
                }
                displayQueue(start);
                break;
            }
            case 3:{
                cout<<"\nsize ="<<Size<<endl;
                break;
            }
            case 4:{
                if(start)
                    cout<<"\ntop= "<<start->el<<endl;
                else    
                    cout<<"The queue is empty\n";
                break;
            }
            default:{
                cout<<"Please enter 0/1/2/3/4";
                break;
           }     
        }
    }
    
}