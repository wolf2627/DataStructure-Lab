#include<iostream>
#include<string>

using namespace std;

class stack{
    public:
        int data; 
        stack *next;
};

stack *top = NULL, *temp;

void push(int element){
    stack *x = new stack();
    x->data = element;
    if(top==NULL){
        top = x;
        x->next = NULL;
    } else {
        x->next = top;
        top = x;
    }
}

int pop(){
    int element;
    temp = top;
    element = top->data;
    top = top->next;
    free(temp);
    return element;
}


int isEmpty(){
    return top == NULL;
}

void evaluation(char *e){
    for(int i=0; e[i]!='\0';i++){
        int o1, o2;
        if(isdigit(e[i])){
            push(e[i]-'0');
        } else {
            if(!isEmpty()){
                o1 = pop();
            } else {
                cout<<"Invalid Expression"<<endl;
            }
            if(!isEmpty()){
                o2 = pop();
            } else {
                cout<<"Invalid Expression"<<endl;
            }
            switch(e[i]){
                case '+':
                    push(o2 + o1);
                    break;
                case '-':
                    push(o2-o1);
                    break;
                case '*':
                    push(o2*o1);
                    break;
                case '/':
                    push(o2/o1);
                    break;
                case '%':
                    push(o2%o1);
                    break;
                default:
                    cout<<"Invalid"<<endl;
            }
        }
    }
    cout<<"Result: "<<top->data<<endl;
}

int main() {
    char exp[20];
    cout << "Enter the postfix Expression: ";
    cin >> exp;
    char *e = exp;
    evaluation(exp); // Convert string to const char* for compatibility
    return 0;
}