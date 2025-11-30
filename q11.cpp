//. Implement BST with following functions- 1. Insert , 2. mirror image, 3. Display with any traversal

#include<iostream>
using namespace std;


struct node{
    int data;
    node*left;
    node*right;
};

node*creatnode(int val){
    node*newnode = new node;
    newnode->data=val;
    newnode->left=nullptr;
    newnode->right=nullptr;

    return newnode;
}


node*insertnode(node*root, int val){
    if (root==nullptr){
        root=creatnode(val);
    }else if(val<root->data){
        root->left = insertnode(root->left,val);
    }else if (val>root->data){
        root->right = insertnode(root->right,val);
    }

    return root;
}



void mirrorTree(node*root){
    if(root==nullptr)
    return;

    node*temp=root->left;
    root->left = root->right;
    root->right =temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}


void inorder(node*root){
    if(root==nullptr)

    return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int main() {
    node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Mirror Image\n";
        cout << "3. Display (Inorder Traversal)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertnode(root, value);
                break;

            case 2:
                mirrorTree(root);
                cout << "Mirror image created successfully.\n";
                break;

            case 3:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}