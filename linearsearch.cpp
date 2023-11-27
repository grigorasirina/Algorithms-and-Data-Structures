#include <iostream>
using namespace std;

// Function to perform linear search
int linearSearch(int arr[], int n, int x) {
    // 'n' is the number of elements in the array
    // 'x' is the element to be searched

    // Loop through each element of the array
    for (int i = 0; i < n; i++) {
        // Compare the current element with 'x'
        if (arr[i] == x) {
            return i; // If element is found, return its index
        }
    }

    // If we reach here, then the element is not present in the array
    return -1;
}

// Main function
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10; // Element to be searched

    int result = linearSearch(arr, n, x);

    if (result == -1) {
        cout << "Element is not present in the array";
    } else {
        cout << "Element is present at index " << result;
    }

    return 0;
}
