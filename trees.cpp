#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int data;
    node*left;
    node*right;
};
    
struct node*createNode(int value){
    node*newnode = new node();
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = value;
    return newnode;

}




void inorder(node*root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data << " ";
    inorder(root->right);
}

void preorder(node*root){
    if(root == nullptr){
        return;
    }
    cout<<root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node*root){
if(root== nullptr){
    return;
}
postorder(root->left);
postorder(root->right);
cout<<root->data << " ";
 
}

int findHeight(node*root){
    if(root == nullptr){
        return -1;
    }
    
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return 1 + max(leftHeight,rightHeight);
}

int countNode(node*root){
     if(root == nullptr){
        return 0 ;
    }
    
    return 1+ countNode(root->left) + countNode(root->right);
}





int main(){
    node*root = createNode(19);
    root->left = createNode(20);
    root->right = createNode(30);
    root->right->right = createNode(55);
    root->right->right->right = createNode(69);
    inorder(root); 
    cout<< endl;
    preorder(root);
    cout<< endl;
    postorder(root);
    cout << endl;
    int height = findHeight(root);
    cout << "Height of the tree is: " << height << endl;
    int nodes = countNode(root);
    cout << "nodes of the tree are: " << nodes << endl;
}