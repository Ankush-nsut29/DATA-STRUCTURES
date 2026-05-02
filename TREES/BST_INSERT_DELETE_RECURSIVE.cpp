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

void inorder(Node* root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

// Recursive function to insert a new value into the Binary Search Tree
Node* insertion(Node* root,int val){
    // Base case: If we reach an empty spot, this is where the new node belongs
    if(root==nullptr){
        return new Node(val);
    }
    
    // If the value to be inserted is smaller, it belongs in the left subtree
    if(root->data>val){
        // Recursively insert into the left subtree and "catch" the updated left child
        root->left=insertion(root->left,val);
    }
    // If the value is larger (or equal), it belongs in the right subtree
    else{
        // Recursively insert into the right subtree and "catch" the updated right child
        root->right=insertion(root->right,val);
    }
    // Return the (unchanged) root pointer back up the call stack to link the tree together
    return root;
}

Node* deletion(Node* root, int key){
    if(root==nullptr){
        return nullptr;
    }
    if(key>root->data){
        root->right=deletion(root->right, key);
    }
    else if(key<root->data){
        root->left=deletion(root->left, key);
    }
    else{
        if(root->left==nullptr){
            return root->right;
        }
        else if(root->right==nullptr){
            return root->left;
        }
        Node* curr = root->right;
        while(curr->left!=nullptr){
            curr=curr->left;
        }
        root->data=curr->data;

        root->right=deletion(root->right, root->data);
    }
    return root;
}

int main(){
    Node* root = new Node(4);
    Node* a = new Node(1);
    Node* b = new Node(6);
    Node* c = new Node(5);
    Node* d = new Node(2);

    root->left=a;
    root->right=b;
    b->left=c;
    a->right=d;

    inorder(root);
    cout<<endl;
    root = insertion(root,3);
    inorder(root);
    cout<<endl;
    root = deletion(root,4);
    inorder(root);
    cout<<endl;
}