#include <bits/stdc++.h>
using namespace std;

// --- Merge Function ---
// This function takes two adjacent sorted halves and merges them into a single sorted array.
// The left half is arr[left...mid] and the right half is arr[mid+1...right].
void merge(int arr[],int left,int mid, int right){
    // Calculate the sizes of the two halves
    // leftSize is the size of the left half
    int leftSize=mid-left+1;
    // rightSize is the size of the right half
    int rightSize=right-mid;
    
    // Create temporary arrays leftArray and rightArray to hold the copied data
    int leftArray[leftSize],rightArray[rightSize];
    
    // Copy data to the temporary left array leftArray[]
    for(int i = 0;i<leftSize;i++){
        leftArray[i]=arr[left+i];
    }
    // Copy data to the temporary right array rightArray[]
    for(int j = 0;j<rightSize;j++){
        rightArray[j]=arr[mid+j+1];
    }

    // Pointers for traversing: i for leftArray[], j for rightArray[], and k for the main arr[]
    int i = 0,j=0,k=left;
    
    // Compare elements from leftArray[] and rightArray[] and place the smaller element into arr[]
    while(i<leftSize && j<rightSize){
        if(leftArray[i]<=rightArray[j]){
            arr[k]=leftArray[i];
            k++;
            i++;
        }
        else{
            arr[k]=rightArray[j];
            k++;
            j++;
        }
    }
    
    // If there are any remaining elements in leftArray[], copy them over
    while(i<leftSize){
        arr[k]=leftArray[i];
        k++;
        i++;
    }
    
    // If there are any remaining elements in rightArray[], copy them over
    // (Note: 'i=j<rightSize' might be a typo for 'j<rightSize')
    while(i=j<rightSize){
        arr[k]=rightArray[j];
        k++;
        j++;
    }
}

// --- Merge Sort Helper Function (Recursive) ---
// The main logic of Merge Sort uses "Divide and Conquer"
void mergesort(int arr[],int left,int right){
    // Base case: An array of 0 or 1 element is already sorted
    if(left>=right){
        return;
    }
    // Find the midpoint to divide the array into two halves safely
    int mid =left+(right-left)/2;
    
    // Recursively sort the left half
    mergesort(arr,left,mid);
    // Recursively sort the right half
    mergesort(arr,mid+1,right);
    // Merge the two sorted halves back together
    merge(arr,left,mid,right);
}


void display(int arr[],int size){
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int a[4]={1,4,3,2};
    mergesort(a,0,3);
    display(a,4);
}
