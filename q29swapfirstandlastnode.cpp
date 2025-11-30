#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = nullptr;

void insertEnd(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = nullptr;
    if(head == nullptr) {
        t->prev = nullptr;
        head = t;
        return;
    }
    Node* p = head;
    while(p->next != nullptr) p = p->next;
    p->next = t;
    t->prev = p;
}

void swapFirstLast() {
    if(head == nullptr || head->next == nullptr) return;

    Node* first = head;
    Node* last = head;

    while(last->next != nullptr) last = last->next;

    if(first->next == last) {
        first->next = nullptr;
        last->prev = nullptr;

        last->next = first;
        first->prev = last;

        head = last;
        return;
    }

    Node* fnext = first->next;
    Node* lprev = last->prev;

    fnext->prev = last;
    last->next = fnext;

    lprev->next = first;
    first->prev = lprev;

    last->prev = nullptr;
    first->next = nullptr;

    head = last;
}

void display() {
    Node* p = head;
    if(p == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    while(p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int ch, val;
    while(true) {
        cout << "\n1. Insert from End\n2. Swap First & Last Node\n3. Display\n4. Exit\nEnter choice: ";
        cin >> ch;

        if(ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertEnd(val);
        }
        else if(ch == 2) {
            swapFirstLast();
        }
        else if(ch == 3) {
            display();
        }
        else if(ch == 4) {
            return 0;
        }
        else {
            cout << "Invalid choice";
        }
    }
}
