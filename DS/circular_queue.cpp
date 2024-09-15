#include <bits/stdc++.h>
#define mxN 10
using namespace std;
int que[mxN];
int front = -1, rear = -1;

int isFull() {
    return (rear + 1) % mxN == front;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int *que, int x) { //push
    if (isFull())
        return;
    if (isEmpty()) 
        front = rear = 0;
    else 
        rear = (rear + 1) % mxN;
    que[rear] = x;
}

void dequeue(int *que) { //pop
    if (isEmpty())
        return;
    if (front == rear)
        front = rear = -1;
    else 
        front = (front + 1) % mxN;
}

void Print(int *que) {
    int i = front;
    while (true) {
        cout << que[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % mxN;
    }
    cout << '\n';
}

int main() {
    for (int i = 1; i <= 10; ++i)
        enqueue(que, i);
    Print(que);
    dequeue(que);
    Print(que);
}
