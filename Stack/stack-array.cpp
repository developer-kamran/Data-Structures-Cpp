#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX_SIZE 5 // Maximum size of the stack

struct Stack {
    int top;
    int array[MAX_SIZE];
};

void push(Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        cout << "Stack overflow\n";
        return;
    }
    stack->array[++stack->top] = value;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        cout << "Stack underflow\n";
        return -1;
    }
    return stack->array[stack->top--];
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void deleteStack(Stack* stack) {
    stack->top = -1; 
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= stack->top; ++i) {
        cout << stack->array[i] << " ";
    }
    cout << endl;
}

bool search(Stack* stack, int value) {
    for (int i = 0; i <= stack->top; ++i) {
        if (stack->array[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {
    Stack stack;
    stack.top = -1; 

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
                push(&stack, value);
                break;
            case 2:
                {
                    int poppedValue = pop(&stack);
                    if (poppedValue != -1)
                        cout << "Popped value: " << poppedValue << endl;
                    break;
                }
            case 3:
                if (isEmpty(&stack)) {
                    cout << "Stack is currently empty. Please insert some value first." << endl;
                    break;
                }
                deleteStack(&stack);
                cout << "Stack deleted\n";
                break;
            case 4:
                display(&stack);
                break;
            case 5:
                if (isEmpty(&stack)) {
                    cout << "Stack is currently empty. Please insert some value first." << endl;
                    break;
                }
                cout << "Enter value to search: ";
                cin >> value;
                if (search(&stack, value)) {
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

