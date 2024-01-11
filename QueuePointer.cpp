#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


class QueueNode {
	public:
	int data;
	QueueNode *next;

};

class QueueList {
	QueueNode * front, * rear;
	public:
		QueueList() {
			front = NULL;
			rear = NULL;
		}
	
        void enqueue(int element) {
            QueueNode *temp = new QueueNode();
            temp->data=element;
            temp->next=NULL;
            if(front==NULL){
                front=rear=temp;
                cout<<"Successfully inserted."<<endl;
            } else{
                rear->next=temp;
                rear=temp;
                cout<<"Successfully inserted."<<endl;
            }
        }

        void dequeue() { 
            QueueNode* temp = new QueueNode(); 
            if(front==NULL) { 
                cout<<"Queue is underflow."<<endl;
            } else { 
                temp=front; 
                front=front->next; 
                cout<<"Deleted value = "<<temp->data<<endl; 
                delete temp;
            }
        }

        void display() { 
            if(front==NULL) { 
                cout<<"Queue is empty."<<endl;
            } else { 
                QueueNode *temp = new QueueNode();
                temp = front; 
                cout<<"Elements in the queue : ";
                while(temp->next!=NULL) { 
                    cout<<temp->data<<" "; 
                    temp=temp->next;
                }
                cout<<temp->data<<" "; 
                cout<<endl;
            }
        }

        void size() { 
            QueueNode* temp = new QueueNode();;
            int t=0;
            if(front==NULL){
                cout<<"Queue size : 0"<<endl;
            } else { 
                int t=0;
                temp=front;
                while(temp->next!=NULL){
                    t++;
                    temp=temp->next; 
                } 
                cout<<"Queue size : "<<t+1<<endl;
            }
        }


        void isEmpty() { 
            if(front==NULL) {
                cout<<"Queue is empty."<<endl;
            } else{
                cout<<"Queue is not empty."<<endl;
            }
        }


};



int main() {
	QueueList q;
	int op, x;
	while(1) {	
		cout <<"1.Enqueue 2.Dequeue 3.Display 4.Is Empty 5.Size 6.Exit\n";
		cout <<"Enter your option : ";
		cin >>op;
		switch(op) {
			case 1: 
				cout <<"Enter an element : ";
				cin >>x;
				q.enqueue(x);
				break;
			case 2: 
				q.dequeue();
				break;
			case 3: 
				q.display();
				break;
			case 4:
				q.isEmpty();
				break;
			case 5:
				q.size();
				break;
			case 6: exit(0);

            default:
                cout<<"Enter a valid choice: "<<endl;
		}
	}
}