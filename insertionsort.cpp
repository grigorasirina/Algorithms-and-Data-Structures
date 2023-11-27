#include <iostream>
#include <vector>

using namespace std;

// Function to perform Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size(); // Get the number of elements in the array
    
    // Iterate through the array
    for (int i = 1; i < n; i++) {
        // Current element to be inserted into the sorted subarray
        int current = arr[i];
        
        // Start from the last element of the sorted subarray
        int j = i - 1;
        
        // Compare the current element with the elements in the sorted subarray
        // Move elements of the sorted subarray that are greater than the current
        // element to the right by one position
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insert the current element into its correct position in the sorted subarray
        arr[j + 1] = current;
        
        // Print the array after each pass for visualization
        cout << "Pass " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<int> arr = {12, 9, 4, 99, 120, 1, 3, 10};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    // Call the InsertionSort function to sort the array
    insertionSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
