#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array
int partition(vector<int>& arr, int low, int high) {
    // Choose the pivot element (here, we'll pick the first element as the pivot)
    int pivot = arr[low];
    
    // Initialize pointers to traverse the array
    int left = low + 1; // Points to the first element to the right of pivot
    int right = high;   // Points to the last element
    
    // Print a message to show the current partitioning process
    cout << "Partitioning between indices " << low << " and " << high << ". Pivot element is: " << pivot << "\n";

    while (true) {
        // Find an element on the left that is greater than the pivot
        while (left <= right && arr[left] <= pivot) {
            left++;
        }
        
        // Find an element on the right that is less than the pivot
        while (left <= right && arr[right] >= pivot) {
            right--;
        }
        
        // If the left and right pointers haven't crossed, swap the elements
        if (left <= right) {
            swap(arr[left], arr[right]);
        } else {
            // If the left and right pointers have crossed, break out of the loop
            break;
        }
    }
    
    // Swap the pivot element with the element at the right pointer position
    swap(arr[low], arr[right]);

    // Print the array after partitioning
    cout << "After partitioning, the array looks like this:\n";
    for (int i = low; i <= high; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Return the index where the pivot element is now placed
    return right;
}

// Function to perform QuickSort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array into two halves and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the left and right sub-arrays
        cout << "Sorting the left partition between indices " << low << " and " << (pivotIndex - 1) << ".\n";
        quickSort(arr, low, pivotIndex - 1);

        cout << "Sorting the right partition between indices " << (pivotIndex + 1) << " and " << high << ".\n";
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {12, 9, 4, 99, 120, 1, 3, 10};
    int n = arr.size();

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    // Call the QuickSort function to sort the array
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
