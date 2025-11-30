#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = NULL;

Node* createNode(int val) {
    Node* t = new Node();
    t->data = val;
    t->left = t->right = NULL;
    return t;
}

void insertBST(int val) {
    Node* t = createNode(val);
    if(root == NULL) {
        root = t;
        return;
    }
    Node* curr = root;
    Node* parent = NULL;
    while(curr != NULL) {
        parent = curr;
        if(val < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    if(val < parent->data) parent->left = t;
    else parent->right = t;
}

void inorderNonRec() {
    Node* stack[100];
    int top = -1;
    Node* curr = root;

    while(curr != NULL || top != -1) {
        while(curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main() {
    int ch, val;
    while(true) {
        cout << "\n1. Insert\n2. In-order (Non-Recursive)\n3. Exit\nEnter choice: ";
        cin >> ch;
        switch(ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertBST(val);
                break;
            case 2:
                inorderNonRec();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice";
        }
    }
}
