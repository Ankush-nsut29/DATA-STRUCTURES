#include <bits/stdc++.h>
using namespace std;
int search(int arr[],int size,int x){
    int low=0;
    int high=size-1;
    int mid=(low+high)/2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]>x){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    int size=10;
    int a[50]={1,2,3,4,5,6,7,8,9,10};
    cout<<search(a,size,79);
}