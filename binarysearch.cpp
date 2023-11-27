#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int x) {
    // 'left' and 'right' are the start and end indices of the array
    // 'x' is the element to be searched

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        // Check if 'x' is present at mid
        if (arr[mid] == x) {
            return mid; // Element found, return its index
        }

        // If 'x' is greater, ignore left half
        if (arr[mid] < x) {
            left = mid + 1;
        }
        // If 'x' is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    // If we reach here, then the element was not present
    return -1;
}

// Main function
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10; // Element to be searched

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1) {
        cout << "Element is not present in array";
    } else {
        cout << "Element is present at index " << result;
    }

    return 0;
}
