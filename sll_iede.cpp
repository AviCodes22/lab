#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertEnd(int x) {
    Node* t = new Node;
    t->data = x;
    t->next = nullptr;
    if(head == nullptr) {
        head = t;
        return;
    }
    Node* p = head;
    while(p->next != nullptr)
        p = p->next;
    p->next = t;
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
    Node* q = nullptr;
    while(p->next != nullptr) {
        q = p;
        p = p->next;
    }
    q->next = nullptr;
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
    int ch, val;
    while(true) {
        cout << "\n1. Insert from End\n2. Delete from End\n3. Display list\n4. Exit\nEnter choice: ";
        cin >> ch;
        if(ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertEnd(val);
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
