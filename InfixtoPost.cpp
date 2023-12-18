#include<iostream>
#include<string>

using namespace std;

#define size 20

char stack [size];
int top = -1;

int isEmpty(){
    return top == -1;
}

void push(char e){
    if(top==size-1){
        cout<<"Stack overflow"<<endl;
        return;
    } else {
        top++;
        stack[top] = e;
    }
}

char pop(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
        return '\0';
    } else {
        char x = stack[top];
        top--;
        return x;
    }
}

int isValid(char e){
    return (e == '+' || e=='-' || e=='*' || e =='/' || e=='^' || e=='%' || e=='(' || e == ')');
}

int priority(char e){
    if(e=='^')
        return 3;
    else if(e=='/' || e=='*' || e=='%')
        return 2;
    else if(e=='+' || e=='-')
        return 1;
    else if(e=='(' || e==')')
        return 0;
    else 
        return -1;
}

void convert(const char *e) {
    string r;
    int f = 0;
    for(int i = 0; e[i] != '\0'; i++) {
        int p = priority(e[i]);
        if((e[i] >= 'a' && e[i] <= 'z') || (e[i] >= 'A' && e[i] <= 'Z') || (e[i] >= '0' && e[i] <= '9')) {
            r += e[i];
        } else if (!isValid(e[i])) {
            cout << "Invalid" << endl;
            return;
        }
        if(e[i] == '(') {
            f++;
            push(e[i]);
        }
        if(e[i] == ')') {
            while(!isEmpty() && stack[top] != '(') {
                r += pop();
            }
            if (!isEmpty()) {
                pop(); // Pop the '('
                f--;
            } else {
                cout << "Invalid infix expression: unbalanced parentheses." << endl;
                return;
            }
        } else {
            if(isValid(e[i]) && (e[i] != '(')) {
                while(!isEmpty() && p < priority(stack[top])) {
                    r += pop();
                }
                push(e[i]);
            }
        }
    }
    if(f == 0) {
        while(!isEmpty()) {
            r += (pop());
        }
        cout << "Postfix expression: " << r << endl;
    } else {
        cout << "Invalid infix expression: unbalanced parentheses." << endl;
    }
}

int main() {
    char exp[20];
    cout << "Enter the infix Expression: ";
    cin >> exp;
    char *e = exp; // Convert array to pointer
    convert(e);
    return 0;
}
