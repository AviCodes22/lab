#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = nullptr;

void insertNode(int x) {
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

void findEven() {
    if(head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* p = head;
    cout << "Even numbers: ";
    bool found = false;
    while(p != nullptr) {
        if(p->data % 2 == 0) {
            cout << p->data << " ";
            found = true;
        }
        p = p->next;
    }
    if(!found) cout << "None";
    cout << endl;
}

int main() {
    int ch, val;
    while(true) {
        cout << "\n1. Insert Node\n2. Find nodes having even numbers\n3. Exit\nEnter choice: ";
        cin >> ch;

        if(ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertNode(val);
        }
        else if(ch == 2) {
            findEven();
        }
        else if(ch == 3) {
            return 0;
        }
        else {
            cout << "Invalid choice";
        }
    }
}
