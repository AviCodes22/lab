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

void deleteFront() {
    if(head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    if(head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* t = head;
    head = head->next;
    head->prev = nullptr;
    delete t;
}

void display() {
    if(head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* p = head;
    while(p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int ch, val;
    while(true) {
        cout << "\n1. Insert from End\n2. Delete from Front\n3. Display list\n4. Exit\nEnter choice: ";
        cin >> ch;
        if(ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertEnd(val);
        } else if(ch == 2) {
            deleteFront();
        } else if(ch == 3) {
            display();
        } else if(ch == 4) {
            return 0;
        } else {
            cout << "Invalid choice" << endl;
        }
    }
}
