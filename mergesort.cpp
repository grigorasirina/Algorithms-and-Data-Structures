#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted subarrays into one sorted array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;    // Size of the left subarray
    int n2 = right - mid;       // Size of the right subarray

    // Create temporary arrays to hold the left and right subarrays
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    // Merge the two subarrays back into the original array
    int i = 0;  // Initial index of left subarray
    int j = 0;  // Initial index of right subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr and rightArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Print the array after merging
    cout << "Merged array from indices " << left << " to " << right << ":\n";
    for (int idx = left; idx <= right; idx++) {
        cout << arr[idx] << " ";
    }
    cout << "\n";
}

// Function to perform MergeSort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point to divide the array into two halves
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

    // Call the MergeSort function to sort the array
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
