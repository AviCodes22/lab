#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
void menu(){
    cout<< "1.Infix to postfix conversion"<< endl;
    cout<<"2.Postfix to infix conversion"<<endl;
    cout<<"3.Evaluating postfix"<<endl;
    cout<<"4.Exit"<<endl;
}

string infixtopostfix(string infix);
string postfixtoinfix(string postfix);
int evaluatePostfix(string postfix);
int getPrecedence(char op) {
    if (op == '^') return 3; // Exponents are most important
    if (op == '*' || op == '/') return 2; // Multiplication/Division are next
    if (op == '+' || op == '-') return 1; // Addition/Subtraction are last
    return 0; // Parentheses or other characters have no precedence
}




int main(){
    int choice;
    
    menu();
    cout<<"enter your choice"<<endl;
    cin>>choice;

    string infix;
    string postfix;
    switch(choice){
        
        case 1: cout<<"enter the infix expression"<<endl;
                cin>>infix;
                cout<<"The postfix expression is: "<<infixtopostfix(infix)<<endl;
                break;

        case 2: cout<<"enter the postfix expression"<<endl;
                cin>>postfix;
                cout<<"The infix expression is: "<<postfixtoinfix(postfix)<<endl;
                break;

        case 3: cout<<"enter the postfix expression"<<endl;
                cin>>postfix;
                cout<<"The evaluation of postfix expression is: "<<evaluatePostfix(postfix)<<endl;
                break;

        case 4: cout<<"Exiting..."<<endl;
                break;

        default: cout<<"Invalid choice"<<endl;
    }


}


string infixtopostfix(string infix){
    stack<char> s;
    string postfix;
    for(int i=0;i<infix.length();i++){
        if(isalnum(infix[i])){
            postfix += infix[i];
        }
        else if(infix[i] == '('){
            s.push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(!s.empty() && s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();
        }
        else{
            while(!s.empty() && getPrecedence(s.top()) >= getPrecedence(infix[i])){
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}


string postfixtoinfix(string postfix) {
    stack<string> s;
    for (char ch : postfix) {
        if (isalnum(ch)) {
            s.push(string(1, ch));
        } else {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string expr = "(" + op1 + ch + op2 + ")";
            s.push(expr);
        }
    }
    return s.top();
}


int evaluatePostfix(string postfix) {
    stack<int> s;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0'); 
        } else {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/': 
                    if (op2 == 0) {
                        cout << "Division by zero error!" << endl;
                        return -1;
                    }
                    s.push(op1 / op2); 
                    break;
                case '^': s.push(pow(op1, op2)); break; 
            }
        }
    }
    return s.top();
}