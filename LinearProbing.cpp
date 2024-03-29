#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define SIZE 13


int HashTable[SIZE];

int hash_function(int x) {
    return x % SIZE;
}

void initializeHashTable() {
    for (int i = 0; i < SIZE; ++i) {
        HashTable[i] = -1;
    }
}

void insertEle(int x) {
    int index = hash_function(x);
    while (HashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == hash_function(x)) {
            cout << "Hash table is full. Unable to insert." << endl;
            return;
        }
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
        HashTable[index] = -1;  // Mark the slot as deleted
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
        cout << "Element " << x << " found at position " << index << " in the hash table." << endl;
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
    int x, op;
    initializeHashTable();

    while (true) {
        cout << "1. Insert 2. Delete 3. Search 4. Print 5. Exit\n";
        cout << "Enter your option: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Enter an element to be inserted: ";
                cin >> x;
                insertEle(x);
                break;
            case 2:
                cout << "Enter an element to be deleted: ";
                cin >> x;
                deleteEle(x);
                break;
            case 3:
                cout << "Enter an element to be searched: ";
                cin >> x;
                searchEle(x);
                break;
            case 4:
                print();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
