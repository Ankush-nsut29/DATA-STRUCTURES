#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next; 
};
void traverse(struct Node* &head){
    struct Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
void enqueue(struct Node* &head, struct Node* &rear, int val){
    Node* newn = new struct Node();
    newn->data=val;
    newn->next=nullptr;
    
    if(head==nullptr){
        head=newn;
        rear=newn;
    }
    else{
        rear->next=newn;
        rear=rear->next;
    }
}
void dequeue(struct Node* &head){
    if(head==nullptr) return;
    Node* temp = head;
    head=head->next;
}
int main(){
    Node* head = nullptr;
    Node* rear = nullptr;
    enqueue(head, rear, 10);
    enqueue(head, rear, 20);
    enqueue(head, rear, 30);
    traverse(head);
    dequeue(head);
    traverse(head);
}