#include <iostream>
#include <string>
#include <stack>

const int Max = 100;
using namespace std;
int arr[Max];
int top = -1;

bool isEmpty() {
    return top == -1;
}
bool isFull(){
    return top == Max-1;
}

bool parsedparentheses(string expression){

    top = -1; 
    for(int i=0; i<expression.length(); i++){
        char ch = expression[i];
        if(ch == '(' || ch == '{'){
            if(isFull()) return false;
            arr[++top] = ch;
        }
        else if(ch == ')'){
            if(isEmpty() || arr[top] != '(') return false;
            top--;
        }
        else if(ch == '}'){
            if(isEmpty() || arr[top] != '{') return false;
            top--;
        }
    }
    return isEmpty();
}

int main(){
    string expression;
    cout<<"Enter a bracket's expression:";
    cin>>expression;
    if(parsedparentheses(expression)){
        cout<<"The expression is balanced.";
    }
    else{
        cout<<"The expression is not balanced.";
    }
    return 0;
}