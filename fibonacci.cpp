#include <iostream>
using namespace std;

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    // Base case: the first and second numbers of the sequence are 1
    if (n <= 1) {
        return n;
    }

    // Recursive case: sum of the two preceding numbers
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Main function
int main() {
    int n;
    cout << "Enter the number of terms for Fibonacci sequence: ";
    cin >> n;

    cout << "Fibonacci sequence up to " << n << " terms:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    return 0;
}
