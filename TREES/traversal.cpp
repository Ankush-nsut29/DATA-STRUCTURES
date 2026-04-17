#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left=nullptr;
    Node* right=nullptr;

    Node(int val) {
        data = val;
    }
};

void preorder(Node* root){
    if(root!=nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if(root!=nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void inorder(Node* root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    Node* root = new Node(4);
    Node* a = new Node(1);
    Node* b = new Node(6);
    Node* c = new Node(5);
    Node* d = new Node(2);

    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;

    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
}