#include <bits/stdc++.h>
using namespace std;

void sort(int arr[],int size){
    for(int i = 0 ; i < size - 1 ; i++){
        for(int j = 0 ; j < size - i - 1 ; j++){
            if(arr[j]>arr[j+1]){
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