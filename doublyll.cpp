#include<iostream>
using namespace std;

struct node{
    int data;
    node*next;
    node*prev;
};

node*head = NULL;
node*tail = NULL;

// Corrected insertion to properly append nodes to the end of the list.
void insertion(int value){
    node* newnode = new node();
    newnode ->data = value;
    newnode ->next = NULL;
    newnode ->prev = NULL;

    if(head == NULL){
        // If the list is empty, the new node is both head and tail.
        head = newnode;
        tail = newnode;
    }else{
        // Otherwise, append to the current tail.
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode; // Update the tail to be the new node.
    }
}

// Corrected deletion to safely handle all cases (head, middle, tail).
void deletion(){
    node* current = head;
    while(current != nullptr){
        node* nextNode = current->next; // Store the next node before potential deletion.

        if((current->data) % 3 == 0){
            cout << "\nDeleting node with value: " << current->data;

            // Case 1: The node to delete is the head.
            if(current == head){
                head = current->next;
                if(head != nullptr){
                    head->prev = nullptr;
                } else {
                    // If the list becomes empty, update tail as well.
                    tail = nullptr;
                }
            }
            // Case 2: The node to delete is the tail.
            else if(current == tail){
                tail = current->prev;
                tail->next = nullptr;
            }
            // Case 3: The node is in the middle.
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            
            delete current; // Safely delete the node.
        }
        current = nextNode; // Move to the next node.
    }
}

// Corrected display to print all nodes in the list.
void display(){
    node*temp = head;
    if(temp == nullptr){
        cout << "List is empty.";
        return;
    }
    while(temp != nullptr){
        cout<< temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    cout << "Inserting elements: 5 3 4 6 9" << endl;
    insertion(5);
    insertion(3);
    insertion(4);
    insertion(6);
    insertion(9);

    cout << "List before deletion: ";
    display();
    cout << endl;

    deletion();
    cout << endl;

    cout << "\nList after deletion: ";
    display();
    cout << endl;

    return 0;
}