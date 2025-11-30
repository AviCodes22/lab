#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct node{
    int data;
    node*left;
    node*right;
    int height;
};

int height(node* n) {
    return n ? n->height : 0;
}

node* newNode(int value){
    node*newnode = new node();
    newnode->data = value;
    newnode->right = nullptr;
    newnode->left = nullptr;
    newnode->height = 1;
    return newnode;
}

int getBalance(node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

node* rightRotate(node* y) {
    node* x = y->left;
    node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

node* leftRotate(node* x) {
    node* y = x->right;
    node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

node* insert(node* node, int data) {
    if (node == nullptr) return(newNode(data));
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Left Heavy Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
    }
    if (balance > 1) return rightRotate(node);

    // Right Heavy Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
    }
    if (balance < -1) return leftRotate(node);

    return node;
}

void displayTree(node* root, int space = 0, int indent = 5) {
    if (root == nullptr) return;
    space += indent;
    displayTree(root->right, space);
    cout << endl << setw(space) << root->data << endl;
    displayTree(root->left, space);
}

int main() {
    node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "AVL Tree after insertions:" << endl;
    displayTree(root);

    return 0;
}
