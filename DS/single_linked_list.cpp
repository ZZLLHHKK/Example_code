#include <bits/stdc++.h>
using namespace std;

struct Node { //single linked list
    int data;
    Node *next;
};
Node *head = nullptr;

void insertFromHead(int n) {
    Node *tmp = new Node();
    tmp -> data = n;
    tmp -> next = nullptr;
    tmp -> next = head;
    head = tmp;
}

void insertFromTail(int n) {
    Node *tmp = new Node();
    tmp -> data = n;
    tmp -> next = nullptr;

    if (head == nullptr)
        head = tmp;
    else {
        Node *cur = head;
        while (cur -> next != nullptr) 
            cur = cur -> next;
        cur -> next = tmp;
    }
}

void insertFromPos(int n, int pos) {
    Node *tmp = new Node();
    tmp -> data = n;
    tmp -> next = nullptr;

    if (head == nullptr || pos == 0) {
        tmp -> next = head;
        head = tmp;
        return;
    }
    
    Node *cur = head;
    for (int i = 0; i < pos && cur -> next != nullptr; ++i)
        cur = cur -> next;
    tmp -> next = cur -> next;
    cur -> next = tmp;
}

void removeFromHead() {
    if (head == nullptr)
        return;

    Node *tmp = head;
    head = head -> next;
    delete tmp;
}

void removeFromTail() {
    if (head == nullptr)
        return;
    if (head -> next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node *tmp = head;
    while (tmp -> next -> next != nullptr) 
        tmp = tmp -> next;
    delete tmp -> next;
    tmp -> next = nullptr;
}

void removeFromPos(int pos) {
    if (head == nullptr)
        return;
    if (pos == 0) {
        removeFromHead();
        return;
    }
    
    Node *tmp = head;
    for (int i = 1; i < pos && tmp -> next != nullptr; ++i) 
        tmp = tmp -> next;
    if (tmp -> next == nullptr)
        return;
    
    Node *nd = tmp -> next;
    tmp -> next = tmp -> next -> next;
    delete nd;
}

int getSize(int cnt = 0) {
    Node *tmp = head;
    while (tmp != nullptr) {
        tmp = tmp -> next;
        cnt++;
    }
    return cnt;
}

void Print(Node *head) {
    Node *tmp = head;
    while (tmp != nullptr) {
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

void Reverse() {
    Node *cur = head, *next, *prev = nullptr;
    while (cur != nullptr) {
        next = cur -> next;
        cur -> next = prev; //point backward
        prev = cur;
        cur = next;
    }
    head = prev;
}

int main() {
    cout << "insert from head : " << endl;
    for (int i = 1; i <= 3; ++i) 
        insertFromHead(i);
    Print(head);

    cout << "\ninsert from tail : " << endl;
    for (int i = 1; i <= 3; ++i) 
        insertFromTail(i);
    Print(head);

    cout << "\ninsert From Pos(Middle) : " << endl;
    for (int i = 0; i < 3; ++i) 
        insertFromPos(6, 2);
    Print(head);

    cout << "\nremove from head : " << endl;
    removeFromHead();
    Print(head);

    cout << "\nremove from tail : " << endl;
    removeFromTail();
    Print(head);

    cout << "\nremove the 2nd element : " << endl;
    removeFromPos(1);
    Print(head);

    cout << "\nelement remaining : " << getSize() << endl;

    cout << "\nReverse list : " << endl;
    Reverse();
    Print(head);
}

//Single Linked List
/*
   head
    |
    V
    Node -> Node -> Node -> Node -> Node
                                     |
                                     V
                                    NULL
*/
