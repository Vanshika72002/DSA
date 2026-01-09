#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
    Node(int data,Node *prev,Node *next){
        this->data=data;
        this->prev=prev;
        this->next=next;
    }
    void displayLL(){
        
        cout<<"LL:\n";
        // cout<<this;
        Node *temp=this;
        // cout<<"(temp==nullptr)"<<(temp==nullptr)<<endl;
        while(temp!=nullptr){
            
            cout<<temp->prev<<" "<<temp<<" "<<temp->data <<" "<<temp->next;
            cout<<endl;
            temp=temp->next;
        }
    }
    Node *deleteHead(Node *head){
        if(head==nullptr||head->next==nullptr){
            delete head;
            return nullptr;
        }
        Node *temp=head;
        head->next->prev=nullptr;
        head=head->next;
        temp->next=nullptr;
        delete temp;
        return head;
    }
    Node *deleteTail(Node *head){
        if(head==nullptr||head->next==nullptr){
            delete head;
            return nullptr;
        }
        Node *temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->prev->next=nullptr;
        temp->prev=nullptr;
        delete temp;
        return head;
    }
    Node *deleteKthElement(Node *head,int k){
        if(head==NULL)
            return nullptr;
        if(k==1){   //or if(temp->prev==nullptr)
            head=deleteHead(head);
            return head;
        }
        Node *temp=head;
        int cnt=1;
        while(cnt!=k){
            temp=temp->next;
            cnt++;
        }
        //directly delete temp if(temp->prev==null && temp->next==null )
        if(temp->next==nullptr){
            head=deleteTail(head);
            return head;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        temp->next=nullptr;
        temp->prev=nullptr;
        delete temp;
        return head;
    }
    Node *deleteNode(Node *temp){
        Node *prev=temp->prev;
        Node *next=temp->next;
        if(next!=nullptr){
            //LAST NODE
            next->prev=prev;
        }
        prev->next=next;
        temp->next=temp->prev=nullptr;
        delete temp;
    }
    Node *insertBeforeHead(Node *head,int val){
        Node *newNode=new Node(val,nullptr,head);
        head->prev=newNode;
        
        return newNode;
    }
    Node *insertBeforeTail(Node *head,int val){
        
        if(head->next==nullptr){
            head=insertBeforeHead(head,val);
            return head;
        }
            
        Node *temp=head;
        while(temp->next!=nullptr)
            temp=temp->next;
        Node *prev=temp->prev;
        Node *newNode=new Node(val,prev,temp);
        prev->next=newNode;
        temp->prev=newNode;
           
        return head;
    }
    Node *insertBeforeKthNode(Node *head,int val,int k){
        int cnt=1;
        Node *temp=head;
        while(temp!=nullptr){
            if(cnt==k){
                if(cnt==1){
                    return insertBeforeHead(head,val);
                }
                break;
            }
            cnt++;
            temp=temp->next;
        }
        //temp is referring to kth node
        Node *prev=temp->prev;
        Node *newNode=new Node(val,prev,temp);
        prev->next=newNode;
        temp->prev=newNode;
        return head;
    }
    void insertBeforeGivenNode(Node *ptrToNode,int val){
        cout<<"inserting before"<<ptrToNode->data<<endl; 

        Node *newNode=new Node(val,ptrToNode->prev,ptrToNode);
        ptrToNode->prev->next=newNode;
        ptrToNode->prev=newNode;
    }
    Node *insertAtTail(Node *head,int val){
        if(head==nullptr)
            return new Node(val);
        Node *temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        Node *newNode=new Node(val,temp,nullptr);
        temp->next=newNode;
        return head;
    }
    Node *reverseDLL(Node *head){
        if(head==nullptr || head->next==nullptr)
            return head;
        // 👇🏼✔ 
        // Node *temp=head;
        // while(temp->next!=nullptr)
        //     temp=temp->next;
        // Node *newHead=temp;
        // while(temp != nullptr){
        //     Node *prev=temp->prev;
        //     temp->prev=temp->next;
        //     temp->next=prev;
        //     temp=prev;
        // }
        // head=newHead;
        // return head;
        // 👇🏼✔
        Node *temp=head;
        Node *newHead;
        while(temp != nullptr){
            if(temp->next==nullptr) 
                newHead=temp;
            Node *prev=temp->prev;
            temp->prev=temp->next;
            temp->next=prev;
            temp=temp->prev;
        }
        // return newHead; 
        // 👇🏼✔
        // Node *pseudohead=head;
        // Node *pseudotail=head;
        // while(pseudotail->next!=nullptr)
        //     pseudotail=pseudotail->next;
        // while(pseudohead->next!=pseudotail && pseudohead->next != pseudotail->prev){
        //     pseudohead->data=pseudohead->data+pseudotail->data;
        //     pseudotail->data=pseudohead->data-pseudotail->data;
        //     pseudohead->data=pseudohead->data-pseudotail->data;
        //     pseudohead=pseudohead->next;
        //     pseudotail=pseudotail->prev;
        // }
        // pseudohead->data=pseudohead->data+pseudotail->data;
        // pseudotail->data=pseudohead->data-pseudotail->data;
        // pseudohead->data=pseudohead->data-pseudotail->data;
        // cout<<"\n\nhead="<<head->data<<endl;
    }
};
int main(){
    int arr[7]={1,2,3,4,5,6,7};
    Node *head=new Node(arr[0]);
    Node *last=head;
    for(int i=1;i<7;i++){
        Node *curr=new Node(arr[i]);
        last->next=curr;
        curr->prev=last;
        last=curr;
    }
    head->displayLL();
    // head=head->deleteHead(head);
    // cout<<"deleted head";
    // head->displayLL();
    // cout<<"deleted tail";
    // head=head->deleteTail(head);
    // head->displayLL();
    // cout<<"deleted 2nd element\n";
    // head=head->deleteKthElement(head,5);
    // head->displayLL();
    // head->deleteNode(head->next->next->next->next);
    // head->displayLL();
    // head=head->insertBeforeHead(head,5);
    // head->displayLL();
    // head=head->insertBeforeTail(head,89);
    // head->displayLL();
    // head=head->insertBeforeKthNode(head,15,7);
    // head->displayLL();
    // head->insertBeforeGivenNode(head->next->next->next->next,90);
    // head->displayLL();
    // head->insertAtTail(head,8);
    head->reverseDLL(head);
    head->displayLL();
    

}