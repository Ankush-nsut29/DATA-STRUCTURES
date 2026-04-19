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



int main(){
    int heap[50]={NULL,60,50,40,30,20};
    int size = 5;
    display(heap,size);
    insert(heap,size,55);
    display(heap,size);
    insert(heap,size,70);
    display(heap,size);
}