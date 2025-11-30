#include<iostream>
using namespace std;

struct node{
    int data;
    node*next;
};

// --- STACK IMPLEMENTATION ---
node*top = nullptr;

// A stack is LIFO (Last-In, First-Out). New nodes are added at the top.
void push(int value){
    node*newnode = new node();
    newnode->data = value;
    newnode->next = top; // New node points to the old top.
    top = newnode;       // The new node becomes the top.
}

// Pop removes the top element from the stack and returns its value.
int pop(){
    if(top == nullptr){
        cout << "Stack is empty, cannot pop." << endl;
        return -1; // Return an indicator of an error
    }
    int value = top->data;
    node* temp = top;
    top = top->next; // Move top to the next node.
    delete temp;     // Free the memory of the popped node.
    return value;
}

// --- QUEUE IMPLEMENTATION ---
node*front = nullptr;
node*rear = nullptr;

// Enqueue adds an element to the rear of the queue.
void enqueue(int value){
    node*newnode = new node();
    newnode->data = value;
    newnode->next = nullptr;

    if(front == nullptr){
        // If queue is empty, new node is both front and rear.
        front = newnode;
        rear = newnode;
    } else {
        // Add the new node at the end of the queue and change rear.
        rear->next = newnode;
        rear = newnode;
    }
}

// Dequeue removes an element from the front of the queue.
int dequeue(){
    if(front == nullptr){
        cout << "Queue is empty, cannot dequeue." << endl;
        return -1; // Return an indicator of an error
    }
    int value = front->data;
    node* temp = front;
    front = front->next;
    
    // If front becomes NULL, then change rear also as NULL
    if(front == nullptr){
        rear = nullptr;
    }
    
    delete temp; // Free memory
    return value;
}

void display(){
    if(top == nullptr){
        cout << "Stack is empty." << endl;
        return;
    }
    
    node* temp = top;
    cout << "Stack elements (top to bottom):" << endl;
    while(temp != nullptr){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main(){
    // 1. Push elements onto the stack
    push(5);
    push(9);
    push(12);
    
    cout << "--- Original Stack ---" << endl;
    display();
    
    // 2. Reverse the stack using a queue
    // Move all elements from stack to queue
    cout << "\n...moving elements from stack to queue..." << endl;
    while(top != nullptr) {
        enqueue(pop());
    }
    
    // Queue now holds elements in original order: 12, 9, 5 (front to rear)
    
    // Move all elements from queue back to stack
    cout << "...moving elements from queue back to stack..." << endl;
    while(front != nullptr) {
        push(dequeue());
    }
    
    // Stack is now reversed. The elements were pushed back in the order 5, 9, 12.
    // So the stack top-to-bottom is 12, 9, 5.
    // Wait, the original stack was 12, 9, 5. Let's re-check.
    // Original stack (top to bottom): 12, 9, 5
    // After popping into queue (front to rear): 12, 9, 5
    // After dequeuing back to stack, we push 12, then 9, then 5.
    // Final stack (top to bottom): 5, 9, 12. It is reversed.
    
    cout << "\n--- Reversed Stack ---" << endl;
    display();
    
    return 0;
}