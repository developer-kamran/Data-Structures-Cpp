#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void swap(int heap[], int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heapify_up(int heap[], int index) {
    int parent = (index - 1) / 2;
    while (parent >= 0 && heap[index] > heap[parent]) {
        swap(heap, index, parent);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapify_down(int heap[], int index, int size) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(heap, index, largest);
        heapify_down(heap, largest, size);
    }
}

void insert(int heap[], int& size, int value) {
    if (size >= MAX_SIZE) {
        cout << "Heap is full. Cannot insert." << endl;
        return;
    }
    heap[size] = value;
    heapify_up(heap, size);
    size++;
}

void remove_max(int heap[], int& size) {
    if (size <= 0) {
        cout << "Heap is empty. Cannot remove." << endl;
        return;
    }

    swap(heap, 0, size - 1);
    size--;
    heapify_down(heap, 0, size);
}

void display(int heap[], int size) {
    if (size <= 0) {
        cout << "Heap is empty." << endl;
        return;
    }
    cout << "Heap elements: ";
    for (int i = 0; i < size; ++i)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    int heap[MAX_SIZE];
    int size = 0;
    char choice;

    do {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                insert(heap, size, value);
                break;
            }
            case '2':
                remove_max(heap, size);
                break;
            case '3':
                display(heap, size);
                break;
            case '4':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != '4');

    return 0;
}

