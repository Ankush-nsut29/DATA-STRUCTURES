#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int size){
    // The main logic of Insertion Sort:
    // Think of it like sorting a hand of playing cards.
    // You pick one card at a time from the unsorted deck and insert it 
    // into its correct position among the already sorted cards in your hand.
    // The array is virtually split into a sorted part (left) and an unsorted part (right).

    // --- Outer loop ---
    // We start at index 1 because we assume the first element (index 0) 
    // is already a "sorted" portion of one item.
    for(int i = 1; i < size; i++){
        // 'key' is the current element we want to pick up and insert into the sorted part.
        int key = arr[i];
        
        // 'j' points to the last element of the sorted part (right before 'i').
        int j = i - 1;

        // --- Inner loop (Shifting) ---
        // We look at the sorted part from right to left (j goes down to 0).
        // If the element we are looking at (arr[j]) is greater than our 'key',
        // it means the 'key' belongs further to the left.
        // So, we shift arr[j] one position to the right to make room.
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j]; // Shift element to the right
            j = j - 1;           // Move to the next element on the left
        }
        
        // Once we find an element smaller than the 'key' (or reach the beginning),
        // we have found the correct empty slot (j + 1) to insert our 'key'.
        arr[j + 1] = key;
    }
}

void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int a[4] = {4, 1, 3, 2};
    sort(a, 4);
    display(a, 4);
    return 0;
}
