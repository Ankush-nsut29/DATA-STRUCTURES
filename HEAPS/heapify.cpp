#include<bits/stdc++.h>
using namespace std;

void heapify(int heap[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && heap[left]>heap[largest]){
        largest=left;
    }
    if(right<=n && heap[right]>heap[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(heap[largest],heap[i]);
        heapify(heap,n,largest);
    }
}

int main() {
    // 1-based indexing array, so we put a dummy value at index 0 (e.g., -1)
    // The actual elements we want to build a heap from are 54, 53, 55, 52, 50
    int heap[] = {-1, 54, 53, 55, 52, 50};
    int n = 5; // Number of actual elements in the heap

    cout << "Array before building heap:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    // Build a max heap by calling heapify starting from the last non-leaf node down to the root
    for (int i = n / 2; i > 0; i--) {
        heapify(heap, n, i);
    }

    cout << "Array after building max heap:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    return 0;
}