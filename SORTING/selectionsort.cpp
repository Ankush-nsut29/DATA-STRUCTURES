#include <bits/stdc++.h>
using namespace std;

void sort(int arr[],int size){
    for(int i = 0;i<size;i++){
        int mini=i;
        for(int j = i+1;j<size;j++){
            if(arr[j]<arr[i]){
                mini=j;
            }
        }
        swap(arr[mini],arr[i]);
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