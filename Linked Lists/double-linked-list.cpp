#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void display(Node* head) {
    if (head == NULL) {
        cout << "Double linked list is empty" << endl;
    } else {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

Node* search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    return temp;
}

void deleteList(Node** head) {
    if (*head == NULL) return;

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
    if (*head == NULL) return;

    Node* temp = *head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp != NULL) {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            *head = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
        cout << "Node with value " << key << " deleted" << endl;
    } else {
        cout << "Node with value " << key << " not found. Nothing deleted." << endl;
    }
}

int main() {
    Node* head = NULL;
    char choice;

    while (true) {
        cout << "1. Insert a value" << endl;
        cout << "2. Display the double linked list" << endl;
        cout << "3. Delete the entire double linked list" << endl;
        cout << "4. Delete a node" << endl;
        cout << "5. Search for a node" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int value;
                cout << "Enter a value to insert into the list: ";
                cin >> value;
                insert(&head, value);
                break;
            }
            case '2': {
                cout << "Double Linked List: ";
                display(head);
                break;
            }
            case '3': {
                deleteList(&head);
                cout << "Double linked list deleted" << endl;
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
                Node* result = search(head, key);
                if (result != NULL) {
                    cout << "Node with value " << key << " found" << endl;
                } else {
                    cout << "Node with value " << key << " not found" << endl;
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

