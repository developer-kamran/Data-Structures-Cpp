#include <iostream>

using namespace std;

void insertion_sort(int arr[], int size){
	
	for(int i=1; i<size; i++){
		int key = arr[i];
		int j = i-1;
		
		while((arr[j] > key) && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
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
	
	insertion_sort(arr, size);
	
	cout << "Sorted array after Bubble Sort: " << endl;
	for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
	
	
	return 0;
}
