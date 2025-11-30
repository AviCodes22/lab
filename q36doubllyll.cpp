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

void deleteOdd() {
    if(head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* p = head;
    while(p != nullptr) {
        Node* nxt = p->next;
        if(p->data % 2 != 0) {
            if(p == head) {
                head = p->next;
                if(head != nullptr) head->prev = nullptr;
            } else {
                if(p->prev) p->prev->next = p->next;
                if(p->next) p->next->prev = p->prev;
            }
            delete p;
        }
        p = nxt;
    }
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
        cout << "\n1. Insert from End\n2. Delete nodes having odd numbers\n3. Display list\n4. Exit\nEnter choice: ";
        cin >> ch;
        if(ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertEnd(val);
        } else if(ch == 2) {
            deleteOdd();
        } else if(ch == 3) {
            display();
        } else if(ch == 4) {
            return 0;
        } else {
            cout << "Invalid choice" << endl;
        }
    }
}
