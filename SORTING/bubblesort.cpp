#include <bits/stdc++.h>
using namespace std;

void sort(int arr[],int size){
    // The main logic of Bubble Sort:
    // It repeatedly steps through the array, compares adjacent elements, 
    // and swaps them if they are in the wrong order (left is greater than right).
    // With each full pass, the largest unsorted element "bubbles up" to its correct position at the end.

    // --- Outer loop ---
    // This loop dictates how many passes we need to make. 
    // We need at most 'size - 1' passes to completely sort the array.
    for(int i = 0 ; i < size - 1 ; i++){
        
        // --- Inner loop ---
        // This loop performs the actual adjacent comparisons for the current pass.
        // The limit is 'size - i - 1' because after 'i' passes, the last 'i' elements are already sorted!
        for(int j = 0 ; j < size - i - 1 ; j++){
            // Compare the current element with the adjacent element to its right
            if(arr[j]>arr[j+1]){
                // If the left element is larger, swap them to push the larger value to the right
                swap(arr[j],arr[j+1]);
            }
        }
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