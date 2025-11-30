

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertFront(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = head;
    head = t;
}

void deleteAtPos(int pos) {
    if(head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    if(pos <= 0) {
        cout << "Invalid position" << endl;
        return;
    }
    if(pos == 1) {
        Node* t = head;
        head = head->next;
        delete t;
        return;
    }
    Node* p = head;
    Node* q = nullptr;
    int i = 1;
    while(p != nullptr && i < pos) {
        q = p;
        p = p->next;
        i++;
    }
    if(p == nullptr) {
        cout << "Position out of range" << endl;
        return;
    }
    q->next = p->next;
    delete p;
}

void display() {
    if(head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* t = head;
    while(t != nullptr) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int ch, val, pos;
    while(true) {
        cout << "\n1. Insert from Front\n2. Delete at given position\n3. Display list\n4. Exit\nEnter choice: ";
        cin >> ch;
        if(ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertFront(val);
        } else if(ch == 2) {
            cout << "Enter position: ";
            cin >> pos;
            deleteAtPos(pos);
        } else if(ch == 3) {
            display();
        } else if(ch == 4) {
            return 0;
        } else {
            cout << "Invalid choice" << endl;
        }
    }
}
