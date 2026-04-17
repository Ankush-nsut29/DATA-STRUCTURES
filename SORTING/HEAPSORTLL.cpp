#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void heapSortLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) return;

    vector<int> arr;
    Node* curr = head;

    while (curr != nullptr) {
        arr.push_back(curr->data);
        curr = curr->next;
    }

    make_heap(arr.begin(), arr.end()); 
    sort_heap(arr.begin(), arr.end()); 
    curr = head;
    for (int val : arr) {
        curr->data = val;
        curr = curr->next;
    }
}

void traverse(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr\n";
}

int main() {
   
    Node* head = new Node(40);
    head->next = new Node(10);
    head->next->next = new Node(30);
    head->next->next->next = new Node(50);
    head->next->next->next->next = new Node(20);

    cout << "Original List: ";
    traverse(head);

    heapSortLinkedList(head);

    cout << "Sorted List: ";
    traverse(head);

    return 0;
}