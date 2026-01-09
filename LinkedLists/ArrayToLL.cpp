#include<iostream>
using namespace std;
class Node{
    int el;
    Node* next;
    public:
    Node(int el){
        this->el=el;
        this->next=nullptr;
    }
    Node(int el,Node *next){
        this->el=el;
        this->next=next;
    }
};
int main(){
    
}