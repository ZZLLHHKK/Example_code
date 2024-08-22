#include <bits/stdc++.h>
using namespace std;

struct Node { //doubly linked list
    int data;
    Node *prev, *next;
};
Node *head = nullptr;

void insertFromHead(int n) {
    Node *tmp = new Node();
    tmp -> data = n;
    tmp -> prev = nullptr;
    tmp -> next = nullptr;
    if (head == nullptr) {
        head = tmp;
        return;
    }
    tmp -> next = head;
    head -> prev = tmp;
    head = tmp;
}

void insertFromTail(int n) {
    Node *tmp = new Node();
    tmp -> data = n;
    tmp -> prev = nullptr;
    tmp -> next = nullptr;
    if (head == nullptr) {
        head = tmp;
        return;
    }
    Node *cur = head;
    while (cur -> next != nullptr) 
        cur = cur -> next;
    cur -> next = tmp;
}

void Print(Node *head) {
    Node *tmp = head;
    while (tmp != nullptr) {
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

int main() {
    for (int i = 1; i <= 5; ++i) 
        insertFromTail(i);
    Print(head);
}
