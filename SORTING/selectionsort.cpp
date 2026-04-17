#include <bits/stdc++.h>
using namespace std;

void sort(int arr[],int size){
    for(int i = 0;i<size;i++){
        // The main logic of Selection Sort:
        // In each pass, find the minimum element from the unsorted part of the array
        // and swap it with the element at the current position.

        // --- Outer loop ---
        // This loop iterates from the beginning of the array to the end.
        // 'i' marks the boundary between the sorted part (left) and the unsorted part (right).
        
        // Assume the first element of the unsorted part is the smallest.
        // 'mini' will store the index of the smallest element found so far.
        int mini = i;

        // --- Inner loop ---
        // This loop iterates through the unsorted part of the array (from i+1 to the end)
        // to find the actual smallest element.
        for(int j = i + 1; j < size; j++){
            // If we find an element smaller than our current minimum...
            if(arr[j] < arr[mini]){ // BUG FIX: Was arr[j] < arr[i], now correctly compares with the smallest found so far.
                // ...we update 'mini' to be the index of that new smallest element.
                mini = j;
            }
        }
        // After the inner loop, 'mini' holds the index of the smallest element in the unsorted part.
        // We swap it with the first element of the unsorted part (at index 'i').
        swap(arr[mini], arr[i]);
    }
}

void display(int arr[],int size){
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int a[4]={1,4,3,2};
    sort(a,4);
    display(a,4);
}