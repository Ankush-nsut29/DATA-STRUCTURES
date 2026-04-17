#include <bits/stdc++.h>
using namespace std;
void traverse(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int append(int arr[],int size,int elt){
    arr[size]=elt;
    size++;
    return size;
}

int pop(int arr[],int size){
    size--;
    return size;
}

int insert(int arr[],int size,int pos,int x){
    for(int i=size;i>=pos-1;i--){
        arr[i+1]=arr[i];
    }
    arr[pos-1]=x;
    size++;
    return size;
}



int del(int arr[],int size,int pos){
    for(int i = pos-1;i<size-1;i++){
        arr[i]=arr[i+1];  
    }
    size--;
    return size;
}



int search(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if (arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    int size;
    int a[40]={1,2,3,4,5};
    size=5;
    traverse(a,size);
    size = del(a,size,1);
    traverse(a,size);
    size = append(a,size,10);
    traverse(a,size);
    size = insert(a,size,1,100);
    traverse(a,size);
    size = pop(a,size);
    traverse(a,size);
    cout<<search(a,size,101);
    }
