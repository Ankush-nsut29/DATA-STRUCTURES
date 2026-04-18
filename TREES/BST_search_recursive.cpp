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

// Recursive approach to search for a value in a Binary Search Tree
Node* search(Node* root,int val){
    Node* curr=root; // Start the search from the current root/node
    
    // Base case: if we reach a null node, the value isn't in the tree
    if(curr==nullptr){
        return nullptr;
    }
    // Target found
    if(curr->data==val){
        return curr;
    }
    // If the target is smaller than current data, recursively search the left child
    else if(curr->data>val){
        return search(curr->left,val);
    }
    // If the target is larger than current data, recursively search the right child
    else{
        return search(curr->right,val);
    }
    // Fallback return (unreachable due to if/else-if/else coverage above)
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