#include<iostream>
using namespace std;
 
struct node{
    int data;
    node*next;
};

node*front = nullptr;
node*rear = nullptr;


bool isEmpty(){
    return (front==nullptr);
}


void enqueue(int value){
    node*newnode = new node();
    newnode->data = value;
    newnode->next = nullptr;

    if(isEmpty()){
        front = newnode;
        rear = newnode;
        rear->next = front; 
    }
    else{
        rear->next = newnode;
        rear = newnode;
        newnode->next = front;
    }
}

void dequeue(){
    if(isEmpty()){
        cout<<"nothing to dequeue"<<endl;
        return;
    }

    node* temp = front;
    // single node
    if(front == rear){
        front = nullptr;
        rear = nullptr;
        delete temp;
        return;
    }

    // more than one node
    front = front->next;
    rear->next = front;
    delete temp;
}

void display(){
    if(isEmpty()){
        cout<<"queue is empty"<<endl;
        return;
    }
    node*temp = front;
    do{
        cout<< temp->data << endl;
        temp = temp->next;
    }while(temp != front);
}

void peek(){
    if(isEmpty()){
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<< front->data << endl;
}

int main(){

    int value;
    int choice;

    do{
        cout<<"1.enqueue" << endl;
        cout<<"2.dequeue" << endl;
        cout<<"3.display" <<endl;
        cout<<"4.peek" <<endl;
        cout<<"5.exit" <<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"enter value: ";
            cin>>value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            cout<<"exiting program"<<endl;
            break;
        default:
            cout<<"select a valid number"<<endl;
            break;
        }
    }while(choice!=5);

    return 0;
}