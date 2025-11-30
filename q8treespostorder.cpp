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

Node* findMin(Node* node) {
    while(node && node->left != nullptr)
        node = node->left;
    return node;
}

Node* deleteNode(Node* node, int key) {
    if(node == nullptr) return node;

    if(key < node->data)
        node->left = deleteNode(node->left, key);
    else if(key > node->data)
        node->right = deleteNode(node->right, key);
    else {
        if(node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if(node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else {
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }
    return node;
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
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        insertNode(x);
    }

    int ch, val;
    while(true) {
        cout << "\n1. Delete\n2. Post-order Traversal (No Recursion)\n3. Exit\nEnter choice: ";
        cin >> ch;

        if(ch == 1) {
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
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
