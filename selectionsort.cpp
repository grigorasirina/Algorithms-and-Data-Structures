#include <iostream>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    // 'n' is the number of elements in the array

    // Loop through each element of the array
    for (int i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted part of the array
        int min_index = i; // Start with the current position as the minimum
        for (int j = i+1; j < n; j++) {
            // If a smaller element is found, update the minimum index
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Call the selectionSort function
    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
