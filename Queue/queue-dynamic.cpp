#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void enqueue(Node** front, Node** rear, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        cout << "Memory allocation failed\n";
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(Node** front, Node** rear) {
    if (*front == NULL) {
        cout << "Queue underflow\n";
        exit(1);
    }
    int dequeuedValue = (*front)->data;
    Node* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return dequeuedValue;
}

bool isEmpty(Node* front) {
    return front == NULL;
}

void display(Node* front) {
    if (isEmpty(front)) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements: ";
    Node* current = front;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteQueue(Node** front, Node** rear) {
    while (*front != NULL) {
        Node* temp = *front;
        *front = (*front)->next;
        free(temp);
    }
    *rear = NULL;
}

bool searchQueue(Node* front, int value){
    Node* current = front;
    while (current != NULL) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    int choice, value;

    while (true) {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display queue\n";
        cout << "4. Search element\n";
        cout << "5. Delete entire queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(&front, &rear, value);
                break;
            case 2:
                cout << "Dequeued value: " << dequeue(&front, &rear) << endl;
                break; 
            case 3:
                display(front);
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchQueue(front, value)) {
                    cout << "Value found in queue\n";
                } else {
                    cout << "Value not found in queue\n";
                }
                break;
            case 5:
                deleteQueue(&front, &rear);
                cout << "Queue deleted\n";
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}

