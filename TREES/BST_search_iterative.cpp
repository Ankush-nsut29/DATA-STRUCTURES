#include<bits/stdc++.h>
using namespace std;

// Structure representing a single node in the tree
struct Node{
    int data;
    Node* left=nullptr;
    Node* right=nullptr;

    Node(int val) {
        data = val;
    }
};

// Inorder traversal: visits Left child, then Root, then Right child
void inorder(Node* root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

// Iterative approach to search for a value in a Binary Search Tree
Node* search(Node* root,int val){
    Node* curr=root; // Start the search from the root of the tree
    
    while(curr!=nullptr){
        // Target found
        if(curr->data==val){
            return curr;
        }
        // If the target is smaller than current data, move to the left child
        else if(curr->data>val){
            curr=curr->left;
        }
        // If the target is larger than current data, move to the right child
        else{
            curr=curr->right;
        }
    }
    // If the loop finishes and we haven't returned, the value isn't in the tree
    return nullptr;
}

int main(){
    // Manually constructing a sample tree
    Node* root = new Node(4);
    Node* a = new Node(1);
    Node* b = new Node(6);
    Node* c = new Node(5);
    Node* d = new Node(2);

    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;

    // Print tree contents
    inorder(root);
    cout<<endl;
    
    // Search for a value that does NOT exist in the tree
    Node* m = search(root,9);
    if(m!=nullptr){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }

    // Search for a value that DOES exist in the tree
    Node* n = search(root,1);
    if(n!=nullptr){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
}