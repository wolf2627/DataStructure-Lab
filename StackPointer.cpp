#include<iostream>

using namespace std;

class stack {
    public: 
    int data;
    stack *next;
};

stack *top = NULL, *temp;

class stackoperations {
    public: 
        void push(int element){
            stack *x = new stack();
            x->data = element;
            if(top == NULL){
                top = x;
                x->next = NULL;
            } else {
                x->next = top;
                top = x;
            }
            cout<<"Successfully inserted"<<endl;
        }

        void pop(){
            if(top == NULL){
                cout<<"Stack is empty"<<endl;
                return;
            } else {
                cout<<"Poping element is "<<top->data<<endl;
                temp = top;
                top = top->next;
                free(temp);
            }
        }


        void display(){
            stack *y = top;
            if(top == NULL){
                cout<<"Stack is empty"<<endl;
            } else {
                while(y!=NULL){
                    cout<<y->data<<endl;
                    y = y->next;
                }
            }
        }
       
};

int main(){
    int ch;
    stackoperations st;
    do{
        cout<<"Choose operation to perform: "<<endl;
        cout<<"1. push 2. pop 3. display 4.exit"<<endl;
        cout<<"Enter you choice : ";
        cin>>ch;
        switch (ch)
        {
            case 1:
                int element;
                cout<<"Enter the element to be inserted: ";
                cin>>element;
                st.push(element);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.display();
                break;
            case 4:
                break;
            default:
                cout<<"Enter the valid choice";
                break;
        }
    }while(ch!=4);
}