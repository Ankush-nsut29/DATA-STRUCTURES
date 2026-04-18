#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int size){
    // --- Swap-Based Insertion Sort Logic ---
    // 1. The array is logically divided into a "sorted" left part and an "unsorted" right part.
    // 2. We assume the first element (index 0) is already sorted.
    // 3. We iterate through the unsorted part starting from index 1.
    // 4. For each element, we compare it to the adjacent element on its left.
    // 5. If it is smaller, we swap them. We keep swapping the element leftwards 
    //    until it reaches its correct sorted position (or the start of the array).

    // Start from the second element (index 1), assuming the first element is already sorted
    for(int i = 1; i < size; i++){
        // 'j' keeps track of the current element's index as it moves backwards
        int j = i;

        // Continue moving the element to the left as long as it's smaller 
        // than the element before it (arr[j-1]) and we haven't reached the start (j > 0)
        while(j > 0 && arr[j-1] > arr[j]){
            // Swap the current element with the larger element on its left
            swap(arr[j],arr[j-1]);
            // Move our index one step to the left to continue checking
            j = j - 1;
        }
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
