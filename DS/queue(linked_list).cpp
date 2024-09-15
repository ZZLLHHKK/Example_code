#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};
Node *que = nullptr;

void enqueue(int x) {
    Node *tmp = new Node();
    tmp -> next = nullptr;
    tmp -> data = x;

    if (que == nullptr) 
        que = tmp;
    else {
        Node *cur = que;
        while (cur -> next != nullptr) 
            cur = cur -> next;
        cur -> next = tmp;
    }
}

void dequeue() {
    if (que == nullptr)
        return;
    Node *tmp = que;
    que = que -> next;
    delete tmp;
}

int front() {
    return que -> data;
}

bool isEmpty() {
    return que == nullptr ? true : false;
}

void Print() {
    Node *tmp = que;
    while (tmp != nullptr) {
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << "\n";
}

int main() {
    for (int i = 1; i <= 10; ++i)
        enqueue(i);
    Print();
    dequeue();
    dequeue();
    Print();
    cout << "Front element : " << front() << '\n';
    cout << "Does the queue empty : " << (isEmpty() == true ? "yes" : "no"); 
    cout << '\n';
}
