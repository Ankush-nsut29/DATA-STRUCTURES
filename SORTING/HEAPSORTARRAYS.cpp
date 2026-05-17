// ANKUSH MARWAHA 2025UCM2371
#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    //checks if left child is larget than part
    if(left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    //checks if right child is larger than parent 
    if(right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    //if largest was switched by left or right then swap and use haepify to fix any anomoly again
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapsort(int arr[], int size) {
//first make any simple array a heap
    for(int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
//now what we do is witch first means largest element weith the last one now largest is at last
//and use heapify to make the array heap again
    for(int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int data[] = {4, 5, 7, 8, 9, 334};
    heapsort(data, 6);
    
    for(int i = 0; i < 6; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    return 0;
}