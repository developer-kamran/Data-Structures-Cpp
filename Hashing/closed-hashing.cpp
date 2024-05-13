#include <iostream>
using namespace std;

const int EMPTY_SLOT = -1;

void linearInsert(int arr[], int size) {
    int element;
    cout << "Enter the element to insert: ";
    cin >> element;
    
    int index = element % size;
    while (arr[index] != EMPTY_SLOT) {
        index = (index + 1) % size;
        if (index == (element % size)) {
            cout << "Hash table is full. Cannot insert element." << endl;
            return;
        }
    }
    arr[index] = element;
    cout << "Element " << element << " inserted at position " << index << endl;
}

void quadraticInsert(int arr[], int size) {
    int element;
    cout << "Enter the element to insert: ";
    cin >> element;
    
    int index = element % size;
    int probe = 1;
    while (arr[index] != EMPTY_SLOT) {
        index = (index + probe * probe) % size;
        probe++;
        if (index == (element % size)) {
            cout << "Hash table is full. Cannot insert element." << endl;
            return;
        }
    }
    arr[index] = element;
    cout << "Element " << element << " inserted at position " << index << endl;
}

void linearSearch(int arr[], int size) {
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    
    int index = key % size;
    while (arr[index] != EMPTY_SLOT && arr[index] != key) {
        index = (index + 1) % size;
        if (arr[index] == key) {
            cout << "Element found at index " << index << "." << endl;
            return;
        }
    }
    cout << "Element not found." << endl;
}

void quadraticSearch(int arr[], int size) {
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    
    int index = key % size;
    int probe = 1;
    while (arr[index] != EMPTY_SLOT && arr[index] != key) {
        index = (index + probe * probe) % size;
        probe++;
        if (arr[index] == key) {
            cout << "Element found at index " << index << "." << endl;
            return;
        }
    }
    cout << "Element not found." << endl;
}

void print(int arr[], int size) {
    cout << "Current state of the hash table:" << endl;
    for (int i = 0; i < size; i++) {
        if (arr[i] != EMPTY_SLOT) {
            cout << "Index " << i << ": " << arr[i] << endl;
        } else {
            cout << "Index " << i << ": Empty (-1)" << endl;
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;
    
    int hashTable[size];
    for (int i = 0; i < size; i++) {
        hashTable[i] = EMPTY_SLOT;
    }
    
    int choice;
    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Insert using linear probing\n";
        cout << "2. Insert using quadratic probing\n";
        cout << "3. Search using linear probing\n";
        cout << "4. Search using quadratic probing\n";
        cout << "5. Print hash table\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                linearInsert(hashTable, size);
                break;
            case 2:
                quadraticInsert(hashTable, size);
                break;
            case 3:
                linearSearch(hashTable, size);
                break;
            case 4:
                quadraticSearch(hashTable, size);
                break;
            case 5:
                print(hashTable, size);
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    
    return 0;
}

