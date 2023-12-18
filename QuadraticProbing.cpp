#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define SIZE 13

int HashTable[SIZE];
int hash_function(int x) {
    return x % SIZE;
}
void insertEle(int x) {
    int index = hash_function(x);
    while (HashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    HashTable[index] = x;
    cout << "Successfully inserted." << endl;
}
void deleteEle(int x) {
    int index = hash_function(x);
    while (HashTable[index] != x && HashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    if (HashTable[index] == x) {
        HashTable[index] = -1; 
        cout << "Successfully deleted." << endl;
    } else {
        cout << "Element not found. So cannot delete the element." << endl;
    }
}
void searchEle(int x) {
    int index = hash_function(x);
    while (HashTable[index] != x && HashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    if (HashTable[index] == x) {
        cout << "Element found."<< endl;
    } else {
        cout << "Element not found." << endl;
    }
}
void print() {
    for (int i = 0; i < SIZE; ++i) {
        cout << "[" << i << "]=>" << HashTable[i] << endl;
    }
}

int main() {
	int x, op, i=0;
	for(i=0;i<SIZE;i++)
		HashTable[i]=-1;
	while(1) {
		cout << "1.Insert 2.Delete 3.Search 4.Print 5.Exit\n";
		cout << "Enter your option : ";
		cin >> op;
		switch(op) {
			case 1:	cout << "Enter an element to be inserted : ";
					cin >> x;
					insertEle(x);
					break;
			case 2:
					cout << "Enter an element to be deleted : ";
					cin >> x;
					deleteEle(x);
					break;
			case 3: 
					cout << "Enter an element to be searched : ";
					cin >> x;
					searchEle(x);
					break;
			case 4: 
					print();
					break;
			case 5:	exit(0);
		}
	}
}