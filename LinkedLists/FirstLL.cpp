#include<iostream>
using namespace std;
class Node{

    public:
    Node *next;
    int data;
    Node(int data1,Node *next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
int length(Node *head){
    if(head==nullptr)
        return 0;
    int cnt=1;
    Node *temp=head;
    while(temp->next!=nullptr){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
void insertNodeAtEnd(Node *head,int data){
    //create node
    Node *newNode=new Node(data);
    Node *temp=head;
    while(temp->next !=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
}
// 👇🏼
Node* insertNodeAtStart(Node *head,int data){
    //create new node
    Node *newNode=new Node(data);
    newNode->next=head;
    head=newNode;
    return head;
}
// 👇🏼
Node *insertAtPosition(Node *head,int data,int pos){
    if(pos>length(head)){
        insertNodeAtEnd(head,data);
    }else if(pos==1){
        insertNodeAtStart(head,data);
    }else{
        int currPos=1;
        Node*temp=head;
        while(currPos!=pos-1){
            currPos++;
            temp=temp->next;
        }
        Node *newNode=new Node(data,temp->next);
        temp->next=newNode;
    }
}
void displayLL(Node *head){
    Node *temp=head;
    // cout<<"(temp==nullptr)"<<(temp==nullptr)<<endl;
    while(temp!=nullptr){
        
        cout<<temp<<" "<<temp->data <<" "<<temp->next;
        cout<<endl;
        temp=temp->next;
    }
}
Node *insertElbeforeValue(Node *head,int val,int el){
    Node *newNode=new Node(el);
    Node *temp=head;
    if(head==nullptr)
        return nullptr;
    if(head->data==val){
        head=newNode;
        head->next=temp;
        return head;
    }
    while(temp->next->data!=val){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}
// 👇🏼
Node* deleteElement(Node *head,int el){

    Node *temp=head;
    if(head->data==el){
        head=head->next;
        delete temp;
        return head;
    }
    while(temp->next!=nullptr && temp->next->data!=el){
        temp=temp->next;
    }
    if(temp->next){
        Node *nodetobedeleted=temp->next;
        temp->next=temp->next->next;
        delete nodetobedeleted;
    }
    return head;
}
// 👇🏼
Node* deleteHead(Node *head){
        Node *temp=head;
        head=head->next;
        delete temp;
        return head;

}
//delete last node or node at any position
Node* deleteNode(Node *head,int n){
    //nth node to be deleted
    //stop at (n-1)th node
    if(n==1){
       head=deleteHead(head);
    } else{
        Node *temp=head;
        int cnt=1;
        while(cnt!=n-1 && temp->next!=nullptr){
            cnt++;
            temp=temp->next;
        }
        Node *tobedeleted=temp->next;
        if(tobedeleted){
            temp->next=temp->next->next;
            delete tobedeleted;
        }
        
    }
    return head;
}

bool search(Node *head,int el){

    Node *temp=head;
    while(temp!=nullptr){
        if(temp->data==el)
            return true;
        temp=temp->next;
    }
    return false;
}
int main(){

    cout<<"creating LL with value 5\n";
    Node* head=new Node(5);
    displayLL(head);

    // cout<<node2<<endl;
    // cout<<node2->data<<endl;
    // cout<<node2->next<<endl;
    // cout<<node1<<endl;
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;


    // cout<<"inserting node with  value 3 at end\n";
    // insertNodeAtEnd(head,3);
    // displayLL(head);
    // cout<<"inserting node with  value 4 at position 2\n";
    // insertAtPosition(head,4,2);
    // displayLL(head);cout<<"inserting node with  value 2 at position greater than length of LL\n";
    // insertAtPosition(head,2,9);
    // displayLL(head);
    // cout<<"inserting node with  value 6 at start\n";
    // head=insertNodeAtStart(head,6);
    // displayLL(head);
    // cout<<"deleting element 6\n";
    // head=deleteElement(head,6);
    // displayLL(head);
    
    // cout<<"deleting element 3\n";
    // head=deleteElement(head,3);
    // displayLL(head);
    // cout<<"deleting head\n";
    // head=deleteHead(head);
    // displayLL(head);
    // cout<<"deeleting node at position 3\n";
    // head=deleteNode(head,3);
    // displayLL(head);
    // cout<<"deeleting node at position 2\n";
    // head=deleteNode(head,2);
    // displayLL(head);
    // cout<<"deeleting node at position 1\n";
    // head=deleteNode(head,1);
    // displayLL(head);
    // cout<<"Search(4) returned "<<search(head,4);

    // cout<<"length= "<<length(head)<<endl;

    // cout<<"deleting ";
    // head=deleteNode(head,1);
    // displayLL(head);
    head=insertElbeforeValue(head,5,4);
    head=insertElbeforeValue(head,4,3);
    head=insertElbeforeValue(head,4,2);
    displayLL(head);
    cout<<"length of LL="<<length(head);
    
    
}
//inserting a  node in LL
//given:head of LL.
//             _______________                  __________
// head        |data:5       |      Node1       | data:3 |
// (0x1f6ea0)  |next:0x1f6e90|      (0x1f6e90)  | next:0 |


