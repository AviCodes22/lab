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

void deleteFront() {
    if(head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* t = head;
    head = head->next;
    delete t;
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
    int ch, val;
    while(true) {
        cout << "\n1. Insert from Front\n2. Delete from Front\n3. Display list\n4. Exit\nEnter choice: ";
        cin >> ch;
        if(ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertFront(val);
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
