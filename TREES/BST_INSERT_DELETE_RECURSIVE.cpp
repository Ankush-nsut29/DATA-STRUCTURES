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

// Helper function: Finds the smallest value in a subtree.
// We need this specifically for Case 3 (Two Children).
Node* minValueNode(Node* root) {
    Node* current = root;
    // Keep going left until we hit a dead end
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* deletion(Node* root, int val) {
    // BASE CASE: If the tree is empty or we didn't find the value
    if (root == nullptr) {
        return root;
    }

    // --- PHASE 1: SEARCHING ---
    // This is identical to your insertion logic!
    if (root->data > val) {
        // The value is smaller, go left. "Catch" the updated subtree.
        root->left = deletion(root->left, val);
    }
    else if (root->data < val) {
        // The value is larger, go right. "Catch" the updated subtree.
        root->right = deletion(root->right, val);
    }
    
    // --- PHASE 2: DELETING ---
    // If root->data == val, we found the node we want to delete!
    else {
        // CASE 1 & CASE 2: The node has 0 or 1 child
        // If there is no left child, bypass this node and return the right child
        if (root->left == nullptr) {
            Node* temp = root->right; // Save the child (might be nullptr if it's a leaf)
            delete root;              // Delete the current node to prevent memory leaks
            return temp;              // Return the child to the parent (Catch and Return!)
        }
        // If there is no right child, bypass this node and return the left child
        else if (root->right == nullptr) {
            Node* temp = root->left;  // Save the child
            delete root;              // Free memory
            return temp;              // Return the child to the parent
        }

        // CASE 3: The node has TWO children
        // We cannot just delete it, or we lose two subtrees!
        
        // Step A: Find the "In-order Successor" 
        // (The smallest value in the right subtree)
        Node* temp = minValueNode(root->right);

        // Step B: Copy the successor's data into the current node.
        // We are NOT deleting the current node, just replacing its value!
        root->data = temp->data;

        // Step C: Delete the successor from the right subtree.
        // Since we copied its value, we don't need the original successor node anymore.
        // The successor will ALWAYS be Case 1 or Case 2, so this is safe.
        root->right = deletion(root->right, temp->data);
    }
    
    // Finally, return the current root back up the call stack
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
    a->left=c;
    a->right=d;

    inorder(root);
    cout<<endl;
    insertion(root,3);
    inorder(root);
    cout<<endl;

}