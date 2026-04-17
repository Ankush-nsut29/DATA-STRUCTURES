#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
};

void push(Node* &head,int data){
    Node* newn = new Node();
    newn->val=data;
    newn->next=head;
    head=newn;
}

void pop(Node* &head){
    if(head==nullptr){
        cout<<"underflow\n";
        return;
    }
    else{
        Node* temp = head;
        head=head->next;
        delete temp;
    }
}

void traverse(Node* &head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
int main(){
    Node* head = nullptr;
    push(head, 10);
    push(head, 20);
    push(head, 30);
    traverse(head); // Expected output: 30 20 10 
    
    pop(head);
    traverse(head); // Expected output: 20 10
    return 0;
}