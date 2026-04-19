#include<bits/stdc++.h>
using namespace std;
//I am considering an array from 1 I will store null in 0
//so left child will be at index 2*i and right at 2*i+1
//and parent at i/2

void display(int arr[],int size){
    for(int i = 1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insert(int arr[],int& size,int val){
    size=size+1;
    int i = size;
    arr[i]=val;
    while(i>1){
        int parent = i/2;

        if(arr[i]>arr[parent]){
            swap(arr[i],arr[parent]);
            i = parent;
        }
        else{
            return;
        }
    }
}

void deletion(int arr[],int& size){
    arr[1]=arr[size];
    size--;
    int i = 1;
    while(i<size){
        int left=2*i;
        int right=2*i+1;
        if(left<size && arr[i]<arr[left]){
            swap(arr[i],arr[left]);
            i=left;
        }
        else if(right<size && arr[i]<arr[right]){
            swap(arr[i],arr[right]);
            i=right;
        }
        else{
            return;
        }
    }
}



int main(){
    int heap[50]={NULL,60,50,40,30,20};
    int size = 5;
    display(heap,size);
    insert(heap,size,55);
    display(heap,size);
    insert(heap,size,70);
    display(heap,size);
    deletion(heap,size);
    display(heap,size);
}