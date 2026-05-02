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

Node* insertion(Node* root, int val){
    Node* newNode = new Node(val);

    // Case 1: The tree is empty. The new node becomes the new root.
    if (root == nullptr) {
        return newNode;
    }

    Node* curr = root;
    Node* parent = nullptr; // This will track the parent of the insertion point

    // Case 2: The tree is not empty. Find the correct spot to insert.
    while (curr != nullptr) {
        parent = curr; // Update the parent before moving down
        if (val < curr->data) {
            curr = curr->left;
        } else { // Includes duplicates, which go to the right subtree
            curr = curr->right;
        }
    }

    // At this point, `curr` is nullptr, and `parent` is the node to attach to.
    // Link the new node to its parent.
    if (val < parent->data) {
        parent->left = newNode;
    }
    else{
        parent->right = newNode;
    }

    // Return the original root pointer (it only changes if the tree was initially empty)
    return root;
}

int main(){
    // Start with an empty tree and use your insertion function to build it!
    Node* root = nullptr;
    root = insertion(root, 4);
    root = insertion(root, 1);
    root = insertion(root, 6);
    root = insertion(root, 5);
    root = insertion(root, 2);

    inorder(root);
    cout<<endl;
    // You must capture the returned root in case the tree was initially empty.
    root = insertion(root,3);
    inorder(root);
    cout<<endl;

}