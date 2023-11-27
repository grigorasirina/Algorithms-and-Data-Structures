#include <iostream>

// Function to implement the Euclidean algorithm
// This function returns the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    // Base case: If b is 0, gcd is a
    if (b == 0) {
        return a;
    }

    // Recursive case: Call gcd with b and the remainder of a divided by b
    return gcd(b, a % b);
}

int main() {
    int num1, num2;

    // Input two numbers
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    // Call the gcd function and display the result
    std::cout << "GCD of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << std::endl;

    return 0;
}
