#include <bits/stdc++.h>
using namespace std;

struct Stack{
    int top;
    int arr[50];
};

void push(Stack &s, int val){
    if(s.top>=49){
        cout<<"overflow\n";
        return;
    }
    else{
        s.top++;
        s.arr[s.top]=val;
    }
}

void pop(Stack &s){
    if(s.top==-1){
        cout<<"underflow\n";
        return;
    }
    else{
        s.top--;
    }
}

void traverse(Stack &s){
    for(int i = 0;i<=s.top;i++){
        cout<<s.arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Stack s;
    s.top = -1; // Initialize the stack
    
    push(s, 10);
    push(s, 20);
    push(s, 30);
    traverse(s); // Expected: 10 20 30
    
    pop(s);
    traverse(s); // Expected: 10 20
    
    return 0;
}