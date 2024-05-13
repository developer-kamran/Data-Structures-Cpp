#include <iostream>

using namespace std;

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main(){
	cout << "Please enter size of the array: " << endl;
	int size;
	cin >> size;
	int arr[size];
	
	cout << "Enter elements for the array: " << endl;
	for (int i = 0; i < size; i++){
	       cin >> arr[i];
	}
	
	cout << "Unsorted array: " << endl;
	for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	bubble_sort(arr, size);
	
	cout << "Sorted array after Bubble Sort: " << endl;
	for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
	
	
	return 0;
}

