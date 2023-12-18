#include<iostream>

using namespace std;

const int maxsize  = 100;

class List {
    private:
        int arr[maxsize];
        int size;

    public:
        List(){
            size = 0;
        }

        void create(){
            cout<<"Enter the size of the array: ";
            cin>>size;
            cout<<"Enter the elements of the array: "<<endl;
            for(int i=0; i<size; i++){
                cout<<"element "<<i+1<<" : ";
                cin>>arr[i];
            }
        }

        int isFull(){
            return size==maxsize;
        }

        int isEmpty(){
            return size == 0;
        }

        void insert(int element, int position){
            if(isFull()){
                cout<<"Array is FUll";
                return;
            }

            if(position < 0 && position > size){
                cout<<"Invalid postion"<<endl;
                return;
            } else {
                for(int i=size-1; i>=position;i--){
                    arr[i+1] = arr[i];
                }
                arr[position] = element;
                size++;
                cout<<"Element inserted successfully"<<endl;
                return;
            }

        }

        void delete_item(int position){
            if(isEmpty()){
                cout<<"Array is Empty"<<endl;
                return;
            }
            if(position < 0 && position > size){
                cout<<"Invalid postion"<<endl;
                return;
            } else {
                for(int i = position; i<size-1; i++){
                    arr[i] = arr[i+1];
                }
                size--;
                cout<<"Element removed Successfully"<<endl;
            }
        }

        int search(int element){
            if(isEmpty()){
                cout<<"Array is Empty"<<endl;
                return -1;
            } else {
                for(int i=0; i<size; i++){
                    if(arr[i] == element){
                        return i+1;
                    }
                }
            }
            return -2;
        }

        void display(){
            if(isEmpty()){
                cout<<"Array is Empty"<<endl;
                return;
            } else {
                cout<<"Elements in the array are : "<<endl;
                for(int i =0 ; i<size; i++){
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
        }
};

int main(){
    List l;
    int ch, e, p;
    l.create();
    while(1){
        cout<<"Choose operation to perform: "<<endl;
        cout<<"1. insert 2.delete 3.search 4.display 5.exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the element to insert: ";
                cin>>e;
                cout<<"Enter the position to be inserted: ";
                cin>>p;
                l.insert(e, p);
                break;
            case 2:
                cout<<"Enter the position to be removed: ";
                cin>>p;
                l.delete_item(p);
                break;
            case 3:
                cout<<"Enter the element to be searched :";
                cin>>p;
                p = l.search(p);
                if(p ==-2){
                    cout<<"Element not found"<<endl;
                }
                if(p == -1){

                } else {
                    cout<<"Element found at position "<<p<<endl;
                }
                break;
            case 4:
                l.display();
                break;
            case 5:
                exit(0);
                break;
            default:
                cout<<"Enter the valid choie.. ";
                break;
        }
    
    }
}
