#include <iostream>

using namespace std;


int binarySearch(int array[], int size, int target){
	int left = 0;
	int right = size - 1;
	int mid;
	
	while (left <= right){	
		mid = (right + left) / 2;
		
		if (target == array[mid]){
			return mid;
		}
		else if (target > array[mid]){
			left = mid + 1;
		}
		else{
			right = mid -1;
		}
	}
	
	return -1;
	
}


int main() {
	int size;
	cout << "Enter the size of the array: " << endl;
	cin >> size;
	int array[size];
	
	cout << "Enter elements for the array in sorted order:" << endl;
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

        int index = binarySearch(array, size, target);

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
