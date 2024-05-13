#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        cout << "Memory allocation failed\n";
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) { 
    if (*top == NULL) {
        cout << "Stack underflow\n";
        return -1;
    }
    int poppedValue = (*top)->data;
    Node* temp = *top;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

bool isEmpty(Node* top) {
    return top == NULL;
}

void deleteStack(Node** top) {
    while (!isEmpty(*top)) {
        pop(top);
    }
}

void display(Node* top) {
    if (isEmpty(top)) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    Node* current = top;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

bool search(Node* top, int value) {
    Node* current = top;
    while (current != NULL) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    Node* top = NULL;
    int choice, value;

    while (true) {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Delete entire stack\n";
        cout << "4. Display stack\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(&top, value);
                break;
            case 2:
                {
                    int poppedValue = pop(&top);
                    if (poppedValue != -1)
                        cout << "Popped value: " << poppedValue << endl;
                    break;
                }
            case 3:
            	if(top == NULL){
				 cout << "Stack is currently empty. Please insert some value first." << endl;
				 break;
			}
                deleteStack(&top);
                cout << "Stack deleted\n";
                break;
            case 4:
                display(top);
                break;
            case 5:
            	if(top == NULL){
				 cout << "Stack is currently empty. Please insert some value first." << endl;
				 break;
			}
                cout << "Enter value to search: ";
                cin >> value;
                if (search(top, value)) {
                    cout << "Value found in stack\n";
                } else {
                    cout << "Value not found in stack\n";
                }
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}

