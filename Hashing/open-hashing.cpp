#include <iostream>

using namespace std;

const int EMPTY_SLOT = -1;

struct Node {
    int data;
    Node* next;
};

void insert(Node* hashTable[], int key, int size) {
    int index = key % size;

    Node* newNode = new Node;
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Element " << key << " inserted at index " << index << endl;
}

void search(Node* hashTable[], int key, int size) {
    int index = key % size;

    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Element " << key << " found at index " << index << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Element " << key << " not found" << endl;
}

void remove(Node* hashTable[], int key, int size) {
    int index = key % size;

    Node* current = hashTable[index];
    Node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            hashTable[index] = current->next;
        }
        delete current;
        cout << "Element " << key << " deleted from index " << index << endl;
    } else {
        cout << "Element " << key << " not found for deletion" << endl;
    }
}

void print(Node* hashTable[], int size) {
    cout << "Current state of the hash table:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Index " << i << ": ";
        Node* temp = hashTable[i];
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;

    Node* hashTable[size];
    for (int i = 0; i < size; ++i) {
        hashTable[i] = NULL;
    }

    int choice, key;
    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Insert element\n";
        cout << "2. Search element\n";
        cout << "3. Delete element\n";
        cout << "4. Print hash table\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> key;
                insert(hashTable, key, size);
                break;
            case 2:
                cout << "Enter element to search: ";
                cin >> key;
                search(hashTable, key, size);
                break;
            case 3:
                cout << "Enter element to delete: ";
                cin >> key;
                remove(hashTable, key, size);
                break;
            case 4:
                print(hashTable, size);
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    for (int i = 0; i < size; ++i) {
        Node* temp = hashTable[i];
        while (temp != NULL) {
            Node* delNode = temp;
            temp = temp->next;
            delete delNode;
        }
    }

    return 0;
}

