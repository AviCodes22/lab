#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* root = nullptr;

Node* createNode(int x) {
    Node* t = new Node;
    t->data = x;
    t->left = t->right = nullptr;
    return t;
}

void insertNode(int x) {
    Node* newNode = createNode(x);
    if(root == nullptr) {
        root = newNode;
        return;
    }
    Node* cur = root;
    Node* parent = nullptr;

    while(cur != nullptr) {
        parent = cur;
        if(x < cur->data) cur = cur->left;
        else cur = cur->right;
    }

    if(x < parent->data) parent->left = newNode;
    else parent->right = newNode;
}

void postorderNoRec() {
    if(root == nullptr) return;

    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while(top1 != -1) {
        Node* temp = stack1[top1--];
        stack2[++top2] = temp;

        if(temp->left) stack1[++top1] = temp->left;
        if(temp->right) stack1[++top1] = temp->right;
    }

    while(top2 != -1) {
        cout << stack2[top2--]->data << " ";
    }
}

int main() {
    int ch, val;
    while(true) {
        cout << "\n1. Insert\n2. Post-order Traversal (No Recursion)\n3. Exit\nEnter choice: ";
        cin >> ch;

        if(ch == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertNode(val);
        }
        else if(ch == 2) {
            postorderNoRec();
            cout << endl;
        }
        else if(ch == 3) {
            return 0;
        }
        else {
            cout << "Invalid option";
        }
    }
}
