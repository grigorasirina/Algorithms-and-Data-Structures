#include <iostream>
#include <vector>

using namespace std;

// Function to perform Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    
    // Iterate through the array
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already sorted, so we don't need to check them
        for (int j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {12, 9, 4, 99, 120, 1, 3, 10};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    // Call the BubbleSort function to sort the array
    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
