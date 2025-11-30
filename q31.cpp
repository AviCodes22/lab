#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = nullptr;

void insertFront(int x) {
    Node* t = new Node;
    t->data = x;
    t->prev = nullptr;
    t->next = head;
    if(head != nullptr) head->prev = t;
    head = t;
}

void deleteEnd() {
    if(head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    if(head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* p = head;
    while(p->next != nullptr) p = p->next;
    p->prev->next = nullptr;
    delete p;
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
        cout << "\n1. Insert from Front\n2. Delete from End\n3. Display list\n4. Exit\nEnter choice: ";
        cin >> ch;
        if(ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertFront(val);
        } else if(ch == 2) {
            deleteEnd();
        } else if(ch == 3) {
            display();
        } else if(ch == 4) {
            return 0;
        } else {
            cout << "Invalid choice" << endl;
        }
    }
}
