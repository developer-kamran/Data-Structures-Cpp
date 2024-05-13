#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the queue

int front = -1;
int rear = -1;

void enqueue(int queue[], int size, int value) {
    if ((rear + 1) % size == front) {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % size;
    queue[rear] = value;
}

int dequeue(int queue[], int size) {
    if (front == -1) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % size;
    }
    return value;
}

void displayQueue(int queue[], int size) {
    if (front == -1) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements are: ";
    if (front <= rear) {
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
    } else {
        for (int i = front; i < size; i++)
            cout << queue[i] << " ";
        for (int i = 0; i <= rear; i++)
            cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    int queue[MAX_SIZE];
    int choice;
    do {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue(queue, size, value);
                break;
            }
            case 2: {
                int value = dequeue(queue, size);
                if (value != -1)
                    cout << "Dequeued value: " << value << endl;
                break;
            }
            case 3:
                displayQueue(queue, size);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 4);
    return 0;
}

