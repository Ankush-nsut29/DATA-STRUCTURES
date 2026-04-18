#include <bits/stdc++.h>
using namespace std;

// --- Partition Function ---
// This function takes the last element as a "pivot", places the pivot in its 
// correct sorted position, and moves all smaller elements to the left of the pivot 
// and all greater elements to the right.
int partition(int arr[],int low,int high){
    // We choose the last element in the current segment as our pivot
    int pivot = arr[high];
    
    // 'i' keeps track of the boundary of elements that are smaller than the pivot
    int i = low-1;
    
    // Loop through the current segment (except for the pivot at the very end)
    for(int j = low; j <= high-1; j++){
        // If the current element is smaller than the pivot...
        if(arr[j]<pivot){
            // ...expand the smaller elements boundary
            i++;
            // ...and swap the current element into that smaller side
            swap(arr[i],arr[j]);
        }
    }
    
    // Finally, place the pivot exactly after all the smaller elements we found
    swap(arr[i+1],arr[high]);
    
    // Return the final index where the pivot ended up
    return i+1;
}

// --- Quick Sort Helper Function (Recursive) ---
void quicksort(int arr[],int low,int high){
    // Base condition: only sort if there are at least 2 elements to compare
    if(low<high){
        // Place the pivot in its correct spot and get its index (pi)
        int pi = partition(arr,low,high);
        
        // Recursively sort the sub-array to the left of the pivot
        quicksort(arr,low,pi-1);
        
        // Recursively sort the sub-array to the right of the pivot
        quicksort(arr,pi+1,high);
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
    
    // The high index should be size - 1 (which is 3 for an array of 4 elements)
    quicksort(a,0,3);
    display(a,4);
}