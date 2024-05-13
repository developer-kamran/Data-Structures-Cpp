#include <iostream>

using namespace std;

void selection_sort(int arr [], int size){
	for(int i = 0; i < size-1; i++){
		int minIndex = i;
		for(int j = i+1; j < size; j++){
			if(arr[minIndex] > arr[j]){
			minIndex = j;
 			}	
		}
		if(minIndex != i){
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;	
		}
	}
}


int main (){
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
	
	selection_sort(arr, size);
	
	cout << "Sorted array after Selection Sort: " << endl;
	for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
	return 0;
}
