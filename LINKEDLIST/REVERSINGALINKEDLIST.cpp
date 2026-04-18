#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next = nullptr ; 

    Node(int val){
        data=val;
    }
};

void reverse(Node* &head){
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* curr = head;

    while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;

        prev=curr;
        curr=next;
    }
    head=prev;
}

void traverse(Node* &head){
    struct Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<endl;
        curr=curr->next;
    }
}

int main(){
    Node* head = new Node(1);
    Node* a = new Node(2);
    Node* b = new Node(3);
    Node* c = new Node(4);

    head->next = a;
    a->next = b;
    b->next = c;
    
    reverse(head);
    traverse(head);

}