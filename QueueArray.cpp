#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


#define MAX 10
class QueueArray {
	public :
	int queue[MAX];
	int front, rear;

	QueueArray() {
		front = rear = -1;
	}

	void enqueue(int x) {
        if(rear>=MAX-1)
		cout<<"Queue is full."<<endl;
        else{
            if(front == -1){
                front++;
            }
            rear++;
            queue[rear] = x;
            cout<<"Successfully inserted."<<endl;
	    }
    }

    void dequeue() {
        if(front>rear)
            cout<<"Queue is underflow."<<endl;
        else{
            int y = queue[front];
            front++;
            cout<<"Deleted element = "<<y<<endl;
        }    
    }

    void display() {
        if(front>rear || rear == -1)
            cout<<"Queue is empty."<<endl;
        else{
            cout<<"Elements in the queue : ";
            for(int i=front;i<=rear;i++){
                cout<<queue[i]<<" ";
            }
            cout<<endl;
        }
    }

    void size() {
        cout<<"Queue size : "<<(rear-front)+1<<endl;
    }
    
    void isEmpty() {
        if(front>rear)
            cout<<"Queue is empty."<<endl;
        else
            cout<<"Queue is not empty."<<endl;
    }
};

int main() {
	QueueArray q;
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
			case 6: 
				exit(0);
		}
	}
}