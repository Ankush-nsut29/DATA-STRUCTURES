#include<bits/stdc++.h>
using namespace std;

struct Queue{
    int front;    
    int rear;     
    int arr[90];
};

void enqueue(Queue &q, int val){
    if (q.front == -1 && q.rear== -1) {
        q.front = 0;
        q.rear = 0;
        q.arr[q.rear] = val;
    }

    else{
    q.rear++;
    q.arr[q.rear] = val;
    }
}

void dequeue(Queue &q){
        q.front++;
}

void display(Queue &q){
     for(int i = q.front;i<=q.rear;i++){
        cout<<q.arr[i]<<" ";
     }
    cout << endl;
}

int main(){
    struct Queue q;
    q.front=-1;
    q.rear=-1;

    enqueue(q, 8);  
    enqueue(q, 7);  
    display(q);    
    dequeue(q);
    display(q);
}      