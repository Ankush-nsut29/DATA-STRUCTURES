#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next; 
};

void traverse(struct Node* &head){
    struct Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<endl;
        curr=curr->next;
    }
}

void insert(struct Node* &head,int val,int pos){
    struct Node* newn=new struct Node();
    newn->data=val;
    newn->next=nullptr;
    if(pos==1){
        newn->next=head;
        head=newn;
    }
    else{
        struct Node* curr=head;
        for(int i=0;i<pos-2;i++){
            curr=curr->next;
        }
        newn->next=curr->next;
        curr->next=newn;
    }
}

void del(struct Node* &head,int pos){
    if(pos==1){
        head=head->next;
    }
    else{
        struct Node* curr=head;
        for(int i=0;i<pos-2;i++){
            curr=curr->next;
        }
        curr->next=(curr->next)->next;

    }
}

int main(){
    struct Node* c = new struct Node();
    c->data=40;
    c->next=nullptr;

    struct Node* b = new struct Node();
    b->data=30;
    b->next=c;

    struct Node* a = new struct Node();
    a->data=20;
    a->next=b;
    
    struct Node* head = new struct Node();
    head->data=10;
    head->next=a;
    insert(head,3,300);
    del(head,2);
    traverse(head);
}

