#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

void preorderNonRecursive(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    stack<Node*> st;
    st.push(root);

    cout << "Pre-order Traversal (Non-Recursive): ";

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();

        cout << curr->data << " ";

        // Push right first so left is processed first
        if (curr->right != nullptr)
            st.push(curr->right);

        if (curr->left != nullptr)
            st.push(curr->left);
    }

    cout << endl;
}

int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\n--- BST MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Pre-order Traversal (Non-Recursive)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            root = insertNode(root, value);
            break;

        case 2:
            preorderNonRecursive(root);
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
