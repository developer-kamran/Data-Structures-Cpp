#include <iostream>
#include <cstdlib> 

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(Node* head) {
    if (head == NULL){
        cout << "Currently empty!";
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteList(Node** head) {
    Node* current = *head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void deleteSingleNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        cout << "Node with value " << key << " deleted" << endl;
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Key not found in the linked list. Nothing deleted!" << endl;
        return;
    }

    prev->next = temp->next;
    free(temp);
    
    cout << "Node with value " << key << " deleted" << endl;
}

bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = NULL;
    char choice;

    while (true) {
        cout << "1. Insert a value" << endl;
        cout << "2. Display the linked list" << endl;
        cout << "3. Delete the entire linked list" << endl;
        cout << "4. Delete a node" << endl;
        cout << "5. Search for node" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int value;
                cout << "Enter a value to insert into the list: ";
                cin >> value;
                insert(head, value);
                break;
            }
            case '2': {
                cout << "Linked List: ";
                display(head);
                break;
            }
            case '3': {
                deleteList(&head);
                cout << "Linked list deleted" << endl;
                break;
            }
            case '4': {
                int key;
                cout << "Enter the value to delete: ";
                cin >> key;
                deleteSingleNode(&head, key);
                break;
            }
               case '5': {
                int key;
                cout << "Enter the value to search for: ";
                cin >> key;
                if (search(head, key)) {
                    cout << "Value " << key << " found in the linked list" << endl;
                } else {
                    cout << "Value " << key << " not found in the linked list" << endl;
                }
                break;
            }
            case '6': {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please enter again." << endl;
                break;
            }
        }
    }

    return 0;
}

