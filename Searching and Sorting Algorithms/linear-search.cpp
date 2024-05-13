#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}


int main() {
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int array[size];

    cout << "Enter elements for the array." << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    cout << "Array elements entered by the user:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }

    char choice;
    do {
        int target;
        cout << "\nEnter the element you want to search for: ";
        cin >> target;

        int index = linearSearch(array, size, target);

        if (index != -1) {
            cout << "Element found at index: " << index << endl;
        } else {
            cout << "Element not found in the array." << endl;
        }

        cout << "Do you want to search again? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
