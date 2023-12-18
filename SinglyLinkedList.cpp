#include<iostream>

using namespace std;

class node{
    public :
        int data;
        node *next;
};

node *head = NULL, *temp, *y ;

class linkedlist{
        int n;
        public: 
        void create(){
            cout<<"Enter the number of nodes to be created: ";
            cin>>n;
            for(int i=0; i<n; i++){
                node *x = new node();
                cout<<"Enter the element to be inserted: ";
                cin>>x->data;
                x->next = NULL;
                if(head == NULL){
                    head = x;
                    y = head;
                } else {
                    y->next = x;
                    y=x;
                }
            }
        }

        void insertion(){
            int position, element, ch;
            node *x = new node();
            cout<<"Enter the element to be inserted: ";
            cin>>x->data;
            x->next=NULL;
            cout<<"Enter the position to be inserted: "<<endl;
            cout<<"1. @begining"<<endl;
            cout<<"2. @middle"<<endl;
            cout<<"3. @end"<<endl;
            cout<<"Your choice: ";
            cin>>ch;
            switch (ch)
            {
            case 1:
                x->next = head;
                head = x;
                n++;
                break;
            case 2:
                cout<<"Enter the position to be inserted: ";
                cin>>position;
                y = head;
                if(position>0 && position<n){
                    for(int i=0; i<position-1;i++){
                        y=y->next;
                    }
                    x->next = y->next;
                    y->next = x;
                    n++;
                } else {
                    cout<<"can't insert"<<endl;
                }
                break;
            case 3:
                y = head;
                while(y->next!=NULL){
                    y = y->next;
                }
                y->next = x;
                n++;
                break;
            default:
                cout<<"Invalid Choice"<<endl;
                break;
            }
        }

        void deletenode(){
            int ch, element, pos;
            cout<<"Enter the position to be deleted: "<<endl;
            cout<<"1. @begining"<<endl;
            cout<<"2. @middle"<<endl;
            cout<<"3. @end"<<endl;
            cout<<"Your choice: ";
            cin>>ch;
            switch (ch)
            {
            case 1:
                y = head;
                head = head->next;
                free(y);
                n--;
                break;
            case 2:
                y = head;
                cout<<"Enter the position to be deleted: ";
                cin>>pos;
                for(int i=0; i< pos -2; i++){
                    y = y->next;
                }
                temp = y->next;
                y->next = temp ->next;
                free(temp);
                n--;
                break;
            case 3:
                y = head;
                while(y->next->next!=NULL){
                    y = y->next;
                }
                y->next = temp;
                y->next = NULL;
                free(temp);
                n--;
                break;
            default:
                cout<<"Invalid Choice"<<endl;
                break;
            }
        }

        void display(){
            y = head;
            cout<<"LINKED LIST"<<endl;
            while(y != NULL){
                cout<<y->data<<"--->";
                y= y->next;
            }
            cout<<"NULL"<<endl;
        }
};


int main(){
    linkedlist sll;
    sll.create();
    int option = 0;
    char null;
    do{
        cout<<"Operations\n";
        cout<<"(1) Inserting an element\n";
        cout<<"(2) Deleting an element\n";
        cout<<"(3) searching an element\n";
        cout<<"(4) Display the List\n";
        cout<<"(5) exit\n";
        cout<<"Enter operation: ";
        cin>>option;
        switch(option){
            case 1:
                sll.insertion();
                cout<<"After insertion\n";
                sll.display();
                break;
            case 2:
                sll.deletenode();
                cout<<"After Deletion\n";
                sll.display();
                break;
            case 3:
                cout<<"Search Function not implemented"<<endl;
                break;
            case 4:
                sll.display();
                break;
            case 5:
                exit(0);
            default:
                cout<<"oh on..the entered choice is not available(^.^)\n";

        }
        cout<<"Press a char key to continue..";
        cin>>null;
    }while(1);
    return 0;
}