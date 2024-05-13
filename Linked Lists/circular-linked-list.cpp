#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

void display(Node* head) {
    if (head == NULL) {
        cout << "Circular linked list is empty" << endl;
    } else {
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
}

void deleteList(Node** head) {
    if (*head == NULL) return;

    Node* current = *head;
    Node* next;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head);

    *head = NULL;
}

void deleteSingleNode(Node** head, int key) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* prev = NULL;

    do {
        if (temp->data == key) break;
        prev = temp;
        temp = temp->next;
    } while (temp != *head);

    if (temp == *head && temp->data == key) {
        if (temp->next == temp) {
            free(temp);
            *head = NULL;
            return;
        } else {
            prev = *head;
            while (prev->next != *head)
                prev = prev->next;
            prev->next = temp->next;
            *head = temp->next;
            free(temp);
            cout << "Node with value " << key << " deleted" << endl;
        }
    } else if (temp != *head) {
        prev->next = temp->next;
        free(temp);
        cout << "Node with value " << key << " deleted" << endl;
    } else {
        cout << "Node with value " << key << " not found. Nothing deleted." << endl;
    }
}

Node* search(Node* head, int key) {
    if (head == NULL) return NULL;

    Node* temp = head;
    do {
        if (temp->data == key) return temp;
        temp = temp->next;
    } while (temp != head);

    return NULL;
}

int main() {
    Node* head = NULL;
    char choice;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Insert a value" << endl;
        cout << "2. Display the circular linked list" << endl;
        cout << "3. Delete the entire circular linked list" << endl;
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
                cout << "Circular Linked List: ";
                display(head);
                break;
            }
            case '3': {
                deleteList(&head);
                cout << "Circular linked list deleted" << endl;
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

